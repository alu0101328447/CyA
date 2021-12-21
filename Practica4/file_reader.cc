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
// Archivo file_reader.cc: clase File_Reader
//
// Esta clase se encarga del almacenamiento de 
// las lineas del fichero de entrada y el titulo
//
// Historial de revisiones
// 25/10/2021 - Creación (primera versión) del código
// 27/10/2021 - Finalización del código

#include "file_reader.h"

File_Reader::File_Reader(std::string in_file) {
  set_in_file(in_file);
}

File_Reader::~File_Reader()
{}

std::string
File_Reader::line(int pos) {
  return file_line_[pos];
}

std::string
File_Reader::title(void) {
  return in_file_;
} 

int
File_Reader::size(void) {
  return file_line_.size();
}

void
File_Reader::AddLine(std::string line) {
  file_line_.push_back(line);
}

void 
File_Reader::SetTitle(std::string title) {
  in_file_ = title;
}

void
File_Reader::clear(void) {
  file_line_.clear();
  in_file_.clear();
}

void 
File_Reader::set_in_file(std::string in_file) {
  std::string chain;
  bool file_open;

  SetTitle(in_file);

  file_open = true;
  std::ifstream read_file(in_file);
  if (!read_file.is_open()) {
    std::cout << "The file you introduced is not avaliable ..." << std::endl
    << "Execute the program without parameters to get the help message ..."
    << std::endl;
    exit (1);
  } else {
    while (getline(read_file, chain)) {
      AddLine(chain);
    }

    read_file.close();
  }
}