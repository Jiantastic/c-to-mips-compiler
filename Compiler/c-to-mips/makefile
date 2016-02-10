CC=g++

main: main.cpp
	flex -o c_lexer.cpp c_lexer.l
	g++ c_lexer.cpp -o c_lexer
clean:
	rm *.o main
