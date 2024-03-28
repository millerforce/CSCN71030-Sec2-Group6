#pragma once

#include "GameFunctions.h"
#include <stdbool.h>

bool SaveProfile(USERPROFILE p);

PUSERPROFILE LoadProfile(char* name);

bool SaveGame(PGAME game, FILE* fp);

bool SaveGameCatalogue(PGAME games[]);

bool LoadGames(PGAME games[]);