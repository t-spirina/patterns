#pragma once
/*
Вам предложено создать систему планирований Экскурсий.
Гости парка могут выбрать гостиницу, заказать билеты на аттракционы,
зарезервировать места в ресторане и даже заказать специальные мероприятия.
Реализуйте паттерн строитель, позволяющий планировать любой день любым удобным способом.

*/

#include <iostream>

class Events{
public:
   virtual void getEvent() = 0;
   virtual ~Events() {}
};

class Hotel: public Events{
public:
   void getEvent() {
       std::cout << "Booking Hotel" << std::endl;
   }
};

class Park: public Events{
public:
    void getEvent() {
       std::cout << "Park visiting" << std::endl;
   }
};

class Food: public Events{
public:
   virtual void getEvent() = 0;
   virtual ~Food() {}
};

class Dinner: public Food{
public:
   Dinner() : _type("breakfast") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   }
private:
   std::string _type;
};

class Lunch: public Food{
public:
   Lunch() : _type("lunch") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   }
private:
   std::string _type;
};

class Breakfast: public Food{
public:
   Breakfast() : _type("breakfast") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   }
private:
   std::string _type;
};

class Special: public Events{
public:
   virtual void getEvent() = 0;
   virtual ~Special() {}
};

class Skating:public Special{
public:
   Skating() : _type("skating") {}
   void getEvent(){
       std::cout << _type << std::endl;
   }
private:
   std::string _type;
};

class Circus:public Special{
public:
   Circus() : _type("circus") {}
   void getEvent(){
       std::cout << _type << std::endl;
   }
private:
   std::string _type;
};

class Day{
public:
    Hotel* hotel;
    Park* park;
    Breakfast* breakfast;
    Dinner* dinner;
    Lunch* lunch;
    Skating* skating;
    Circus* circus;
    void eventInfo(){
        if(hotel){
            hotel->getEvent();
        }
        if(park){
            park->getEvent();
        }
        if(breakfast){
            breakfast->getEvent();
        }
        if(lunch){
            lunch->getEvent();
        }
        if(dinner){
            dinner->getEvent();
        }
        if(skating){
            skating->getEvent();
        }
        if(circus)
        {
            circus->getEvent();
        }
    }
};

class Planner{//builder
protected:
    Day* day = nullptr;
public:
    virtual void planningNewDay(){}
    virtual void addHotel(){}
    virtual void addPark(){}
    virtual void addBreakfast(){}
    virtual void addLunch(){}
    virtual void addDinner(){}
    virtual void addSkating(){}
    virtual void addCircus(){}
    virtual Day* getDay() const {return day;}
};

class DayConstructer: public Planner{
   public:
    void planningNewDay() override {
        day = new Day;
    }
    void addHotel() override{
        day->hotel = new Hotel;
    }
    void addBreakfast() override{
        day->breakfast =new Breakfast;
    }
    void addLunch() override{
        day->lunch = new Lunch;
    }
    void addDinner() override{
        day->dinner = new Dinner;
    }
    void addPark() override{
        day->park = new Park;
    }
    void addSkating() override{
        day->skating = new Skating;
    }
    void addCircus() override{
        day->circus = new Circus;
    }
    ~DayConstructer(){
        if(day->hotel){
           delete day->hotel;
        }
        if(day->park){
            delete day->park;
        }
        if(day->breakfast){
            delete day->breakfast;
        }
        if(day->lunch){
            delete day->lunch;
        }
        if(day->dinner){
            delete day->dinner;
        }
        if(day->skating){
            delete day->skating;
        }
        if(day->circus)
        {
            delete day->circus;
        }
    }
};

class FirstDaySchedule{
public:
    Day* createDaySchedule(DayConstructer &planForTheDay){
        planForTheDay.planningNewDay();
        planForTheDay.addHotel();
        planForTheDay.addDinner();
        planForTheDay.addPark();
        return planForTheDay.getDay();
    }
};
