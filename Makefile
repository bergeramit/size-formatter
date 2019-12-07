XMACRO = $(wildcard *.mx)
SRC = $(wildcard *.c)
HEADER = $(wildcard *.h)
ASSEMBLY = $(SRC:.c=.s)

sf:
	gcc $(SRC) $(HEADER) $(XMACRO) -S
	gcc -o $@ $(ASSEMBLY)

.PHONY: clean

clean:
	rm -f *.o *.s *.gch sf

remake:
	make clean && make

install:
	make
	cp ./sf /usr/local/bin/sf
	make clean
	@echo "sf -> installed successfully"
	@echo "run sf for the usage"

