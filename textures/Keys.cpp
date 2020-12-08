
//Keys is just to store the possible puzzle combinations
struct Keys
{
  
    //Original
    char keyOne [5][5] = {{'e','c','e','c','c'},
                          {'c','c','e','c','e'},
                          {'e','b','e','e','e'},
                          {'c','e','e','e','c'}, 
                          {'e','c','c','c','e'}};

    //Skull
    char keyTwo [5][5] =   {{'e','c','c','c','e'},
                            {'c','c','c','c','c'},
                            {'c','e','c','e','c'},
                            {'c','c','c','c','c'}, 
                            {'e','c','e','c','e'}};

    //Castle             
    char keyThree [5][5] =   {{'c','e','c','e','c'},
                            {'c','c','c','c','c'},
                            {'e','c','c','c','e'},
                            {'e','c','e','c','e'}, 
                            {'e','c','c','c','e'}};

    //Cross
    char keyFour [5][5] =   {{'e','c','c','c','e'},
                            {'c','c','e','c','c'},
                            {'c','e','e','e','c'},
                            {'c','c','e','c','c'}, 
                            {'e','c','c','c','e'}};


};