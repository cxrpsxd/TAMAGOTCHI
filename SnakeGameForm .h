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
            srand((unsigned int)time(0)); // ������������� �������
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
                return " ������";
            }
            else if (lastDigit >= 2 && lastDigit <= 4 && (lastTwoDigits < 12 || lastTwoDigits > 14))
            {
                return " ������";
            }
            else
            {
                return " �����";
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
        // ���������
        const int TileSize = 20; // ������ ������ (������ ��������)
        const int FieldWidth = 27; // ������ �������� ���� (���������� ������)
        const int FieldHeight = 14; // ������ �������� ���� (���������� ������)

        // ������� ����������
        array<Point>^ snake; // ������ ����� ��� �������� ���� ������
        int snakeLength; // ����� ������
        Point food; // ���
        Timer^ timer; // ������ ��� ��������� ����
        enum class Direction { Up, Down, Left, Right }; // �����������
        Direction currentDirection; // ������� ����������� ������
        bool gameOver; // ���� ��������� ����

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
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // ������� �����
            this->WindowState = System::Windows::Forms::FormWindowState::Normal; // ������ �����
            this->TopMost = true; // ������ ������ ���� (�� �������)
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Left = 692; // ������� �� ������ ���� ������
            this->Top = 155;  // ������� �� �������� ���� ������


            timer = gcnew Timer();
            timer->Interval = 75; // �������� ���� (100 ��)
            timer->Tick += gcnew EventHandler(this, &SnakeGameForm::GameLoop);
        }
#pragma endregion

        // ������� ��������� ������� ����
        void InitializeGame()
        {
            snake = gcnew array<Point>(FieldWidth * FieldHeight); // ����������� ��������� ������ ������
            snake[0] = Point(FieldWidth / 2, FieldHeight / 2); // ��������� ������� ������
            snakeLength = 1; // ��������� ����� ������
            currentDirection = Direction::Right; // ��������� �������� ������
            gameOver = false;

            GenerateFood(); // ������ ������ "���"
            timer->Start(); // ��������� ������� ����
            Invalidate(); // ��������� �����
        }

        // ��������� ��������� ���
        void GenerateFood()
        {
            food = Point(rand() % FieldWidth, rand() % FieldHeight);
        }

        // ������� ����
        void GameLoop(System::Object^ sender, System::EventArgs^ e)
        {
            if (gameOver)
            {
                timer->Stop();
                MyMessage^ form = gcnew MyMessage("���� ��������! �� ����������: " + ((snakeLength - 1) * 2).ToString() + GetMonet((snakeLength - 1) * 2), snakeLength - 1 == 0 ? false: true);
                form->ShowDialog();  
                this->Close();
                return;
            }

            // �������� ������
            MoveSnake();

            // �������� ������������
            CheckCollisions();

            // ����������� �����
            Invalidate();
        }

        // ������ �������� ������
        void MoveSnake()
        {
            // ����������� ���� ������
            for (int i = snakeLength - 1; i > 0; i--)
            {

                snake[i] = snake[i - 1];
            }

            // ����������� ������ ������
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

            // ��������, ����� �� ������ ���
            if (snake[0] == food)
            {
                snakeLength++;
                score++;
                GenerateFood();
            }
        }

        // �������� ������������ ������
        void CheckCollisions()
        {
            // ������������ � ��������� ����
            if (snake[0].X < 0 || snake[0].Y < 0 || snake[0].X >= FieldWidth || snake[0].Y >= FieldHeight)
            {
                gameOver = true;
            }

            // ������������ � ����� �����
            for (int i = 1; i < snakeLength; i++)
            {
                if (snake[0] == snake[i])
                {
                    gameOver = true;
                }
            }
        }

        // ��������� ������ � ���
        void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;

            // ������ ����
            g->Clear(Color::Black);

            // ������ ������
            for (int i = 0; i < snakeLength; i++)
            {
                g->FillRectangle(Brushes::Green, Rectangle(snake[i].X * TileSize, snake[i].Y * TileSize, TileSize, TileSize));
            }

            // ������ ���
            g->FillRectangle(Brushes::Red, Rectangle(food.X * TileSize, food.Y * TileSize, TileSize, TileSize));
        }

        // ���������� ������� � ����������
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
