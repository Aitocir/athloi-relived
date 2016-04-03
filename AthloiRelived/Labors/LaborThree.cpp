//
//  LaborThree.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborThree.hpp"



LaborThree::LaborThree() {
    currStage = L3_Intro1;
}

GameOutput LaborThree::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborThree::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L3_Intro1:
            //
            break;
        case L3_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborThree::transitionToNextModule() {
    return this->nextModule;
}
