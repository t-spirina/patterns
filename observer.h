#pragma once
#include <iostream>
#include <vector>

class ICitizen{ //iobserver

public:
    virtual ~ICitizen(){}
    virtual void listen (int, std::string)   = 0; //update
};

class Isubject{
public:
    virtual ~Isubject(){}
    virtual void add(ICitizen* citizen)=0;
    virtual void detach(ICitizen *citizen)=0;
    virtual void makeAnnouncement()=0;
    //virtual void makeAnnouncement(std::string)=0;
};

class Herald:public Isubject{ //Isubject
private:
    int voicePower;
    std::string announcement;
    std::vector <ICitizen*> citizens;
public:
    Herald(){ voicePower=10; announcement="Hello";}
    void add(ICitizen *citizen) override {
        citizens.push_back(citizen);
    }
    void detach(ICitizen *citizen) override{
        for (auto it=citizens.begin();it!=citizens.end();++it)
        {
            if(*it==citizen)
                citizens.erase(it);
        }
    }
    void goOut(){for (auto it=citizens.begin();it!=citizens.end();++it)
        {
            citizens.erase(it);
        }
    }
    int getVoicePower(){return voicePower;}
    std::string getAnnouncement(){return announcement;}
    void setVoicePower(int Power){voicePower = Power;  }
    void setAnnouncement(std::string Announcement){announcement=Announcement; }
    void makeAnnouncement()override{
        voicePower = getVoicePower();
        announcement = getAnnouncement();
        for(const auto citizen: citizens){
            citizen->listen(voicePower,announcement);
        }
    }
};



class Doctor: public ICitizen {
private:
    int hearingPower = 100;
    Herald &herald;
public:
    Doctor(Herald &_herald): herald(_herald){
        this->herald.add(this);
    }
    ~Doctor(){this->herald.detach(this);}
    void listen(int voicePower, std::string announcement)override {
        if (hearingPower >= voicePower)
            std::cout<<"Doctor - "<<announcement<<std::endl;
    }
};


class Blacksmith: public ICitizen {
private:
    int hearingPower = 50;
    Herald &herald;
public:

    Blacksmith(Herald &_herald): herald(_herald){
        this->herald.add(this);
    }
    ~Blacksmith()override {this->herald.detach(this);}

    void listen(int voicePower, std::string announcement )override {
        if (hearingPower >= voicePower)
            std::cout<<"Blacksmith - "<<announcement<<std::endl;
    }
};

class Child: public ICitizen {
private:
    int hearingPower = 30;
    Herald &herald;
public:
    Child(Herald &_herald): herald(_herald){
        this->herald.add(this);
    }
    ~Child(){this->herald.detach(this);}
    void listen(int voicePower, std::string announcement)override {
        if (hearingPower >= voicePower)
            std::cout<<"Child - "<<announcement<<std::endl;
    }
};

/*
class CityRumors: public ICitizen, Herald{
private:
    Herald* herald;
    int hearingPower=0;
public:
    CityRumors(Herald *herald): herald(herald){
        herald->add(this);
    }
    void SetHearingPower(int hearingPower){hearingPower=hearingPower;}
    void listen(int voicePower, std::string announcement )override {
        if (hearingPower >= voicePower)
            std::cout<<announcement<<std::endl;
    }

};
*/
