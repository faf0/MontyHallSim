#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 * Returns the position of the door that the player may switch to,
 * given the door position of the player's initial choice and the
 * door position of the shown goat.
 * 
 * @param pos1 the door position of the shown goat.
 * @param pos2 the door position of the player's initial choice.
 */
static int getSwitchPos(int pos1, int pos2) {
  /* assert: 0 <= pos1, pos2 <= 2 && pos1 != pos2 */
  switch (pos1 + pos2) {
    case 1: /* (0,1) or (1,0) */
      return 2;
    case 2: /* (0,2) or (2,0) */
      return 1;
    case 3: /* (1,2) or (2,1) */
      return 0;
    default:
      exit(EXIT_FAILURE);
  }
}

/*
 * Runs the specified number of games with the specified
 * player behavior.
 * 
 * @param switches if zero, the player will switch his initial
 *                 choice.
 *                 Otherwise, the player will not switch his initial
 *                 choice.
 * @param games    the number of games.
 */
static void runGame(int switches, int games) {
  int win = 0;

  if (switches) {
    for (int i = 0; i < games; i++) {
      int carPos = rand() % 3;
      int firstPlayerChoice = rand() % 3;
      int shownGoatPos = rand() % 3;

      /* Determine random position of shown goat. */
      while (shownGoatPos == carPos || shownGoatPos == firstPlayerChoice) {
        shownGoatPos = rand() % 3;
      }

      /* The player switches */
      if (getSwitchPos(shownGoatPos, firstPlayerChoice) == carPos) {
        win++;
      }
    }
  } else {
    /* Player does not switch */
    for (int i = 0; i < games; i++) {
      int carPos = rand() % 3;
      int playerChoice = rand() % 3;

      if (playerChoice == carPos) {
        win++;
      }
    }
  }

  printf("Number of games: %d. The player won %d times and lost %d times.\n"
      "Success rate: %f\n",
      games, win, games - win, (double) win / (double) games);
}

/*
 * Parse the command-line parameters and run the simulation.
 */
int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Syntax: %s B N.\n\nSet B to 0 if the player never switches."
        "\nIf B is 1 then the player always switches."
        "\nN is an integer representing the number of games.\n", argv[0]);
    return EXIT_FAILURE;
  } else {
    int switches;
    int games;

    switches = atoi(argv[1]);
    if ((switches != 0) && (switches != 1)) {
      printf("The first parameter must be either zero or one!\n");
      return EXIT_FAILURE;
    }

    games = atoi(argv[2]);
    if (games < 1) {
      printf("The second parameter must be an integer greater than zero!\n");
      return EXIT_FAILURE;
    }

    srand((unsigned) time(NULL));
    runGame(switches, games);
    return EXIT_SUCCESS;
  }
}
