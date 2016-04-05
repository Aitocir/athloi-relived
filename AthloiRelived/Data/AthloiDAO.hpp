//
//  AthloiDAO.hpp
//  AthloiRelived
//
//  Created by Aitocir on 4/3/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef AthloiDAO_hpp
#define AthloiDAO_hpp

#include <stdlib.h>
#include <stdio.h>
#include "akvs.h"
#include <string>


class DAO {
public:
    // Game getters
    static bool isGameInProgress();
    static int getCurrentLabor();
    
    // Game setters
    static void setGameInProgress(bool isInProgress);
    static void setPlayerMight(int amnt);
    static void setPlayerSkill(int amnt);
    static void setPlayerCunning(int amnt);
    static void setPlayerHumility(int amnt);
    static void setCurrentLabor(int laborNumber);
    
    // Game Incrementers
    static void incPlayerMight(int addl);
    static void incPlayerSkill(int addl);
    static void incPlayerCunning(int addl);
    static void incPlayerHumility(int addl);
    
    static void incKeyWithAmount(std::string key, int amnt);
};


#endif /* AthloiDAO_hpp */
