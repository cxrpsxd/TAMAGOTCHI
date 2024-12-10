#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name) {
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

void Dog::feed(int amount, int dirtycost) { generalFeed(amount, dirtycost); }
void Dog::play() { generalPlay(10, 5, 6); }
void Dog::heal() { generalHeal(10); }
void Dog::sleep() { generalSleep(20, 5, 30); }
void Dog::bathe() { generalBathe(100, 3); }
void Dog::timerHunger() { generalTimerHunger(1); }
void Dog::timerFatigue() { generalTimerFatigue(1); }
void Dog::timerHappiness() { generalTimerHappiness(1); }
void Dog::timerHealth() { generalTimerHealth(1); }
void Dog::timerAge() { generalTimerAge(1); }

void Dog::update() {
    incrementHunger();
    happiness--;
    decrementHealth(1);
    fatigue++;
    incrementDirtiness();
    incrementAge();
}

void Dog::displayStatus() const {
    std::cout << "Собака " << name << ":\n";
    printCommonStatus();
}

bool Dog::isAlive() const { return health > 0; }
std::string Dog::getType() const { return "Dog"; }

std::string Dog::getName() const { return name; }
int Dog::getAge() const { return age; }
int Dog::getHunger() const { return hunger; }
int Dog::getHappiness() const { return happiness; }
int Dog::getHealth() const { return health; }
int Dog::getFatigue() const { return fatigue; }
int Dog::getDirtiness() const { return dirtiness; }
int Dog::getMoney() const { return money; }
////////////////
int Dog::getPizza() const { return pizza; }
int Dog::getBurger() const { return burger; }
int Dog::getCoce() const { return coce; }

void Dog::setHunger(int hunger) {
    this->hunger = hunger;
}

void Dog::setHappiness(int happiness) {
    this->happiness = happiness;
}

void Dog::setHealth(int health) {
    this->health = health;
}

void Dog::setAge(int age) {
    this->age = age;
}

void Dog::setFatigue(int fatigue) {
    this->fatigue = fatigue;
}

void Dog::setDirtiness(int dirtiness) {
    this->dirtiness = dirtiness;
}

void Dog::setName(std::string name) {
    this->name = name;
}

void Dog::setMoney(int money) {
    this->money = money;
}
////////////////////////////////////////////////////////////////////

void Dog::setPizza(int pizza) {
    this->pizza = pizza;
}
void Dog::setBurger(int burger) {
    this->burger = burger;
}
void Dog::setCoce(int coce) {
    this->coce = coce;
}


void Dog::setPetData(const std::string& name, int age, int hunger, int happiness, int health, int fatigue, int dirtiness, int money, int pizza, int burger, int coce) {
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

void Dog::printCommonStatus() const {
    std::cout << "Голод: " << hunger << "\n";
    std::cout << "Счастье: " << happiness << "\n";
    std::cout << "Здоровье: " << health << "\n";
    std::cout << "Возраст: " << age << " лет\n";
    std::cout << "Усталость: " << fatigue << "\n";
    std::cout << "Загрязнение: " << dirtiness << "\n";
}