#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "word.h"

#define WORD_LEN 5

Game *initGame(const char *wordlist_path) {
    Game *game = malloc(sizeof(Game));
    if (!game) return NULL;

    game->word = NULL;
    game->guesses = 5;
    game->wordlist_path = wordlist_path;

    return game;
}

char *get_word(const char *wordfile_path) {
    return get_random_word(wordfile_path);
}

int check_correct_word(const char *user_word, const char *current_word) {
    return strcmp(user_word, current_word) == 0;
}

char *get_user_input(void) {
    char *user_input = malloc(WORD_LEN + 1);
    if (!user_input) return NULL;

    while (1) {
        printf("\nGuess word: ");
        scanf("%5s", user_input);

        if (strlen(user_input) == WORD_LEN)
            break;

        printf("Please enter exactly 5 letters.\n");
    }

    return user_input;
}

void display_guesses(const char *user_word, const char *current_word, int *won) {
    char display[WORD_LEN + 1] = "_____";
    int used[26] = {0};

    if (check_correct_word(user_word, current_word)) {
        printf("You Won!\nCorrect word: %s\n\n", current_word);
        *won = 0;
        return;
    }

    for (int i = 0; i < WORD_LEN; i++)
        used[current_word[i] - 'a']++;

    for (int i = 0; i < WORD_LEN; i++) {
        if (user_word[i] == current_word[i]) {
            display[i] = user_word[i];
            used[user_word[i] - 'a']--;
        }
    }

    for (int i = 0; i < WORD_LEN; i++) {
        if (display[i] == '_' && used[user_word[i] - 'a'] > 0) {
            display[i] = '^';
            used[user_word[i] - 'a']--;
        }
    }

    for (int i = 0; i < WORD_LEN; i++)
        printf("%c ", display[i]);

    printf("\n\n");
}

void StartGame(Game *game) {
    if (!game) return;

    system("clear");
    printf("Wordle\n\n");
    printf("_ _ _ _ _\n");

    game->word = get_word(game->wordlist_path);
    if (!game->word) return;

    int guesses = 0;
    int won = 1;

    while (guesses < game->guesses && won) {
        char *user_guess = get_user_input();
        if (!user_guess) break;

        display_guesses(user_guess, game->word, &won);

        free(user_guess);
        guesses++;
    }

    if (won)
        printf("You ran out of guesses! Word was: %s\n", game->word);

    free(game->word);
    free(game);
}

