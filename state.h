#pragma once
#include <iostream>

class StateContext;

class State
{
private:
    std::string name;

public:
    State (const std::string& name): name(name){}
    const std::string& getName(){return name;}
    virtual void next(StateContext*) = 0;
    virtual void prev(StateContext*) = 0;
};

class StateContext{
private:
    State* state;
public:
    StateContext(State *state): state(state){}
    void next() {state->next(this);}
    void prev() {state->prev(this);}
    void SetState(State *newState){
        delete state;
        state = newState;
    }
    State* GetState(){ return state;}
    virtual ~StateContext(){delete state;}
};

class Start: public State
{
   public:
    Start():State("Start"){}
    void next(StateContext* state) override;
    void prev(StateContext* state) override;
};
class PutMoney: public State
{
public:
    PutMoney():State("PutMoney"){}
    void next(StateContext* state) override;
    void prev(StateContext* state) override;
    int money = 10;
};

class PushTheButton: public State
{
    public:
    PushTheButton():State("Push the button"){}
    void next(StateContext* state ) override;
    void prev(StateContext* state) override;
    int coffee = 2;
};

class TakeCoffee: public State
{
    public:
    TakeCoffee():State("Take Coffee"){}
    void next(StateContext*) override;
    void prev(StateContext*) override;
};

void Start::next(StateContext* state){
    std::cout<<"Внесите деньги"<<std::endl;
    state->SetState(new PutMoney);

}
void Start::prev(StateContext*){
    std::cout<<"This is start "<<std::endl;
}


void PutMoney::next(StateContext*state){
    if(money<5)
    {
        std::cout<<"недостаточно денег"<<std::endl;
        state->SetState(new Start);
    }
    else
    {
     std::cout<<"оплата приянта, нажмите кнопку"<<std::endl;
     state->SetState(new PushTheButton);
    }
}
void PutMoney::prev(StateContext* state){
    state->SetState(new Start);
}

void PushTheButton::next(StateContext* state){
    if(coffee>0){
        std::cout<<"Варим кофе"<<std::endl;
        state->SetState(new TakeCoffee);
        coffee--;
    }
    else
    {
        state->SetState(new Start);
        std::cout<<"Возврат денег "<<std::endl;
    }
}
void PushTheButton::prev(StateContext* state){
    state->SetState(new PutMoney);
}

void TakeCoffee::next(StateContext* state){
    std::cout<<"Cпасибо за визит "<<std::endl;
}
void TakeCoffee::prev(StateContext* state){
    state->SetState(new PushTheButton);
}


