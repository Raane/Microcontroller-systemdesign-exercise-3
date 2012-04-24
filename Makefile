all:
	gcc *.c -g -o scorched-land-defence

run: all
	./scorched-land-defence

debug: all
	gdb scorched-land-defence
