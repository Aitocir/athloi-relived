//
//  main.cpp
//  AthloiRelived
//
//  Created by Aitocir on 3/27/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#include <iostream>
#include "Data/akvs.h"

int main(int argc, const char * argv[]) {
    
    int t = 0;
    openDatabase("/Users/aitocir/bob.akvs");
    setInt("LOL", 13);
    printf("\njim\n");
    t = getInt("LOL");
    if (t==13) {
        printf("SUCCESS!!!!");
    }
    return 0;
}
