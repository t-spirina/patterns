#include <iostream>
#include "state.h"
#include "prototype.h"
#include <vector>


int main()
{
    std::vector<Prototype*> Monsters;
    Monsters.push_back(new Monster(10,5,2,"type1"));
    Monsters.push_back((Monsters[0])->Clone() );
    std::cout<< Monsters[0]->getType() << "  "<< Monsters[1]->getType() <<std::endl;

    StateContext* pCoffeeMashine = new StateContext(new Start());
        if (pCoffeeMashine != nullptr)
        {
            pCoffeeMashine->next();
            pCoffeeMashine->next();
            pCoffeeMashine->next();
            pCoffeeMashine->next();
            delete pCoffeeMashine;
        }
    return 0;
}
