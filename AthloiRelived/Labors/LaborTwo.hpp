//
//  LaborTwo.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborTwo_hpp
#define LaborTwo_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborTwo : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L2Stage {
        L2_Intro1,
        L2_Intro2,
        L2_Convo1
    }L2Stage;
    
    L2Stage currStage;
    int laborM;
    int laborS;
    int laborC;
    int laborH;
    
    GameOutput handleIntro1(std::string input);
    
public:
    LaborTwo();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborTwo_hpp */
