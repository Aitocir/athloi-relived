//
//  LaborOne.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborOne.hpp"

#define L1TEXT_INTRO1 "Labor 1 introduction\n"\
"some more text"\
"blah blah blah"

//
// Private functions
//

GameOutput LaborOne::handleIntro1(std::string input) {
    // intro has no invalid input
    GameOutput o;
    o.signal = Replace;
    o.text = L1TEXT_INTRO1;
    this->currStage = L1_Intro2;
    return o;
}

//
// Public functions
//

LaborOne::LaborOne() {
    this->currStage = L1_Intro1;
}

GameOutput LaborOne::getOutputForStartOfModule() {
    // TODO: return introduction to the First Labor
    GameOutput o;
    o.signal = Replace;
    o.text = L1TEXT_INTRO1;
    return o;
}

GameOutput LaborOne::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (this->currStage) {
        case L1_Intro1:
            return this->handleIntro1(input);
        case L1_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborOne::transitionToNextModule() {
    return this->nextModule;
}
