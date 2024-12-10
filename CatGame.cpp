#include "CatGame.h"
#include "Cat.h"
#include "Functions.h"
#include "Computer.h"
#include "Kitchen.h"
#include "MyMessage.h"


System::Void TAMAGOTCHIW::CatGame::button_exit_Click_1(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(cat);
    Application::Exit();
}

System::Void TAMAGOTCHIW::CatGame::Feed1_Click(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(cat);
    Kitchen^ form = gcnew Kitchen(cat);
    form->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &CatGame::OnKitchenClosed);
    form->Show();
    timerHunger->Stop();
}

System::Void TAMAGOTCHIW::CatGame::OnKitchenClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    timerHunger->Start();
    UpdatePetStatus(); 
}

System::Void TAMAGOTCHIW::CatGame::play1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!(cat->getFatigue() <= 20) && !(cat->getHunger() <= 20)) {
        savePetToXML(cat);
        Computer^ form = gcnew Computer(cat);
        form->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &CatGame::OnComputerClosed);
        form->Show();
        timerHappy->Stop();
    }   
    else {
        MyMessage^ form = gcnew MyMessage(Name + " хочет спать или есть", false);
        form->ShowDialog();
    }
}


System::Void TAMAGOTCHIW::CatGame::OnComputerClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    timerHappy->Start();
    UpdatePetStatus();
}


System::Void TAMAGOTCHIW::CatGame::sleep1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (cat->getFatigue() <= 30) {
        gifs->Image = Image::FromFile("gifs\\bedroom.gif"); // ”кажите путь к гифке
        gifs->Visible = true;
        gif->Start();
        cat->sleep();
        UpdatePetStatus();
    }   
    else {
        MyMessage^ form = gcnew MyMessage(Name + " не хочет спать", false);
        form->ShowDialog();
    }
}

System::Void TAMAGOTCHIW::CatGame::wash1_Click(System::Object^ sender, System::EventArgs^ e)
{
    gifs->Image = Image::FromFile("gifs\\bath_cat.gif"); // ”кажите путь к гифке
    gifs->Visible = true;
    gif->Start();
    cat->bathe();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::CatGame::heal1_Click(System::Object^ sender, System::EventArgs^ e)
{
    cat->heal();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::CatGame::timerFatigue_Tick(System::Object^ sender, System::EventArgs^ e)
{
    cat->timerFatigue();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::CatGame::timerHappy_Tick(System::Object^ sender, System::EventArgs^ e)
{
    cat->timerHappiness();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::CatGame::timerHealth_Tick(System::Object^ sender, System::EventArgs^ e)
{
    cat->timerHealth();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::CatGame::timerAge_Tick(System::Object^ sender, System::EventArgs^ e)
{
    cat->timerAge();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::CatGame::gif_Tick(System::Object^ sender, System::EventArgs^ e)
{
    gifs->Visible = false;
    gifs->Image = nullptr;
    gif->Stop();
}

System::Void TAMAGOTCHIW::CatGame::timerHunger_Tick(System::Object^ sender, System::EventArgs^ e)
{ 
    cat->timerHunger();
    UpdatePetStatus();
}





    