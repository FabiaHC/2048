OBJ=main.o board.o logic.o

%.o: %.c
	g++ -c -o $@ $<

2038Game: $(OBJ)
	g++ -o 2048 $(OBJ) -I.

.PHONY: clean
clean:
	del /s *.o
