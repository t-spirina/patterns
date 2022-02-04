#include <vector>
#include "fabric_method.h"
#include "builder.h"
#include "brige.h"
int main()
{
    //---------------------- fabric_method -------
    std::cout<<"fabric_method:"<<std::endl;
    std::vector<Pizza*> order;
    PizzaFactory* cheesePizzaFactory = new CheesePizzaFactory;
    PizzaFactory* pepperoniPizzaFactory = new PepperoniPizzaFactory;
    PizzaFactory* greekPizzaFactory = new GreekPizzaFactory;
    order.push_back(pepperoniPizzaFactory->createPizza());
    order.push_back(greekPizzaFactory->createPizza());
    order.push_back(cheesePizzaFactory->createPizza());
    for(const auto& pizza: order){
       pizza->prepare();
    }
    std::cout<<std::endl;

    //---------------------- builder-------
    std::cout<<"builder:"<<std::endl;
    FirstDaySchedule firstDaySchedule;
    DayConstructer dayMaker;
    Day* firstDay = firstDaySchedule.createDaySchedule(dayMaker);
    firstDay->eventInfo();
    std::cout<<std::endl;

    //------------------ brige -------------
    std::cout<<"brige:"<<std::endl;
    Rectangle* r=new Rectangle((new DrawWithBrush),1.0);
    r->draw();
    return 0;
}
