//
//  LaborOne.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include <time.h>
#include "LaborOne.hpp"
#include "LaborTwo.hpp"
#include "AthloiDAO.hpp"

#define L1TEXT_INTRO0 "I, Heracles, find myself consulting Pythia, the Oracle of Delphi. I am in need of atonement "\
"following my purifaction by King Thespius. Even writing about this bring the terrors back from "\
"... from... what I did. Ok, you know what, that physician is full if it, writing about this isn't helping. Who talks "\
"about themselves this way, anyway? Screw this journal.\n\n"\
"\t--Heracles' one and only journal entry\n\n"\
"\t<Hit Enter to Continue>"

#define L1TEXT_INTRO1 "[Pythia] Heracles, your willingness to atone for your sins is admirable. To complete your healing, I recommend "\
"you go to your cousin, Eurystheus, King at Tiryns. He will assign you --\n\n"\
"[Heracles] Eurystheus?!\n\n"\
"\tEvery head in the room swings toward you, the rage and shock palpable.\n\n"\
"[Pythia] ...the labors required to complete your healing, and allow you to "\
"achieve the immortality for which you are destined. Do you defy the will of the gods, Heracles?\n\n"\
"\tWith all eyes on you, you swallow everthing else you want to say.\n\n"\
"[Heracles] No. I serve my father Zeus with all willingness.\n\n"\
"[Pythia] Excellent. Go forth, and do well.\n\n"\
"With bitterness in your every step, you leave the Oracle, but not before dropping coins into the offering jar being "\
"hinted to by the only man in the room larger than yourself. You make your way to Tiryns, where you meet with your cousin King Eurystheus.\n\n"\
"\t<Hit Enter to Continue>"


#define L1TEXT_INTRO2 "[King Eurystheus] \"Well. It's Heracles. Am I next?\" he said with a straight face.\n\n"\
"[Heracles] \"Your disrespect borders on hubris, cousin,\" you retort, spitting on the floor.\n\n"\
"[King Eurystheus] \"Hubris? For doubting the honor of a family-killer? Methinks you are the one guilty of such a sin, cousin.\"\n\n"\
"\tYou and King Eurystheus stare at each other for several seconds.\n\n"\
"[King Eurystheus] \"Well, the choice is yours I suppose: would you like your restoration or not?\"\n\n"\
"\tYou stare at him awhile longer, the weight of principle versus pride heavy on your soul.\n\n"\
"[Heracles] What labor do you require of me?\n\n"\
"[King Eurystheus] \"You shall perform ten Labors, Heracles. The first is to slay the Lion near Nemea. It's been terrorizing the locals, killing "\
"innocent people... Don't befriend it on common ground, Heracles, that won't count.\"\n\n"\
"\tYou reflexively make a fist, but keep yourself under control. King Eurystheus flinches, and his crown falls off his head.\n\n"\
"[King Eurystheus] \"You have your assignment, Heracles!\"\n\n"\
"\tWithout another word, you make your way toward Nemea, leaving King Eurystheus to simultaneously pick up his crown and maintain composure.\n\n"\
"\t<Hit Enter to Continue>"

#define L1TEXT_CONVO1 "After some travel, you find yourself at Cleonae. After replentishing your supplies and reluctantly declining not a few \n"\
"offers of companionship, you make your way out of town in the general direction of the terror the citizens described so fearfully.\n\n"\
"You only make it about a stone's throw outside of twon before you run into a little boy. He looks afraid.\n\n"\
"[Boy] \"Sir! Why are you off the road?! There's a dangerous lion out here!\"\n\n"\
"[Heracles] \"My name is Heracles, and I have come to slay the Lion for you.\"\n\n"\
"\tThe boy's eyes got incredibly wide, and all signs of panic left his voice.\n\n"\
"[Boy] No way!!!! You are so cool! Listen, sir,\" the boy whispered conspiratorially. \"While sneaking out to pick some berries, I actually saw "\
"its prints. No really!\" he added defensively. \"Maybe I could show them to you? I may not be a big hero like you, but I know I can help. And "\
"I really want to, because if you can't kill it, I'm not sure anybody can.\"\n\n"\
"\t============================== Your Response ==============================\n"\
"\t[A] \"A hero always needs a sidekick, kid. Where should I go?\"\n"\
"\t[B] \"My abilities far exceed yours, young one. Go home to your family.\"\n"

