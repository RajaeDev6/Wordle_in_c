#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 5

int count_lines(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;

    int lines = 0;
    char buffer[WORD_LEN + 2]; // word + '\n' + '\0'

    while (fgets(buffer, sizeof(buffer), f))
        lines++;

    fclose(f);
    return lines;
}

char *get_random_word(const char *path) {
    int total_lines = count_lines(path);
    if (total_lines == 0) return NULL;

    FILE *f = fopen(path, "r");
    if (!f) return NULL;

    int r = rand() % total_lines;
    char buffer[WORD_LEN + 2];

    for (int i = 0; i <= r; i++) {
        if (!fgets(buffer, sizeof(buffer), f)) {
            fclose(f);
            return NULL;
        }
    }

    fclose(f);

    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) != WORD_LEN)
        return NULL;

    char *out_word = malloc(WORD_LEN + 1);
    if (!out_word) return NULL;

    strcpy(out_word, buffer);
    return out_word;
}

