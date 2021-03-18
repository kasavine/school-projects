CC		= gcc
FLAGS	= -Wall -Wextra -Werror
NAME	= ngram

all: $(NAME)

$(NAME): ngram.o
	$(CC) $(FLAGS) ngram.o -o $(NAME)

my_mastermind.o: ngram.c
	$(CC) $(FLAGS) -c ngram.c

clean:
	rm *.o $(NAME)

.PHONY: all clean
