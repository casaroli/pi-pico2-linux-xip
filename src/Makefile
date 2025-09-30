CC = gcc

.PHONY: clean

hello: hello.c alloc
	$(CC) -fPIC -Os -g0 -static -Wl,-elf2flt=-r -o '$@' '$<'

alloc: alloc.c
	$(CC) -fPIC -Os -g0 -static -Wl,-elf2flt=-r -o '$@' '$<'

clean:
	rm hello alloc
