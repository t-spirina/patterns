#pragma once
/*
Давайте вспомним наше домашнее задание по абстрактным фабрикам и пиццериям.
Не кажется ли вам, что его будет намного логичнее выполнить с помощью паттерна Абстрактный метод?)
Ведь когда фабрика по производству пиццерий одна, то нет смысла в их большом количестве.
А вот метод по изготовлению разных пицц - самое оно.
Решите задачу с пиццериями с использованием паттерна “Фабричный метод”.
*/
#include <iostream>

class Pizza
{
public:
    virtual void prepare()=0;
    virtual void bake() {}
    virtual void cut() {}
    virtual void box() {}
};

class CheesePizza : public Pizza
{
public:

    void prepare() override{
        std::cout << "CheesePizza" << std::endl;
    }
    void bake() override{}
    void cut() override{}
    void box() override{}
};

class GreekPizza : public Pizza
{
public:

    void prepare() override{
        std::cout << "GreekPizza" << std::endl;
    }
    virtual void bake() override{}
    virtual void cut() override{}
    virtual void box() override{}
};

class PepperoniPizza : public Pizza
{
public:
    void prepare() override{
        std::cout << "PepperoniPizza" << std::endl;
    }
    virtual void bake()override {}
    virtual void cut() override{}
    virtual void box() override{}
};

class PizzaFactory{
public:
    virtual Pizza* createPizza() = 0;
};

class CheesePizzaFactory: public PizzaFactory{
    Pizza *createPizza() override {
        return new CheesePizza;
    }
};

class GreekPizzaFactory: public PizzaFactory{
    Pizza *createPizza() override {
        return new GreekPizza;
    }
};

class PepperoniPizzaFactory: public PizzaFactory{
    Pizza *createPizza() override {
        return new PepperoniPizza;
    }
};

Pizza * addPizza(PizzaFactory* pizzaFactory){
    return pizzaFactory->createPizza();
}



