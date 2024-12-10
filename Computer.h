#pragma once
#include "Functions.h"
#include "Cat.h"
#include <algorithm>

namespace TAMAGOTCHIW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Computer
	/// </summary>
	public ref class Computer : public System::Windows::Forms::Form
	{
	private:
		Pet* pet;
	private: System::Windows::Forms::PictureBox^ button_exit;
	private: System::Windows::Forms::PictureBox^ back_to_form;
	private: System::Windows::Forms::Timer^ timerHunger;
	private: System::Windows::Forms::Timer^ timerFatigue;
	private: System::Windows::Forms::Timer^ timerHappy;
	private: System::Windows::Forms::Timer^ timerHealth;
	private: System::Windows::Forms::Label^ happy;
	private: System::Windows::Forms::Label^ money;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		   String^ Name;
	public:
		Computer(Pet* p)
		{
			InitializeComponent();
			pet = p;
			UpdatePetStatus();
		}
		void UpdatePetStatus()
		{
			String^ happ = Convert::ToString(pet->getHappiness()) + "%";
			String^ mn = "Монет: " + Convert::ToString(pet->getMoney());

			happy->Text = happ;
			money->Text = mn;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Computer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureTicTac;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureSnake;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Computer::typeid));
			this->pictureTicTac = (gcnew System::Windows::Forms::PictureBox());
			this->pictureSnake = (gcnew System::Windows::Forms::PictureBox());
			this->button_exit = (gcnew System::Windows::Forms::PictureBox());
			this->back_to_form = (gcnew System::Windows::Forms::PictureBox());
			this->timerHunger = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerFatigue = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerHappy = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerHealth = (gcnew System::Windows::Forms::Timer(this->components));
			this->happy = (gcnew System::Windows::Forms::Label());
			this->money = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureTicTac))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureSnake))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_to_form))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureTicTac
			// 
			this->pictureTicTac->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureTicTac.Image")));
			this->pictureTicTac->Location = System::Drawing::Point(106, 64);
			this->pictureTicTac->Name = L"pictureTicTac";
			this->pictureTicTac->Size = System::Drawing::Size(50, 50);
			this->pictureTicTac->TabIndex = 0;
			this->pictureTicTac->TabStop = false;
			this->pictureTicTac->Click += gcnew System::EventHandler(this, &Computer::pictureTicTac_Click);
			// 
			// pictureSnake
			// 
			this->pictureSnake->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureSnake.Image")));
			this->pictureSnake->Location = System::Drawing::Point(106, 135);
			this->pictureSnake->Name = L"pictureSnake";
			this->pictureSnake->Size = System::Drawing::Size(50, 50);
			this->pictureSnake->TabIndex = 1;
			this->pictureSnake->TabStop = false;
			this->pictureSnake->Click += gcnew System::EventHandler(this, &Computer::pictureSnake_Click);
			// 
			// button_exit
			// 
			this->button_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.Image")));
			this->button_exit->Location = System::Drawing::Point(598, 0);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(42, 42);
			this->button_exit->TabIndex = 2;
			this->button_exit->TabStop = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &Computer::button_exit_Click);
			// 
			// back_to_form
			// 
			this->back_to_form->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_to_form.Image")));
			this->back_to_form->Location = System::Drawing::Point(12, 670);
			this->back_to_form->Name = L"back_to_form";
			this->back_to_form->Size = System::Drawing::Size(104, 104);
			this->back_to_form->TabIndex = 3;
			this->back_to_form->TabStop = false;
			this->back_to_form->Click += gcnew System::EventHandler(this, &Computer::back_to_form_Click);
			// 
			// timerHunger
			// 
			this->timerHunger->Enabled = true;
			this->timerHunger->Interval = 5500;
			this->timerHunger->Tick += gcnew System::EventHandler(this, &Computer::timerHunger_Tick);
			// 
			// timerFatigue
			// 
			this->timerFatigue->Interval = 8000;
			this->timerFatigue->Tick += gcnew System::EventHandler(this, &Computer::timerFatigue_Tick);
			// 
			// timerHappy
			// 
			this->timerHappy->Interval = 5000;
			this->timerHappy->Tick += gcnew System::EventHandler(this, &Computer::timerHappy_Tick);
			// 
			// timerHealth
			// 
			this->timerHealth->Interval = 2000;
			this->timerHealth->Tick += gcnew System::EventHandler(this, &Computer::timerHealth_Tick);
			// 
			// happy
			// 
			this->happy->AutoSize = true;
			this->happy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->happy->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->happy->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->happy->Location = System::Drawing::Point(308, 774);
			this->happy->Name = L"happy";
			this->happy->Size = System::Drawing::Size(35, 17);
			this->happy->TabIndex = 4;
			this->happy->Text = L"hap";
			// 
			// money
			// 
			this->money->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(93)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)));
			this->money->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->money->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->money->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"money.Image")));
			this->money->Location = System::Drawing::Point(362, 46);
			this->money->Name = L"money";
			this->money->Size = System::Drawing::Size(218, 37);
			this->money->TabIndex = 5;
			this->money->Text = L"label1";
			this->money->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(268, 671);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(104, 104);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// Computer
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(640, 800);
			this->Controls->Add(this->money);
			this->Controls->Add(this->happy);
			this->Controls->Add(this->back_to_form);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->pictureSnake);
			this->Controls->Add(this->pictureTicTac);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Computer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureTicTac))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureSnake))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_to_form))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void timerHunger_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void timerFatigue_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void timerHappy_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void timerHealth_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureTicTac_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureSnake_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void back_to_form_Click(System::Object^ sender, System::EventArgs^ e);
};
}
