#include "ChooseName.h"
#include "CatGame.h"
#include "DogGame.h"
#include "Functions.h"
#include "Cat.h"
#include "Dog.h"
#include "SelectCharacter.h"


System::Void TAMAGOTCHIW::ChooseName::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void TAMAGOTCHIW::ChooseName::OK_Click(System::Object^ sender, System::EventArgs^ e)
{

    String^ name = this->textBox1->Text;

    if (type == "Cat") {
        CatGame^ form = gcnew CatGame(name == "" ? name = "Барсик" : name, false);
        form->Show();
        this->Close();
    }
    if (type == "Dog") {
        DogGame^ form = gcnew DogGame(name == "" ? name = "Бобик" : name, false);
        form->Show();
        this->Close();
    }

}

System::Void TAMAGOTCHIW::ChooseName::label2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ name = this->textBox1->Text;

    if (type == "Cat") {
        CatGame^ form = gcnew CatGame(name == "" ? name = "Барсик" : name, false);
        form->Show();
        this->Close();
    }
    if (type == "Dog") {
        DogGame^ form = gcnew DogGame(name == "" ? name = "Бобик" : name, false);
        form->Show();
        this->Close();
    }
}
