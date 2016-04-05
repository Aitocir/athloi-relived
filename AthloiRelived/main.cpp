//
//  main.cpp
//  AthloiRelived
//
//  Created by Aitocir on 3/27/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Data/akvs.h"
#include "sys_cmds.h"
#include "GameModule.h"
#include "MenuMain.hpp"

#define AR_DIR_NAME ".athloi-relived"
#define AR_DB_NAME "gamedata.akvs"

using namespace std;

string printOutputWithResetAndInvalidPrompt(string s, bool clear, bool invalid) {
    
    if (clear) {
        system(CMD_CLEAR_TERMINAL);
    }
    cout << s;
    if (invalid) {
        cout << "\n[ERROR]: Invalid input. Try again.";
    }
    cout << "\n\t-> ";
    return s;
}

int main(int argc, const char * argv[]) {

    // 0) Open connection to game database
    string pathPrefix = string(getenv(DATA_ROOT));
    pathPrefix += PATH_SEP;
    pathPrefix += AR_DIR_NAME;
    pathPrefix += PATH_SEP;
    pathPrefix += AR_DB_NAME;
    if (!openDatabase(pathPrefix)) {
        cout << "[ERROR] Failed to open game database! Check that " << AR_DB_NAME
        << " exists at " << pathPrefix << endl;
        return 1;
    }
    
    // 1) Launch game with Main Menu
    GameModule* module = new MenuMain();
    GameOutput output = module->getOutputForStartOfModule();
    string lastOutput;
    while (output.signal != Quit) {
        
        switch (output.signal) {
            case NewModule:
                module = module->transitionToNextModule();
                lastOutput = printOutputWithResetAndInvalidPrompt((module->getOutputForStartOfModule()).text, true, false);
                break;
            case Replace:
                lastOutput = printOutputWithResetAndInvalidPrompt(output.text, true, false);
                break;
            case Append:
                lastOutput = printOutputWithResetAndInvalidPrompt(output.text, false, false);
                break;
            case InvalidInput:
                printOutputWithResetAndInvalidPrompt(lastOutput, true, true);
                break;
            case Quit:
                // not possible, while won't run in this case!
                break;
        }
        
        string input;
        getline(cin, input);
        output = module->getOutputForInput(input);
    }
    
    // 2) Game ended by user, clean up
    closeDatabase();
    return 0;
}
