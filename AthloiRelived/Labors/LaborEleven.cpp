//
//  LaborEleven.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborEleven.hpp"



LaborEleven::LaborEleven() {
    currStage = L11_Intro1;
}

GameOutput LaborEleven::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborEleven::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L11_Intro1:
            //
            break;
        case L11_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborEleven::transitionToNextModule() {
    return this->nextModule;
}
