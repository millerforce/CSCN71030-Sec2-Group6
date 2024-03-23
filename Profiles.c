#include "profiles.h"
#include <stdio.h>

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

    profiles[totalProfiles].userID = generate_profile_id();
    profiles[totalProfiles].isActive = 1; // Set profile as active
    totalProfiles++;

    printf("Profile created successfully. Profile ID is %d\n", profiles[totalProfiles - 1].userID);
}

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
    }

    if (!found) {
        printf("Profile ID not found or profile is inactive. Update failed.\n");
    }
}
void delete_profile() {
    int userID;
    printf("Enter the profile ID to delete: ");
    if (scanf("%d", &userID) != 1) {
        printf("Error reading profile ID.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < totalProfiles; i++) {
        if (profiles[i].userID == userID && profiles[i].isActive) {
            profiles[i].isActive = 0; // Mark profile as inactive (deleted)
            printf("Profile deleted successfully.\n");
            found = 1;
            break;
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
            printf("Gamertag: %s\n\n", profiles[i].gamertag);
        }
    }
}
