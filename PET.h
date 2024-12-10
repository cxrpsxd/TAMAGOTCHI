#pragma once
#include <string>


class Pet {
public:
    virtual ~Pet() = default;

    virtual void feed(int amount, int dirtycost) = 0;
    virtual void play() = 0;
    virtual void heal() = 0;
    virtual void sleep() = 0;
    virtual void bathe() = 0;
    virtual void update() = 0;

    virtual void timerHunger() = 0;
    virtual void timerFatigue() = 0;
    virtual void timerHappiness() = 0;
    virtual void timerHealth() = 0;
    virtual void timerAge() = 0;

    virtual void displayStatus() const = 0;
    virtual bool isAlive() const = 0;
    virtual std::string getName() const = 0;
    virtual int getAge() const = 0;
    virtual int getHunger() const = 0;
    virtual int getHappiness() const = 0;
    virtual int getHealth() const = 0;
    virtual int getFatigue() const = 0;
    virtual int getDirtiness() const = 0;
    virtual int getMoney() const = 0;
    ////////////////////////
    virtual int getPizza() const = 0;
    virtual int getBurger() const = 0;
    virtual int getCoce() const = 0;


    virtual void setHunger(int hunger) = 0;
    virtual void setHappiness(int happiness) = 0;
    virtual void setHealth(int health) = 0;
    virtual void setAge(int age) = 0;
    virtual void setFatigue(int fatigue) = 0;
    virtual void setDirtiness(int dirtiness) = 0;
    virtual void setName(std::string name) = 0;
    virtual void setMoney(int money) = 0;
    //////////////////////////////////////////////////////
    virtual void setPizza(int pizza) = 0;
    virtual void setBurger(int burger) = 0;
    virtual void setCoce(int coce) = 0;

    virtual void setPetData(const std::string& name, int age, int hunger, int happiness, int health, int fatigue, int dirtiness, int money,
    int pizza, int burger, int coce) = 0;
    virtual std::string getType() const = 0;

    


protected:
    std::string name = "";
    int hunger = 0;
    int happiness = 0;
    int health = 0;
    int age = 0;
    int fatigue = 0;
    int dirtiness = 0;
    int money = 0;

    int pizza = 0;
    int burger = 0;
    int coce = 0;

    // Общие методы
    void incrementAge();
    void incrementHunger();
    void decrementHealth(int amount);
    void incrementDirtiness();

    // Общая реализация методов действий 
    void generalFeed(int amount, int dirtyCost);
    void generalPlay(int happinessGain, int hungerCost, int fatigueCost);
    void generalHeal(int amount);
    void generalSleep(int hungerCost, int healthHealAmount, int dirtyCost);
    void generalBathe(int dirtinessCost, int happinessGain);

    void generalTimerHunger(int amount);
    void generalTimerFatigue(int amount);
    void generalTimerHappiness(int amount);
    void generalTimerHealth(int amount);
    void generalTimerAge(int amount);



};


