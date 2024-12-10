#include "Cat.h"
#include <iostream>

Cat::Cat(const std::string& name) {
    this->name = name;
    hunger = 50;
    happiness = 50;
    health = 100;
    age = 1;
    fatigue = 50;
    dirtiness = 100;
    money = 100;
    pizza = 1;
    burger = 1;
    coce = 1;
}


void Cat::feed(int amount, int dirtycost) { generalFeed(amount, dirtycost); }
void Cat::play() { generalPlay(12, 2, 5); }
void Cat::heal() { generalHeal(12); }
void Cat::sleep() { generalSleep(50, 5, 30); }
void Cat::bathe() { generalBathe(100, 5); }
void Cat::timerHunger() { generalTimerHunger(1); }
void Cat::timerFatigue() { generalTimerFatigue(1); }
void Cat::timerHappiness() { generalTimerHappiness(1); }
void Cat::timerHealth() { generalTimerHealth(1); }
void Cat::timerAge() { generalTimerAge(1); }

void Cat::update() {
    incrementHunger();
    happiness--;
    decrementHealth(1);
    fatigue++;
    incrementDirtiness();
    incrementAge();
}

void Cat::displayStatus() const {
    std::cout << "Кот " << name << ":\n";
    printCommonStatus();
}

bool Cat::isAlive() const { return health > 0; }
std::string Cat::getType() const { return "Cat"; }

void Cat::setHunger(int hunger) {
    this->hunger = hunger;
}

void Cat::setHappiness(int happiness) {
    this->happiness = happiness;
}

void Cat::setHealth(int health) {
    this->health = health;
}

void Cat::setAge(int age) {
    this->age = age;
}

void Cat::setFatigue(int fatigue) {
    this->fatigue = fatigue;
}

void Cat::setDirtiness(int dirtiness) {
    this->dirtiness = dirtiness;
}

void Cat::setName(std::string name) {
    this->name = name;
}

void Cat::setMoney(int money) {
    this->money = money;
}
///////////////////////////////////
void Cat::setPizza(int pizza) {
    this->pizza = pizza;
}
void Cat::setBurger(int burger) {
    this->burger = burger;
}
void Cat::setCoce(int coce) {
    this->coce = coce;
}



std::string Cat::getName() const { return name; }
int Cat::getAge() const { return age; }
int Cat::getHunger() const { return hunger; }
int Cat::getHappiness() const { return happiness; }
int Cat::getHealth() const { return health; }
int Cat::getFatigue() const { return fatigue; }
int Cat::getDirtiness() const { return dirtiness; }
int Cat::getMoney() const { return money; }
//////////////
int Cat::getPizza() const { return pizza; }
int Cat::getBurger() const { return burger; }
int Cat::getCoce() const { return coce; }


void Cat::setPetData(const std::string& name, int age, int hunger, int happiness, int health, int fatigue, int dirtiness, int money, int pizza, int burger, int coce) {
    this->name = name;
    this->age = age;
    this->hunger = hunger;
    this->happiness = happiness;
    this->health = health;
    this->fatigue = fatigue;
    this->dirtiness = dirtiness;
    this->money = money;
    this->pizza = pizza;
    this->burger = burger;
    this->coce = coce;
}

void Cat::printCommonStatus() const {
    std::cout << "Голод: " << hunger << "\n";
    std::cout << "Счастье: " << happiness << "\n";
    std::cout << "Здоровье: " << health << "\n";
    std::cout << "Возраст: " << age << " лет\n";
    std::cout << "Усталость: " << fatigue << "\n";
    std::cout << "Загрязнение: " << dirtiness << "\n";
}
