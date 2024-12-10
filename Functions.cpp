#include <iostream>
#include "Functions.h"
#include <string>
#include <pugixml.hpp>
#include "Cat.h"
#include "Dog.h"
#include <chrono>
#include <sstream>
#include <iomanip>


using namespace System;
using namespace System::Windows::Forms;
using namespace pugi;



void savePetToXML(const Pet* pet) {
    xml_document doc;
    xml_node root = doc.append_child("Pet");

    root.append_attribute("Type") = pet->getType().c_str();
    root.append_attribute("Name") = pet->getName().c_str();
    root.append_attribute("Age") = pet->getAge();
    root.append_attribute("Hunger") = pet->getHunger();
    root.append_attribute("Happiness") = pet->getHappiness();
    root.append_attribute("Health") = pet->getHealth();
    root.append_attribute("Fatigue") = pet->getFatigue();
    root.append_attribute("Dirtiness") = pet->getDirtiness();
    root.append_attribute("Money") = pet->getMoney();

    root.append_attribute("Pizza") = pet->getPizza();
    root.append_attribute("Burger") = pet->getBurger();
    root.append_attribute("Coce") = pet->getCoce();


    // **��������� ������� ����� � ������� ISO 8601**
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    char timeBuffer[20]; // ������: yyyy-MM-ddTHH:mm:ss
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%dT%H:%M:%S", std::localtime(&now_time));
    root.append_attribute("LastSaveTime") = timeBuffer;

    doc.save_file("pet_info.xml");
}

void ClearPet() {
    xml_document doc;
    xml_node root = doc.append_child("Pet");
    root.append_attribute("Type") = "";
    root.append_attribute("Name") = "";
    root.append_attribute("Age") = "";
    root.append_attribute("Hunger") = "";
    root.append_attribute("Happiness") = "";
    root.append_attribute("Health") = "";
    root.append_attribute("Fatigue") = "";
    root.append_attribute("Dirtiness") = "";
    root.append_attribute("Money") = "";

    root.append_attribute("Pizza") = "";
    root.append_attribute("Burger") = "";
    root.append_attribute("Coce") = "";
    doc.reset();
    doc.save_file("pet_info.xml");
}


void loadPetFromXML(Pet*& pet, int& minutes) { // ��������� ������ �� ���������� elapsedMinutes
    xml_document doc;
    if (!doc.load_file("pet_info.xml")) {
        pet = nullptr; // ��������� ��������� �� nullptr
        minutes = -1; // ���������, ��� �������� �� �������
        return;
    }

    xml_node root = doc.child("Pet");
    if (!root) {
        pet = nullptr; // ��������� ��������� �� nullptr
        minutes = -1; // ���������, ��� ������ ���
        return;
    }

    std::string type = root.attribute("Type").as_string();
    std::string name = root.attribute("Name").as_string();
    int age = root.attribute("Age").as_int();
    int hunger = root.attribute("Hunger").as_int();
    int happiness = root.attribute("Happiness").as_int();
    int health = root.attribute("Health").as_int();
    int fatigue = root.attribute("Fatigue").as_int();
    int dirtiness = root.attribute("Dirtiness").as_int();
    int money = root.attribute("Money").as_int();
    int pizza = root.attribute("Pizza").as_int();
    int burger = root.attribute("Burger").as_int();
    int coce = root.attribute("Coce").as_int();

    // ��������� ������� ������� ���������� ����������
    auto lastSaveTimeAttr = root.attribute("LastSaveTime");
    if (!lastSaveTimeAttr) {
        pet = nullptr; // ���� ����������� ����� ���������� ����������
        minutes = -1; // ��������� ��������� ��������
        return;
    }

    // ��������� ����� ���������� ���������� (������ ISO 8601: YYYY-MM-DDTHH:mm:ss)
    std::string lastSaveTimeStr = lastSaveTimeAttr.as_string();
    std::tm lastSaveTime = {};
    std::istringstream ss(lastSaveTimeStr);
    ss >> std::get_time(&lastSaveTime, "%Y-%m-%dT%H:%M:%S");
    if (ss.fail()) {
        pet = nullptr; // ���� ������� ������� �� ������
        minutes = -1; // ��������� ��������� ��������
        return;
    }

    // �������� ������� ��������� �����
    std::time_t currentTime = std::time(nullptr);
    std::time_t lastSaveEpoch = std::mktime(&lastSaveTime); // ����� ���������� � ������� UNIX
    if (lastSaveEpoch == -1) {
        pet = nullptr; // ������ ��� �������������� �������
        minutes = -1; // ��������� ��������� ��������
        return;
    }

    // ������� ������� �� ������� (� �������)
    minutes = static_cast<int>(std::difftime(currentTime, lastSaveEpoch) / 60);

    // ��������� ��� ������� � �������� ������
    if (type == "Cat") {
        pet = new Cat(name); // �������� ������ ��� ������� Cat
    }
    else if (type == "Dog") {
        pet = new Dog(name); // �������� ������ ��� ������� Dog
    }
    else {
        pet = nullptr; // ���������������� ���
        minutes = -1; // ��������� ��������� ��������
        return;
    }

    // ������������� ������ �������
    pet->setPetData(name, age, hunger, happiness, health, fatigue, dirtiness, money, pizza, burger, coce);
}






//������������ System::string^ � std::string
std::string& Convert_String_to_string(String^ s, std::string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    return os;
}

//������������ std::string � System::string^
String^ Convert_string_to_String(std::string& os, String^ s) {
    s = gcnew System::String(os.c_str());

    return s;
}

//������������ System::string^ � std::string
std::string& Convert_String_to_string(String^ s) {
    std::string os;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    return os;
}

//������������ std::string � System::string^
String^ Convert_string_to_String(std::string& os) {
    System::String^ s = gcnew System::String(os.c_str());

    return s;
}

//������������ char � System::string^
System::String^ Convert_char_to_String(char ch) {
    char* chr = new char();
    chr[0] = ch;
    System::String^ str;
    for (int i = 0; chr[i] != '\0'; i++)
        str += wchar_t(ch);
    return str;
}

//������������ System::string^ � char*
char* Convert_String_to_char(System::String^ string) {
    using namespace System::Runtime::InteropServices;
    return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}

//������������ char* � System::string^
System::String^ Convert_char_to_String(char* ch) {
    char* chr = new char();
    chr = ch;
    System::String^ str;
    for (int i = 0; chr[i] != '\0'; i++)
        str += wchar_t(ch[i]);
    return str;
}