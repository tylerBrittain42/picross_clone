#pragma once

class State{

private:
    
    bool endState;

public:
    
    State();

    virtual void TriggerEndState();

    virtual bool isEndState() const;

    ~State();

};