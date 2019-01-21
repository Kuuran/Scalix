OBJ=scalix.o scalix_l.o scalix_y.o
CC=gcc
CFLAGS=-Wall -ansi -std=c99 -I./ -g
LDFLAGS= -g -lfl
scalix : $(OBJ)
	$(CC) -o scalix $(OBJ) $(LDFLAGS)

test_lex: scalix_y.h test_lex.o scalix_l.o
	$(CC) -o test_lex  test_lex.o scalix_l.o $(LDFLAGS)

# Si absent lance yacc et fait "mv y.tab.c tp.c" ce qui ecrase notre fichier.
scalix.c :
	echo ''

scalix.o: scalix.c scalix_y.h scalix.h
	$(CC) $(CFLAGS) -c scalix.c

scalix_l.o: scalix_l.c scalix_y.h
	$(CC) $(CFLAGS) -Wno-unused-function -Wno-implicit-function-declaration -c scalix_l.c

scalix_l.c:scalix.l
	flex --yylineno -oscalix_l.c scalix.l

scalix_y.o : scalix_y.c
	$(CC) $(CFLAGS) -c scalix_y.c

scalix_y.h scalix_y.c : scalix.y scalix.h
	bison -v -d -o scalix_y.c scalix.y

test_lex.o : test_lex.c scalix.h scalix_y.h
	$(CC) $(CFLAGS) -c test_lex.c

.Phony: clean

clean:
	rm -f *~ scalix ./scalix.o scalix_l.* scalix_y.* test_lex scalix_y.output
