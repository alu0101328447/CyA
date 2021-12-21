TARGET = p07_nfa_simulation
OBJS = main.o nfa.o alphabet.o state.o symbol.o chain.o language.o
INCDIR = /home/usuario/practicas/Practica6
CFLAGS = -Wall -I $(INCDIR)

$(TARGET) : $(OBJS)
	@g++ $(CFLAGS) $(OBJS) -o $(TARGET)

main.o : main.cc nfa.h chain.h language.h
	@g++ -c main.cc
nfa.o : nfa.cc nfa.h alphabet.h state.h
	@g++ -c nfa.cc 
alphabet.o : alphabet.cc alphabet.h symbol.h
	@g++ -c alphabet.cc 
state.o : state.cc state.h symbol.h 
	@g++ -c state.cc 
symbol.o : symbol.cc symbol.h 
	@g++ -c symbol.cc 
chain.o : chain.cc chain.h symbol.h alphabet.h 
	@g++ -c chain.cc
language.o : language.cc language.h chain.h
	@g++ -c language.cc

.PHONY : clean 
clean :
	@rm -f $(TARGET) $(OBJS)