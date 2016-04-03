//
//  LaborNine.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborNine.hpp"



LaborNine::LaborNine() {
    currStage = L9_Intro1;
}

GameOutput LaborNine::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborNine::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L9_Intro1:
            //
            break;
        case L9_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborNine::transitionToNextModule() {
    return this->nextModule;
}
