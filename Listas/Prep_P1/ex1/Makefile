PROGS = test_static test_dynamic

all: $(PROGS)

test_static:
	gcc -o test_static test_static.c staticdeque.c

test_dynamic:
	gcc -o test_dynamic test_dynamic.c dynamicdeque.c

clean:
	rm -f *.o $(PROGS)
