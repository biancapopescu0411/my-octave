CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS=my_octave

build: $(TARGETS)

my_octave: *.c
	$(CC) $(CFLAGS) *.c -o my_octave

pack:
	zip -FSr 325CA_PopescuMariaBianca_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean