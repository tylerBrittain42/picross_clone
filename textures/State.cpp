#include "State.h"
#include <iostream>



bool endState;



State::State(){

    endState = false;
    std::cout << endState << std::endl;

}

void State::TriggerEndState(){
    //std::cout << "triggered" << std::endl;
    endState = true;

}


bool State::isEndState() const{

    return(endState);

}

State::~State(){

}

