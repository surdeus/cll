all:V:test
test:V:
	cc *.c && ./a.out
clean:V:
	rm -f a.out
