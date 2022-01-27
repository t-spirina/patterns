/*Decorator
Вы решили открыть кофейню и вам понадобилось наладить учет производства напитков.
Вы создали абстрактный класс, в котором определили метод для расчета стоимости всех напитков.
class Beverage{            // Абстрактный класс
   virtual double getDescription() const = 0;
   virtual double cost() const = 0;
};

class HouseBlend: public Beverage{   // Молотый
public:
   double cost() const override {
       return 5.5;
   }
};

class DarkRoast: public Beverage{  // Темной обжарки
   double cost() const override {
       return 6.0;
   }
};

class Decaf: public Beverage{    // Без кофеина
   double cost() const override {
       return 7.3;
   }
};

class Espresso: public Beverage{  // Эспрессо
   double cost() const override {
       return 3.5;
   }
};


Но к кофе можно заказать еще различные  добавки (шоколад, корица, взбитые сливки) или наоборот взять без сахара.
Дополнения не бесплатны, поэтому они должны быть встроены в систему оформления заказов.
А отсутствие сахара должно наоборот снижать стоимость.
Понятное дело, что создавать отдельные классы для каждого варианта “сборки” кофе - не вариант.
И тут нам на помощь придет декоратор!
Реализуйте паттерн декоратор с помощью которого можно будет сварить кофе с любым составом добавок.
*/
#pragma once
#include <iostream>

class Beverage{
public:// Абстрактный класс
   virtual std::string getDescription() const = 0;
   virtual double cost() const = 0;
};

class HouseBlend: public Beverage{   // Молотый
public:
   std::string getDescription() const override{
       return "HouseBlend";
   }
   double cost() const override {
       return 5.5;
   }
};

class DarkRoast: public Beverage{  // Темной обжарки
public:
    std::string getDescription() const override{
        return "DarkRoast";
    }
    double cost() const override {
       return 6.0;
   }
};

class Decaf: public Beverage{    // Без кофеина
public:
    std::string getDescription() const override{
        return "Decaf";
    }
    double cost() const override {
       return 7.3;
   }
};

class Espresso: public Beverage{  // Эспрессо
public:
    std::string getDescription() const override{
        return "Espresso";
    }
    double cost() const override {
       return 3.5;
   }
};
class Decorator: public Beverage{
    Beverage* m_beverage;
public:
    Decorator(Beverage* beverage):m_beverage(beverage){}
    virtual std::string getDescription() const override{
        return m_beverage->getDescription();
    }
    virtual double cost() const override{
        return (m_beverage->cost());
    }
};

class AddMilk: public Decorator
{
 public:
    AddMilk(Beverage *beverage):Decorator(beverage){}
    virtual std::string getDescription() const override{
        return Decorator::getDescription() + " with milk";
    }
    virtual double cost() const override{
        return (Decorator::cost() +0.5);
    }
};
class AddSugar: public Decorator
{
 public:
    AddSugar(Beverage *beverage):Decorator(beverage){}
    virtual std::string getDescription() const override{
        return Decorator::getDescription() + " with sugar";
    }
    virtual double cost() const override{
        return (Decorator::cost() +0.3);
    }
};

class NoSugar: public Decorator
{
 public:
    NoSugar(Beverage *beverage):Decorator(beverage){}
    virtual std::string getDescription() const override{
        return Decorator::getDescription() + " no sugar";
    }
    virtual double cost() const override{
        return (Decorator::cost() - 0.3);
    }
};
