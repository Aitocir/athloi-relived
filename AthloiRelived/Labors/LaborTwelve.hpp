//
//  LaborTwelve.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborTwelve_hpp
#define LaborTwelve_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborTwelve : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L12Stage {
        L12_Intro1,
        L12_Intro2,
        L12_Convo1
    }L12Stage;
    
    L12Stage currStage;
    
public:
    LaborTwelve();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborTwelve_hpp */
