XMACRO = $(wildcard *.mx)
SRC = $(wildcard *.c)
HEADER = $(wildcard *.h)
ASSEMBLY = $(SRC:.c=.s)

sf:
	gcc $(SRC) $(HEADER) $(XMACRO) -S
	gcc -o $@ $(ASSEMBLY)

.PHONY: clean

clean:
	rm -f *.o *.s sf
