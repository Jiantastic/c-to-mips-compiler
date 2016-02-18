bin/c_lexer : src/c_lexer.yy.c src/c_bison.tab.c
	g++ src/c_lexer.yy.c src/c_bison.tab.c -o bin/c_parser

src/c_lexer.yy.c : src/c_lexer.l
	flex -o src/c_lexer.yy.c src/c_lexer.l

src/c_bison.tab.c : src/c_bison.y
	bison -d src/c_bison.y -o src/c_bison.tab.c

clean :
	rm src/c_lexer.yy.c src/c_bison.tab.c src/c_bison.tab.h
	rm bin/c_lexer
