all:
	gcc -o test1 test_knapsack.c knapsack.c

.PHONY: test
test:
	./test1

.PHONY: clean
clean:
		rm -rf *o test1
