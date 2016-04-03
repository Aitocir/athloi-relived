//
//  LaborTwelve.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborTwelve.hpp"



LaborTwelve::LaborTwelve() {
    currStage = L12_Intro1;
}

GameOutput LaborTwelve::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = "";
    return o;
}

GameOutput LaborTwelve::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L12_Intro1:
            //
            break;
        case L12_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborTwelve::transitionToNextModule() {
    return this->nextModule;
}
