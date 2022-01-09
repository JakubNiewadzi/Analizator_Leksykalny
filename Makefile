a.out: stack_test.o fun_stack.o
	$(CC) $^

stack_test.o: fun_stack.h
fun_stack.o: fun_stack.h
