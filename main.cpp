#include <iostream>
#include "composite.h"
#include "mediator.h"
#include "template.h"
int main()
{

    std::cout<<"------- composite -----------"<<std::endl;
    CompositeEat* BusinessLunch = CreateBusinessLunchMenu();
    std::cout<<"Business Lunch menu: \n"<<BusinessLunch->GetName()<<std::endl;
    std::cout<<"Price: "<<BusinessLunch->GetPrice()<<std::endl;

    std::cout<<std::endl<<"------- mediator -----------"<<std::endl;
    Calendar* calendar = new Calendar(3);
    Gadget* alarm = new Alarm(calendar);
    Gadget* coffee = new Coffee(calendar);
    Gadget* teapot = new TeaPot(calendar);

    calendar->add(alarm);
    calendar->add(coffee);
    calendar->add(teapot);
    calendar->StartDay();

    delete calendar;

    std::cout<<std::endl<<"------- template -----------"<<std::endl;
    BitmapImage* bmp = new BitmapImage();
    VectorImage* vmp = new VectorImage();
    bmp->DrawFromFile("file1");
    vmp->DrawFromFile("file2");
    return 0;
}
