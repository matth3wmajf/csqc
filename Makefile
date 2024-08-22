CC = cc
CFLAGS = -Wall -Wextra -O2 -Iinclude

SOURCES = $(wildcard source/*.c)
OBJECTS = $(SOURCES:source/%.c=source/%.o)

all: csqlang

csqlang: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

source/%.o: source/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) csqlang

.PHONY: all clean
