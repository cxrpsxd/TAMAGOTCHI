#include "Shop.h"
#include "Kitchen.h"
#include "MyMessage.h"

System::Void TAMAGOTCHIW::Shop::pizza_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (pet->getMoney() >= 15) {
		pet->setMoney(pet->getMoney() - 15);
		pet->setPizza(pet->getPizza() + 1);
		UpdatePetStatus();
	}	
	else {
		MyMessage^ form = gcnew MyMessage("У вас закончились монеты",false);
		form->ShowDialog();
	}
}

System::Void TAMAGOTCHIW::Shop::coce_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (pet->getMoney() >= 10) {
		pet->setMoney(pet->getMoney() - 10);
		pet->setCoce(pet->getCoce() + 1);
		UpdatePetStatus();
	}	
	else {
		MyMessage^ form = gcnew MyMessage("У вас закончились монеты",false);
		form->ShowDialog();
	}
}

System::Void TAMAGOTCHIW::Shop::burger_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (pet->getMoney() >= 20) {
		pet->setMoney(pet->getMoney() - 20);
		pet->setBurger(pet->getBurger() + 1);
		UpdatePetStatus();
	}	
	else {
		MyMessage^ form = gcnew MyMessage("У вас закончились монеты",false);
		form->ShowDialog();
	}
}

System::Void TAMAGOTCHIW::Shop::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	savePetToXML(pet);
	Application::Exit();
}

System::Void TAMAGOTCHIW::Shop::to_kitchen_Click(System::Object^ sender, System::EventArgs^ e)
{
	savePetToXML(pet);
	this -> Close();
}
