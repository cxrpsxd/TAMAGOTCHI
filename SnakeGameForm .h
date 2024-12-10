#pragma once
#include <ctime>
#include <cstdlib>
#include "CatGame.h"
#include "MyMessage.h"

namespace TAMAGOTCHIW {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class SnakeGameForm : public System::Windows::Forms::Form
    {
    private:
        int score = 0;
    public:
        SnakeGameForm(void)
        {
            srand((unsigned int)time(0)); // Инициализация рандома
            InitializeComponent();
            InitializeGame();            
        }

        int GetScore()
        {
            return this->score;
        }

        String^ GetMonet(int quantity)
        {
            int lastDigit = quantity % 10;
            int lastTwoDigits = quantity % 100;

            if (lastDigit == 1 && lastTwoDigits != 11)
            {
                return " монета";
            }
            else if (lastDigit >= 2 && lastDigit <= 4 && (lastTwoDigits < 12 || lastTwoDigits > 14))
            {
                return " монеты";
            }
            else
            {
                return " монет";
            }
        }

    protected:
        ~SnakeGameForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Константы
        const int TileSize = 20; // Размер плитки (одного квадрата)
        const int FieldWidth = 27; // Ширина игрового поля (количество клеток)
        const int FieldHeight = 14; // Высота игрового поля (количество клеток)

        // Игровые переменные
        array<Point>^ snake; // Массив точек для хранения тела змейки
        int snakeLength; // Длина змейки
        Point food; // Еда
        Timer^ timer; // Таймер для обработки игры
        enum class Direction { Up, Down, Left, Right }; // Направления
        Direction currentDirection; // Текущее направление змейки
        bool gameOver; // Флаг окончания игры

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->Text = L"Snake Game";
            this->ClientSize = System::Drawing::Size(TileSize * FieldWidth, TileSize * FieldHeight);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SnakeGameForm::OnPaint);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SnakeGameForm::OnKeyDown);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // Убираем рамки
            this->WindowState = System::Windows::Forms::FormWindowState::Normal; // Полный экран
            this->TopMost = true; // Поверх прочих окон (по желанию)
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Left = 692; // Позиция от левого края экрана
            this->Top = 155;  // Позиция от верхнего края экрана


            timer = gcnew Timer();
            timer->Interval = 75; // Скорость игры (100 мс)
            timer->Tick += gcnew EventHandler(this, &SnakeGameForm::GameLoop);
        }
#pragma endregion

        // Задание начальных условий игры
        void InitializeGame()
        {
            snake = gcnew array<Point>(FieldWidth * FieldHeight); // Максимально возможный размер змейки
            snake[0] = Point(FieldWidth / 2, FieldHeight / 2); // Начальная позиция змейки
            snakeLength = 1; // Начальная длина змейки
            currentDirection = Direction::Right; // Стартовое движение вправо
            gameOver = false;

            GenerateFood(); // Создаём первую "еду"
            timer->Start(); // Запускаем игровой цикл
            Invalidate(); // Обновляем экран
        }

        // Генерация случайной еды
        void GenerateFood()
        {
            food = Point(rand() % FieldWidth, rand() % FieldHeight);
        }

        // Игровой цикл
        void GameLoop(System::Object^ sender, System::EventArgs^ e)
        {
            if (gameOver)
            {
                timer->Stop();
                MyMessage^ form = gcnew MyMessage("Игра окончена! Вы заработали: " + ((snakeLength - 1) * 2).ToString() + GetMonet((snakeLength - 1) * 2), snakeLength - 1 == 0 ? false: true);
                form->ShowDialog();  
                this->Close();
                return;
            }

            // Движение змейки
            MoveSnake();

            // Проверка столкновений
            CheckCollisions();

            // Перерисовка формы
            Invalidate();
        }

        // Логика движения змейки
        void MoveSnake()
        {
            // Перемещение тела змейки
            for (int i = snakeLength - 1; i > 0; i--)
            {

                snake[i] = snake[i - 1];
            }

            // Перемещение головы змейки
            switch (currentDirection)
            {
            case Direction::Up:
                snake[0].Y--;
                break;
            case Direction::Down:
                snake[0].Y++;
                break;
            case Direction::Left:
                snake[0].X--;
                break;
            case Direction::Right:
                snake[0].X++;
                break;
            }

            // Проверка, съела ли змейка еду
            if (snake[0] == food)
            {
                snakeLength++;
                score++;
                GenerateFood();
            }
        }

        // Проверка столкновений змейки
        void CheckCollisions()
        {
            // Столкновение с границами поля
            if (snake[0].X < 0 || snake[0].Y < 0 || snake[0].X >= FieldWidth || snake[0].Y >= FieldHeight)
            {
                gameOver = true;
            }

            // Столкновение с самим собой
            for (int i = 1; i < snakeLength; i++)
            {
                if (snake[0] == snake[i])
                {
                    gameOver = true;
                }
            }
        }

        // Рисование змейки и еды
        void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;

            // Рисуем поле
            g->Clear(Color::Black);

            // Рисуем змейку
            for (int i = 0; i < snakeLength; i++)
            {
                g->FillRectangle(Brushes::Green, Rectangle(snake[i].X * TileSize, snake[i].Y * TileSize, TileSize, TileSize));
            }

            // Рисуем еду
            g->FillRectangle(Brushes::Red, Rectangle(food.X * TileSize, food.Y * TileSize, TileSize, TileSize));
        }

        // Управление змейкой с клавиатуры
        void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
        {
            switch (e->KeyCode)
            {
            case Keys::Up:
                if (currentDirection != Direction::Down) currentDirection = Direction::Up;
                break;
            case Keys::Down:
                if (currentDirection != Direction::Up) currentDirection = Direction::Down;
                break;
            case Keys::Left:
                if (currentDirection != Direction::Right) currentDirection = Direction::Left;
                break;
            case Keys::Right:
                if (currentDirection != Direction::Left) currentDirection = Direction::Right;
                break;
            }
        }
    };
}
