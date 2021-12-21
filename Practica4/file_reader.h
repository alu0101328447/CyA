// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 4: Expresiones regulares 
// Autor: José Pablo Ruiz Galván
// Correo: alu0101328447@ull.edu.es
// Fecha: 25/10/2021
//
// Archivo file_reader.h: clase File_Reader
//
// Esta clase se encarga del almacenamiento de 
// las lineas del fichero de entrada y el titulo
//
// Historial de revisiones
// 25/10/2021 - Creación (primera versión) del código
// 27/10/2021 - Finalización del código

#ifndef FILE_READER
#define FILE_READER 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class File_Reader {
  public:
    File_Reader(std::string);
    ~File_Reader();

    std::string line(int);
    std::string title(void);
    int size(void);
    
    void set_in_file(std::string);

    void clear(void);

  private:
    std::vector <std::string> file_line_;
    std::string in_file_;


    void AddLine(std::string);
    void SetTitle(std::string);

};


#endif