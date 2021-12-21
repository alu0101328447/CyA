TARGET = p05_dfa
OBJS = main.o dfa.o alphabet.o states.o simbol.o chain.o languaje.o
INCDIR = /home/usuario/practicas/Practica5
CFLAGS = -Wall -I $(INCDIR)

$(TARGET) : $(OBJS)
	@g++ $(CFLAGS) $(OBJS) -o $(TARGET)

main.o : main.cc dfa.h chain.h languaje.h
	@g++ -c main.cc
dfa.o : dfa.cc dfa.h alphabet.h states.h
	@g++ -c dfa.cc 
alphabet.o : alphabet.cc alphabet.h simbol.h
	@g++ -c alphabet.cc 
states.o : states.cc states.h simbol.h 
	@g++ -c states.cc 
simbol.o : simbol.cc simbol.h 
	@g++ -c simbol.cc 
chain.o : chain.cc chain.h simbol.h alphabet.h 
	@g++ -c chain.cc
languaje.o : languaje.cc languaje.h chain.h
	@g++ -c languaje.cc

.PHONY : clean 
clean :
	@rm -f $(TARGET) $(OBJS)