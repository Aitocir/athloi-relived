//
//  LaborFour.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborFour_hpp
#define LaborFour_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborFour : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L4Stage {
        L4_Intro1,
        L4_Intro2,
        L4_Convo1
    }L4Stage;
    
    L4Stage currStage;
    
public:
    LaborFour();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborFour_hpp */
