//
//  LaborEleven.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborEleven_hpp
#define LaborEleven_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborEleven : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L11Stage {
        L11_Intro1,
        L11_Intro2,
        L11_Convo1
    }L11Stage;
    
    L11Stage currStage;
    int laborM;
    int laborS;
    int laborC;
    int laborH;
    
public:
    LaborEleven();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborEleven_hpp */
