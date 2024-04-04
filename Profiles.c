#include "profiles.h"
#include <stdio.h>
#include <string.h>

UserProfile profiles[MAX_PROFILES];
int totalProfiles = 0;

// Function to generate a unique profile ID
int generate_profile_id() {
    static int nextID = 1000;
    return nextID++;
}

// Function to create a new user profile
void create_profile() {
    if (totalProfiles >= MAX_PROFILES) {
        printf("Maximum number of profiles reached. Cannot create more profiles.\n");
        return;
    }

    printf("Creating a new profile...\n");
    printf("Enter first name: ");
    if (scanf("%49s", profiles[totalProfiles].firstName) != 1) {
        printf("Error reading first name.\n");
        return;
    }

    printf("Enter last name: ");
    if (scanf("%49s", profiles[totalProfiles].lastName) != 1) {
        printf("Error reading last name.\n");
        return;
    }

    printf("Enter gamertag: ");
    if (scanf("%49s", profiles[totalProfiles].gamertag) != 1) {
        printf("Error reading gamertag.\n");
        return;
    }

    printf("Enter password for the profile: ");
    if (scanf("%49s", profiles[totalProfiles].password) != 1) {
        printf("Error reading password.\n");
        return;
    }

    profiles[totalProfiles].userID = generate_profile_id();
    profiles[totalProfiles].isActive = 1; // Set profile as active
    profiles[totalProfiles].totalGames = 0; // Initialize totalGames for the new profile

    // Prompt the user to add games to the catalog
    printf("Add games to the catalog (enter 'done' to finish):\n");
    char input[100];
    do {
        printf("Enter game title (or 'done' to finish): ");
        if (scanf("%99s", input) != 1) {
            printf("Error reading game title.\n");
            return;
        }
        input[99] = '\0'; // Ensure input is null-terminated

        if (strcmp(input, "done") == 0) {
            break;
        }

        // Add the game to the catalog
        if (profiles[totalProfiles].totalGames < MAX_GAMES) {
            strcpy(profiles[totalProfiles].gameCatalog[profiles[totalProfiles].totalGames].title, input);
            int year, scanfResult;
            do {
                printf("Enter game year: ");
                scanfResult = scanf("%d", &year);
                if (scanfResult != 1) {
                    printf("Invalid input. Please enter an integer for the year.\n");
                    while (getchar() != '\n'); // Clear input buffer
                }
            } while (scanfResult != 1);
            profiles[totalProfiles].gameCatalog[profiles[totalProfiles].totalGames].year = year;

            float rating;
            do {
                printf("Enter game rating: ");
                scanfResult = scanf("%f", &rating);
                if (scanfResult != 1) {
                    printf("Invalid input. Please enter a number for the rating.\n");
                    while (getchar() != '\n'); // Clear input buffer
                }
            } while (scanfResult != 1);
            profiles[totalProfiles].gameCatalog[profiles[totalProfiles].totalGames].rating = rating;

            profiles[totalProfiles].totalGames++;
        }
        else {
            printf("Maximum number of games reached. Cannot add more games.\n");
            break;
        }
    } while (1);

    totalProfiles++;

    printf("Profile created successfully. Profile ID is %d\n", profiles[totalProfiles - 1].userID);
}

// Function to update an existing user profile
void update_profile() {
    int userID;
    printf("Enter the profile ID to update: ");
    if (scanf("%d", &userID) != 1) {
        printf("Error reading profile ID.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < totalProfiles; i++) {
        if (profiles[i].userID == userID && profiles[i].isActive) {
            char password[50];
            printf("Enter password to update profile: ");
            if (scanf("%49s", password) != 1) {
                printf("Error reading password.\n");
                return;
            }

            if (verify_password(userID, password)) {
                printf("Enter new first name: ");
                if (scanf("%49s", profiles[i].firstName) != 1) {
                    printf("Error reading new first name.\n");
                    return;
                }

                printf("Enter new last name: ");
                if (scanf("%49s", profiles[i].lastName) != 1) {
                    printf("Error reading new last name.\n");
                    return;
                }

                printf("Enter new gamertag: ");
                if (scanf("%49s", profiles[i].gamertag) != 1) {
                    printf("Error reading new gamertag.\n");
                    return;
                }

                printf("Profile updated successfully.\n");
                found = 1;
                break;
            }
            else {
                printf("Incorrect password. Update failed.\n");
                return;
            }
        }
    }

    if (!found) {
        printf("Profile ID not found or profile is inactive. Update failed.\n");
    }
}

// Function to delete a user profile
void delete_profile() {
    int userID;
    printf("Enter the profile ID to delete: ");
    if (scanf("%d", &userID) != 1) {
        printf("Error reading profile ID.\n");
        return;
    }

    char password[50];
    printf("Enter password to delete profile: ");
    if (scanf("%49s", password) != 1) {
        printf("Error reading password.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < totalProfiles; i++) {
        if (profiles[i].userID == userID && profiles[i].isActive) {
            if (verify_password(userID, password)) {
                profiles[i].isActive = 0; // Mark profile as inactive (deleted)
                printf("Profile deleted successfully.\n");
                found = 1;
                break;
            }
            else {
                printf("Incorrect password. Deletion failed.\n");
                return;
            }
        }
    }

    if (!found) {
        printf("Profile ID not found or profile is already inactive. Deletion failed.\n");
    }
}

// Function to display all user profiles
void display_profiles() {
    printf("User Profiles:\n");
    for (int i = 0; i < totalProfiles; i++) {
        if (profiles[i].isActive) {
            printf("Profile ID: %d\n", profiles[i].userID);
            printf("Name: %s %s\n", profiles[i].firstName, profiles[i].lastName);
            printf("Gamertag: %s\n", profiles[i].gamertag);
            printf("Games Catalog:\n");
            for (int j = 0; j < profiles[i].totalGames; j++) {
                printf("Game %d:\n", j + 1);
                printf("Title: %s\n", profiles[i].gameCatalog[j].title);
                printf("Year: %d\n", profiles[i].gameCatalog[j].year);
                printf("Rating: %.1f\n", profiles[i].gameCatalog[j].rating);
            }
            printf("\n");
        }
    }
}

// Function to verify the password
int verify_password(int userID, const char* password) {
    for (int i = 0; i < totalProfiles; i++) {
        if (profiles[i].userID == userID && profiles[i].isActive) {
            if (strcmp(profiles[i].password, password) == 0) {
                return 1; // Password matches
            }
            else {
                return 0; // Password does not match
            }
        }
    }
    return -1; // User ID not found or profile inactive
}
