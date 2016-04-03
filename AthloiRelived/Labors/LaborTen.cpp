//
//  LaborTen.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborTen.hpp"



LaborTen::LaborTen() {
    currStage = L10_Intro1;
}

GameOutput LaborTen::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborTen::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L10_Intro1:
            //
            break;
        case L10_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborTen::transitionToNextModule() {
    return this->nextModule;
}
