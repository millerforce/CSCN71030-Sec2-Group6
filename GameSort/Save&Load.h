#pragma once

#include "Profiles.h"
#include "GameFunctions.h"
#include <stdbool.h>
#include <string.h>

bool SaveProfile(PUSERPROFILE user);

PUSERPROFILE LoadProfile(char* name, PGAME games[]);

bool SaveGameTitle(PGAME game, FILE* fp);

bool SaveGame(PGAME games[], FILE* fp, int index);

bool SaveGameCatalogue(PGAME games[]);

bool LoadGames(PGAME games[]);