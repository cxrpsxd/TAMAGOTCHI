#include "DogGame.h"
#include "Dog.h"
#include "Functions.h"
#include "Computer.h"
#include "Kitchen.h"
#include "MyMessage.h"


System::Void TAMAGOTCHIW::DogGame::button_exit_Click_1(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(dog);
    Application::Exit();
}

System::Void TAMAGOTCHIW::DogGame::Feed1_Click(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(dog);
    Kitchen^ form = gcnew Kitchen(dog);
    form->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DogGame::OnKitchenClosed);
    form->Show();
    timerHunger->Stop();
}

System::Void TAMAGOTCHIW::DogGame::OnKitchenClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    timerHunger->Start();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::DogGame::play1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!(dog->getFatigue() <= 20) && !(dog->getHunger() <= 20)) {
        savePetToXML(dog);
        Computer^ form = gcnew Computer(dog);
        form->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DogGame::OnComputerClosed);
        form->Show();
        timerHappy->Stop();
    }
    else {
        MyMessage^ form = gcnew MyMessage(Name + " хочет спать или есть", false);
        form->ShowDialog();
    }
}


System::Void TAMAGOTCHIW::DogGame::OnComputerClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    timerHappy->Start();
    UpdatePetStatus();
}


System::Void TAMAGOTCHIW::DogGame::sleep1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dog->getFatigue() <= 30) {
        gifs->Image = Image::FromFile("gifs\\bedroom_dog.gif"); // ”кажите путь к гифке
        gifs->Visible = true;
        gif->Start();
        dog->sleep();
        UpdatePetStatus();
    }
    else {
        MyMessage^ form = gcnew MyMessage(Name + " не хочет спать", false);
        form->ShowDialog();
    }
}

System::Void TAMAGOTCHIW::DogGame::wash1_Click(System::Object^ sender, System::EventArgs^ e)
{
    gifs->Image = Image::FromFile("gifs\\bath_dog.gif"); // ”кажите путь к гифке
    gifs->Visible = true;
    gif->Start();
    dog->bathe();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::DogGame::heal1_Click(System::Object^ sender, System::EventArgs^ e)
{
    dog->heal();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::DogGame::timerFatigue_Tick(System::Object^ sender, System::EventArgs^ e)
{
    dog->timerFatigue();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::DogGame::timerHappy_Tick(System::Object^ sender, System::EventArgs^ e)
{
    dog->timerHappiness();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::DogGame::timerHealth_Tick(System::Object^ sender, System::EventArgs^ e)
{
    dog->timerHealth();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::DogGame::timerAge_Tick(System::Object^ sender, System::EventArgs^ e)
{
    dog->timerAge();
    UpdatePetStatus();
}

System::Void TAMAGOTCHIW::DogGame::gif_Tick(System::Object^ sender, System::EventArgs^ e)
{
    gifs->Visible = false;
    gifs->Image = nullptr;
    gif->Stop();
}

System::Void TAMAGOTCHIW::DogGame::timerHunger_Tick(System::Object^ sender, System::EventArgs^ e)
{
    dog->timerHunger();
    UpdatePetStatus();
}





