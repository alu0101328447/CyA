TARGET = p02_strings
OBJS = main.o cadena.o alfabeto.o simbolos.o
INCDIR = /home/usuario/practicas/Practica2
CFLAGS = -Wall -I$(INCDIR)

$(TARGET) : $(OBJS)
	g++ $(CFLAGS) $(OBJS) -o $(TARGET)


main.o : main.cc cadena.h alfabeto.h
cadena.o : cadena.cc cadena.h alfabeto.h simbolos.h
alfabeto.o : alfabeto.cc alfabeto.h simbolos.h
simbolos.o: simbolos.o simbolos.h

.PHONY : clean
clean:
	@rm -f $(OBJS) $(TARGET)


