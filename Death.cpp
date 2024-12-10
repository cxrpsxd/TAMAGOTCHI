#include "Death.h"
#include "MenuForm.h"

System::Void TAMAGOTCHIW::Death::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void TAMAGOTCHIW::Death::NewGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
