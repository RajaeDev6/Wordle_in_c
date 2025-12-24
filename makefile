CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c11
TARGET  = wordle

SRC     = main.c game.c word.c

.PHONY: all clean run

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

