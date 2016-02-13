CC=g++

main:	 
	cd src/ && \
	flex -o c_lexer.cpp c_lexer.l && \
	${CC} c_lexer.cpp -o c_lexer
clean:
	cd src/ && rm *.o main
