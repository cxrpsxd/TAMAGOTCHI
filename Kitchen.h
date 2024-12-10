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
	public ref class Kitchen : public System::Windows::Forms::Form
	{
	private:
		Pet* pet;
	private: System::Windows::Forms::Timer^ timerHunger;
	private: System::Windows::Forms::Timer^ timerHappy;
	private: System::Windows::Forms::Timer^ timerFatigue;
	private: System::Windows::Forms::Timer^ timerHealth;
	private: System::Windows::Forms::Label^ hungry;
	private: System::Windows::Forms::PictureBox^ Shop;
	private: System::Windows::Forms::PictureBox^ burger_feed;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

	private: System::Windows::Forms::PictureBox^ swap;
	private: System::Windows::Forms::PictureBox^ feed_coce;
	private: System::Windows::Forms::PictureBox^ eat_gif;
	private: System::Windows::Forms::Timer^ gif;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	private: System::Windows::Forms::Label^ count_food;

		   System::Void OnShopClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		   String^ Name;
	private:
		array<PictureBox^>^ buttons;
		int b_index = 0;
		
	public:
		Kitchen(Pet* p)
		{
			InitializeComponent();
			pet = p;
			UpdatePetStatus();
			InitializeButtons();
			UpdateGifs();
		}

		void UpdateGifs() {
			if (pet->getType() == "Dog") {
				this->BackgroundImage = Image::FromFile("gifs\\кухня_собака.jpg");
				feed_coce->Image = Image::FromFile("gifs\\кола_собака.jpg");
				burger_feed->Image = Image::FromFile("gifs\\бургер_собака.jpg");
				feed->Image = Image::FromFile("gifs\\пицца_собака.jpg");
				eat_gif->Image = Image::FromFile("gifs\\eat_dog.gif");
			}
		}

		void UpdatePetStatus() {
			String^ hunger = Convert::ToString(pet->getHunger()) + "%";
			hungry->Text = hunger;
		}

		void InitializeButtons() {
			buttons = gcnew array<PictureBox^> { this->feed, this->burger_feed, this->feed_coce };
			b_index = -1; // Изначально ничего не отображаем
			UpdateButtonsVisibility(); // Обновляем видимость кнопок сразу при инициализации
		}

		void UpdateButtonsVisibility() {
			// Скрываем все кнопки
			for (int i = 0; i < buttons->Length; i++) {
				buttons[i]->Visible = false;
			}

			// Ищем первую доступную кнопку
			for (b_index = 0; b_index < buttons->Length; b_index++) {
				bool buttonFound = false; // Флаг для проверки наличия доступной кнопки

				switch (b_index) {
				case 0: // Индекс для Пиццы
					buttonFound = (pet->getPizza() > 0);
					break;
				case 1: // Индекс для Бургера
					buttonFound = (pet->getBurger() > 0);
					break;
				case 2: // Индекс для Колы
					buttonFound = (pet->getCoce() > 0);
					break;
				default:
					buttonFound = false; // На всякий случай
					break;
				}

				if (buttonFound) {
					buttons[b_index]->Visible = true; // Показываем кнопку
					UpdateFoodCountLabel(); // Обновляем Label с количеством еды
					return; // Завершаем, поскольку нашли первую доступную кнопку
				}
			}

			// Если не осталось доступных кнопок
			b_index = -1; // Значение означает, что нет активной кнопки
			count_food->Text = ""; // Очистка текста
		}

		void UpdateFoodCountLabel() {
			if (b_index == -1) { // Если нет активной кнопки, ничего не показываем
				count_food->Text = "";
				return;
			}

			switch (b_index) {
			case 0: // Индекс для Пиццы
				count_food->Text = Convert::ToString(pet->getPizza());
				break;
			case 1: // Индекс для Бургера
				count_food->Text = Convert::ToString(pet->getBurger());
				break;
			case 2: // Индекс для Колы
				count_food->Text = Convert::ToString(pet->getCoce());
				break;
			default:
				count_food->Text = "";
				break;
			}
		}

		void ShowNextButton() {
			if (pet->getPizza() == 0 && pet->getBurger() == 0 && pet->getCoce() == 0) {
				// Если вся еда равна 0, ничего не делаем
				count_food->Text = "Еда закончилась :(";
				return;
			}

			if (b_index != -1) {
				buttons[b_index]->Visible = false; // Скрываем текущую кнопку
			}

			// Ищем следующую доступную кнопку
			for (b_index = (b_index + 1) % buttons->Length; b_index != -1; b_index = (b_index + 1) % buttons->Length) {
				bool buttonFound = false;

				switch (b_index) {
				case 0: // Индекс для Пиццы
					buttonFound = (pet->getPizza() > 0);
					break;
				case 1: // Индекс для Бургера
					buttonFound = (pet->getBurger() > 0);
					break;
				case 2: // Индекс для Колы
					buttonFound = (pet->getCoce() > 0);
					break;
				}

				if (buttonFound) {
					buttons[b_index]->Visible = true; // Показываем кнопку
					UpdateFoodCountLabel(); // Обновляем Label
					return; // Завершаем, поскольку нашли следующую доступную кнопку
				}
			}

			// Если нет доступных кнопок
			b_index = -1; // Сбрасываем значение
			count_food->Text = ""; // Сбрасываем текст
		}

		void ShowPreviousButton() {
			if (pet->getPizza() == 0 && pet->getBurger() == 0 && pet->getCoce() == 0) {
				// Если вся еда равна 0, ничего не делаем
				count_food->Text = "Еда закончилась :(";
				return;
			}

			if (b_index != -1) {
				buttons[b_index]->Visible = false; // Скрываем текущую кнопку
			}

			// Ищем предыдущую доступную кнопку
			for (b_index = (b_index - 1 + buttons->Length) % buttons->Length; b_index != -1; b_index = (b_index - 1 + buttons->Length) % buttons->Length) {
				bool buttonFound = false;

				switch (b_index) {
				case 0: // Индекс для Пиццы
					buttonFound = (pet->getPizza() > 0);
					break;
				case 1: // Индекс для Бургера
					buttonFound = (pet->getBurger() > 0);
					break;
				case 2: // Индекс для Колы
					buttonFound = (pet->getCoce() > 0);
					break;
				}

				if (buttonFound) {
					buttons[b_index]->Visible = true; // Показываем кнопку
					UpdateFoodCountLabel(); // Обновляем Label
					return; // Завершаем, поскольку нашли предыдущую доступную кнопку
				}
			}

			b_index = -1;
			count_food->Text = "";
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Kitchen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ button_exit;
	protected:
	private: System::Windows::Forms::PictureBox^ back_to_form;
	private: System::Windows::Forms::PictureBox^ feed;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Kitchen::typeid));
			this->button_exit = (gcnew System::Windows::Forms::PictureBox());
			this->back_to_form = (gcnew System::Windows::Forms::PictureBox());
			this->feed = (gcnew System::Windows::Forms::PictureBox());
			this->timerHunger = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerHappy = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerFatigue = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerHealth = (gcnew System::Windows::Forms::Timer(this->components));
			this->hungry = (gcnew System::Windows::Forms::Label());
			this->Shop = (gcnew System::Windows::Forms::PictureBox());
			this->count_food = (gcnew System::Windows::Forms::Label());
			this->burger_feed = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->swap = (gcnew System::Windows::Forms::PictureBox());
			this->feed_coce = (gcnew System::Windows::Forms::PictureBox());
			this->eat_gif = (gcnew System::Windows::Forms::PictureBox());
			this->gif = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_to_form))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Shop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->burger_feed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->swap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed_coce))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eat_gif))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.Image")));
			this->button_exit->Location = System::Drawing::Point(598, -1);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(42, 42);
			this->button_exit->TabIndex = 0;
			this->button_exit->TabStop = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &Kitchen::button_exit_Click);
			// 
			// back_to_form
			// 
			this->back_to_form->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_to_form.Image")));
			this->back_to_form->Location = System::Drawing::Point(12, 673);
			this->back_to_form->Name = L"back_to_form";
			this->back_to_form->Size = System::Drawing::Size(104, 104);
			this->back_to_form->TabIndex = 1;
			this->back_to_form->TabStop = false;
			this->back_to_form->Click += gcnew System::EventHandler(this, &Kitchen::back_to_form_Click);
			// 
			// feed
			// 
			this->feed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"feed.Image")));
			this->feed->Location = System::Drawing::Point(254, 374);
			this->feed->Name = L"feed";
			this->feed->Size = System::Drawing::Size(128, 128);
			this->feed->TabIndex = 2;
			this->feed->TabStop = false;
			this->feed->Click += gcnew System::EventHandler(this, &Kitchen::feed_Pizza);
			// 
			// timerHunger
			// 
			this->timerHunger->Enabled = true;
			this->timerHunger->Interval = 5500;
			this->timerHunger->Tick += gcnew System::EventHandler(this, &Kitchen::timerHunger_Tick);
			// 
			// hungry
			// 
			this->hungry->AutoSize = true;
			this->hungry->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->hungry->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->hungry->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->hungry->Location = System::Drawing::Point(301, 776);
			this->hungry->Name = L"hungry";
			this->hungry->Size = System::Drawing::Size(34, 13);
			this->hungry->TabIndex = 3;
			this->hungry->Text = L" qwe";
			// 
			// Shop
			// 
			this->Shop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Shop.Image")));
			this->Shop->Location = System::Drawing::Point(524, 673);
			this->Shop->Name = L"Shop";
			this->Shop->Size = System::Drawing::Size(104, 104);
			this->Shop->TabIndex = 4;
			this->Shop->TabStop = false;
			this->Shop->Click += gcnew System::EventHandler(this, &Kitchen::Shop_Click);
			// 
			// count_food
			// 
			this->count_food->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->count_food->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(133)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->count_food->Font = (gcnew System::Drawing::Font(L"Epilepsy Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->count_food->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(203)));
			this->count_food->Location = System::Drawing::Point(249, 521);
			this->count_food->Name = L"count_food";
			this->count_food->Size = System::Drawing::Size(141, 35);
			this->count_food->TabIndex = 5;
			this->count_food->Text = L" ";
			this->count_food->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// burger_feed
			// 
			this->burger_feed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"burger_feed.Image")));
			this->burger_feed->Location = System::Drawing::Point(254, 375);
			this->burger_feed->Name = L"burger_feed";
			this->burger_feed->Size = System::Drawing::Size(128, 128);
			this->burger_feed->TabIndex = 6;
			this->burger_feed->TabStop = false;
			this->burger_feed->Click += gcnew System::EventHandler(this, &Kitchen::burger_feed_Click);
			// 
			// swap
			// 
			this->swap->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"swap.Image")));
			this->swap->Location = System::Drawing::Point(405, 443);
			this->swap->Name = L"swap";
			this->swap->Size = System::Drawing::Size(55, 55);
			this->swap->TabIndex = 8;
			this->swap->TabStop = false;
			this->swap->Click += gcnew System::EventHandler(this, &Kitchen::swap_Click);
			// 
			// feed_coce
			// 
			this->feed_coce->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->feed_coce->Cursor = System::Windows::Forms::Cursors::Default;
			this->feed_coce->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"feed_coce.Image")));
			this->feed_coce->Location = System::Drawing::Point(254, 375);
			this->feed_coce->Name = L"feed_coce";
			this->feed_coce->Size = System::Drawing::Size(128, 128);
			this->feed_coce->TabIndex = 9;
			this->feed_coce->TabStop = false;
			this->feed_coce->Click += gcnew System::EventHandler(this, &Kitchen::feed_coce_Click);
			// 
			// eat_gif
			// 
			this->eat_gif->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"eat_gif.Image")));
			this->eat_gif->Location = System::Drawing::Point(0, 0);
			this->eat_gif->Name = L"eat_gif";
			this->eat_gif->Size = System::Drawing::Size(640, 800);
			this->eat_gif->TabIndex = 10;
			this->eat_gif->TabStop = false;
			this->eat_gif->Visible = false;
			// 
			// gif
			// 
			this->gif->Interval = 1500;
			this->gif->Tick += gcnew System::EventHandler(this, &Kitchen::gif_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(178, 443);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(55, 55);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Kitchen::swap_2);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(264, 673);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(104, 104);
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// Kitchen
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(640, 800);
			this->Controls->Add(this->eat_gif);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->feed_coce);
			this->Controls->Add(this->swap);
			this->Controls->Add(this->burger_feed);
			this->Controls->Add(this->count_food);
			this->Controls->Add(this->Shop);
			this->Controls->Add(this->hungry);
			this->Controls->Add(this->feed);
			this->Controls->Add(this->back_to_form);
			this->Controls->Add(this->button_exit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Kitchen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->button_exit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_to_form))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Shop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->burger_feed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->swap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed_coce))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eat_gif))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void timerHunger_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void back_to_form_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void feed_Pizza(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Shop_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void burger_feed_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void swap_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void feed_coce_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void gif_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void swap_2(System::Object^ sender, System::EventArgs^ e);
};
}
