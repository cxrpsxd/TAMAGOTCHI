#include "MenuForm.h"
#include "SelectCharacter.h"
#include "ChooseName.h"
#include "Functions.h"
#include <iostream>
#include "PET.h"
#include "Cat.h"
#include "Dog.h"
#include "CatGame.h"
#include "DogGame.h"
#include "MyMessage.h"
#include "Death.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TAMAGOTCHIW::MenuForm form;
	Application::Run(% form);
}

System::Void TAMAGOTCHIW::MenuForm::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void TAMAGOTCHIW::MenuForm::StartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	SelectCharacter^ form = gcnew SelectCharacter();
	
	form->Show();
    this->Hide();
}

System::Void TAMAGOTCHIW::MenuForm::load_Click(System::Object^ sender, System::EventArgs^ e)
{

    Pet* pet = nullptr;
    int min = 0;
    loadPetFromXML(pet, min);

    if (min > 2880) {
        Death^ form = gcnew Death(Convert_string_to_String(pet->getType()));
        ClearPet();
        form->Show();
        this->Hide();        
    }   
    else {
        if (pet != nullptr) {
            if (pet->getType() == "Cat") {
                CatGame^ form = gcnew CatGame(Convert_string_to_String(pet->getName()), true);
                form->Show();
                this->Hide();
            }
            if (pet->getType() == "Dog") {
                DogGame^ form = gcnew DogGame(Convert_string_to_String(pet->getName()), true);
                form->Show();
                this->Hide();
            }
        }
        else {
            MyMessage^ form = gcnew MyMessage("Ошибка: не удалось загрузить питомца.", false);
            form->ShowDialog();
        }
    }
}

System::Void TAMAGOTCHIW::MenuForm::label2_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pet* pet = nullptr;
    int min = 0;
    loadPetFromXML(pet, min);

    if (min > 2880) {
        Death^ form = gcnew Death(Convert_string_to_String(pet->getType()));
        ClearPet();
        form->Show();
        this->Hide();

    }
    else {
        if (pet != nullptr) {
            if (pet->getType() == "Cat") {
                CatGame^ form = gcnew CatGame(Convert_string_to_String(pet->getName()), true);
                form->Show();
                this->Hide();
            }
            if (pet->getType() == "Dog") {
                DogGame^ form = gcnew DogGame(Convert_string_to_String(pet->getName()), true);
                form->Show();
                this->Hide();
            }
        }
        else {
            MyMessage^ form = gcnew MyMessage("Ошибка: не удалось загрузить питомца.", false);
            form->ShowDialog();
        }
    }
}

System::Void TAMAGOTCHIW::MenuForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
    SelectCharacter^ form = gcnew SelectCharacter();

    form->Show();
    this->Hide();
}
