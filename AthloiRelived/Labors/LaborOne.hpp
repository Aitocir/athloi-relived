//
//  LaborOne.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborOne_hpp
#define LaborOne_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborOne : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L1Stage {
        L1_Intro1,
        L1_Intro2,
        L1_Convo1
    }L1Stage;
    
    L1Stage currStage;
    
    GameOutput handleIntro1(std::string input);
    
public:
    LaborOne();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborOne_hpp */
