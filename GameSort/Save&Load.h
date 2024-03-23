#pragma once

#include "GameFunctions.h"
#include <stdbool.h>

bool SaveProfile(USERPROFILE p);

PUSERPROFILE LoadProfile(char* name);

bool SaveGames(GAME games[]);

PGAME LoadGames();