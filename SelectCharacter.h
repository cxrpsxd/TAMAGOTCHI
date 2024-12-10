#pragma once
#include "Cat.h"


namespace TAMAGOTCHIW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SelectCharacter
	/// </summary>
	public ref class SelectCharacter : public System::Windows::Forms::Form
	{
	public:
		SelectCharacter(void)
		{

			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SelectCharacter()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ Cat;
	private: System::Windows::Forms::PictureBox^ Dog;
	private: System::Windows::Forms::PictureBox^ button_exit;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SelectCharacter::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Cat = (gcnew System::Windows::Forms::PictureBox());
			this->Dog = (gcnew System::Windows::Forms::PictureBox());
			this->button_exit = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Cat))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dog))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(105)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->label1->Location = System::Drawing::Point(142, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(367, 32);
			this->label1->TabIndex = 4;
			this->label1->Text = L"ВЫБЕРИТЕ ПИТОМЦА";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Cat
			// 
			this->Cat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Cat.Image")));
			this->Cat->Location = System::Drawing::Point(50, 274);
			this->Cat->Name = L"Cat";
			this->Cat->Size = System::Drawing::Size(243, 243);
			this->Cat->TabIndex = 5;
			this->Cat->TabStop = false;
			this->Cat->Click += gcnew System::EventHandler(this, &SelectCharacter::Cat_Click);
			// 
			// Dog
			// 
			this->Dog->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Dog.Image")));
			this->Dog->Location = System::Drawing::Point(371, 274);
			this->Dog->Name = L"Dog";
			this->Dog->Size = System::Drawing::Size(243, 243);
			this->Dog->TabIndex = 6;
			this->Dog->TabStop = false;
			this->Dog->Click += gcnew System::EventHandler(this, &SelectCharacter::Dog_Click);
			// 
			// button_exit
			// 
			this->button_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.Image")));
			this->button_exit->Location = System::Drawing::Point(598, 0);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(42, 42);
			this->button_exit->TabIndex = 7;
			this->button_exit->TabStop = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &SelectCharacter::button_exit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(63, 61);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(515, 75);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// SelectCharacter
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(640, 800);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->Dog);
			this->Controls->Add(this->Cat);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SelectCharacter";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"    ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Cat))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dog))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void Cat_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Dog_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
