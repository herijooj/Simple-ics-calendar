# Escrito por mim, debugado por Deus...
CC	 = gcc
FLAGS	 = -g3 -c -Wall
LFLAGS	 = -lical

all: main calendar.o

main: calendar.o
	$(CC) -g3 -Wall -g calendar.o -o main -lical main.c

calendar.o: calendar.c
	$(CC) $(FLAGS) calendar.c

# clean
clean:
	rm -f $(OBJS) $(OUT)

# Purge
purge:
	rm -f $(OBJS) $(OUT) calendar.o main

# run
run: $(OUT)
	./$(OUT)

# debug
debug: $(OUT)
	valgrind $(OUT)

# valgrind
valgrind: $(OUT)
	valgrind $(OUT)

# valgrind leak checks
valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

# valgrind leak checks (extreme)
valgrind_extreme: $(OUT)
	valgrind -s --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)