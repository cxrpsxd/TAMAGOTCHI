#pragma once

#include <cstdlib> // ��� ���������� ��������� �����
#include <ctime>   // ��� ������������� ��������� �����
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
            this->Text = L"��������-������";
            this->Width = 522;
            this->Height = 280;
            this->BackColor = Color::FromArgb(30, 30, 30); // Ҹ���-����� ���
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // ������ �����
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Left = 699; // ������� �� ������ ���� ������
            this->Top = 155;  // ������� �� �������� ���� ������
            InitializeGameBoard();            

            srand((unsigned int)time(nullptr)); // ������������� ���������� ��������� �����
        }
        int GetScore()
        {
            return this->score;
        }

    private:
        array<Button^, 2>^ board;
        bool isPlayerXTurn = true; // ���� true, ����� �����

        
        // ������������� �������� ����
        // ������������� �������� ����
        void InitializeGameBoard() {
            board = gcnew array<Button^, 2>(3, 3);

            int buttonSize = 77; // ������ ������
            int spacing = 10;   // ������� ����� ��������

            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    board[row, col] = gcnew Button();

                    // ��������� ������
                    board[row, col]->Width = buttonSize;
                    board[row, col]->Height = buttonSize;
                    board[row, col]->BackColor = Color::FromArgb(60, 60, 60); // Ҹ���� ���� ������
                    board[row, col]->FlatStyle = FlatStyle::Flat;
                    board[row, col]->FlatAppearance->BorderSize = 0; // ������� �������
                    board[row, col]->Font = gcnew Drawing::Font(L"Arial", 22, FontStyle::Bold); // ����� ��� "X" � "O"
                    board[row, col]->ForeColor = Color::White;

                    // ������������ ������
                    board[row, col]->Left = col * (buttonSize + spacing) + spacing + 128; // ������ �����
                    board[row, col]->Top = row * (buttonSize + spacing) + spacing + 5; // ������ ������

                    // ��������� ������
                    board[row, col]->Click += gcnew EventHandler(this, &TicTacToeForm::ButtonClick);

                    // ��������� ������ � �����
                    this->Controls->Add(board[row, col]);
                }
            }
        }

        

        // ��������� ���� ������
        void ButtonClick(Object^ sender, EventArgs^ e) {
            Button^ clickedButton = (Button^)sender;

            // ���� ������ ��� ������, ������ �� ������
            if (clickedButton->Text != L"") return;

            // ��� ������
            clickedButton->Text = L"X";

            // ��������� ������ ����� ���� ������
            if (CheckWin(L"X")) {
                MyMessage^ form = gcnew MyMessage("������!\n �� ���������� 30 �����", true);
                form->ShowDialog();
                score = 30;
                this->Close();  // �������� ������� �����
                return;
            }

            // ���� ����� ���� ������ ��� ������ ������, ������ �����
            if (IsBoardFull()) {
                MyMessage^ form = gcnew MyMessage("�����!\n �� ���������� 5 �����", true);
                score = 5;
                form->ShowDialog();
                this->Close();  // �������� ������� �����
                return;
            }

            // ��� ����������
            ComputerMove();

            // ��������� ������ ����� ���� ����������
            if (CheckWin(L"O")) {
                MyMessage^ form = gcnew MyMessage("��������� �������!", false);
                form->ShowDialog();
                this->Close();  // �������� ������� �����
                return;
            }

        }

        void ComputerMove() {
            // ��������� ������� ����� ���������, ����� �� �� �������� ��� ����������� ���, � ������ ����� �������� ��������� ����:
            if (MakeSmartMove(L"O")) return; // ������� ��������
            if (MakeSmartMove(L"X")) return; // ������� ����������� ������

            // ���� ����� � ���������/����������� ���, �������� ��������� ����
            while (true) {
                int row = rand() % 3;
                int col = rand() % 3;

                if (board[row, col]->Text == L"") {
                    board[row, col]->Text = L"O";
                    break;
                }
            }
        }

        // ����� ��� (����������/��������)
        bool MakeSmartMove(String^ symbol) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                    if (board[i, j]->Text == L"") {
                        // ��������� ��������� �������
                        board[i, j]->Text = symbol;

                        // ���������, �������� �� ���� ��� � ������
                        if (CheckWin(symbol)) {
                            if (symbol == L"O") return true;  // ��������� ������, ���� ��� ������ ����������
                            board[i, j]->Text = L"O";        // ��������� �� ������ ���������� ��� ����������
                            return true;
                        }

                        // ���������� ���, ���� �� �� �������� � ��������
                        board[i, j]->Text = L"";
                    }
                }
            }

            return false; // ���� ��� ����������� ��� ��������� ����
        }

        // ���������, ���� �� ������ ��� ���������� �������
        bool CheckWin(String^ symbol) {
            // �������� ����� � ��������
            for (int i = 0; i < 3; i++) {
                if (board[i, 0]->Text == symbol && board[i, 1]->Text == symbol && board[i, 2]->Text == symbol)
                    return true;
                if (board[0, i]->Text == symbol && board[1, i]->Text == symbol && board[2, i]->Text == symbol)
                    return true;
            }

            // �������� ����������
            if (board[0, 0]->Text == symbol && board[1, 1]->Text == symbol && board[2, 2]->Text == symbol)
                return true;
            if (board[0, 2]->Text == symbol && board[1, 1]->Text == symbol && board[2, 0]->Text == symbol)
                return true;

            return false;
        }

        // ���������, ��������� �� �����
        bool IsBoardFull() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i, j]->Text == L"") return false;
                }
            }
            return true;
        }

        // ����� ����
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
