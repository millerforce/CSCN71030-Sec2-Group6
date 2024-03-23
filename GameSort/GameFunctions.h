
#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h> 


#define MAX_GAMES 100
#define MAX_PROFILES 10

// Struct for a game
typedef struct {
    int gameID;
    char title[100];
    char genre[50];

} Game;

// Struct for a user profile
typedef struct {
    int userID;
    char firstName[50];
    char lastName[50];
    char gamertag[50];

} UserProfile;

// Functions
void create_profile(UserProfile profiles[], int* currentProfileIndex, int* totalProfiles);
void select_profile(UserProfile profiles[], int* currentProfileIndex, int totalProfiles);
void add_game(Game games[], int* totalGames);
void update_game(Game games[], int currentProfileIndex);
void remove_game(Game games[], int currentProfileIndex);
void display_games(const Game games[], int currentProfileIndex);
void get_recommendations(const Game games[], int currentProfileIndex);
void search_game_catalogue(const Game games[], int totalGames);

#endif 