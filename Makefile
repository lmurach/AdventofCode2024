CC = gcc
DAY = 2b
CFLAGS = -I ./day$(DAY)/include/ -I ./lnm/include
DEPS = $(wildcard **/*.h)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

day$(DAY)file: $(wildcard **/*.c)
	$(CC) -g -o day$(DAY)file $(wildcard ./day$(DAY)/*.c) $(wildcard ./lnm/*.c) $(CFLAGS)

.PHONY: clean

clean:
	rm -f day$(DAY)/*.o
