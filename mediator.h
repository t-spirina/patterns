#pragma once
#include <iostream>
#include <vector>
/*
Вам необходимо реализовать систему “Умный дом”. Все домашние приборы и
устройства сконструированы так, чтобы сделать жизнь максимально комфортной. У
вас есть 2 объекта: Будильник и Кофеварка. Когда выключается сигнал будильника, то
будильник приказывает кофеварке приступить к приготовлению кофе. Но возникают
новые задачи - не варить кофе по выходным, ставить будильник на более раннее
время в дни вывоза мусора. А в выходные наоборот хочется поспать подольше. А утро
начинать не с кофе, а с чая. То есть необходимо подключить к системе еще два
объекта - умный чайник и календарь, которые в совокупности образуют сложную
систему. Мы попытались связать всю систему вместе. И вроде работает, но есть четкое
понимание, что дальше будет хуже) Самое время реализовать паттерн Посредник,
который будет определять всю логику. А сами классы устройств будут только
выполнять свою работу.
*/

class Gadget;

class Calendar{
    int day;
    std::vector<Gadget*> gadgets;
public:
    Calendar(int _day):day(_day){}

    bool checkCalendar(){
        return ((day<6) ? true : false) ; // Упрощенная реализация, должен возвращать true,если рабочий день.
    }
    void add(Gadget*  g)  {
        gadgets.push_back(g);
    }
    void StartDay();
    ~Calendar() ;
};

class Gadget
{
public:
    Gadget(){}
    Gadget( Calendar*  calendar) :
         calendar( calendar ) {}
    virtual ~ Gadget() {}
    virtual bool checkDay() = 0;
    virtual void DoSmth() = 0;

protected:
    Calendar* calendar;
};

class Coffee: public Gadget{
private:
    Calendar* calendar;
public:
    Coffee( Calendar*  calendar) : calendar( calendar) {}
    void DoSmth(){
       std::cout << "Starting coffee" << std::endl;
    }
    bool checkDay(){
        return (calendar->checkCalendar());
    }
};


class TeaPot: public Gadget{
private:
    Calendar* calendar;
public:
    TeaPot( Calendar*  calendar) : calendar( calendar) {}
    void DoSmth()  override{
        std::cout << "Starting tea" << std::endl;
    }
    bool checkDay()  override{
        return (!calendar->checkCalendar());
    }
};

class Alarm: public Gadget{
private:
    Calendar* calendar;
public:
    Alarm (Calendar*  calendar) : calendar( calendar) {}
    void DoSmth()  override{
        if (checkDay())
            std::cout << "Alarm call" << std::endl;
        else
            std::cout << "Sun rise" << std::endl;
    }
    bool checkDay()  override{
        return (calendar->checkCalendar());
    }
};

Calendar::~Calendar(){

        for ( auto gadget : gadgets){
            delete gadget;
        }
        gadgets.clear();

}
void Calendar::StartDay() {
    std::cout << "Starting day" << std::endl;
    for ( Gadget* gadget : gadgets){
        if (gadget->checkDay()){
            gadget->DoSmth();
        }

    }
}


