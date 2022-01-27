#include <iostream>
#include "pizzafactory.h"
#include "command.h"
#include "decorator.h"
int main()
{
   Visitor visitor;

   BakePepperoniPizza peperoniBakery;
   BakeGreekPizza greekBakery;
   BakeCheesePizza cheeseBakery;

   visitor.addPizza(peperoniBakery);
   visitor.addPizza(cheeseBakery);
   visitor.addPizza(greekBakery);

   visitor.getOrderInfo();



   LightPlayer lightPlayer;
   lightPlayer.Add(Colors::BLUE);
   lightPlayer.Add(Colors::VIOLET);
   lightPlayer.Add(Colors::ORANGE);
   lightPlayer.Undo();

   Espresso es1;
   AddMilk em(&es1);
   NoSugar mse(&em);
   std::cout<<mse.getDescription()<<std::endl;
   std::cout<<es1.cost()<<" +milk  "<<em.cost()<<" -sugar "<<mse.cost()<<std::endl;
    return 0;
}
