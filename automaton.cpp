#include "automaton.h"
#include <cmath>
void Automaton::changePrice(std::string name, float newPrice) {
    goods_price[name] = newPrice;
}

void Automaton::sellProduct(std::string name){
    if(goods_count[name] > 0){
        recieved_money += goods_price[name];
    }
    else{
        std::cerr << "Not enough goods" << std::endl;
    }
}

void Automaton::addProduct(std::string name, size_t count){
    goods_count[name] += count;
}

double Automaton::allMoneyReport() const{
    return recieved_money - spent_money;
}

const std::string& Automaton::getLocationReport() const {
    return location;
}

void Automaton::goodsCountReport() const{
    for (auto& [product,count]: goods_count){
        std::cout << product << ": " << count << std::endl;
    }
};

void Automaton::goodsPriceReport() const{
    for (auto& [product,price]: goods_price){
        std::cout << product << ": " << price << std::endl;
    }
};

bool ProxyForAutomation::checkTime()
{
    bool flag;
    std::time_t rawTime;
    std::tm* requestTime;
    time(&rawTime);
    requestTime=gmtime( &rawTime );
    if (std::abs((requestTime->tm_hour*60+requestTime->tm_min) - (logDataTime->tm_hour*60+logDataTime->tm_min)) > 60)
    {

        flag = true;
    }
    else {
        flag = false;
    }
     logDataTime=requestTime;
     return flag;
}
const std::string& ProxyForAutomation::getLocationReport()
{
    if (checkTime()) //прошло больше часа
    {
        setLocation( automaton->getLocationReport());
        std::cout<<"обновляю местоположение из реального объекта"<<std::endl;
    }
    else {
        std::cout<<"беру старое местоположение"<<std::endl;
    }
    return location;
}
void ProxyForAutomation::updateProductLog(std::string name, size_t count){
   goods_count[name] += count;
}
void ProxyForAutomation::goodsCountReport() {
    if(checkTime())
    {
       goods_count.clear();
        std::cout<<"обновляю из реального объекта"<<std::endl;
       goods_count=automaton->GetGoodCount();
    }
    for (auto& [product,count]: goods_count){
        std::cout << product << ": " << count << std::endl;
    }
}
void ProxyForAutomation::goodsPriceReport()
{
    if(checkTime())
    {
       goods_price.clear();
       std::cout<<"обновляю из реального объекта"<<std::endl;
       goods_price=automaton->GetGoodPrice();
    }
    for (auto& [product,price]: goods_price){
        std::cout << product << ": " << price << std::endl;
    }
}
