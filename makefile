compile:
	gcc -o output ./src/*.c *.c -lm
run:
	./output
del:
	rm output