//
//  LaborFour.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborFour.hpp"



LaborFour::LaborFour() {
    currStage = L4_Intro1;
}

GameOutput LaborFour::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborFour::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L4_Intro1:
            //
            break;
        case L4_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborFour::transitionToNextModule() {
    return this->nextModule;
}
