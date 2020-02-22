XMACROS = $(wildcard *.xm)
SRC = $(wildcard *.c)
HEADER = $(wildcard *.h)
OBJECTS = $(SRC:.c=.o)
OUTPUT_NAME = sf

$(OUTPUT_NAME):
	gcc -o $(OUTPUT_NAME) $(OBJECTS)
	rm -f $(OBJECTS)

release:
	gcc $(SRC) $(HEADER) -imacros $(XMACROS) -c
	make $(OUTPUT_NAME)

debug:
	gcc $(OUTPUT_NAME) $(SRC) $(HEADER) -imacros $(XMACROS) -DDEBUG -c
	make $(OUTPUT_NAME)

.PHONY: clean

clean:
	rm -f *.o *.s *.gch sf

remake:
	make clean && make sf

install:
	make release
	cp ./sf /usr/local/bin/sf
	make clean
	@echo "sf -> installed successfully"
	@echo "run sf for the usage"

