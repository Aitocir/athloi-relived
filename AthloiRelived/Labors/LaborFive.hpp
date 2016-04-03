//
//  LaborFive.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborFive_hpp
#define LaborFive_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborFive : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L5Stage {
        L5_Intro1,
        L5_Intro2,
        L5_Convo1
    }L5Stage;
    
    L5Stage currStage;
    
public:
    LaborFive();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborFive_hpp */
