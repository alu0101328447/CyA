TARGET = p08_grammar
OBJS = main.o alphabet.o symbol.o chain.o language.o grammar.o 
INCDIR = /home/usuario/practicas/Practica8
CFLAGS = -Wall -I $(INCDIR)

$(TARGET) : $(OBJS)
	@g++ $(CFLAGS) $(OBJS) -o $(TARGET)

main.o : main.cc chain.h language.h
	@g++ -c main.cc
alphabet.o : alphabet.cc alphabet.h symbol.h
	@g++ -c alphabet.cc 
symbol.o : symbol.cc symbol.h 
	@g++ -c symbol.cc 
chain.o : chain.cc chain.h symbol.h alphabet.h 
	@g++ -c chain.cc
language.o : language.cc language.h chain.h
	@g++ -c language.cc
grammar.o : grammar.cc grammar.h alphabet.h
	@g++ -c grammar.cc

.PHONY : clean 
clean :
	@rm -f $(TARGET) $(OBJS)