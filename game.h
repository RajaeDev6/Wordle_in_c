#ifndef GAME_H
#define GAME_H

typedef struct {

	char *word;
	int guesses;
	const char *wordlist_path;

} Game;

Game *initGame(const char *wordlist_path);

void StartGame(Game *game);

#endif
