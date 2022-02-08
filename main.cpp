#include <iostream>
#include "facade.h"
#include "visitor.h"
#include "observer.h"

int main()
{

  std::cout<<"------ facade -----"<<std::endl;
  FacadeForMediaPlayer mp;
  mp.OnAndPlay("1 film");
  mp.ChangeMovie("2 film");
  mp.Off();

  std::cout<<"------ observer -----"<<std::endl;
  Herald* hrld = new Herald;
  Doctor* doc = new Doctor(*hrld);
  Child* cld = new Child(*hrld);
  Blacksmith* blm = new Blacksmith(*hrld);
  hrld->makeAnnouncement();
  hrld->setVoicePower(50);
  hrld->setAnnouncement("first message");
  hrld->makeAnnouncement();

  std::cout<<"------ visitor -----"<<std::endl;
  Ingredient* potato = new Ingredient;
  MenuItem *boild_potato = new MenuItem("boid potato","-",5.5);
  MenuInfo *newInfo = new MenuInfo;
  boild_potato->add(potato);
  potato->SetInfo("potato",5,2.0,0,0.1,0);
  Ingredient* butter = new Ingredient;
  butter->SetInfo("butter",1,20.0,10,0.1,10);
  boild_potato->add(butter);
  newInfo->visit(boild_potato);
  //newInfo->visit(potato);
  return 0;
}
