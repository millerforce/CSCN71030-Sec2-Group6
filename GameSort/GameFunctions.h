
#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

#define MAX_GAMES 100
#define MAX_PROFILES 10
#define MAXTITLE 100
#define MAXGENRE 50
#define MAXDESCRIPTION 400

// Struct for a game
typedef struct game{
    int gameID;
    char title[MAXTITLE];
    char genre[MAXGENRE];
    char description[MAXDESCRIPTION];
    int length;
} GAME, *PGAME;

// Struct for a user profile
typedef struct userprofile{
    int userID;
    char firstName[50];
    char lastName[50];
    char gamertag[50];
    PGAME personalGames[MAX_GAMES];
} USERPROFILE, *PUSERPROFILE;

// Functions
//C


PGAME CreateGame(int ID, char title[], char genre[], char description[], int length);

//R
void select_profile(USERPROFILE profiles[], int* currentProfileIndex, int totalProfiles);

int SearchForGame(PGAME games[], char title[]);
void PrintGame(PGAME games[], int index);
int getTotalGames(PGAME games[]);
int getID(PGAME games[], int index);
char* getTitle(PGAME games[], int index);
char* getGenre(PGAME games[], int index);
char* getDescription(PGAME games[], int index);
int getLength(PGAME games[], int index);

//U
bool setID(PGAME games[], int index, int ID);
bool setTitle(PGAME games[], int index, char title[]);
bool setGenre(PGAME games[], int index, char genre[]);
bool setDescription(PGAME games[], int index, char description[]);
bool setLength(PGAME games[], int index, int length);

void update_game(GAME games[], int currentProfileIndex);

//D
void DeleteGame(PGAME games[], int index);
void DeleteGameCatalogue(PGAME games[]);


void display_games(const GAME games[], int currentProfileIndex);
void get_recommendations(const GAME games[], int currentProfileIndex);
void search_game_catalogue(const GAME games[], int totalGAMEs);
void create_profile(USERPROFILE profiles[], int* currentProfileIndex, int* totalProfiles);
#endif 