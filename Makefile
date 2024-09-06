CFLAGS = -Iinclude

SOURCES := $(wildcard source/*.c)
OBJECTS := $(SOURCES:.c=.o)

all: csqlang

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

csqlang: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(OBJECTS) csqlang