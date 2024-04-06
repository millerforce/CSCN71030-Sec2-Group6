#include "Gamefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Save&Load.h"

int main(void) {
    PGAME games[MAX_GAMES] = { 0 };
    PUSERPROFILE profiles[MAX_PROFILES] = { 0 };
    char title[MAXTITLE], genre[MAXGENRE], description[MAXDESCRIPTION];
    int menuChoice = 9, length, ID, searchedIndex = 0;
    int currentProfileIndex = 0;
    int totalProfiles = 0;
    int createProfileOptionEnabled = 1;
    bool exitCondition = true;
    char search[MAXTITLE];

    srand(time(NULL));

    if (!LoadGames(games))
        exit(1);
    int totalGames = getTotalGames(games);

    while (exitCondition) {
        
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
            printf("Title: ");
            scanf(" %[^\n]s", title);
            ID = totalGames;
            printf("Genre: ");
            scanf(" %[^\n]s", genre);
            printf("Descrtiption: ");
            scanf(" %[^\n]s", description);
            printf("Length: ");
            scanf("%d", &length);
            games[totalGames] = CreateGame(ID, title, genre, description, length);
            totalGames++;
            break;
        case 2:
            //   case for updating a game
            break;
        case 3:
      
            printf("Please enter the title of the game to delete: ");
            scanf(" %[^\n]s", search);
            searchedIndex = SearchForGame(games, search);
            if (searchedIndex == -1) {
                printf("No game matching that title is currently in the master catalogue\nplease try again\n");
                break;
            }
            else {
                DeleteGame(games, searchedIndex);
                printf("Game titled: %s was deleted successfully", search);
            }
            //  for removing a game
            break;
        case 4:
            // for searching the game catalogue
            printf("Please enter the title of the game to find: ");
            scanf(" %[^\n]s", search);
            searchedIndex = SearchForGame(games, search);
            if (searchedIndex == -1) {
                printf("No game matching that title is currently in the master catalogue\nplease try again\n");
                break;
            }
            else {
                PrintGame(games, searchedIndex);
                break;
            }
        case 5:
            if (createProfileOptionEnabled) {

                // for creating a profile
               PUSERPROFILE john = LoadProfile("John.dat", games);
                SaveProfile(john);

               free(john);
            }
            break;
        case 6:
            // case for selecting a profile
            //select_profile(profiles, &currentProfileIndex, totalProfiles);
            break;
        case 7:
            // case for getting game recommendations
            if (totalGames > 0) {
                get_recommendations(games, totalGames);
            }
            else {
                printf("No games available for recommendations. Please add games first.\n");
            }
            break;
        case 8:
            // Exit 
            SaveGameCatalogue(games);
            DeleteGameCatalogue(games);
            exitCondition = false;
            break;
        default:
            printf("Not a valid option.\n");
            break;
        }
    }
 
    return 0;
}

