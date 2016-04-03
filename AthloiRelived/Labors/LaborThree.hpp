//
//  LaborThree.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborThree_hpp
#define LaborThree_hpp

#include <stdio.h>
#include "GameModule.h"

class LaborThree : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L3Stage {
        L3_Intro1,
        L3_Intro2,
        L3_Convo1
    }L3Stage;
    
    L3Stage currStage;
    
public:
    LaborThree();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborThree_hpp */
