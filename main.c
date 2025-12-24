#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "word.h"
#include "game.h"



int main() {

	srand(time(NULL));

	Game *game = initGame("wordlist.txt");

	StartGame(game);

	printf("\nGame end");
}
