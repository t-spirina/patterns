#pragma once
#include <iostream>
#include <vector>
class MenuItem;
class Ingredient;

class Visitor{
  public:
    virtual void visit(MenuItem* b)=0;
    virtual void visit(Ingredient* b)=0;
};
class Menu{
public:
    virtual void accsept(class Visitor* v)=0;
    virtual void getState()=0;
};
class MenuItem: public Menu{
  private:
    std::string name;
    std::string description;
    float price;
    std::vector<Ingredient*> ingredients;
public:
    MenuItem(const std::string &name, const std::string &description, float price):
        name(name),description(description),price(price){}
    MenuItem():name(""),description(""),price(0.0){}
    const std::string &getName() const{return name;}
    const std::string &getDescription() const {return description;}
    float getPrice() const { return price; }
    void add(Ingredient* ingredient){
        ingredients.push_back(ingredient);
    }
    void accsept(Visitor* v)override {v->visit(this);}
    void getState() override;

};
class Ingredient:public MenuItem{
private:
    std::string Name;
    int HealthRating;
    float Calories;
    float Protein;
    float Carbs;
    float Fats;
public:
     void SetInfo(std::string name, int healthRating=0,float calories=0.0, float protein=0.0, float carbs=0.0, float fats=0.0)
     {
        Name = name;
        HealthRating=healthRating;
        Calories=calories;
        Protein=protein;
        Carbs=carbs;
        Fats=fats;
     }
     void getState() override{
        std::cout<<"name= "<<Name<<":\n healthRating= "<<
                               HealthRating<<" calories="<<Calories<<" Protein="<<
                               Protein<<" Carbs="<<Carbs<<" Fats="<<Fats<<std::endl;
     }
    void accsept(Visitor* v)override {v->visit(this);}
    int getHealthRating() {return HealthRating;}
    float getCalories() {return Calories;}
    float getProtein() {return Protein;}
    float getCarbs() {return Carbs;}
    float getFats() {return Fats;}
};
void MenuItem::getState() {
    int HealthRating=0;
    float Calories=0;
    float Protein=0;
    float Carbs=0;
    float Fats=0;
    std::cout<<"name= "<<name<<":"<<std::endl;
    for (Ingredient* it: ingredients){
       it->getState();
       Calories+=it->getCalories();
       Protein+=it->getProtein();
       Carbs+=it->getCarbs();
       Fats+=it->getFats();
       HealthRating+=it->getHealthRating();
   }
    std::cout<<"Sumary: \n healthRating= "<<
                           HealthRating<<" calories="<<Calories<<" Protein="<<
                           Protein<<" Carbs="<<Carbs<<" Fats="<<Fats<<std::endl;
}


class MenuInfo: public Visitor{
public:
    void visit(MenuItem* mi) override{mi->getState();}
    void visit(Ingredient* ing) override {ing->getState();}
};
