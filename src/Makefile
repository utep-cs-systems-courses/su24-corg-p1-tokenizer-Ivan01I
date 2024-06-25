OBJ = uimain.o tokenizer.o history.o
CFLAGS=-g -O3
all: tokenizer
tokenizer: $(OBJ)
	cc -o tokenizer $(CFLAGS) $(OBJ) && rm -f *.o
$(OBJ): tokenizer.h history.h
clean:
	rm -f *.o tokenizer
run:tokenizer
	./tokenizer
