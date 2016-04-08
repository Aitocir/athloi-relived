//
//  LaborTwo.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "LaborTwo.hpp"

#define L2TEXT_INTRO1 "[Herald] \"Heracles, slayer of the Lion, I come bearing a message from King Eurystheus,\" began a nervous-looking aide from the King's court.\n\n"\
"[Heracles] \"Yes, let's pretend like neither of us saw the King soil himself ten minutes ago and banish me to the town gate,\" you reply "\
"dryly. You talk over the young aide's visible protest about to form. \"What is this labor my cousin has prepared for me?\"\n\n"\
"[Herald] \"Sir, the King has requested you slay the Hydra, a terrible demon torturing the people. It dwells in a cave near Lake Lerna. We wish you the best on your journey.\"\n\n"\
"[Heracles] \"And there's nothing else you can tell me of this demon, Herald?\"\n\n"\
"\tThe herald shook his head emphatically at first, but froze when your blank stare didn't break.\n\n"\
"[Herald] \"Well, sir, to speak of a truth, I overheard a priestess of Hera say the Hydra was her very own creation. Even with the miracle of your encounter with the Lion, I don't think you shall prevail this time,\" the young man whispered almost fearfully.\n\n"\
"[Heracles] \"We shall see. I shall see you soon, Herald,\" and with a confident pose, you turn to venture forth on your Second Labor.\n\n"\
"<Hit Enter to begin Second Labor>"

#define L2TEXT_INTRO2 "After much journeying, you approach Lake Lerna, and catch sight of the dreaded cave wherein the Hydra is rumored to be hiding. Under the darkness of night, with a partial moon to show the cave, you prepare for battle. You stick your torch into a nearby tree, and draw your bow, lighting an arrow on your torch. With the purpose befitting a hero, you arch, then let loose your glowing arrow, arching like Helios through the sky toward the cave to summon your enemy.\n\n"\
"As it travels, you briefly see a much smaller but still formidable enemy scuttling, a crab of immense proportions. As the arrow passes and strikes the cave entrance, you hear it coming toward you. Knowing the Hydra will come looking for your blood at any moment, how will you respond to this new threat?\n\n"\
"\t[A] Draw your mighty club and rein heroic glory down on the sea monster\n"\
"\t[B] Pick up your torch for greater illumination\n"\
"\t[C] Draw another arrow, and hope you can find a gap in the monster's shell\n\n"\
""


GameOutput LaborTwo::handleIntro1(std::string input) {
    GameOutput o;
    o.signal = Replace;
    o.text = L2TEXT_INTRO1;
    return o;
}




LaborTwo::LaborTwo() {
    currStage = L2_Intro1;
}

GameOutput LaborTwo::getOutputForStartOfModule() {
    GameOutput o;
    o.signal = Replace;
    o.text = L2TEXT_INTRO1;
    return o;
}

GameOutput LaborTwo::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (currStage) {
        case L2_Intro1:
            return this->handleIntro1(input);
            break;
        case L2_Intro2:
            //
            break;
        default:
            break;
    }
    
    return o;
}

GameModule* LaborTwo::transitionToNextModule() {
    return this->nextModule;
}
