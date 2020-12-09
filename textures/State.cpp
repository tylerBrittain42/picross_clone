#include "State.h"
#include <iostream>






State::State(){

    currState = true;


}

void State::changeState(bool currState){
    //std::cout << "triggered" << std::endl;
    this->currState = currState;
}


bool State::isCurrState() const{

    return(currState);

}

State::~State(){

}

