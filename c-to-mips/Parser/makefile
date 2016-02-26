bin/c_parser: src/c_bison.tab.o src/c_lexer.yy.o
	g++ src/c_bison.tab.o src/c_lexer.yy.o -o bin/c_parser && chmod +x bin/c_parser

src/c_lexer.yy.o: src/c_lexer.yy.c src/c_bison.tab.h
	g++ -c src/c_lexer.yy.c && mv c_lexer.yy.o src/

src/c_bison.tab.o: src/c_bison.tab.c src/c_bison.tab.h
	g++ -c src/c_bison.tab.c && mv c_bison.tab.o src/

src/c_bison.tab.c : src/c_bison.y
	bison -d src/c_bison.y && mv c_bison.tab.c src/

src/c_bison.tab.h: src/c_bison.y
	bison -d src/c_bison.y && mv c_bison.tab.h src/

src/c_lexer.yy.c: src/c_lexer.l
	flex -o src/c_lexer.yy.c src/c_lexer.l

clean :
	rm src/c_lexer.yy.c src/c_bison.tab.c src/c_bison.tab.h
	rm bin/c_parser
	rm src/*.o 
