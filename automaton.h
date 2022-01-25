/*Автоматы в наше время все чаще заменяют людей.
 * Появились автоматы, наливающие напитки, продающие сухарики, контактные линзы, автоматы выдающие ваши интернет заказы.
 * Обычно все эти автоматы связаны между собой в сеть и управляются с клиента.
 * Раз в месяц необходимо составлять отчет о состоянии автоматов.
 * Но проблема в том, что ресурсов на клиенте недостаточно, чтобы постоянно опрашивать сраазу все автоматы в режиме реального
 * времени.
*/
/*
    Реализуйте паттерн Proxy для данного кода.
    Заместитель должен хранить в себе еще одно дополнительное поле с датой получения данных.
    При вызове любого из отчетов, должна происходить проверка времени последнего запроса данных.
    Если прошло более одного часа, то тогда вызываем метод с отчетом в реальном объекте.
    Если меньше, то выводим на экран сохраненные данные с прошлого отчета.
    Для времени удобно использовать #include <ctime>
*/
#pragma once
#include <iostream>
#include <map>
#include <ctime>

class ISellSystem{
public:
   virtual void changePrice(std::string, float) = 0;
   virtual void sellProduct(std::string) = 0;
   virtual void addProduct(std::string, size_t) = 0;
};


class Automaton: public ISellSystem {
private:
   std::string location;
   double recieved_money;
   double spent_money;
   std::map <std::string, float> goods_price;
   std::map <std::string, float> goods_count;

public:
   Automaton(const std::string &location, double recievedMoney) : location(location), recieved_money(recievedMoney) {
       spent_money = 0.0;
   }
   void changePrice(std::string name, float newPrice) override ;
   void sellProduct(std::string name);
   void addProduct(std::string name, size_t count);
   double allMoneyReport() const;
   const std::string& getLocationReport() const ;
   void goodsCountReport() const;
   void goodsPriceReport() const;
   void setLocation(const std::string &_location){location = _location;}
   void setReceivedMoney(double recievedMoney){recieved_money = recievedMoney;}
   auto GetGoodPrice(){return goods_price;}
   auto GetGoodCount(){return goods_count;}
};

class ProxyForAutomation: public ISellSystem{
private:
    std::string location;
    double recieved_money;
    double spent_money;
    std::map <std::string, float> goods_price;
    std::map <std::string, float> goods_count;
    std::tm* logDataTime;
    Automaton* automaton{};
    bool checkTime();
public:
    ProxyForAutomation(Automaton* Rautomaton): automaton(new Automaton(*Rautomaton)){
        spent_money = 0.0;}
    ~ProxyForAutomation() {
        delete automaton;
    }
    void changePrice(std::string name, float newPrice){ automaton->changePrice(name,newPrice);}
    void sellProduct(std::string name){automaton->sellProduct(name);}
    void addProduct(std::string name, size_t count){ automaton->addProduct(name,count); }
    void updateProductLog(std::string name, size_t count);
    void setLocation(const std::string &_location){location =_location;}
    void setReceivedMoney(double recievedMoney){recieved_money = recievedMoney;}

    double allMoneyReport() const;
    const std::string& getLocationReport();
    void goodsCountReport();
    void goodsPriceReport();
};