#define L1TEXT_CONVO2A "[Boy] \"This is great, thank you so much! I was planning on sacrificing myself this coming month.\" Tears began to well "\
"in his eyes. \"The lion took my sister, and my dad hasn't talked to me since she was taken. I wouldn't want anyone else in the world feeling "\
"the way I feel every night.\n\n"\
"You kneel down and hug the now crying boy for a moment before he leaps up and excitedly leads to down an easy-to-miss path to the west. It "\
"wasn't long before very large lion tracks came into view. The boy hesitated, and pointed down a game trail.\n\n"\
"[Boy] \"I think I've seen him down there before. I hope this helped, Mr. Heracles.\"\n\n"\
"[Heracles] \"A great deal, my young soldier. Go home, and prepare a celebration. Your sister and every other victim will be avenged tonight, "\
"you have my word.\"\n\n"\
"The boy sprinted off back toward Cleonae. You laugh to yourself, shaking your head. So hopeful. So young. You turn back to look at the massive "\
"animal tracks, and begin the hunt.\n\n"\
"\tHail Hero! You have increased your Humility!!!\n\n"\
"\t[A] Begin hunting\n"\
"\t[B] Cleonae sounds like way more fun\n"

#define L1TEXT_CONVO2B "[Boy] \"Yeah, you're probably right. I've never been so good at the heroics like my sister was. She was like a tiny "\
"Artemis, but taller than me I guess.\" He began to cry. \"Please kill this lion, Heracles. He took my sister away from me.\" With loud wails, "\
"he ran back toward Nemea without looking back.\n\n"\
"You shake your head in disgust. Kids shouldn't be out here for exactly this reason: so weak. You turn away from Cleonae and begin hunting for "\
"the lion.\n\n"\
"\t[A] Begin hunting\n"\
"\t[B] Cleonae sounds like way more fun\n"

#define L1TEXT_HUNTFAIL "You take another turn, and peer across the grasses. No movement there, %s.\n\n"\
"\t============================== Your Choice of Action ==============================\n"\
"\t[A] Continue hunting\n"\
"\t[B] Give up and return to Cleonae\n"

#define L1TEXT_HUNTLAME "You waste time thinking about how nice it would be back in Nemea with some dancing girls, then get back to the hunt.\n\n"\
"\t============================== Your Choice of Action ==============================\n"\
"\t[A] Continue hunting\n"\
"\t[B] Give up and return to Cleonae\n"

#define L1TEXT_HUNTOK "As you turn another corner following the tracks, you see the beast in the flesh. It is facing away from you, a perfect "\
"situation for a normal man, let alone for someone with your archery skills. You nock an arrow, pull back and release a glorious shot...\n\n"\
"...which bounces off its thigh! The Lion leaps around, and locks eyes with you. As it begins to roar and creep forward, you realize you'll "\
"need to make a quick choice if you're going to make it out of this alive.\n\n"\
"\t============================== Your Choice of Action ==============================\n"\
"\t[A] Put the bow down and rush the beast. Real men use their bare hands.\n"\
"\t[B] Nock another arrow, because impervious fur is no match for your accuracy.\n"

#define L1TEXT_WRESTLE "You throw down your bow, and with a mighty roar, rush toward the Lion. As it lunges toward you with claws outstretched, "\
"you execute a flawless high jump, barely clearing the Lion's fur. On your way to the ground, you place the Lion in a headlock. You both hit the ground with a tremendous pounding felt throughout the earth, and causing the Nemeans to tremble in fear miles away.\n\n"\
"Mustering all of your strength, you hang on as the Lion thrashes about and slowly suffocates. After several minutes, it goes limp as the breath of life ebbs from its carcass. Since nobody is present to see your lapse in heroic poise, you collapse against a nearby boulder and catch your breath.\n\n"\
"\tHail Hero! You have increased your Might!!!\n\n"\
"\t<Hit Enter to return to King Eurystheus>"

