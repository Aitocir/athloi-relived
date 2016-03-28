//
//  sys_cmds.h
//  WanderingHome
//
//  Created by Aitocir on 2/26/16.
//  Copyright © 2016 AitocirLabs. All rights reserved.
//

#ifndef sys_cmds_h
#define sys_cmds_h

//
// define the system command for clearing the screen
//
#ifdef _WIN32
#define CMD_CLEAR_TERMINAL "cls"
#elif _WIN64
#define CMD_CLEAR_TERMINAL "cls"
#else
#define CMD_CLEAR_TERMINAL "clear"
#endif

//
// define the system command for waiting (take seconds as parameter)
//
#ifdef _WIN32
#define CMD_WAIT(x) "pause x"
#elif _WIN64
#define CMD_WAIT(x) "pause x"
#else
#define CMD_WAIT(x) "sleep x"
#endif

//
// define the root folder for creating our own settings
// (AppData\Roaming folder for Windows 7+, home folder for linux, ~/Library/Preferences for OS X)
//
#ifdef _WIN32
#define DATA_ROOT "APPDATA"
#elif _WIN64
#define DATA_ROOT "APPDATA"
#else
#define DATA_ROOT "HOME"
#endif

//
// define the system file path separator
//
#ifdef _WIN32
#define PATH_SEP "\\"
#elif _WIN64
#define PATH_SEP "\\"
#else
#define PATH_SEP "/"
#endif


#endif /* sys_cmds_h */
