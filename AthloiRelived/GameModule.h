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
    NewModule
}GameSignal;

struct GameOutput {
    GameSignal signal;
    std::string text;
};

class GameModule {
    
    // Functions
    GameOutput getOutputForInput(std::string input);
    GameModule transitionToNextModule();
};

#endif /* GameModule_h */