#define L1TEXT_SHOOT "You ignore the terror in your veins as the Lion rapidly closes the distance between you. With complete confidence, you draw your bow again, breathing deeply as the Lion bears down on you. Your keen eye focuses on the Lion's mouth, which hangs open in anticipation of your tasty flesh as it begins its attack leap. You release your arrow, and it flies toward the Lion...\n\n"\
"... and buries its entire length into the roof of the Lion's mouth, a tell-tale bump in the Lion's impervious fur showing the arrow trying to pierce straight through its head. The Lion falls to the ground, skidding across the dirt, coming to a stop at your feet. Placing on efoot on its head, you take advantage of the moment to strike a glorious pose, regretting the lack of a nearby artist to capture the moment.\n\n"\
"\tHail Hero! You have increased your Skill with that shot!!!\n\n"\
"\t<Hit Enter to return to King Eurystheus>"

#define L1TEXT_RETURN "Shortly after your victory, Athena appears before you. You try desperately to pretend that she didn't catch you trying in frustration to gnaw a hole in the Lion's hide so you could remove it. Athena, with a smirk on her face, suggests you use the Lion's own claws to cut the hide away from the carcass. You thank her and wait for her to leave before removing the hide and making your way back to King Eurystheus.\n\n"\
"Hundreds of cheers erupt as the twonsfolk of Cleonae spot you coming back on the road through their town with the Lion's hide across your back. You catch sight of the boy you ran into on your way in, and see tears of gratitude in his eyes. With a short layover for much-deserved rest, you return to King Eurystheus.\n\n"\
"You approach your cousin the King who is standing with his back toward you. His aides see the hide you're carrying and immediately stand more erect, and begin whispering amonst themselves.\n\n"\
"[King Eurystheus] \"And who bears the body of beloved cousin?\" he enquired, back still turned, obviously misreading the situation. \"I can't say I'm-- hounds of Hades!!!\" he almost squeaked as he finally turned and noticed the fur across your back.\n\n"\
"[Heracles] \"Do you care for it? I thought the color complimented my features nicely,\" you reply, as the women and a few men giggle to themselves. You continue to speak as the King stands speechless. \"I have completed the first of your Ten Labors, cousin. What shall be my second?\"\n\n"\
"[King Eurystheus] \"Out, sir, out! I shall send word to you for your second task.\"\n\n"\
"As you stand awkwardly wondering what the disconnect was, the King screamed once more, this time with a break in his voice making his order sound more like a plea. Out of pity as much as respect, you descend from the palace and to the gate of the city, where you are soon joined by a herald of the King.\n\n"\
"\t<Hit Enter to continue on to the Second Labor>"

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

GameOutput LaborOne::handleIntro2(std::string input) {
    // intro has no invalid input
    GameOutput o;
    o.signal = Replace;
    o.text = L1TEXT_INTRO2;
    this->currStage = L1_Convo1;
    return o;
}

GameOutput LaborOne::handleConvo1(std::string input) {
    // output conversation with young boy near Cleonae
    // pitch choices, next stage will validate and handle them
    GameOutput o;
    o.signal = Replace;
    o.text = L1TEXT_CONVO1;
    this->currStage = L1_Convo2;
    return o;
}

GameOutput LaborOne::handleConvo2(std::string input) {
    // conversation with young boy near Cleonae
    // intput should be player response
    GameOutput o;
    
    // input needs to be either A or B (accepting/declining assistance)
    if (input.length() == 1) {
        char c = tolower(input[0]);
        if (c == 'a') {
            // accepted boy's help
            this->laborH++;
            this->lionFindProbability = 0.5;
            this->currStage = L1_Search;
            o.signal = Replace;
            o.text = L1TEXT_CONVO2A;
            return o;
        }
        if (c=='b') {
            // declined boy's help
            this->currStage = L1_Search;
            o.signal = Replace;
            o.text = L1TEXT_CONVO2B;
            return o;
        }
    }
    
    // if we get here, input was invalid
    o.signal = InvalidInput;
    o.text = "";
    return o;
}

