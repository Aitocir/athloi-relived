//
//  LaborSeven.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborSeven_hpp
#define LaborSeven_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborSeven : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L7Stage {
        L7_Intro1,
        L7_Intro2,
        L7_Convo1
    }L7Stage;
    
    L7Stage currStage;
    
public:
    LaborSeven();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborSeven_hpp */
