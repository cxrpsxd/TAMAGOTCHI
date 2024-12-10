#pragma once

#include "PET.h"



class Cat : public Pet {
public:
    Cat(const std::string& name);



    void feed(int amount, int dirtycost) override;
    void play() override;
    void heal() override;
    void sleep() override;
    void bathe() override;

    void timerHunger() override;
    void timerFatigue() override;
    void timerHappiness() override;
    void timerHealth() override;
    void timerAge() override;

    void update() override;

    void displayStatus() const override;

    bool isAlive() const override;
    std::string getType() const override;

    std::string getName() const override;
    int getAge() const override;
    int getHunger() const override;
    int getHappiness() const override;
    int getHealth() const override;
    int getFatigue() const override;
    int getDirtiness() const override;
    int getMoney() const override;
    ///////////////////
    int getPizza() const override;
    int getBurger() const override;
    int getCoce() const override;


    void setPetData(const std::string& name, int age, int hunger, int happiness, int health, int fatigue, int dirtiness, int money, int pizza, int burger, int coce) override;
    void setHunger(int hunger) override;
    void setHappiness(int happiness) override;
    void setHealth(int health) override;
    void setAge(int age) override;
    void setFatigue(int fatigue) override;
    void setDirtiness(int dirtiness) override;
    void setName(std::string name) override;
    void setMoney(int money) override;

    void setPizza(int pizza) override;
    void setBurger(int burger) override;
    void setCoce(int coce) override;


private:
    void printCommonStatus() const;
};