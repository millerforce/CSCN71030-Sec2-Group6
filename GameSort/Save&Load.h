#pragma once

#include "Profiles.h"
#include "GameFunctions.h"
#include <stdbool.h>

bool SaveProfile(USERPROFILE p);

PUSERPROFILE LoadProfile(char* name, PGAME games[]);

bool SaveGame(PGAME games[], FILE* fp, int index);

bool SaveGameCatalogue(PGAME games[]);

bool LoadGames(PGAME games[]);