#pragma once

namespace TAMAGOTCHIW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::PictureBox^ button_exit;

	private: System::Windows::Forms::PictureBox^ load;
	private: System::Windows::Forms::PictureBox^ StartGame;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;











	protected:

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->button_exit = (gcnew System::Windows::Forms::PictureBox());
			this->load = (gcnew System::Windows::Forms::PictureBox());
			this->StartGame = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->load))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StartGame))->BeginInit();
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.Image")));
			this->button_exit->Location = System::Drawing::Point(599, -1);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(42, 42);
			this->button_exit->TabIndex = 4;
			this->button_exit->TabStop = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &MenuForm::button_exit_Click);
			// 
			// load
			// 
			this->load->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"load.Image")));
			this->load->Location = System::Drawing::Point(144, 149);
			this->load->Name = L"load";
			this->load->Size = System::Drawing::Size(353, 120);
			this->load->TabIndex = 5;
			this->load->TabStop = false;
			this->load->Click += gcnew System::EventHandler(this, &MenuForm::load_Click);
			// 
			// StartGame
			// 
			this->StartGame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StartGame.Image")));
			this->StartGame->Location = System::Drawing::Point(144, 389);
			this->StartGame->Name = L"StartGame";
			this->StartGame->Size = System::Drawing::Size(353, 120);
			this->StartGame->TabIndex = 3;
			this->StartGame->TabStop = false;
			this->StartGame->Click += gcnew System::EventHandler(this, &MenuForm::StartGame_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(105)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->label1->Location = System::Drawing::Point(181, 436);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 32);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Ќќ¬јя »√–ј";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MenuForm::label1_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(105)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->label2->Location = System::Drawing::Point(210, 195);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(228, 32);
			this->label2->TabIndex = 7;
			this->label2->Text = L"ѕ–ќƒќЋ∆»“№";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &MenuForm::label2_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(640, 800);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->load);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->StartGame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->load))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StartGame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void StartGame_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void load_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
