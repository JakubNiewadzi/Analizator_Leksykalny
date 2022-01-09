a.out: main.o alex.o fun_stack.o parser.o store.o
	$(CC) $^

main.o: parser.h store.h
alex.o: alex.h fun_stack.h
fun_stack.o: fun_stack.h
parser.o: alex.h fun_stack.h store.h
store.o: store.h fun_stack.h