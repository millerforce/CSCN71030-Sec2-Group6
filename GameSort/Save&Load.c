
#include "Save&Load.h"

bool SaveProfile(USERPROFILE p) {

}

PUSERPROFILE LoadProfile(char* name) {

}

bool SaveGame(PGAME game, FILE* fp) {
	fprintf(fp, "%s\n", game->title);
	fprintf(fp, "%d\n", game->gameID);
	fprintf(fp, "%s\n", game->genre);
	fprintf(fp, "%s\n", game->description);
	fprintf(fp, "%d\n", game->length);
	return true;
}

bool SaveGameCatalogue(PGAME games[]) {
	FILE* fp = fopen("GameCatalogue.dat", "w");

	if (fp == NULL) {
		printf("ERROR opening main catalogue program will now exit\n");
		exit(1);
	}

	//fprintf(fp, "\n");

	for (int i = 0; i < MAX_GAMES; i++) {
		if (games[i] != NULL)
			SaveGame(games[i], fp);
		fprintf(fp, "\n");
	}

	fclose(fp);

	return true;

}

bool LoadGames(PGAME games[]) {
	FILE* fp = fopen("GameCatalogue.dat", "r");
	char title[MAXTITLE], genre[MAXGENRE], description[MAXDESCRIPTION];
	int ID, length;
	if (fp == NULL)
		return false;
	int index = 0;

	//if (fgetc(fp) == EOF) return true;

	while (fscanf(fp, "%s\n", title) != EOF) {
		fscanf(fp, "%d\n", &ID);
		fscanf(fp, "%s\n", genre);
		fscanf(fp, "%s\n", description);
		fscanf(fp, "%d\n\n", &length);
		games[index] = CreateGame(ID, title, genre, description, length);
		index++;

		if (feof(fp))
			break;
	} ;
	fclose(fp);
	return true;
}