GameOutput LaborOne::handleSearch(std::string input) {
    // player can give up, kind of not really
    GameOutput o;
    
    // input needs to be either A or B (accepting/declining assistance)
    if (input.length() == 1) {
        char c = tolower(input[0]);
        if (c == 'a') {
            // continue hunting
            srand((int)time(NULL));
            int attempt = rand() % 100;
            if (attempt < (this->lionFindProbability*100)) {
                // found the lion!
                this->currStage = L1_Found;
                o.signal = Replace;
                o.text = L1TEXT_HUNTOK;
                return o;
            }
            else {
                // didn't find it, but you're getting closer
                this->lionFindProbability += 0.05;
                this->currStage = L1_Search;
                o.signal = Append;
                o.text = L1TEXT_HUNTFAIL;
                return o;
            }
        }
        if (c=='b') {
            // go back to Nemea, kind of not really
            this->currStage = L1_Search;
            o.signal = Append;
            o.text = L1TEXT_HUNTLAME;
            return o;
        }
    }
    
    // if we get here, input was invalid
    o.signal = InvalidInput;
    o.text = "";
    return o;
}

GameOutput LaborOne::handleFound(std::string input) {
    // choose to either wrestle the lion, or shoot it in the mouth
    GameOutput o;
    
    // input needs to be either A or B (MIGHT or SKILL solution)
    if (input.length() == 1) {
        char c = tolower(input[0]);
        if (c == 'a') {
            // wrestle the lion
            this->laborM++;
            this->currStage = L1_Wrestle;
            o.signal = Replace;
            o.text = L1TEXT_WRESTLE;
            return o;
        }
        if (c=='b') {
            // shoot the lion
            this->laborS++;
            this->currStage = L1_Shoot;
            o.signal = Replace;
            o.text = L1TEXT_SHOOT;
            return o;
        }
    }
    
    // if we get here, input was invalid
    o.signal = InvalidInput;
    o.text = "";
    return o;
}

GameOutput LaborOne::handleShoot(std::string input) {
    // no invalid input; just returning home
    GameOutput o;
    o.signal = Replace;
    o.text = L1TEXT_RETURN;
    return o;
}

GameOutput LaborOne::handleWrestle(std::string input) {
    // no invalid input; just returning home
    GameOutput o;
    o.signal = Replace;
    o.text = L1TEXT_RETURN;
    return o;
}

GameOutput LaborOne::handleWrapup(std::string input) {
    // no invalid input; moving on to Labor 2 after a spiel
    GameOutput o;
    if (this->nextModule == NULL) {
        this->nextModule = new LaborTwo();
        o.signal = Replace;
        o.text = L1TEXT_RETURN; // TODO: another text entry, or we don't need this stage!!!
        
        // save this labor
        DAO::incPlayerMight(this->laborM);
        DAO::incPlayerSkill(this->laborS);
        DAO::incPlayerCunning(this->laborC);
        DAO::incPlayerHumility(this->laborH);
        DAO::setCurrentLabor(2);
    }
    else {
        o.signal = NewModule;
        o.text = "";
    }
    return o;
}

//
// Public functions
//

LaborOne::LaborOne() {
    this->currStage = L1_Intro1;
    this->lionFindProbability = 0.0;
}

GameOutput LaborOne::getOutputForStartOfModule() {
    this->currStage = L1_Intro1;
    GameOutput o;
    o.signal = Replace;
    o.text = L1TEXT_INTRO0;
    return o;
}

GameOutput LaborOne::getOutputForInput(std::string input) {
    
    GameOutput o;
    switch (this->currStage) {
        case L1_Intro1:
            return this->handleIntro1(input);
        case L1_Intro2:
            return this->handleIntro2(input);
        case L1_Convo1:
            return this->handleConvo1(input);
        case L1_Convo2:
            return this->handleConvo2(input);
        case L1_Search:
            return this->handleSearch(input);
        case L1_Found:
            return this->handleFound(input);
        case L1_Wrestle:
            return this->handleWrestle(input);
        case L1_Shoot:
            return this->handleShoot(input);
        case L1_WrapUp:
            return this->handleWrapup(input);
    }
    
    return o;
}

GameModule* LaborOne::transitionToNextModule() {
    return this->nextModule;
}
