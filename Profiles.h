#pragma once

#define _CRT_SECURE_NO_WARNINGS

#ifndef PROFILES_H
#define PROFILES_H

#include <stdbool.h> // Include for boolean type

#define MAX_PROFILES 10
#define MAX_GAMES 50

// Struct for a game in the catalog
typedef struct {
    char title[100];
    int year;
    float rating;
} Game;

// Struct for a user profile
typedef struct {
    int userID;
    char firstName[50];
    char lastName[50];
    char gamertag[50];
    char password[50]; // Password field
    int isActive; // Flag to indicate if the profile is active or deleted
    Game gameCatalog[MAX_GAMES]; // Array to store the game catalog
    int totalGames; // Number of games in the catalog
} UserProfile;

extern UserProfile profiles[MAX_PROFILES];
extern int totalProfiles;

// Function declarations
int generate_profile_id();
void create_profile();
void update_profile();
void delete_profile();
void display_profiles();
int verify_password(int userID, const char* password);

#endif /* PROFILES_H */
