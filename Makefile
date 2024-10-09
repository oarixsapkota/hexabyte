CC :=x86_64-w64-mingw32-gcc
CCFLG :=-I src/include

all:
	$(CC) -c src/hex.c $(CCFLG)
	$(CC) -c src/file.c $(CCFLG)
	$(CC) -c src/lexcial.c $(CCFLG)
	$(CC) -o main.exe file.o hex.o lexcial.o $(CCFLG)

.PHONY: all hexdmp
