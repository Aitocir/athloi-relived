//
//  LaborTwo.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborTwo.hpp"



GameOutput LaborTwo::handleIntro1(std::string input) {
    GameOutput o;
    o.signal = Replace;
    o.text = "AND THIS IS WHERE I STOPPPED\n";
    return o;
}




LaborTwo::LaborTwo() {
    currStage = L2_Intro1;
}

GameOutput LaborTwo::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborTwo::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L2_Intro1:
            return this->handleIntro1(input);
            break;
        case L2_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborTwo::transitionToNextModule() {
    return this->nextModule;
}
