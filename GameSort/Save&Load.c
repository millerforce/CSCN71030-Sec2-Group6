
#include "Save&Load.h"

bool SaveProfile(USERPROFILE p) {

}

PUSERPROFILE LoadProfile(char* name, PGAME games[]) {
	PGAME tempGames[MAX_GAMES] = { 0 };
		//= (PGAME)malloc(sizeof(GAME));
	//PUSERPROFILE tempUser = (PGAME)malloc(sizeof(GAME));
	int ID;
	char first[MAXNAME], last[MAXNAME], tag[MAXNAME], password[MAXPASSWORD];
	FILE* fp = fopen("John.dat", "r");

	if (fp == NULL || tempGames == NULL)
		exit(2);

	fscanf(fp, "%d\n", &ID);
	fscanf(fp, " %[^\n]s\n", first);
	fscanf(fp, " %[^\n]s\n", last);
	fscanf(fp, " %[^\n]s\n", tag);
	fscanf(fp, " %[^\n]s\n\n", password);

	char title[MAXTITLE];
	int index;

	while (fscanf(fp, " %[^\n]s\n", title) != EOF) {
		index = SearchForGame(games, title);
		if (index != -1) {
			AddGameToProfile(tempGames, games[index]);
		}
	}

	PUSERPROFILE temp = create_profile(ID, first, last, tag, password, tempGames);

	//free(tempGames);
	fclose(fp);

	return temp;
}

bool SaveGame(PGAME games[], FILE* fp, int index) {
	fprintf(fp, "%s\n", getTitle(games, index));
	fprintf(fp, "%d\n", getID(games, index));
	fprintf(fp, "%s\n", getGenre(games, index));
	fprintf(fp, "%s\n", getDescription(games, index));
	fprintf(fp, "%d\n", getLength(games, index));
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
			SaveGame(games, fp, i);
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

	while (fscanf(fp, " %[^\n]s\n", title) != EOF) {
		fscanf(fp, "%d\n", &ID);
		fscanf(fp, " %[^\n]s\n", genre);
		fscanf(fp, " %[^\n]s\n", description);
		fscanf(fp, "%d\n\n", &length);
		games[index] = CreateGame(ID, title, genre, description, length);
		index++;

		if (feof(fp))
			break;
	} ;
	fclose(fp);
	return true;
}