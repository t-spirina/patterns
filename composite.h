#pragma once
#include <iostream>
#include <vector>
/*Представьте, что кафе-мороженное решило объединиться с блинной. Ранее у них был
простой код, который позволял им работать всего с одним классом и разными
объектами . Но теперь появилась необходимость комбинировать разные элементы в
меню, чтобы можно было предлагать комплексные завтраки/обеды/ужины. Реализуйте
паттерн компоновщик, исправив текущий код (внимание на main - нужно будет
избавиться от объектов превратив их в классы). И реализуйте комбо-наборы
(скомбинировать можно по своему усмотрению)*/
class IEat{
    std::string name;
    float price;
public:
    virtual int GetPrice() = 0;
    virtual std::string GetName() = 0;
    virtual ~IEat(){}
};

class Pancake:public IEat{
    std::string name;
    float price;
public:
    Pancake(const std::string &name, float price):
        name(name), price(price) {}
    int GetPrice() override {return price;}
    std::string GetName()override {return name;}
};

class IceCream :public IEat{
private:
    std::string name;
    float price;
public:
    IceCream(const std::string &name, float price):
        name(name), price(price) {}
    int GetPrice() override{return price;}
    std::string GetName()override {return name;}
};

class Beverage :public IEat{
private:
    std::string name;
    float price;
public:
    Beverage(const std::string &name, float price):
        name(name), price(price) {}
    int GetPrice()override {return price;}
    std::string GetName()override {return name;}
};

class CompositeEat :public IEat{
private:
    std::vector<IEat*> eats;
public:
    int GetPrice() override{
        int price=0;
        for (const auto& eat: eats){
            price+=eat->GetPrice();
        }
        return price;
    }
    std::string GetName()override {
        std::string name="";
        for (const auto& eat: eats){
            name+=(eat->GetName()+"\n");
        }
        return name;
    }
    void add(IEat *eat){
        eats.push_back(eat);
    }
    ~CompositeEat(){
        for (const auto& eat: eats){
            delete eat;
        }
    }
};

CompositeEat* CreateHeartyPancakesMenu(){
    CompositeEat* HeartyPancakes = new CompositeEat;
    HeartyPancakes->add(new Pancake("Morning pancake", 240.0f));
    HeartyPancakes->add(new Pancake("Lunch pancake", 280.0f));
    HeartyPancakes->add(new Pancake("Mexican pancake", 270.0f));
    return HeartyPancakes;
}

CompositeEat* CreateVegetablesPancakesMenu(){
    CompositeEat* VegetablesPancakes = new CompositeEat;
    VegetablesPancakes->add(new Pancake("Potato pancake", 210.0f));
    VegetablesPancakes->add(new Pancake("Mushroom pancake", 220.0f));
    VegetablesPancakes->add(new Pancake("Corn pancake", 270.0f));
    return VegetablesPancakes;
}

CompositeEat* CreateSweetPancakesMenu(){
    CompositeEat* SweetPancakes = new CompositeEat;
    SweetPancakes->add(new Pancake("Chocolate pancake", 260.0f));
    SweetPancakes->add(new Pancake("Banana pancake", 260.0f));
    SweetPancakes->add(new Pancake("Jam pancake", 190.0f));
    return SweetPancakes;
}
CompositeEat* CreateIcecreamMenu(){
    CompositeEat* Icecreams = new CompositeEat;
    Icecreams->add(new IceCream("Banana Split", 260));
    Icecreams->add(new IceCream("Berry ice cream", 260));
    Icecreams->add(new IceCream("Hot Brauni", 310));
    Icecreams->add(new IceCream("Tutti Fruity", 240));
    Icecreams->add(new IceCream("Vanilla ice cream", 180));
    Icecreams->add(new IceCream("Pistachio ice cream", 230));
    return Icecreams;
}
CompositeEat* CreateBeverageMenu(){
    CompositeEat* Beverages = new CompositeEat;
    Beverages->add(new Beverage("Pepsi", 120));
    Beverages->add(new Beverage("Coffee", 80));
    Beverages->add(new Beverage("Tea", 50));
    return Beverages;
}

CompositeEat* CreateBusinessLunchMenu(){
    CompositeEat* BusinessLunch = new CompositeEat;
    BusinessLunch->add(new Pancake("Lunch pancake", 280.0f));
    BusinessLunch->add(new IceCream("Vanilla ice cream", 180));
    BusinessLunch->add(new Beverage("Coffee", 80));
    return BusinessLunch;
}
