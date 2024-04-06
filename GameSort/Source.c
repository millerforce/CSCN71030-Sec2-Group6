#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"
#include "GameFunctions.h"

void get_recommendations(const PGAME games[], int totalGames) {
    char genreInput[MAXGENRE];
    printf("Give an idea of what you want (e.g., sport, action, adventure): ");
    // Use scanf with a format specifier to prevent buffer overflow
    scanf("%49s", genreInput); // Assuming MAXGENRE is 50 or more

    int found = 0;
    for (int i = 0; i < totalGames; i++) {
        if (games[i] != NULL && _stricmp(games[i]->genre, genreInput) == 0) {
            // For 'sport', specifically recommend 'FIFA' if it exists
            if (_stricmp(genreInput, "sport") == 0 && _stricmp(games[i]->title, "FIFA") == 0) {
                printf("Recommendation: %s\n", games[i]->title);
                found++;
                break; // Exit the loop after recommending 'FIFA'
            }
            else {
                // Otherwise, list all games in the specified genre
                printf("Recommendation: %s\n", games[i]->title);
                found++;
            }
        }
    }

    if (found == 0) {
        printf("No games found in the '%s' genre.\n", genreInput);
    }
}


void search_game_catalogue(const GAME games[], int totalGAMEs) {
    char searchQuery[100];
    printf("Enter the game title to search for: ");
    scanf_s("%s", searchQuery, (unsigned int)sizeof(searchQuery));



}

void generateRandomDate(char* dateStr) {
    int year = 2022 + rand() % 3; // For years 2022 to 2024, adjust as needed
    int month = 1 + rand() % 12; // Random month
    int day;

    switch (month) {
    case 2: // February
        day = 1 + rand() % 28; // Simplification: not accounting for leap years
        break;
    case 4: case 6: case 9: case 11:
        day = 1 + rand() % 30;
        break;
    default:
        day = 1 + rand() % 31;
    }

    sprintf(dateStr, "%04d-%02d-%02d", year, month, day);
}