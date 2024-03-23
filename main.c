#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "profiles.h"

int main() {
    int choice;
    int scanfResult; // Variable to store the return value of scanf

    do {
        printf("1. Create Profile\n");
        printf("2. Update Profile\n");
        printf("3. Delete Profile\n");
        printf("4. Display Profiles\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Check the return value of scanf
        scanfResult = scanf("%d", &choice);
        if (scanfResult != 1) {
            printf("Error reading choice. Please enter a valid integer.\n");

            // Clear input buffer
            while (getchar() != '\n'); // Discard remaining characters in input buffer

            continue; // Skip the rest of the loop and restart
        }

        switch (choice) {
        case 1:
            create_profile();
            break;
        case 2:
            if (totalProfiles == 0) {
                printf("No profiles available to update.\n");
                break;
            }
            update_profile();
            break;
        case 3:
            if (totalProfiles == 0) {
                printf("No profiles available to delete.\n");
                break;
            }
            delete_profile();
            break;
        case 4:
            if (totalProfiles == 0) {
                printf("No profiles available to display.\n");
                break;
            }
            display_profiles();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}