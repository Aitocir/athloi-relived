//
//  LaborNine.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborNine_hpp
#define LaborNine_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborNine : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L9Stage {
        L9_Intro1,
        L9_Intro2,
        L9_Convo1
    }L9Stage;
    
    L9Stage currStage;
    
public:
    LaborNine();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborNine_hpp */
