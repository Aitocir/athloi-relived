//
//  MenuMain.cpp
//  AthloiRelived
//
//  Created by Aitocir on 3/28/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//
#include <stdio.h>
#include <string>
#include "AthloiDAO.hpp"
#include "MenuMain.hpp"
#include "LaborOne.hpp"
#include "LaborTwo.hpp"
#include "LaborThree.hpp"
#include "LaborFour.hpp"
#include "LaborFive.hpp"
#include "LaborSix.hpp"
#include "LaborSeven.hpp"
#include "LaborEight.hpp"
#include "LaborNine.hpp"
#include "LaborTen.hpp"
#include "LaborEleven.hpp"
#include "LaborTwelve.hpp"

using namespace std;

static const char FIRST_CHAR_NEW = 'N';
static const char FIRST_CHAR_CONT = 'C';
static const string FIRST_OPT_NEW = "New";
static const string FIRST_OPT_CONT = "Continue";

GameModule* MenuMain::moduleForLaborNumber(int labor) {
    if (labor < 1 || labor > 12) {
        return new LaborOne();
    }
    
    switch (labor) {
        case 1:
            return new LaborOne();
        case 2:
            return new LaborTwo();
        case 3:
            return new LaborThree();
        case 4:
            return new LaborFour();
        case 5:
            return new LaborFive();
        case 6:
            return new LaborSix();
        case 7:
            return new LaborSeven();
        case 8:
            return new LaborEight();
        case 9:
            return new LaborNine();
        case 10:
            return new LaborTen();
        case 11:
            return new LaborEleven();
        case 12:
            return new LaborTwelve();
        default:
            return new LaborOne();
    }
}

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
    bool gameInProgress = DAO::isGameInProgress();
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
    bool gameInProgress = DAO::isGameInProgress();
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
                this->nextModule = new LaborOne();
                
                // make persistence changes necessary
                DAO::setGameInProgress(true);
                DAO::setPlayerMight(0);
                DAO::setPlayerSkill(0);
                DAO::setPlayerCunning(0);
                DAO::setPlayerHumility(0);
                DAO::setCurrentLabor(1);
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
                this->nextModule = this->moduleForLaborNumber(DAO::getCurrentLabor());
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
