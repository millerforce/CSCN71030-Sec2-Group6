#include "Gamefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main() {
    PGAME games[MAX_GAMES] = { 0 };
    PUSERPROFILE profiles[MAX_PROFILES] = { 0 };
    int menuChoice;
    int currentProfileIndex = 0;
    int totalGames = 0;
    int totalProfiles = 0;
    int createProfileOptionEnabled = 1;


    srand(time(NULL));

    do {
        printf("                        Welcome to the GameSort program              \n");
        printf("-----------------------------------------------------------------------\n");
        printf("Please choose one of the following options:\n");
        printf("1. Add a game\n");
        printf("2. Update a game\n");
        printf("3. Remove a game\n");
        printf("4. Search game catalogue\n"); // New option added
        if (createProfileOptionEnabled) {
            printf("5. Create profile\n");
        }
        printf("6. Select profile\n");
        printf("7. Get game recommendations\n");
        printf("8. Exit the program\n");
        scanf_s("%d", &menuChoice);

        switch (menuChoice) {
        case 1:
            // case for adding a game
            add_game(games, totalGames);
            totalGames++;
            break;
        case 2:
            //   case for updating a game
            break;
        case 3:
            //  for removing a game
            break;
        case 4:
            // for searching the game catalogue
            search_game_catalogue(games, totalGames);
            break;
        case 5:
            if (createProfileOptionEnabled) {

                // for creating a profile
                create_profile(profiles, &currentProfileIndex, &totalProfiles);
                createProfileOptionEnabled = 0;
            }
            break;
        case 6:
            // case for selecting a profile
            select_profile(profiles, &currentProfileIndex, totalProfiles);
            break;
        case 7:
            // case for getting game recommendations
            get_recommendations(games, currentProfileIndex);
            break;
        case 8:
            // Exit 
            free(games);
            return 0;
        default:
            printf("Not a valid option.\n");
            break;
        }
    } while (menuChoice != 8);
 
    return 0;
}