//
//  LaborEight.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborEight.hpp"



LaborEight::LaborEight() {
    currStage = L8_Intro1;
}

GameOutput LaborEight::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborEight::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L8_Intro1:
            //
            break;
        case L8_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborEight::transitionToNextModule() {
    return this->nextModule;
}
