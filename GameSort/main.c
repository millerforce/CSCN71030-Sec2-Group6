#include "Gamefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Save&Load.h"

int main(void) {
    PGAME games[MAX_GAMES] = { 0 };
    PUSERPROFILE profiles[MAX_PROFILES] = { 0 }, activeProfile = { 0 };
    char title[MAXTITLE], genre[MAXGENRE], description[MAXDESCRIPTION], gamertag[MAXNAME], password[MAXPASSWORD];
    int menuAChoice = 9, menuBChoice, length, ID, searchedIndex = 0;
    int currentProfileIndex = 0;
    int totalProfiles = 0;
    int createProfileOptionEnabled = 1;
    bool exitCondition = true, exitProgram = true;
    char search[MAXTITLE];
    char choice, first[MAXNAME], last[MAXNAME], ingamertag[MAXNAME], inpassword[MAXPASSWORD];
    srand(time(NULL));

   

    if (!LoadGames(games))
        exit(1);
    int totalGames = getTotalGames(games);

    if (!LoadProfileList(profiles, games))
        exit(1);

    while (exitProgram) {
        printf("                        Welcome to the GameSort program              \n");
        printf("-----------------------------------------------------------------------\n");
        printf("Please choose one of the following options:\n");
        printf("1. Sign in\n");
        printf("2. Create account\n");
        printf("3. Modify Main Catalogue\n");
        printf("4. exit\n");
        scanf("%d", &menuAChoice);

        int profileIndex = -1;
        int currentTotalGames;
        switch (menuAChoice) {
        case (1):
            printf("Please enter your gamertag: ");
            scanf(" %s", gamertag);
            for (int i = 0; i < MAX_PROFILES; i++) {
                if (profiles[i] != NULL && strcmp(profiles[i]->gamertag, gamertag) == 0) {
                    printf("Gamertag found! please enter your password %s: ", getFirstName(profiles[i]));
                    profileIndex = i;
                }
            }
            scanf("%s", password);
            if (!VerifyPassword(profiles[profileIndex], password)) {
                printf("Incorrect password please try again\n");
                break;
            }
            else {
                printf("Password verified welcome back\n");
                PUSERPROFILE loggedIn = profiles[profileIndex];
                currentTotalGames = getTotalGames(profiles[profileIndex]->gameCatalog);
            }
            
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
                scanf_s("%d", &menuBChoice);

                switch (menuBChoice) {
                case 1:
                    printf("Do you want to add a new game or one from the catalogue. Enter N for new and C for catalogue\n");
                    
                    scanf(" %c", &choice);
                    switch (choice) {
                    case ('N'):
                        printf("Title: ");
                        scanf(" %[^\n]s", title);
                        ID = totalGames;
                        printf("Genre: ");
                        scanf(" %[^\n]s", genre);
                        printf("Descrtiption: ");
                        scanf(" %[^\n]s", description);
                        printf("Length: ");
                        scanf("%d", &length);
                        profiles[profileIndex]->gameCatalog[currentTotalGames] = CreateGame(ID, title, genre, description, length);
                        games[totalGames] = profiles[profileIndex]->gameCatalog[currentTotalGames];
                        totalGames++;
                        currentTotalGames++;
                        break;
                    case('C'):
                        printf("Please enter the name of the game to add: ");
                        scanf(" %[^\n]s", search);
                        searchedIndex = SearchForGame(games, search);
                        if (searchedIndex == -1) {
                            printf("No game in catlogue that matches that title\n");
                        }
                        else {
                            printf("Now adding %s to your personal catalogue\n", games[searchedIndex]->title);
                            profiles[profileIndex]->gameCatalog[currentTotalGames] = games[searchedIndex];
                        }

                        break;
                    default:
                        printf("Invalid option\n");
                        break;
                    }
                    // case for adding a game
                   
                    break;
                case 2:
                    //   case for updating a game
                    break;
                case 3:

                    printf("Please enter the title of the game to delete: ");
                    scanf(" %[^\n]s", search);
                    searchedIndex = SearchForGame(profiles[profileIndex]->gameCatalog, search);
                    if (searchedIndex == -1) {
                        printf("No game matching that title is currently in the master catalogue\nplease try again\n");
                        break;
                    }
                    else {
                        DeleteGame(profiles[profileIndex]->gameCatalog, searchedIndex);
                        printf("Game titled: %s was deleted successfully", search);
                    }
                    //  for removing a game
                    break;
                case 4:
                    // for searching the game catalogue
                    printf("Please enter the title of the game to find: ");
                    scanf(" %[^\n]s", search);
                    searchedIndex = SearchForGame(profiles[profileIndex]->gameCatalog, search);
                    if (searchedIndex == -1) {
                        printf("No game matching that title is currently in the master catalogue\nplease try again\n");
                        break;
                    }
                    else {
                        PrintGame(profiles[profileIndex]->gameCatalog, searchedIndex);
                        break;
                    }
                case 5:
                    if (createProfileOptionEnabled) {

                        // for creating a profile
                        /*PUSERPROFILE john = LoadProfile("John.dat", games);
                        SaveProfile(john);

                        free(john);*/
                    }
                    break;
                case 6:
                    // case for selecting a profile
                    //select_profile(profiles, &currentProfileIndex, totalProfiles);
                    break;
                case 7:
                    // case for getting game recommendations
                    if (currentTotalGames > 0) {
                        get_recommendations(profiles[profileIndex]->gameCatalog, currentTotalGames);
                    }
                    else {
                        printf("No games available for recommendations. Please add games first.\n");
                    }
                    break;
                case 8:
                    // Exit 
                 /*   SaveGameCatalogue(games);
                    DeleteGameCatalogue(games);*/
                    if (!SaveProfile(profiles[currentProfileIndex])) {
                        printf("Error profile save failure\n");
                    }
                    exitCondition = false;
                    break;
                default:
                    printf("Not a valid option.\n");
                    break;
                }
            }
            break;
        case(2):
            
            printf("Please enter your first name: ");
            scanf(" %s", )
            break;
        case(3):
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
                scanf_s("%d", &menuBChoice);

                switch (menuBChoice) {
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
                    //DeleteGameCatalogue(games);
                    exitCondition = false;
                    break;
                default:
                    printf("Not a valid option.\n");
                    break;
                }
            }
            break;
        case(4):
            SaveGameCatalogue(games);
            DeleteGameCatalogue(games);
            exit(0);
            break;
        default:

            break;
        }
      

    }
    return 0;
}

