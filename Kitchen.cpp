#include "Kitchen.h"
#include "CatGame.h"
#include "Shop.h"
#include "MyMessage.h"


System::Void TAMAGOTCHIW::Kitchen::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(pet);
    Application::Exit();
}

System::Void TAMAGOTCHIW::Kitchen::back_to_form_Click(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(pet);
    this->Close();
}

System::Void TAMAGOTCHIW::Kitchen::feed_Pizza(System::Object^ sender, System::EventArgs^ e)
{
    if (pet->getHunger() < 90)    {
        this->eat_gif->Visible = true;
        gif->Start();
        pet->setPizza(pet->getPizza() - 1);
        pet->feed(15, 3);
        UpdatePetStatus();
        UpdateFoodCountLabel();
        UpdateButtonsVisibility();
    }
    else {
        MyMessage^ form = gcnew MyMessage(Convert_string_to_String(pet->getName()) + " не хочет есть", true);
        form->ShowDialog();
    }
}

System::Void TAMAGOTCHIW::Kitchen::Shop_Click(System::Object^ sender, System::EventArgs^ e)
{
    savePetToXML(pet);
    TAMAGOTCHIW::Shop^ form = gcnew TAMAGOTCHIW::Shop(pet);
    form->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Kitchen::OnShopClosed);
    form->ShowDialog();
}

System::Void TAMAGOTCHIW::Kitchen::burger_feed_Click(System::Object^ sender, System::EventArgs^ e)
{
    if(pet->getHunger() < 90)    {
        this->eat_gif->Visible = true;
        gif->Start();
        pet->setBurger(pet->getBurger() - 1);
        pet->feed(20, 7);
        UpdatePetStatus();
        UpdateFoodCountLabel();
        UpdateButtonsVisibility();
    }
    else {
        MyMessage^ form = gcnew MyMessage(Convert_string_to_String(pet->getName()) + " не хочет есть",true);
        form->ShowDialog();
    }
}

System::Void TAMAGOTCHIW::Kitchen::swap_Click(System::Object^ sender, System::EventArgs^ e)
{
    ShowNextButton();
}

System::Void TAMAGOTCHIW::Kitchen::feed_coce_Click(System::Object^ sender, System::EventArgs^ e)
{
    if(pet->getHunger() < 90)    {
        this->eat_gif->Visible = true;
        gif->Start();
        pet->setCoce(pet->getCoce() - 1);
        pet->feed(11, 0);
        UpdatePetStatus();
        UpdateFoodCountLabel();
        UpdateButtonsVisibility();
    }
    else {
        MyMessage^ form = gcnew MyMessage(Convert_string_to_String(pet->getName()) + " не хочет есть", true);
        form->ShowDialog();
    }
}

System::Void TAMAGOTCHIW::Kitchen::gif_Tick(System::Object^ sender, System::EventArgs^ e)
{
    eat_gif->Visible = false;
    gif->Stop();
}

System::Void TAMAGOTCHIW::Kitchen::swap_2(System::Object^ sender, System::EventArgs^ e)
{
    ShowPreviousButton();
}

System::Void TAMAGOTCHIW::Kitchen::OnShopClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    UpdatePetStatus();
    UpdateFoodCountLabel();
    UpdateButtonsVisibility();
}

System::Void TAMAGOTCHIW::Kitchen::timerHunger_Tick(System::Object^ sender, System::EventArgs^ e)
{
    pet->timerHunger();
    UpdatePetStatus();
}
