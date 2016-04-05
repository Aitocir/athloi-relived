//
//  LaborTen.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborTen_hpp
#define LaborTen_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborTen : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L10Stage {
        L10_Intro1,
        L10_Intro2,
        L10_Convo1
    }L10Stage;
    
    L10Stage currStage;
    int laborM;
    int laborS;
    int laborC;
    int laborH;
    
public:
    LaborTen();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborTen_hpp */
