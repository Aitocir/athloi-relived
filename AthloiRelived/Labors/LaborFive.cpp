//
//  LaborFive.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborFive.hpp"



LaborFive::LaborFive() {
    currStage = L5_Intro1;
}

GameOutput LaborFive::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborFive::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L5_Intro1:
            //
            break;
        case L5_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborFive::transitionToNextModule() {
    return this->nextModule;
}
