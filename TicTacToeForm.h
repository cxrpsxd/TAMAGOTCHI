#pragma once

#include <cstdlib> // Для генератора случайных чисел
#include <ctime>   // Для инициализации случайных чисел
#include "CatGame.h"
#include "DogGame.h"
#include "MyMessage.h"

namespace TAMAGOTCHIW {

    using namespace System;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    public ref class TicTacToeForm : public Form {
    private:
        int score = 0;
    public:
        TicTacToeForm() {
            this->Text = L"Крестики-Нолики";
            this->Width = 522;
            this->Height = 280;
            this->BackColor = Color::FromArgb(30, 30, 30); // Тёмно-серый фон
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // Убрать рамки
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Left = 699; // Позиция от левого края экрана
            this->Top = 155;  // Позиция от верхнего края экрана
            InitializeGameBoard();            

            srand((unsigned int)time(nullptr)); // Инициализация генератора случайных чисел
        }
        int GetScore()
        {
            return this->score;
        }

    private:
        array<Button^, 2>^ board;
        bool isPlayerXTurn = true; // Если true, ходит игрок

        
        // Инициализация игрового поля
        // Инициализация игрового поля
        void InitializeGameBoard() {
            board = gcnew array<Button^, 2>(3, 3);

            int buttonSize = 77; // Размер кнопки
            int spacing = 10;   // Отступы между кнопками

            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    board[row, col] = gcnew Button();

                    // Параметры кнопки
                    board[row, col]->Width = buttonSize;
                    board[row, col]->Height = buttonSize;
                    board[row, col]->BackColor = Color::FromArgb(60, 60, 60); // Тёмный цвет кнопки
                    board[row, col]->FlatStyle = FlatStyle::Flat;
                    board[row, col]->FlatAppearance->BorderSize = 0; // Убираем границы
                    board[row, col]->Font = gcnew Drawing::Font(L"Arial", 22, FontStyle::Bold); // Шрифт для "X" и "O"
                    board[row, col]->ForeColor = Color::White;

                    // Расположение кнопок
                    board[row, col]->Left = col * (buttonSize + spacing) + spacing + 128; // Отступ слева
                    board[row, col]->Top = row * (buttonSize + spacing) + spacing + 5; // Отступ сверху

                    // Обработка кликов
                    board[row, col]->Click += gcnew EventHandler(this, &TicTacToeForm::ButtonClick);

                    // Добавляем кнопки в форму
                    this->Controls->Add(board[row, col]);
                }
            }
        }

        

        // Обработка хода игрока
        void ButtonClick(Object^ sender, EventArgs^ e) {
            Button^ clickedButton = (Button^)sender;

            // Если клетка уже занята, ничего не делаем
            if (clickedButton->Text != L"") return;

            // Ход игрока
            clickedButton->Text = L"X";

            // Проверяем победу после хода игрока
            if (CheckWin(L"X")) {
                MyMessage^ form = gcnew MyMessage("Победа!\n Вы заработали 30 монет", true);
                form->ShowDialog();
                score = 30;
                this->Close();  // Закрытие текущей формы
                return;
            }

            // Если после хода игрока все клетки заняты, значит ничья
            if (IsBoardFull()) {
                MyMessage^ form = gcnew MyMessage("Ничья!\n Вы заработали 5 монет", true);
                score = 5;
                form->ShowDialog();
                this->Close();  // Закрытие текущей формы
                return;
            }

            // Ход компьютера
            ComputerMove();

            // Проверяем победу после хода компьютера
            if (CheckWin(L"O")) {
                MyMessage^ form = gcnew MyMessage("Компьютер победил!", false);
                form->ShowDialog();
                this->Close();  // Закрытие текущей формы
                return;
            }

        }

        void ComputerMove() {
            // Компьютер сначала будет проверять, может ли он выиграть или блокировать ход, а только потом выбирать случайное поле:
            if (MakeSmartMove(L"O")) return; // Попытка выиграть
            if (MakeSmartMove(L"X")) return; // Попытка блокировать игрока

            // Если ходов с выигрышем/блокировкой нет, выбираем случайное поле
            while (true) {
                int row = rand() % 3;
                int col = rand() % 3;

                if (board[row, col]->Text == L"") {
                    board[row, col]->Text = L"O";
                    break;
                }
            }
        }

        // Умный ход (выигрышный/защитный)
        bool MakeSmartMove(String^ symbol) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                    if (board[i, j]->Text == L"") {
                        // Временная установка символа
                        board[i, j]->Text = symbol;

                        // Проверяем, приводит ли этот ход к победе
                        if (CheckWin(symbol)) {
                            if (symbol == L"O") return true;  // Оставляем символ, если это победа компьютера
                            board[i, j]->Text = L"O";        // Подменяем на символ компьютера для блокировки
                            return true;
                        }

                        // Откатываем ход, если он не приводит к выигрышу
                        board[i, j]->Text = L"";
                    }
                }
            }

            return false; // Если нет выигрышного или защитного хода
        }

        // Проверяет, есть ли победа для указанного символа
        bool CheckWin(String^ symbol) {
            // Проверка строк и столбцов
            for (int i = 0; i < 3; i++) {
                if (board[i, 0]->Text == symbol && board[i, 1]->Text == symbol && board[i, 2]->Text == symbol)
                    return true;
                if (board[0, i]->Text == symbol && board[1, i]->Text == symbol && board[2, i]->Text == symbol)
                    return true;
            }

            // Проверка диагоналей
            if (board[0, 0]->Text == symbol && board[1, 1]->Text == symbol && board[2, 2]->Text == symbol)
                return true;
            if (board[0, 2]->Text == symbol && board[1, 1]->Text == symbol && board[2, 0]->Text == symbol)
                return true;

            return false;
        }

        // Проверяет, заполнена ли доска
        bool IsBoardFull() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i, j]->Text == L"") return false;
                }
            }
            return true;
        }

        // Сброс игры
        void ResetGame() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i, j]->Text = L"";
                }
            }
            isPlayerXTurn = true;
        }
    };
}
