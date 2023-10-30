CFLAGS = -g -O3
OBJS = ui.o tokenizer.o history.o

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)

# file dependencies
tokenizer.o: tokenizer.h tokenizer.c
history.o: history.h history.c
ui.o: tokenizer.h history.h

clean:
	rm -f *.o tokenizer

run: tokenize
	./tokenize
