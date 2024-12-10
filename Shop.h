#pragma once
#include "PET.h"

namespace TAMAGOTCHIW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Shop
	/// </summary>
	public ref class Shop : public System::Windows::Forms::Form
	{
	private:
		Pet* pet;
	public:
		Shop(Pet* p)
		{
			InitializeComponent();
			pet = p;
			UpdatePetStatus();			
		}
		void UpdatePetStatus() {
			String^ mn = Convert::ToString(pet->getMoney());
			money->Text = mn;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Shop()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pizza;
	protected:
	private: System::Windows::Forms::PictureBox^ coce;
	private: System::Windows::Forms::PictureBox^ burger;
	private: System::Windows::Forms::PictureBox^ button_exit;
	private: System::Windows::Forms::PictureBox^ to_kitchen;
	private: System::Windows::Forms::Label^ money;
	private: System::Windows::Forms::Label^ pizza_cost;
	private: System::Windows::Forms::Label^ burger_cost;
	private: System::Windows::Forms::Label^ coce_cost;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Shop::typeid));
			this->pizza = (gcnew System::Windows::Forms::PictureBox());
			this->coce = (gcnew System::Windows::Forms::PictureBox());
			this->burger = (gcnew System::Windows::Forms::PictureBox());
			this->button_exit = (gcnew System::Windows::Forms::PictureBox());
			this->to_kitchen = (gcnew System::Windows::Forms::PictureBox());
			this->money = (gcnew System::Windows::Forms::Label());
			this->pizza_cost = (gcnew System::Windows::Forms::Label());
			this->burger_cost = (gcnew System::Windows::Forms::Label());
			this->coce_cost = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pizza))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->coce))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->burger))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->to_kitchen))->BeginInit();
			this->SuspendLayout();
			// 
			// pizza
			// 
			this->pizza->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pizza->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pizza.BackgroundImage")));
			this->pizza->Location = System::Drawing::Point(86, 142);
			this->pizza->Name = L"pizza";
			this->pizza->Size = System::Drawing::Size(128, 128);
			this->pizza->TabIndex = 0;
			this->pizza->TabStop = false;
			this->pizza->Click += gcnew System::EventHandler(this, &Shop::pizza_Click);
			// 
			// coce
			// 
			this->coce->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->coce->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"coce.BackgroundImage")));
			this->coce->Location = System::Drawing::Point(432, 142);
			this->coce->Name = L"coce";
			this->coce->Size = System::Drawing::Size(128, 128);
			this->coce->TabIndex = 1;
			this->coce->TabStop = false;
			this->coce->Click += gcnew System::EventHandler(this, &Shop::coce_Click);
			// 
			// burger
			// 
			this->burger->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->burger->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"burger.BackgroundImage")));
			this->burger->Location = System::Drawing::Point(256, 142);
			this->burger->Name = L"burger";
			this->burger->Size = System::Drawing::Size(128, 128);
			this->burger->TabIndex = 2;
			this->burger->TabStop = false;
			this->burger->Click += gcnew System::EventHandler(this, &Shop::burger_Click);
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.Image")));
			this->button_exit->Location = System::Drawing::Point(598, 0);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(42, 42);
			this->button_exit->TabIndex = 3;
			this->button_exit->TabStop = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &Shop::button_exit_Click);
			// 
			// to_kitchen
			// 
			this->to_kitchen->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->to_kitchen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"to_kitchen.Image")));
			this->to_kitchen->Location = System::Drawing::Point(12, 684);
			this->to_kitchen->Name = L"to_kitchen";
			this->to_kitchen->Size = System::Drawing::Size(104, 104);
			this->to_kitchen->TabIndex = 4;
			this->to_kitchen->TabStop = false;
			this->to_kitchen->Click += gcnew System::EventHandler(this, &Shop::to_kitchen_Click);
			// 
			// money
			// 
			this->money->AutoSize = true;
			this->money->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->money->Location = System::Drawing::Point(281, 35);
			this->money->Name = L"money";
			this->money->Size = System::Drawing::Size(74, 24);
			this->money->TabIndex = 5;
			this->money->Text = L"label1";
			this->money->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pizza_cost
			// 
			this->pizza_cost->AutoSize = true;
			this->pizza_cost->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pizza_cost->Location = System::Drawing::Point(127, 285);
			this->pizza_cost->Name = L"pizza_cost";
			this->pizza_cost->Size = System::Drawing::Size(26, 17);
			this->pizza_cost->TabIndex = 6;
			this->pizza_cost->Text = L"15";
			this->pizza_cost->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// burger_cost
			// 
			this->burger_cost->AutoSize = true;
			this->burger_cost->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->burger_cost->Location = System::Drawing::Point(301, 287);
			this->burger_cost->Name = L"burger_cost";
			this->burger_cost->Size = System::Drawing::Size(26, 17);
			this->burger_cost->TabIndex = 7;
			this->burger_cost->Text = L"20";
			this->burger_cost->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// coce_cost
			// 
			this->coce_cost->AutoSize = true;
			this->coce_cost->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->coce_cost->Location = System::Drawing::Point(476, 286);
			this->coce_cost->Name = L"coce_cost";
			this->coce_cost->Size = System::Drawing::Size(26, 17);
			this->coce_cost->TabIndex = 8;
			this->coce_cost->Text = L"10";
			this->coce_cost->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Shop
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(640, 800);
			this->Controls->Add(this->coce_cost);
			this->Controls->Add(this->burger_cost);
			this->Controls->Add(this->pizza_cost);
			this->Controls->Add(this->money);
			this->Controls->Add(this->to_kitchen);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->burger);
			this->Controls->Add(this->coce);
			this->Controls->Add(this->pizza);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Shop";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Shop";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pizza))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->coce))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->burger))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->to_kitchen))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pizza_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void coce_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void burger_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void to_kitchen_Click(System::Object^ sender, System::EventArgs^ e);
};
}
