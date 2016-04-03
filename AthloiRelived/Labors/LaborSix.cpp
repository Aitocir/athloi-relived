//
//  LaborSix.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborSix.hpp"



LaborSix::LaborSix() {
    currStage = L6_Intro1;
}

GameOutput LaborSix::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborSix::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L6_Intro1:
            //
            break;
        case L6_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborSix::transitionToNextModule() {
    return this->nextModule;
}
