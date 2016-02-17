# each line of the Makefile is a rule 

# the first rule is executed if we don't specify a label:
# in this case we can execute the rule calc either as 
# make calc
# or as just
# make
	
# each rule has on the left hand side of the colon the target (what we want to achieve)
# and on the rhs the list of dependencies needed in order to achieve it

# right afterwards (always preceded by a tab) there is the command
# which achieves the result 

# (compare this structure with BNF grammars)

# for instance in order to obtain the executable calc
# we need the .o files of each of the components... 

calc: Calculator.tab.o lex.yy.o
	g++ -o calc Calculator.tab.o lex.yy.o
	
# ...and we obtain each .o file compiling each source file with the option -c

lex.yy.o: lex.yy.c Calculator.tab.h
	g++ -c lex.yy.c
	
Calculator.tab.o: Calculator.tab.c Calculator.tab.h
	g++ -c Calculator.tab.c

# the idea is that the rule related to a dependency is triggered only
# if the dependency doesn't exist or has changed since the last time

# for instance if we call make and we build the overall target,
# then afterwards we change only something in Calculator.tab.c
# (dependency for Calculator.tab.o) and finally we call make again, 
# then lex.yy.c is not compiled again in order to obtain
# the corresponding .o (because it hasn't changed)

# sometimes it's not a matter of compiling:
# for instance we get the source Calculator.tab.c from bison
	
Calculator.tab.h: Calculator.y
	bison -d Calculator.y

Calculator.tab.c : Calculator.y
	bison -d Calculator.y
	
lex.yy.c: Calculator.l
	flex Calculator.l 
	
# make clean 
# executes this rule which deletes the generated files

clean:
	rm -f lex.yy.c Calculator.tab.h Calculator.tab.c *.o calc
