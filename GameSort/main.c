#include "Gamefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Save&Load.h"

int main(void) {
    PGAME games[MAX_GAMES] = { 0 }, blank[MAX_GAMES] = {0};
    PUSERPROFILE profiles[MAX_PROFILES] = { 0 }, activeProfile = { 0 };
    char title[MAXTITLE], genre[MAXGENRE], description[MAXDESCRIPTION], gamertag[MAXNAME], password[MAXPASSWORD];
    int menuAChoice = 9, menuBChoice, length, ID, searchedIndex = 0;
    int currentProfileIndex = 0;
    int totalProfiles = 0;
    int createProfileOptionEnabled = 1;
    bool exitCondition = true, exitProgram = true;
    char search[MAXTITLE], input;
    char choice, first[MAXNAME], last[MAXNAME], ingamertag[MAXNAME], inpassword[MAXPASSWORD];
    srand(time(NULL));

   

    if (!LoadGames(games))
        exit(1);
    int totalGames = getTotalGames(games);

    if (!LoadProfileList(profiles, games))
        exit(1);
    totalProfiles = getTotalProfiles(profiles);

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
            if (scanf(" %s", gamertag) != 1)
                printf("input error\n");
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
            exitCondition = true;
            while (exitCondition) {

                printf("                        Welcome to the GameSort program              \n");
                printf("-----------------------------------------------------------------------\n");
                printf("Please choose one of the following options:\n");
                printf("1. Add a game\n");
                printf("2. Update a game\n");
                printf("3. Remove a game\n");
                printf("4. Search game catalogue\n"); // New option added
                printf("5. Display whole catalogue\n");
                printf("6. Update profile\n");
                printf("7. Get game recommendations\n");
                printf("8. Log out\n");
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
                    printf("What game would you like to update?: ");
                    scanf(" %s", search);
                    searchedIndex = SearchForGame(profiles[profileIndex]->gameCatalog, search);
                    if (searchedIndex == -1) {
                        printf("No game matching that title is currently in your catalogue\nplease try again\n");
                    }
                    else {
                        printf("What would you like to update?\nTitle, Genre, Description, Length\n");
                        scanf(" %c", &input);
                        switch (input) {
                        case('t'):
                            printf("Enter new title: ");
                            scanf(" %[^\n]s", games[searchedIndex]->title);
                            break;
                        case('g'):
                            printf("Enter new genre: ");
                            scanf(" %[^\n]s", games[searchedIndex]->genre);
                            break;
                        case('d'):
                            printf("Enter new description: ");
                            scanf(" %[^\n]s", games[searchedIndex]->description);
                            break;
                        case('l'):
                            printf("Enter new length: ");
                            scanf(" %d", &games[searchedIndex]->length);
                            break;
                        default:
                            printf("Invalid input\n");
                            break;
                            
                        }
                    }
                    break;
                case 3:

                    printf("Please enter the title of the game to delete: ");
                    scanf(" %[^\n]s", search);
                    searchedIndex = SearchForGame(profiles[profileIndex]->gameCatalog, search);
                    if (searchedIndex == -1) {
                        printf("No game matching that title is currently in your catalogue\nplease try again\n");
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
                    for (int i = 0; i < MAX_GAMES; i++) {
                        if (profiles[profileIndex]->gameCatalog[i] != NULL) {
                            printf("%s\n", getTitle(profiles[profileIndex]->gameCatalog, i));
                            printf("%s\n", getGenre(profiles[profileIndex]->gameCatalog, i));
                            printf("%s\n", getDescription(profiles[profileIndex]->gameCatalog, i));
                            printf("%d\n\n", getLength(profiles[profileIndex]->gameCatalog, i));
                        }
                    }
                    break;
                case 6:
                        printf("What would you like to update?\nFirst Name, Last Name, Gamertag, Password\n");
                        scanf(" %c", &input);
                        switch (input) {
                        case('f'):
                            printf("Enter new First Name: ");
                            scanf(" %[^\n]s", profiles[profileIndex]->firstName);
                            break;
                        case('l'):
                            printf("Enter new Last Name: ");
                            scanf(" %[^\n]s", profiles[profileIndex]->lastName);
                            break;
                        case('g'):
                            printf("Enter new Gamertag: ");
                            scanf(" %[^\n]s", profiles[profileIndex]->gamertag);
                            break;
                        case('p'):
                            printf("Enter new Password: ");
                            scanf(" %s", profiles[profileIndex]->password);
                            break;
                        default:
                            printf("Invalid input\n");
                            break;

                        }
                        printf("\nYou will now need to re login\n");
                        exitCondition = false;
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
                 /*   if (!SaveProfile(profiles[currentProfileIndex])) {
                        printf("Error profile save failure\n");
                    }*/
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
            scanf(" %s", first);
            printf("Please enter your last name: ");
            scanf(" %s", last);
            printf("Please enter your gamertag: ");
            scanf(" %s", ingamertag);
            printf("Please enter your password: ");
            scanf(" %s", inpassword);

            profiles[totalProfiles] = create_profile(1, first, last, ingamertag, inpassword, blank);
            totalProfiles++;
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
                printf("5. Display whole catalogue\n");
                printf("6. Back to main menu\n");
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
                    printf("What game would you like to update?: ");
                    scanf(" %s", search);
                    searchedIndex = SearchForGame(games, search);
                    if (searchedIndex == -1) {
                        printf("No game matching that title is currently in master catalogue\nplease try again\n");
                    }
                    else {
                        printf("What would you like to update?\nTitle, Genre, Description, Length\n");
                        scanf(" %c", &input);
                        switch (input) {
                        case('t'):
                            printf("Enter new title: ");
                            scanf(" %[^\n]s", games[searchedIndex]->title);
                            break;
                        case('g'):
                            printf("Enter new genre: ");
                            scanf(" %[^\n]s", games[searchedIndex]->genre);
                            break;
                        case('d'):
                            printf("Enter new description: ");
                            scanf(" %[^\n]s", games[searchedIndex]->description);
                            break;
                        case('l'):
                            printf("Enter new length: ");
                            scanf(" %d", &games[searchedIndex]->length);
                            break;
                        default:
                            printf("Invalid input\n");
                            break;

                        }
                    }
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
                    for (int i = 0; i < MAX_GAMES; i++) {
                        if (games[i] != NULL) {
                            printf("%s\n", getTitle(games, i));
                            printf("%s\n", getGenre(games, i));
                            printf("%s\n", getDescription(games, i));
                            printf("%d\n\n", getLength(games, i));
                        }
                    }
                    break;
                case 6:
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
            SaveProfileList(profiles);
            SaveAllProfiles(profiles);
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

