#pragma once

class State{

private:
    
    bool currState;

public:
    
    State();

    virtual void changeState(bool currState);

    virtual bool isCurrState() const;

    ~State();

};