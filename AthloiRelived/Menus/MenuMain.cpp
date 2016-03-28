//
//  MenuMain.cpp
//  AthloiRelived
//
//  Created by Aitocir on 3/28/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//
#include <stdio.h>
#include <string>
#include "akvs.h"
#include "MenuMain.hpp"

using namespace std;

static const char FIRST_CHAR_NEW = 'N';
static const char FIRST_CHAR_CONT = 'C';
static const string FIRST_OPT_NEW = "New";
static const string FIRST_OPT_CONT = "Continue";

GameOutput mainMenuAtFirstLaunch(bool gameInProgress, bool invalidInput) {
    
    char firstMenuChar = gameInProgress ? FIRST_CHAR_CONT : FIRST_CHAR_NEW;
    string firstMenuItem = gameInProgress ? FIRST_OPT_CONT : FIRST_OPT_NEW;
    string format = MENUMAIN_FORMATBODY;
    char* format_charstar = new char[format.size() + 1 + firstMenuItem.size()];
    sprintf(format_charstar, format.c_str(), firstMenuChar, firstMenuItem.c_str());
    string menuText = string(format_charstar);
    if (invalidInput) {
        menuText += "Invalid input. Try choosing a menu option again:\n\t";
    }
    
    GameOutput results;
    results.signal = Replace;
    results.text = menuText;
    return results;
}

GameOutput MenuMain::getOutputForStartOfModule() {
    bool gameInProgress = getBool("GameInProgress");
    char firstMenuChar = gameInProgress ? FIRST_CHAR_CONT : FIRST_CHAR_NEW;
    string firstMenuItem = gameInProgress ? FIRST_OPT_CONT : FIRST_OPT_NEW;
    string format = MENUMAIN_FORMATBODY;
    char* format_charstar = new char[format.size() + 1 + firstMenuItem.size()];
    sprintf(format_charstar, format.c_str(), firstMenuChar, firstMenuItem.c_str());
    string menuText = string(format_charstar);
    
    GameOutput results;
    results.signal = Replace;
    results.text = menuText;
    return results;
}

GameOutput MenuMain::getOutputForInput(string input) {
    
    GameOutput output;
    bool gameInProgress = getBool("GameInProgress");
    char choice = tolower(input[0]);
    switch (choice) {
            
        case 'n':
            // invalid if "Continue" is what's up
            if (gameInProgress) {
                output = mainMenuAtFirstLaunch(gameInProgress,true);
                this->nextModule = this;
            }
            else {
                // start a new game
                output.signal = NewModule;
                output.text = "";
                // TODO: this->nextModule = new NewGameModule()
            }
            break;
            
        case 'c':
            // invalid if "New" is what's up
            if (!gameInProgress) {
                output = mainMenuAtFirstLaunch(gameInProgress, true);
            }
            else {
                // continue current game
                output.signal = NewModule;
                output.text = "";
                // TODO: this->nextModule = new ContinueGameModule()
            }
            break;
            
        case 's':
            // Settings menu
            output.signal = NewModule;
            output.text = "";
            // TODO: this->nextModule = new MenuSettings()
            break;
            
        case 'a':
            // Achievements menu
            output.signal = NewModule;
            output.text = "";
            // TODO: this->nextModule = new MenuAchievements()
            break;
            
        case 'q':
            // Quit!
            output.signal = Quit;
            output.text = "";
            this->nextModule = NULL;
            break;
            
        default:
            // invalid input!
            output = mainMenuAtFirstLaunch(gameInProgress,true);
            break;
    }
    
    return output;
}

GameModule* MenuMain::transitionToNextModule() {
    
    return this->nextModule;
}
