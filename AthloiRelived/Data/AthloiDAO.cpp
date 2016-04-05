//
//  AthloiDAO.cpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include "AthloiDAO.hpp"
#include <string>
#include <stdlib.h>

#define KEY_GameInProgress "GameInProgress"
#define KEY_PlayerMight "PlayerMight"
#define KEY_PlayerSkill "PlayerSkill"
#define KEY_PlayerCunning "PlayerCunning"
#define KEY_PlayerHumility "PlayerHumility"
#define KEY_LaborNumber "LaborNumber"

//
// Game getters
//

bool DAO::isGameInProgress() {
    return getBool(KEY_GameInProgress);
}

int DAO::getCurrentLabor() {
    return getInt(KEY_LaborNumber);
}

//
// Game setters
//

void DAO::setGameInProgress(bool isInProgress) {
    setBool(KEY_GameInProgress, isInProgress);
}

void DAO::setPlayerMight(int amnt) {
    setInt(KEY_PlayerMight, amnt);
}

void DAO::setPlayerSkill(int amnt) {
    setInt(KEY_PlayerSkill, amnt);
}

void DAO::setPlayerCunning(int amnt) {
    setInt(KEY_PlayerCunning, amnt);
}

void DAO::setPlayerHumility(int amnt) {
    setInt(KEY_PlayerHumility, amnt);
}

void DAO::setCurrentLabor(int laborNumber) {
    
    // silently fail for invalid Labor numbers
    if (laborNumber >= 1 && laborNumber <= 12) {
        setInt(KEY_LaborNumber, laborNumber);
    }
}

//
// Game Incrementers
//

void DAO::incKeyWithAmount(std::string key, int amnt) {
    int old = getInt(key);
    old += amnt;
    setInt(key, amnt);
}

void DAO::incPlayerMight(int addl) {
    DAO::incKeyWithAmount(KEY_PlayerMight, addl);
}

void DAO::incPlayerSkill(int addl) {
    DAO::incKeyWithAmount(KEY_PlayerSkill, addl);
}

void DAO::incPlayerCunning(int addl) {
    DAO::incKeyWithAmount(KEY_PlayerCunning, addl);
}

void DAO::incPlayerHumility(int addl) {
    DAO::incKeyWithAmount(KEY_PlayerHumility, addl);
}


