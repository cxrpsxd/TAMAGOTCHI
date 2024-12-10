#include "SelectCharacter.h"
#include "ChooseName.h"
#include "PET.h"
#include "Cat.h"
#include "Dog.h"
#include "Functions.h"


System::Void TAMAGOTCHIW::SelectCharacter::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void TAMAGOTCHIW::SelectCharacter::Cat_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChooseName^ form = gcnew ChooseName("Cat");
	this->Hide();
	form->Show();
}

System::Void TAMAGOTCHIW::SelectCharacter::Dog_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChooseName^ form = gcnew ChooseName("Dog");
	this->Hide();
	form->Show();
}


