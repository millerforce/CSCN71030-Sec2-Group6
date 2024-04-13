
#include "Save&Load.h"

bool SaveGameTitle(PGAME game, FILE* fp) {
	fprintf(fp, "%s\n", game->title);
	return true;
}

bool SaveProfile(PUSERPROFILE user) {
	char tempFirst[MAXNAME];
	strcpy(tempFirst, user->firstName);
	strcat(tempFirst, ".dat");
	FILE* fp = fopen(tempFirst, "w");

	if (fp == NULL)
		exit(3);
	fprintf(fp, "%d\n", getUserID(user));
	fprintf(fp, "%s\n", getFirstName(user));
	fprintf(fp, "%s\n", getLastName(user));
	fprintf(fp, "%s\n", getGamertag(user));
	fprintf(fp, "%s\n\n", getPassword(user));

	//int numGames = getTotalGames(user->gameCatalog);

	for (int i = 0; i < MAX_GAMES; i++) {
		if (user->gameCatalog[i] != NULL)
		SaveGameTitle(user->gameCatalog[i], fp);
	}

	return true;
	fclose(fp);
}

PUSERPROFILE LoadProfile(char* name, PGAME games[]) {
	PGAME tempGames[MAX_GAMES] = { 0 };
		//= (PGAME)malloc(sizeof(GAME));
	//PUSERPROFILE tempUser = (PGAME)malloc(sizeof(GAME));
	strcat(name, ".dat");
	FILE* fp = fopen(name, "r");
	int ID;
	char first[MAXNAME], last[MAXNAME], tag[MAXNAME], password[MAXPASSWORD];
	if (fp == NULL)
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

bool LoadProfileList(PUSERPROFILE users[MAX_PROFILES], PGAME games[]) {
	char names[MAX_PROFILES][MAXNAME] = { 0 };
	FILE* fp = fopen("profileList.txt", "r");
	int j = 0;
	if (fp == NULL)
		exit(-2);

	while (fscanf(fp, "%s\n", names[j]) != EOF) {
		j++;
	}

	for (int i = 0; i < MAX_PROFILES; i++) {
		if (strlen(names[i]) > 0)
		users[i] = LoadProfile(names[i], games);
	}

	fclose(fp);
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