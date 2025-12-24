#include "word.h"
#include "game.h"
#include <time.h>



int main() {

	srand(time(NULL));

	Game *game = initGame("wordlist.txt");

	StartGame(game);

	printf("\nGame end");
}
