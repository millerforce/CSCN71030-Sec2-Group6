#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"
#include "GameFunctions.h"

void get_recommendations(const PGAME games[], int totalGames) {
    char genreFilter[MAXGENRE] = { 0 };
    char difficultyFilter[MAXDIFFICULTY] = { 0 };
    int minHours = 0, maxHours = INT_MAX; // Defaults if the user does not filter by length
    char input = 'N';

    // Ask the user for filters
    printf("Would you like to filter by genre? (Y/N): ");
    scanf(" %c", &input);
    if (toupper(input) == 'Y') {
        printf("What genre are you interested in? ");
        scanf(" %[^\n]s", genreFilter);
    }

    printf("Would you like to filter by difficulty level? (Y/N): ");
    scanf(" %c", &input);
    if (toupper(input) == 'Y') {
        printf("What difficulty level do you prefer (easy, medium, hard, very hard, impossible, casual)? ");
        scanf(" %[^\n]s", difficultyFilter);
    }

    printf("Would you like to filter by game length? (Y/N): ");
    scanf(" %c", &input);
    if (toupper(input) == 'Y') {
        printf("1. 0-5 hours\n");
        printf("2. 5-25 hours\n");
        printf("3. 26-50 hours\n");
        printf("4. More than 50 hours\n");
        printf("Enter option (1-4): ");
        int lengthOption;
        scanf("%d", &lengthOption);

        // Map the user's choice to min and max hours
        switch (lengthOption) {
        case 1: minHours = 0; maxHours = 5; break;
        case 2: minHours = 5; maxHours = 25; break;
        case 3: minHours = 26; maxHours = 50; break;
        case 4: minHours = 51; maxHours = INT_MAX; break;
        default: printf("Invalid choice. No length filter will be applied.\n"); break;
        }
    }

    // Search and recommend games based on the filters
    int found = 0;
    for (int i = 0; i < totalGames; i++) {
        if (games[i] != NULL) {
            bool matchesGenre = (strlen(genreFilter) == 0 || _stricmp(games[i]->genre, genreFilter) == 0);
            bool matchesDifficulty = (strlen(difficultyFilter) == 0 || _stricmp(games[i]->difficulty, difficultyFilter) == 0);
            bool matchesLength = (games[i]->length >= minHours && games[i]->length <= maxHours);

            if (matchesGenre && matchesDifficulty && matchesLength) {
                printf("Recommendation: %s\n", games[i]->title);
                found++;
            }
        }
    }

    if (found == 0) {
        printf("No games found matching your criteria.\n");
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