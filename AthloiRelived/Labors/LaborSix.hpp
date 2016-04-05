//
//  LaborSix.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborSix_hpp
#define LaborSix_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborSix : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L6Stage {
        L6_Intro1,
        L6_Intro2,
        L6_Convo1
    }L6Stage;
    
    L6Stage currStage;
    int laborM;
    int laborS;
    int laborC;
    int laborH;
    
public:
    LaborSix();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborSix_hpp */
