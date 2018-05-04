PROGS = test_stack test_stackmin

all: $(PROGS)

test_stack:
	gcc -o test_stack test_stack.c stack.c

test_stackmin:
	gcc -o test_stackmin test_stackmin.c stack.c stackmin.c

clean:
	rm -f *.o $(PROGS)
