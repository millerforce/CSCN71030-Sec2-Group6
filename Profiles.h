#pragma once

#define _CRT_SECURE_NO_WARNINGS

#ifndef PROFILES_H
#define PROFILES_H

#define MAX_PROFILES 10

// Struct for a user profile
typedef struct {
    int userID;
    char firstName[50];
    char lastName[50];
    char gamertag[50];
    int isActive; // Flag to indicate if the profile is active or deleted
} UserProfile;

extern UserProfile profiles[MAX_PROFILES];
extern int totalProfiles;

// Function declarations
int generate_profile_id();
void create_profile();
void update_profile();
void delete_profile();
void display_profiles();

#endif /* PROFILES_H */

