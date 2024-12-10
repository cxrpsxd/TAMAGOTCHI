#include "Computer.h"
#include "TicTacToeForm.h"
#include "SnakeGameForm .h"
#include "CatGame.h"


System::Void TAMAGOTCHIW::Computer::pictureTicTac_Click(System::Object^ sender, System::EventArgs^ e)
{
    pet->play();
    TicTacToeForm^ form = gcnew TicTacToeForm();
    form->ShowDialog();
    int mon = form->GetScore();
    pet->setMoney(pet->getMoney() + mon);
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::Computer::pictureSnake_Click(System::Object^ sender, System::EventArgs^ e)
{
    pet->play();
    SnakeGameForm^ form = gcnew SnakeGameForm();
    form->ShowDialog();
    int mon = form->GetScore();
    pet->setMoney(pet->getMoney() + (mon * 2));
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::Computer::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(pet);
    Application::Exit();
}

System::Void TAMAGOTCHIW::Computer::back_to_form_Click(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(pet);
    this->Close();

}

System::Void TAMAGOTCHIW::Computer::timerFatigue_Tick(System::Object^ sender, System::EventArgs^ e)
{
    pet->timerFatigue();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::Computer::timerHappy_Tick(System::Object^ sender, System::EventArgs^ e)
{
    pet->timerHappiness();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::Computer::timerHealth_Tick(System::Object^ sender, System::EventArgs^ e)
{
    pet->timerHealth();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::Computer::timerHunger_Tick(System::Object^ sender, System::EventArgs^ e)
{
    pet->timerHunger();
    UpdatePetStatus();
}
