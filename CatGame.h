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
	/// Сводка для CatGame
	/// </summary>
	public ref class CatGame : public System::Windows::Forms::Form
	{
	private:
		Cat* cat;
	private: System::Windows::Forms::Label^ Name1;
	private: System::Windows::Forms::Label^ fatigue;
	private: System::Windows::Forms::Label^ dirty;
	private: System::Windows::Forms::Label^ heal;


	private: System::Windows::Forms::Timer^ timerHunger;
	private: System::Windows::Forms::Timer^ timerFatigue;
	private: System::Windows::Forms::Timer^ timerHappy;
	private: System::Windows::Forms::Timer^ timerHealth;
	private: System::Windows::Forms::Timer^ timerAge;

	private: System::Windows::Forms::PictureBox^ gifs;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Timer^ gif;
	private: System::Windows::Forms::PictureBox^ Feed1;
	private: System::Windows::Forms::PictureBox^ heal1;
	private: System::Windows::Forms::PictureBox^ play1;
	private: System::Windows::Forms::PictureBox^ wash1;
	private: System::Windows::Forms::PictureBox^ sleep1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ money;

	private: System::Windows::Forms::PictureBox^ button_exit;
	private:
		System::Void OnKitchenClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		System::Void OnComputerClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);


		   String^ Name;
	public:
		CatGame(String^ name, bool load)
		{				
			if (load){ 
				InitializeComponent();
				Pet* pet;
				int min = 0;
				loadPetFromXML(pet, min);
				cat = new Cat(Convert_String_to_string(name));
				cat->setHealth(min > 1000 ? std::max(1, pet->getHealth() - ((min - 1000) / 10)) : pet->getHealth());
				cat->setHunger(std::max(0, pet->getHunger() - min / 10));
				cat->setHappiness(std::max(0, pet->getHappiness() - min / 10));
				cat->setFatigue(std::max(0, pet->getFatigue() - min / 10));
				cat->setDirtiness(std::max(0, pet->getDirtiness() - min / 10));
				cat->setAge(pet->getAge());
				cat->setName(pet->getName());
				cat->setMoney(pet->getMoney());

				///////////////////////////
				cat->setPizza(pet->getPizza());
				cat->setBurger(pet->getBurger());
				cat->setCoce(pet->getCoce());


				delete pet; 
				Name = name;
				UpdatePetStatus();	
			}
			else {
				InitializeComponent();
				cat = new Cat(Convert_String_to_string(name));
				cat->setName(Convert_String_to_char(name));
				Name = name;
				UpdatePetStatus();	

			}				
		}
		void UpdatePetStatus()
		{
			// Получите статус питомца
			String^ name1 = Convert_string_to_String(cat->getName());

			String^ health = Convert::ToString(cat->getHealth()) + "%";
			String^ hunger = Convert::ToString(cat->getHunger()) + "%";
			String^ happ = Convert::ToString(cat->getHappiness()) + "%";
			String^ fatig = Convert::ToString(cat->getFatigue()) + "%";
			String^ dirtiness = Convert::ToString(cat->getDirtiness()) + "%";
			String^ ag = Convert::ToString(cat->getAge()) + "%";
			String^ m = Convert::ToString(cat->getMoney());

			if (cat->getHunger() < 50) { timerFatigue->Start(); }
			else { timerFatigue->Stop(); }
			if (cat->getHunger() < 30) { timerHappy->Start(); }
			else { timerHappy->Stop(); }
			if (cat->getHunger() < 1) { timerHealth->Start(); }
			else { timerHealth->Stop(); }

			// Установите текст в Label
			Name1->Text = Name;
			money->Text = m;
			heal->Text = health;
			Hungry->Text = hunger;
			dirty->Text = dirtiness;
			fatigue->Text = fatig;
			happiness->Text = happ;
			/*age->Text = ag;*/
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CatGame()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ Hungry;
	private: System::Windows::Forms::Label^ happiness;









	private: System::ComponentModel::IContainer^ components;


	protected:	

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CatGame::typeid));
			this->Hungry = (gcnew System::Windows::Forms::Label());
			this->happiness = (gcnew System::Windows::Forms::Label());
			this->Name1 = (gcnew System::Windows::Forms::Label());
			this->fatigue = (gcnew System::Windows::Forms::Label());
			this->dirty = (gcnew System::Windows::Forms::Label());
			this->heal = (gcnew System::Windows::Forms::Label());
			this->timerHunger = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerFatigue = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerHappy = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerHealth = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAge = (gcnew System::Windows::Forms::Timer(this->components));
			this->gifs = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->gif = (gcnew System::Windows::Forms::Timer(this->components));
			this->Feed1 = (gcnew System::Windows::Forms::PictureBox());
			this->heal1 = (gcnew System::Windows::Forms::PictureBox());
			this->play1 = (gcnew System::Windows::Forms::PictureBox());
			this->wash1 = (gcnew System::Windows::Forms::PictureBox());
			this->sleep1 = (gcnew System::Windows::Forms::PictureBox());
			this->button_exit = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->money = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gifs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Feed1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heal1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->play1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wash1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sleep1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// Hungry
			// 
			this->Hungry->AutoSize = true;
			this->Hungry->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Hungry->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Hungry->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->Hungry->Location = System::Drawing::Point(305, 775);
			this->Hungry->Name = L"Hungry";
			this->Hungry->Size = System::Drawing::Size(30, 13);
			this->Hungry->TabIndex = 5;
			this->Hungry->Text = L"50%";
			// 
			// happiness
			// 
			this->happiness->AutoSize = true;
			this->happiness->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->happiness->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->happiness->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->happiness->Location = System::Drawing::Point(82, 775);
			this->happiness->Name = L"happiness";
			this->happiness->Size = System::Drawing::Size(33, 13);
			this->happiness->TabIndex = 6;
			this->happiness->Text = L" 50%";
			this->happiness->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Name1
			// 
			this->Name1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(105)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Name1->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->Name1->Location = System::Drawing::Point(29, 12);
			this->Name1->Name = L"Name1";
			this->Name1->Size = System::Drawing::Size(105, 25);
			this->Name1->TabIndex = 12;
			this->Name1->Text = L"name";
			this->Name1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// fatigue
			// 
			this->fatigue->AutoSize = true;
			this->fatigue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->fatigue->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fatigue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->fatigue->Location = System::Drawing::Point(526, 774);
			this->fatigue->Name = L"fatigue";
			this->fatigue->Size = System::Drawing::Size(30, 13);
			this->fatigue->TabIndex = 13;
			this->fatigue->Text = L"50%";
			// 
			// dirty
			// 
			this->dirty->AutoSize = true;
			this->dirty->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dirty->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dirty->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->dirty->Location = System::Drawing::Point(414, 774);
			this->dirty->Name = L"dirty";
			this->dirty->Size = System::Drawing::Size(30, 13);
			this->dirty->TabIndex = 14;
			this->dirty->Text = L"50%";
			// 
			// heal
			// 
			this->heal->AutoSize = true;
			this->heal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->heal->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->heal->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->heal->Location = System::Drawing::Point(193, 775);
			this->heal->Name = L"heal";
			this->heal->Size = System::Drawing::Size(30, 13);
			this->heal->TabIndex = 15;
			this->heal->Text = L"50%";
			this->heal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timerHunger
			// 
			this->timerHunger->Enabled = true;
			this->timerHunger->Interval = 5500;
			this->timerHunger->Tick += gcnew System::EventHandler(this, &CatGame::timerHunger_Tick);
			// 
			// timerFatigue
			// 
			this->timerFatigue->Interval = 8000;
			this->timerFatigue->Tick += gcnew System::EventHandler(this, &CatGame::timerFatigue_Tick);
			// 
			// timerHappy
			// 
			this->timerHappy->Interval = 5000;
			this->timerHappy->Tick += gcnew System::EventHandler(this, &CatGame::timerHappy_Tick);
			// 
			// timerHealth
			// 
			this->timerHealth->Interval = 2000;
			this->timerHealth->Tick += gcnew System::EventHandler(this, &CatGame::timerHealth_Tick);
			// 
			// timerAge
			// 
			this->timerAge->Enabled = true;
			this->timerAge->Interval = 300000;
			this->timerAge->Tick += gcnew System::EventHandler(this, &CatGame::timerAge_Tick);
			// 
			// gifs
			// 
			this->gifs->Location = System::Drawing::Point(0, 0);
			this->gifs->Name = L"gifs";
			this->gifs->Size = System::Drawing::Size(640, 800);
			this->gifs->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->gifs->TabIndex = 19;
			this->gifs->TabStop = false;
			this->gifs->Visible = false;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// gif
			// 
			this->gif->Interval = 4000;
			this->gif->Tick += gcnew System::EventHandler(this, &CatGame::gif_Tick);
			// 
			// Feed1
			// 
			this->Feed1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Feed1.Image")));
			this->Feed1->Location = System::Drawing::Point(265, 671);
			this->Feed1->Name = L"Feed1";
			this->Feed1->Size = System::Drawing::Size(104, 104);
			this->Feed1->TabIndex = 20;
			this->Feed1->TabStop = false;
			this->Feed1->Click += gcnew System::EventHandler(this, &CatGame::Feed1_Click);
			// 
			// heal1
			// 
			this->heal1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"heal1.Image")));
			this->heal1->Location = System::Drawing::Point(155, 671);
			this->heal1->Name = L"heal1";
			this->heal1->Size = System::Drawing::Size(104, 104);
			this->heal1->TabIndex = 21;
			this->heal1->TabStop = false;
			this->heal1->Click += gcnew System::EventHandler(this, &CatGame::heal1_Click);
			// 
			// play1
			// 
			this->play1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"play1.Image")));
			this->play1->Location = System::Drawing::Point(45, 671);
			this->play1->Name = L"play1";
			this->play1->Size = System::Drawing::Size(104, 104);
			this->play1->TabIndex = 22;
			this->play1->TabStop = false;
			this->play1->Click += gcnew System::EventHandler(this, &CatGame::play1_Click);
			// 
			// wash1
			// 
			this->wash1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wash1.Image")));
			this->wash1->Location = System::Drawing::Point(375, 671);
			this->wash1->Name = L"wash1";
			this->wash1->Size = System::Drawing::Size(104, 104);
			this->wash1->TabIndex = 23;
			this->wash1->TabStop = false;
			this->wash1->Click += gcnew System::EventHandler(this, &CatGame::wash1_Click);
			// 
			// sleep1
			// 
			this->sleep1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sleep1.Image")));
			this->sleep1->Location = System::Drawing::Point(485, 671);
			this->sleep1->Name = L"sleep1";
			this->sleep1->Size = System::Drawing::Size(104, 104);
			this->sleep1->TabIndex = 24;
			this->sleep1->TabStop = false;
			this->sleep1->Click += gcnew System::EventHandler(this, &CatGame::sleep1_Click);
			// 
			// button_exit
			// 
			this->button_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.Image")));
			this->button_exit->Location = System::Drawing::Point(598, 0);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(42, 42);
			this->button_exit->TabIndex = 25;
			this->button_exit->TabStop = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &CatGame::button_exit_Click_1);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(155, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(114, 35);
			this->pictureBox1->TabIndex = 26;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(10, 7);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(139, 35);
			this->pictureBox2->TabIndex = 27;
			this->pictureBox2->TabStop = false;
			// 
			// money
			// 
			this->money->AutoSize = true;
			this->money->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(105)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->money->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->money->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->money->Location = System::Drawing::Point(191, 15);
			this->money->Name = L"money";
			this->money->Size = System::Drawing::Size(48, 16);
			this->money->TabIndex = 28;
			this->money->Text = L"name";
			this->money->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CatGame
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(640, 800);
			this->Controls->Add(this->gifs);
			this->Controls->Add(this->money);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->sleep1);
			this->Controls->Add(this->wash1);
			this->Controls->Add(this->play1);
			this->Controls->Add(this->heal1);
			this->Controls->Add(this->Feed1);
			this->Controls->Add(this->heal);
			this->Controls->Add(this->dirty);
			this->Controls->Add(this->fatigue);
			this->Controls->Add(this->Name1);
			this->Controls->Add(this->happiness);
			this->Controls->Add(this->Hungry);
			this->Controls->Add(this->pictureBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CatGame";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"    ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gifs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Feed1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heal1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->play1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wash1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sleep1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void timerHunger_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void timerFatigue_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void timerHappy_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void timerHealth_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void timerAge_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void gif_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void Feed1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void heal1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void play1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void wash1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sleep1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click_1(System::Object^ sender, System::EventArgs^ e);
};
}
