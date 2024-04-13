#include "profiles.h"
#include <stdio.h>
#include <string.h>

//UserProfile profiles[MAX_PROFILES];
//int totalProfiles = 0;

// Function to generate a unique profile ID
int generate_profile_id() {
    static int nextID = 1000;
    return nextID++;
}

int getTotalProfiles(PUSERPROFILE users[]) {
    int count = 0;
    for (int i = 0; i < MAX_PROFILES; i++) {
        if (users[i] != NULL)
            count++;
    }
    return count;
}

// Function to create a new user profile
PUSERPROFILE create_profile(int ID, char first[], char last[], char tag[], char password[], PGAME catalogue[]) {

    PUSERPROFILE temp = (PUSERPROFILE)malloc(sizeof(USERPROFILE));

    if (temp == NULL) {
        printf("Memory Allocation Error\n");
        exit(1);
    }
    for (int i = 0; i < MAX_GAMES; i++) {
        temp->gameCatalog[i] = NULL;
    }

    temp->userID = ID;

    strcpy(temp->firstName, first);

    strcpy(temp->lastName, last);

    strcpy(temp->gamertag, tag);

    strcpy(temp->password, password);

    for (int i = 0; i < MAX_GAMES; i++) {
        if (catalogue[i] != NULL)
            temp->gameCatalog[i] = catalogue[i];
   }

    return temp;
}

int getUserID(PUSERPROFILE user) {
    return user->userID;
}

char* getFirstName(PUSERPROFILE user) {
    return user->firstName;
}

char* getLastName(PUSERPROFILE user) {
    return user->lastName;
}

char* getGamertag(PUSERPROFILE user) {
    return user->gamertag;
}

char* getPassword(PUSERPROFILE user) {
    return user->password;
}

bool VerifyPassword(PUSERPROFILE user, const char* password) {
    if (strcmp(getPassword(user), password) == 0)
        return true;
    else
        return false;
}

bool AddGameToProfile(PGAME usersGames[], PGAME game) {
    for (int i = 0; i < MAX_GAMES; i++) {
        if (usersGames[i] == NULL) {
            usersGames[i] = game;
            return true;
        }
    }

    printf("No room in users catalogue\n");
    return false;
}

//// Function to update an existing user profile
//void update_profile() {
//    int userID;
//    printf("Enter the profile ID to update: ");
//    if (scanf("%d", &userID) != 1) {
//        printf("Error reading profile ID.\n");
//        return;
//    }
//
//    int found = 0;
//    for (int i = 0; i < totalProfiles; i++) {
//        if (profiles[i].userID == userID && profiles[i].isActive) {
//            char password[50];
//            printf("Enter password to update profile: ");
//            if (scanf("%49s", password) != 1) {
//                printf("Error reading password.\n");
//                return;
//            }
//
//            if (verify_password(userID, password)) {
//                printf("Enter new first name: ");
//                if (scanf("%49s", profiles[i].firstName) != 1) {
//                    printf("Error reading new first name.\n");
//                    return;
//                }
//
//                printf("Enter new last name: ");
//                if (scanf("%49s", profiles[i].lastName) != 1) {
//                    printf("Error reading new last name.\n");
//                    return;
//                }
//
//                printf("Enter new gamertag: ");
//                if (scanf("%49s", profiles[i].gamertag) != 1) {
//                    printf("Error reading new gamertag.\n");
//                    return;
//                }
//
//                printf("Profile updated successfully.\n");
//                found = 1;
//                break;
//            }
//            else {
//                printf("Incorrect password. Update failed.\n");
//                return;
//            }
//        }
//    }
//
//    if (!found) {
//        printf("Profile ID not found or profile is inactive. Update failed.\n");
//    }
//}
//
//// Function to delete a user profile
//void delete_profile() {
//    int userID;
//    printf("Enter the profile ID to delete: ");
//    if (scanf("%d", &userID) != 1) {
//        printf("Error reading profile ID.\n");
//        return;
//    }
//
//    char password[50];
//    printf("Enter password to delete profile: ");
//    if (scanf("%49s", password) != 1) {
//        printf("Error reading password.\n");
//        return;
//    }
//
//    int found = 0;
//    for (int i = 0; i < totalProfiles; i++) {
//        if (profiles[i].userID == userID && profiles[i].isActive) {
//            if (verify_password(userID, password)) {
//                profiles[i].isActive = 0; // Mark profile as inactive (deleted)
//                printf("Profile deleted successfully.\n");
//                found = 1;
//                break;
//            }
//            else {
//                printf("Incorrect password. Deletion failed.\n");
//                return;
//            }
//        }
//    }
//
//    if (!found) {
//        printf("Profile ID not found or profile is already inactive. Deletion failed.\n");
//    }
//}
//
//// Function to display all user profiles
//void display_profiles() {
//    printf("User Profiles:\n");
//    for (int i = 0; i < totalProfiles; i++) {
//        if (profiles[i].isActive) {
//            printf("Profile ID: %d\n", profiles[i].userID);
//            printf("Name: %s %s\n", profiles[i].firstName, profiles[i].lastName);
//            printf("Gamertag: %s\n", profiles[i].gamertag);
//            printf("Games Catalog:\n");
//            for (int j = 0; j < profiles[i].totalGames; j++) {
//                printf("Game %d:\n", j + 1);
//                printf("Title: %s\n", profiles[i].gameCatalog[j].title);
//                printf("Year: %d\n", profiles[i].gameCatalog[j].year);
//                printf("Rating: %.1f\n", profiles[i].gameCatalog[j].rating);
//            }
//            printf("\n");
//        }
//    }
//}
//
//// Function to verify the password
//int verify_password(int userID, const char* password) {
//    
//    }
//    return -1; // User ID not found or profile inactive
//}
