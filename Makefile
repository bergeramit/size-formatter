XMACROS = $(wildcard *.mx)
SRC = $(wildcard *.c)
HEADER = $(wildcard *.h)
ASSEMBLY = $(SRC:.c=.s)

sf:
	gcc $(SRC) $(HEADER) $(XMACROS) -S
	gcc -o $@ $(ASSEMBLY)

debug:
	gcc $(SRC) $(HEADER) $(XMACROS) -D DEBUG -S
	gcc -o sf $(ASSEMBLY)

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

