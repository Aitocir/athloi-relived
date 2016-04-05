//
//  LaborEight.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborEight_hpp
#define LaborEight_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborEight : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L8Stage {
        L8_Intro1,
        L8_Intro2,
        L8_Convo1
    }L8Stage;
    
    L8Stage currStage;
    int laborM;
    int laborS;
    int laborC;
    int laborH;
    
public:
    LaborEight();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborEight_hpp */
