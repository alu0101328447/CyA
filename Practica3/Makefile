TARGET = p02_strings
OBJS = main.o cadena.o alfabeto.o simbolos.o 
INCDIR = /home/usuario/practicas/Practica3/
CFLAGS = -Wall -I $(INCDIR)

$(TARGET) : $(OBJS)
	@g++ $(CFLAGS) $(OBJS) -o $(TARGET)

main.o : main.cc cadena.h alfabeto.h
	@g++ -c main.cc
cadena.o : cadena.cc cadena.h alfabeto.h 
	@g++ -c cadena.cc
alfabeto.o : alfabeto.cc alfabeto.h simbolos.h 
	@g++ -c alfabeto.cc
simbolos.o : simbolos.cc simbolos.h 
	@g++ -c simbolos.cc

.PHONY : clean
clean: 
	@rm -f $(OBJS) $(TARGET)