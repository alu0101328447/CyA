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
// Archivo main.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases
// file_reader y regular_expression para el almacenamiento de datos y 
// lenguajes regulares
//
// Este archivo se encarga de la gestión de las clases, 
// del almacenamiento de datos y salida de datos a otro fichero
//
// Historial de revisiones
// 25/10/2021 - Creación (primera versión) del código
// 27/10/2021 - Finalización del código

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_reader.h"
#include "regular_expression.h"

void Help_Message(void);
void Print_Expression(Regular_Expression);
void Print_Variable(Regular_Expression);
void Print_Multiline(Regular_Expression, Regular_Expression);


int main(int args, char **argv) {

  if (args < 3) {
    Help_Message();
    return 1;
  }

  Regular_Expression int_expression(Int, "INT");
  Regular_Expression double_expression(Double, "DOUBLE");
  //Regular_Expression for_expression(For, "LOOP");
  //Regular_Expression while_expression(While, "LOOP");
  Regular_Expression loop_expression(Loop, "LOOP");
  Regular_Expression line_comment_expression(LineComment, "");
  Regular_Expression multi_ini_expression(MultiCommentIni, "");
  Regular_Expression multi_last_expression(MultiCommentLast, "");
  Regular_Expression main_expression(Main, "");

  File_Reader file_in(argv[1]);

  for (int i = 0; i < file_in.size(); i++) {
    if (multi_ini_expression.Search(file_in.line(i))) {
      do {
        multi_ini_expression.AddResult(file_in.line(i + 1));
        multi_ini_expression.set_line(i + 1);
      } while ((!multi_last_expression.Search(file_in.line(i++))) && (i < file_in.size()));
      if (i < file_in.size()) {
        multi_last_expression.set_line(i);
      }
    } else if (i < file_in.size()) {
      if (int_expression.Search(file_in.line(i))) {
        int_expression.set_line(i + 1);
      } 
      if (loop_expression.Search(file_in.line(i))) {
        loop_expression.set_line(i + 1);
      }
      if (line_comment_expression.Search(file_in.line(i))) {
        line_comment_expression.set_line(i + 1);
      }
      if (main_expression.Search(file_in.line(i))) {
        main_expression.set_line(i + 1);
      }
    }
  }

  int defout = dup(1);
  int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
  if  (fd < 0) {
    std::cerr << "No se puedo abrir el fichero" << std::endl;
    return 1;
  }
  dup2(fd, STDOUT_FILENO);



  std::cout << "PROGRAM : " << file_in.title() << std::endl;

  if (multi_ini_expression.get_line().size() > 0) {
    if (multi_ini_expression.get_line()[0] == 1) {
      if (multi_last_expression.get_line().size() > 0) {
        std::cout << "DESCRIPTION: " << std::endl;
        for (int i = 0; i < multi_last_expression.get_line()[0]; i++) {
          std::cout << multi_ini_expression.get_result()[i] << std::endl;
        }
        std::cout << std::endl;
      }
    }
  }

  std::cout << "VARIABLES : " << std::endl;
  // Print_Expression(int_expression);
  Print_Variable(int_expression);
  Print_Variable(double_expression);
  std::cout << std::endl;

  std::cout << "STATEMENTS: " << std::endl;
  Print_Expression(loop_expression);
  std::cout << std::endl;

  std::cout << "MAIN: " 
  << ((main_expression.get_line().size() > 0) ? "True" : "False") << std::endl;
  std::cout << std::endl;

  std::cout << "COMMENTS: " << std::endl;
  Print_Multiline(multi_ini_expression, multi_last_expression);
  Print_Expression(line_comment_expression);
  
  std::cout << std::endl;

  dup2(defout, 1);
  close(fd);
  close(defout);

  return 0;
}


void
Help_Message(void) {
  system("clear");
  std::cout << "El modo de uso de este programa es el siguiente:" << std::endl
  << "./ p04 filein.cc fileout.txt" << std::endl
  << "-Teniendo en cuenta que:" << std::endl
  << "\tfilein.cc : es el nombre de el fichero de entrada de datos"
  << std::endl << "\tfilout.txt : es el nombre de el fichero de salida";

  std::cout << std::endl << "PRESIONE ENTER PARA SALIR ..." << std::endl;
  getchar();

  system("clear");
}

void 
Print_Expression(Regular_Expression regular_expression) {
  for (int i = 0; i < regular_expression.get_line().size(); i++) {
    std::cout << "[LINE " << regular_expression.get_line()[i] << "] "  
    << regular_expression.get_tipe()  << ": " 
    << regular_expression.get_result()[i] << std::endl;
  }
}

void 
Print_Multiline(Regular_Expression multi_ini_expression, 
  Regular_Expression multi_last_expression) 
{
  if (multi_ini_expression.get_line().size() > 0) {
    if (multi_ini_expression.get_line()[0] == 1) {
      if (multi_last_expression.get_line().size() > 0) {
        std::cout << "[LINE " << multi_ini_expression.get_line()[0] 
        << " - " << multi_last_expression.get_line()[0] << "] : "
        << "DESCRIPTION" << std::endl;
      }
    } else {
        std::cout << "[LINE " << multi_ini_expression.get_line()[0] 
        << " - " << multi_last_expression.get_line()[0] << "] : ";
        for (int i = 0; i < multi_ini_expression.get_line().size(); i++) {
          std::cout << multi_ini_expression.get_result()[i] << std::endl;
        }
    }
  }
}

void
Print_Variable(Regular_Expression regular_expression) {
  for (int i = 0; i < regular_expression.get_line().size(); i++) {
    std::cout << "[LINE " << regular_expression.get_line()[i] << "] "  
    << regular_expression.get_tipe()  << ": name: "  
    << regular_expression.get_name(i) << "\tvalue: ";
    if (regular_expression.get_value(i) == "") {
      std::cout << "Not asigned value" << std::endl;
    } else {
      std::cout << regular_expression.get_value(i) << std::endl;
    }
    
  }
}