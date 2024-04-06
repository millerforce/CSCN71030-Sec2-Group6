#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include "GameFunctions.h"
// Functions


void get_recommendations(const GAME games[], int currentProfileIndex);
void search_game_catalogue(const GAME games[], int totalGAMEs);
static void generateRandomDate(char* dateStr);