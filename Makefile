CCwin :=x86_64-w64-mingw32-gcc
CClux :=gcc

all:
	$(CCwin) -o hex.exe src/main.c
	$(CClux) -o hex.bin src/main.c

.PHONY: all