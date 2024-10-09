#CC :=x86_64-w64-mingw32-gcc
CC :=gcc
CCFLG :=-I src/include

all: main

main: hex.o lexcial.o file.o hexlib.o
	$(CC) -o main hex.o lexcial.o file.o hexlib.o $(CCFLG)

hex.o: src/hex.c
	$(CC) -c src/hex.c $(CCFLG)

lexcial.o: src/lexcial.c
	$(CC) -c src/lexcial.c $(CCFLG)

file.o: src/file.c
	$(CC) -c src/file.c $(CCFLG)

hexlib.o: src/hexlib.c
	$(CC) -c src/hexlib.c $(CCFLG)

clean:
	rm -f *.o *.exe main

.PHONY: all clean
