#pragma once

#include "Profiles.h"
#include "GameFunctions.h"
#include <stdbool.h>
#include <string.h>

bool SaveProfile(PUSERPROFILE user);

bool SaveAllProfiles(PUSERPROFILE users[MAX_PROFILES]);

PUSERPROFILE LoadProfile(char* name, PGAME games[]);

bool LoadProfileList(PUSERPROFILE users[MAX_PROFILES], PGAME games[]);

bool SaveProfileList(PUSERPROFILE users[MAX_PROFILES]);

bool SaveGameTitle(PGAME game, FILE* fp);

bool SaveGame(PGAME games[], FILE* fp, int index);

bool SaveGameCatalogue(PGAME games[]);

bool LoadGames(PGAME games[]);