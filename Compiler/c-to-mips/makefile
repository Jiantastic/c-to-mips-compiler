CC=g++ -std=c++11

c_lexer:	 
	flex -o c_lexer.yy.cpp c_lexer.l && \
	${CC} c_lexer.yy.cpp -o c_lexer
clean:
	cd src/ && rm *.o main
