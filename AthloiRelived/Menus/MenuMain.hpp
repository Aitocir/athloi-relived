//
//  MenuMain.hpp
//  AthloiRelived
//
//  Created by Aitocir on 3/28/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef MenuMain_hpp
#define MenuMain_hpp

#include <stdio.h>
#include <string>
#include "GameModule.h"

#define MENUMAIN_FORMATBODY "************************************************************************\n"\
"************************************************************************\n"\
"*************************   Athloi  Relived   **************************\n"\
"************************************************************************\n"\
"************************************************************************\n"\
"\n"\
"\t[%c] %s\n"\
"\t[S] Settings\n"\
"\t[A] Achievements\n"\
"\t[Q] Quit\n"\
"\n"\
"\n"\
"\n\t"

class MenuMain : public GameModule {
    
private:
    GameModule* nextModule;
    GameModule* moduleForLaborNumber(int labor);
    
public:
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* MenuMain_hpp */
