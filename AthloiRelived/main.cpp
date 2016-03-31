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

int main(int argc, const char * argv[]) {
    
//    int t = 0;
//    openDatabase("/Users/aitocir/bob.akvs");
//    setInt("LOL", 13);
//    printf("\njim\n");
//    t = getInt("LOL");
//    if (t==13) {
//        printf("SUCCESS!!!!");
//    }

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
    while (output.signal != Quit) {
        
        switch (output.signal) {
            case NewModule:
                module = module->transitionToNextModule();
                cout << (module->getOutputForStartOfModule()).text;
                break;
            case Replace:
                system(CMD_CLEAR_TERMINAL);
            case Append:
                cout << output.text;
                break;
            case Quit:
                // not possible, while won't run in this case!
                break;
        }
        
        cout << "> ";
        string input;
        getline(cin, input);
        output = module->getOutputForInput(input);
    }
    
    closeDatabase();
    return 0;
}
