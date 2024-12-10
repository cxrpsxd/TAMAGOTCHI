#include "PET.h"
#include <algorithm>
#include "Functions.h"

using namespace std;

void Pet::incrementAge() { age++; }
void Pet::incrementHunger() { hunger++; }
void Pet::decrementHealth(int amount) { health = max(0, health - amount); }
void Pet::incrementDirtiness() { dirtiness++; }

// Общая реализация методов действий 

void Pet::generalFeed(int amount, int dirtyCost) {
    hunger = min(100, hunger + amount);
    dirtiness = max(0, dirtiness - dirtyCost);
}
void Pet::generalPlay(int happinessGain, int hungerCost, int fatigueCost) {
    happiness = min(100, happiness + happinessGain);
    hunger = max(0, hunger - hungerCost);
    fatigue = max(0, fatigue - fatigueCost);
}
void Pet::generalHeal(int amount) { health = min(100, health + amount); }
void Pet::generalSleep(int hungerCost, int healthHealAmount, int dirtyCost) {
    fatigue = 100;
    happiness = 50;
    hunger = max(0, hunger - hungerCost);
    health = min(100, health + healthHealAmount);
    dirtiness = max(0, dirtiness - dirtyCost);
}
void Pet::generalBathe(int dirtinessCost, int happinessGain) {
    dirtiness = min(100, dirtiness + dirtinessCost);
    happiness = min(100, happiness + happinessGain);
}
void Pet::generalTimerHunger(int amount) {
    hunger = max(0, hunger - amount);
}
void Pet::generalTimerFatigue(int amount) {
    fatigue = max(0, fatigue - amount);
}
void Pet::generalTimerHappiness(int amount) {
    happiness = max(0, happiness - amount);
}
void Pet::generalTimerHealth(int amount) {
    health = max(0, health - amount);
}
void Pet::generalTimerAge(int amount) {
    age = min(100, age + amount);
}



void Pet::setHunger(int hunger) {
    this->hunger = hunger;
}

void Pet::setHappiness(int happiness) {
    this->happiness = happiness;
}

void Pet::setHealth(int health) {
    this->health = health;
}

void Pet::setAge(int age) {
    this->age = age;
}

void Pet::setFatigue(int fatigue) {
    this->fatigue = fatigue;
}

void Pet::setDirtiness(int dirtiness) {
    this->dirtiness = dirtiness;
}

void Pet::setName(std::string name) {
    this->name = name;
}

void Pet::setMoney(int money) {
    this->money = money;
}
/// <summary>
/// //////////////////////////////////////////////
/// </summary>
/// <param name="pizza"></param>

void Pet::setPizza(int pizza) {
    this->pizza = pizza;
}
void Pet::setBurger(int burger) {
    this->burger = burger;
}
void Pet::setCoce(int coce) {
    this->coce = coce;
}

