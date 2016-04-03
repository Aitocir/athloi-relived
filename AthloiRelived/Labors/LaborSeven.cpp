//
//  LaborSeven.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborSeven.hpp"



LaborSeven::LaborSeven() {
    currStage = L7_Intro1;
}

GameOutput LaborSeven::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborSeven::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L7_Intro1:
            //
            break;
        case L7_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborSeven::transitionToNextModule() {
    return this->nextModule;
}
