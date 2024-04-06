/*  if (totalProfiles >= MAX_PROFILES) {
      printf("Maximum number of profiles reached. Cannot create more profiles.\n");
      return;
  }*/

  //printf("Creating a new profile...\n");
  //printf("Enter first name: ");
  //if (scanf("%49s", profiles[totalProfiles].firstName) != 1) {
  //    printf("Error reading first name.\n");
  //    return;
  //}

  //printf("Enter last name: ");
  //if (scanf("%49s", profiles[totalProfiles].lastName) != 1) {
  //    printf("Error reading last name.\n");
  //    return;
  //}

  //printf("Enter gamertag: ");
  //if (scanf("%49s", profiles[totalProfiles].gamertag) != 1) {
  //    printf("Error reading gamertag.\n");
  //    return;
  //}

  //printf("Enter password for the profile: ");
  //if (scanf("%49s", profiles[totalProfiles].password) != 1) {
  //    printf("Error reading password.\n");
  //    return;
  //}

////profiles[totalProfiles].userID = generate_profile_id();
//   //profiles[totalProfiles].isActive = 1; // Set profile as active
//   //profiles[totalProfiles].totalGames = 0; // Initialize totalGames for the new profile
//
//   // Prompt the user to add games to the catalog
//printf("Add games to the catalog (enter 'done' to finish):\n");
//char input[100];
//do {
//    printf("Enter game title (or 'done' to finish): ");
//    if (scanf("%99s", input) != 1) {
//        printf("Error reading game title.\n");
//        return;
//    }
//    input[99] = '\0'; // Ensure input is null-terminated
//
//    if (strcmp(input, "done") == 0) {
//        break;
//    }
//
//    // Add the game to the catalog
//    if (profiles[totalProfiles].totalGames < MAX_GAMES) {
//        strcpy(profiles[totalProfiles].gameCatalog[profiles[totalProfiles].totalGames].title, input);
//        int year, scanfResult;
//        do {
//            printf("Enter game year: ");
//            scanfResult = scanf("%d", &year);
//            if (scanfResult != 1) {
//                printf("Invalid input. Please enter an integer for the year.\n");
//                while (getchar() != '\n'); // Clear input buffer
//            }
//        } while (scanfResult != 1);
//        profiles[totalProfiles].gameCatalog[profiles[totalProfiles].totalGames].year = year;
//
//        float rating;
//        do {
//            printf("Enter game rating: ");
//            scanfResult = scanf("%f", &rating);
//            if (scanfResult != 1) {
//                printf("Invalid input. Please enter a number for the rating.\n");
//                while (getchar() != '\n'); // Clear input buffer
//            }
//        } while (scanfResult != 1);
//        profiles[totalProfiles].gameCatalog[profiles[totalProfiles].totalGames].rating = rating;
//
//        profiles[totalProfiles].totalGames++;
//    }
//    else {
//        printf("Maximum number of games reached. Cannot add more games.\n");
//        break;
//    }
//} while (1);
//
//totalProfiles++;
//
//printf("Profile created successfully. Profile ID is %d\n", profiles[totalProfiles - 1].userID);