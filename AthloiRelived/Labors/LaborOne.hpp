//
//  LaborOne.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef LaborOne_hpp
#define LaborOne_hpp

#include <stdio.h>
#include "GameModule.h"
#include "AthloiDAO.hpp"

class LaborOne : public GameModule {
    
private:
    GameModule* nextModule;
    typedef enum L1Stage {
        L1_Intro1, // intro to the game
        L1_Intro2, // intro to Labor 1
        L1_Convo1, // convo with little boy, 0/1 HUMILITY
        L1_Convo2, // end of convo
        L1_Search, // probability searching for Lion cave
        L1_Found,  // found Lion, discover fur is impervious to arrows
        L1_Wrestle,// chose to melee, MIGHT
        L1_Shoot,  // chose to shoot, SKILL
        L1_WrapUp
    }L1Stage;
    
    L1Stage currStage;
    float lionFindProbability;
    int laborM;
    int laborS;
    int laborC;
    int laborH;
    
    GameOutput handleIntro1(std::string input);
    GameOutput handleIntro2(std::string input);
    GameOutput handleConvo1(std::string input);
    GameOutput handleConvo2(std::string input);
    GameOutput handleSearch(std::string input);
    GameOutput handleFound(std::string input);
    GameOutput handleShoot(std::string input);
    GameOutput handleWrestle(std::string input);
    GameOutput handleWrapup(std::string input);
    
public:
    LaborOne();
    GameOutput getOutputForStartOfModule();
    GameOutput getOutputForInput(std::string input);
    GameModule* transitionToNextModule();
};

#endif /* LaborOne_hpp */
