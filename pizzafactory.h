#pragma once
/*
Разработчики начали писать код для пиццерии. Выглядит он следующим образом:

class Pizza{
public:
   virtual void prepare(std::string);
   virtual void bake() {};
   virtual void cut() {};
   virtual void box() {};
};

class CheesePizza:public Pizza{};
class GreekPizza:public Pizza{};
class PepperoniPizza:public Pizza{};

Pizza* orderPizza(std::string type){
   Pizza* pizza = nullptr;
   if (type == "cheese"){
       pizza = new CheesePizza;
   }
   else if (type == "greek"){
       pizza = new GreekPizza;
   }
   else if (type == "pepperoni"){
       pizza = new PepperoniPizza;
   }
   return pizza;
}


Как видите, на каждый тип пиццы создается свой собственный класс. И в целом это неплохо.
Но выбор конкретного класса для создания экземпляра усложняет функцию orderPizza() и не позволяет закрыть её для изменений.
Реализуйте паттерн “абстрактная фабрика” который позволит создавать пиццу не привязываясь к её типу, чтобы внутри функции orderPizza()
не создавались конкретные экземпляры классов с пиццами
*/
#include <iostream>
#include <vector>
class Pizza
{
public:
    virtual void prepare(std::string)=0;
    virtual void bake() {}
    virtual void cut() {}
    virtual void box() {}
    virtual ~Pizza() {}
};
class CheesePizza : public Pizza
{
public:

    void prepare(std::string) override{
        std::cout << "CheesePizza" << std::endl;
    }
    void bake() override{}
    void cut() override{}
    void box() override{}
};

class GreekPizza : public Pizza
{
public:

    void prepare(std::string) override{
        std::cout << "GreekPizza" << std::endl;
    }
    virtual void bake() override{}
    virtual void cut() override{}
    virtual void box() override{}
};

class PepperoniPizza : public Pizza
{
public:
    void prepare(std::string) override{
        std::cout << "PepperoniPizza" << std::endl;
    }
    virtual void bake()override {}
    virtual void cut() override{}
    virtual void box() override{}
};

class pizzaBakery
{
public:
    virtual Pizza* bakePizza() = 0;
    virtual ~ pizzaBakery(){}
};

class BakeCheesePizza : public pizzaBakery
{
public:
    Pizza* bakePizza(){
        return new CheesePizza;
    }
};
class BakeGreekPizza : public pizzaBakery
{
public:
    Pizza* bakePizza(){
        return new GreekPizza;
    }
};
class BakePepperoniPizza : public pizzaBakery
{
public:
    Pizza* bakePizza(){
        return new PepperoniPizza;
    }
};


struct Order
{
    ~Order(){for (const auto & i : order_list)  delete i;}
    void info(){for (const auto & i : order_list)   i->prepare("  ");}
    std::vector <Pizza*> order_list;

};

class Visitor{
public:
    void addPizza(pizzaBakery& bakery)
    {
       order.order_list.push_back(bakery.bakePizza());
    }
    void getOrderInfo()
    {
        order.info();
    }
private:
    Order order;
};
