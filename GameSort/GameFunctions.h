
#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h> 


#define MAX_GAMES 100
#define MAX_PROFILES 10

// Struct for a game
typedef struct game{
    int gameID;
    char title[100];
    char genre[50];

} GAME, *PGAME;

// Struct for a user profile
typedef struct userprofile{
    int userID;
    char firstName[50];
    char lastName[50];
    char gamertag[50];

} USERPROFILE, *PUSERPROFILE;

// Functions
void create_profile(USERPROFILE profiles[], int* currentProfileIndex, int* totalProfiles);
void select_profile(USERPROFILE profiles[], int* currentProfileIndex, int totalProfiles);
void add_game(GAME games[], int* totalGAMEs);
void update_game(GAME games[], int currentProfileIndex);
void remove_game(GAME games[], int currentProfileIndex);
void display_games(const GAME games[], int currentProfileIndex);
void get_recommendations(const GAME games[], int currentProfileIndex);
void search_game_catalogue(const GAME games[], int totalGAMEs);

#endif 