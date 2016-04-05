//
//  GameModule.h
//  AthloiRelived
//
//  Created by Aitocir on 3/28/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef GameModule_h
#define GameModule_h
#include <stdlib.h>
#include <string>

typedef enum GameSignal {
    Quit,
    Append,
    Replace,
    NewModule,
    InvalidInput
}GameSignal;

struct GameOutput {
    GameSignal signal;
    std::string text;
};

class GameModule {
    
public:
    // Functions
    virtual GameOutput getOutputForStartOfModule() = 0;
    virtual GameOutput getOutputForInput(std::string input) = 0;
    virtual GameModule* transitionToNextModule() = 0;
};

#endif /* GameModule_h */
