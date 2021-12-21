TARGET =  p04
OBJS = main.o file_reader.o regular_expression.o
INCDIR = /home/usuario/practicas/Practica4/
CFLAGS = -Wall -I $(INCDIR)

$(TARGET) : $(OBJS)
	@g++ $(CFLAGS) $(OBJS) -o $(TARGET)

main.o : main.cc regular_expression.h file_reader.h
	@g++ -c main.cc
regular_expression.o : regular_expression.cc regular_expression.h
	@g++ -c regular_expression.cc
file_reader.o : file_reader.cc file_reader.h 
	@g++ -c file_reader.cc

.PHONY : clean
clean: 
	@rm -f $(OBJS) $(TARGET)
