EXEC=DisplayAsciiTable
CFLAGS=-Wall -Wextra -Werror
CC=gcc
NAME=ft_ascii_table
.PHONY: run
run: $(EXEC)
	./$(EXEC)

$(EXEC): main.o $(NAME).o
	$(CC) $^ -o $(EXEC)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

$(NAME).o: $(NAME).c 
	$(CC) $(CFLAGS) -c $(NAME).c

.PHONY: clean
clean:
	rm -rf $(EXEC) *.o
