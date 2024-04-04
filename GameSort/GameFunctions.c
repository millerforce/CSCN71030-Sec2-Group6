#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "GameFunctions.h"

//  generate a profile ID
int generate_profile_id() {
    srand(time(NULL));
    return rand() % 9000 + 1000;
}

void create_profile(USERPROFILE profiles[], int* currentProfileIndex, int* totalProfiles) {
    if (*totalProfiles >= MAX_PROFILES) {
        printf("Maximum number of profiles reached. Cannot create more profiles.\n");
        return;
    }

    // Create a new profile
    printf("Creating a new profile...\n");
    printf("Enter first name: ");
    scanf_s("%s", profiles[*totalProfiles].firstName, (unsigned)_countof(profiles[*totalProfiles].firstName));

    printf("Enter last name: ");
    scanf_s("%s", profiles[*totalProfiles].lastName, (unsigned)_countof(profiles[*totalProfiles].lastName));

    printf("Enter gamertag: ");
    scanf_s("%s", profiles[*totalProfiles].gamertag, (unsigned)_countof(profiles[*totalProfiles].gamertag));

    profiles[*totalProfiles].userID = generate_profile_id(); // Generate profile ID
    *currentProfileIndex = *totalProfiles;
    (*totalProfiles)++;
    printf("Profile created successfully. Profile ID is %d\n", profiles[*currentProfileIndex].userID);
}

PGAME CreateGame(int ID, char title[], char genre[], char description[], int length) {
    //printf("Adding a game to profile %d...\n", index);

    PGAME temp = (PGAME)malloc(sizeof(GAME));
  
    if (temp == NULL) {
        fprintf(stderr, "MEMORY ALLOCATION ERROR PROGRAM WILL NOW EXIT\n");
        exit(1);

    }
    else {
        temp->gameID = ID;
        strcpy(temp->title, title);
        strcpy(temp->genre, genre);
        strcpy(temp->description, description);
        temp->length = length;
        return temp;
    }
}

//R

// this uses linear search. this could be made better but in the scale of this project it is sufficient
int SearchForGame(PGAME games[], char title[]) {

    for (int i = 0; i < MAX_GAMES; i++) {
        if (games[i] != NULL) {
            if (strcmp(getTitle(games, i), title) == 0)
                return i;
        }
    }
    return -1;
}

void PrintGame(PGAME games[], int index) {
    if (games[index] == NULL) {
        printf("No game at index %d to print", index);
        return;
    }
    else {
        printf("%s\n", getTitle(games, index));
        printf("%d\n", getID(games, index));
        printf("%s\n", getGenre(games, index));
        printf("%s\n", getDescription(games, index));
        printf("%d\n", getLength(games, index));
    }
}

int getTotalGames(PGAME games[]) {
    int total = 0;
    for (int i = 0; i < MAX_GAMES; i++) {
        if (games[i] != NULL)
            total++;
    }
    return total;
}

int getID(PGAME games[], int index) {
    if (games[index] == NULL) {
        printf("No GAME at index %d unable to retrieve ID\n", index);
    }
    else
        return games[index]->gameID;
}

char* getTitle(PGAME games[], int index) {
    if (games[index] == NULL) {
        printf("No GAME at index %d unable to retrieve Title\n", index);
    }
    else
        return games[index]->title;
}

char* getGenre(PGAME games[], int index) {
    if (games[index] == NULL) {
        printf("No GAME at index %d unable to retrieve Genre\n", index);
    }
    else
        return games[index]->genre;
}

char* getDescription(PGAME games[], int index) {
    if (games[index] == NULL) {
        printf("No GAME at index %d unable to retrieve Description\n", index);
    }
    else
        return games[index]->description;
}

int getLength(PGAME games[], int index) {
    if (games[index] == NULL) {
        printf("No GAME at index %d unable to retrieve Length\n", index);
        return 0;
    }
    else
        return games[index]->length;
}

//U
bool setID(PGAME games[], int index, int ID) {
    if (ID < 0 || ID > 200) {
        printf("GAME ID is out of valid range\n");
        return false;
    }
    else {
        games[index]->gameID = ID;
        return true;
    }
}
bool setTitle(PGAME games[], int index, char title[]) {
    if (strlen(title) > MAXTITLE) {
        printf("GAME title is too long\n");
        return false;
    }
    else {
        strcpy(games[index]->title, title);
        return true;
    }
}
bool setGenre(PGAME games[], int index, char genre[]) {
    if (strlen(genre) > MAXGENRE) {
        printf("GAME genre is too long\n");
        return false;
    }
    else {
        strcpy(games[index]->genre, genre);
        return true;
    }
}
bool setDescription(PGAME games[], int index, char description[]) {
    if (strlen(description) > MAXDESCRIPTION) {
        printf("GAME genre is too long\n");
        return false;
    }
    else {
        strcpy(games[index]->description, description);
        return true;
    }
}
bool setLength(PGAME games[], int index, int length) {
    if (length < 0) {
        printf("GAME length is out of valid range\n");
        return false;
    }
    else {
        games[index]->length = length;
        return true;
    }
}

void update_game(GAME games[], int currentProfileIndex) {
    printf("Updating a game in profile %d...\n", currentProfileIndex);

}

void DeleteGame(PGAME games[], int index) {
    printf("Deleted %s from master catalogue this game will no longer\n", games[index]->title);
    printf("be saved to disk at next catalogue save\n");

    free(games[index]);
    games[index] = NULL;
}

void DeleteGameCatalogue(PGAME games[]) {
    for (int i = 0; i < MAX_GAMES; i++) {
        if (games[i] != NULL)
            free(games[i]);
        games[i] = NULL;
    }
}

void display_games(const GAME games[], int currentProfileIndex) {
    printf("Displaying games for profile %d...\n", currentProfileIndex);

}

void get_recommendations(const GAME games[], int currentProfileIndex) {
    printf("Getting recommendations for profile %d...\n", currentProfileIndex);

}

void select_profile(USERPROFILE profiles[], int* currentProfileIndex, int totalProfiles) {
    if (totalProfiles == 0) {
        printf("No profiles exist. Please create a profile first.\n");
        return;
    }

    // Select an existing profile
    int profileID;
    printf("Enter the profile ID to select: ");
    scanf_s("%d", &profileID);

    // Verify if  profile ID entered is valid
    int found = 0;
    for (int i = 0; i < totalProfiles; i++) {
        if (profiles[i].userID == profileID) {
            *currentProfileIndex = i;
            printf("Profile ID %d selected.\n", profileID);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid profile ID. Please try again.\n");
    }
}


void search_game_catalogue(const GAME games[], int totalGAMEs) {
    char searchQuery[100];
    printf("Enter the game title to search for: ");
    scanf_s("%s", searchQuery, (unsigned int)sizeof(searchQuery));



}