// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo main.cc: main.cc cadena.cc cadena.h alfabeto.cc 
// alfabeto.h simbolos.cc simbolos.h
// Contiene la función main del proyecto que usa las clases cadena, alfabeto y simbolos
// que realizan el trabajo de transformar los datos de entrada en cadenas y alfabetos
// identificando patrones en el texto que dan lugar
// al fichero de salida.
//
// Historial de revisiones
// 08/10/2021 - Creación (primera versión) del código
// 13/10/2021 - Revisión (ultima versión) del código
// 
// Este archivo se encarga de la lectura del fichero y la getión de las clases
// para posteriormente imprimir los restultados en el fichero de salida.


#include "cadena.h"
#include "alfabeto.h"

#include <fstream>
#include <cstring>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <exception>

void helpMessage(void);
void printOption(int, Cadena, int, int&);
void comparacion(Cadena, int, int&);
void concatenacion(Cadena, int, int&);
void potencia(Cadena, int, int&);
void fileReaderMenu(std::string, int, int, int&);

int main(int argc, char **argv)
{
  // Compruebo que se hayan introducido bien el numero de parametros
  if (argc != 4) {
    helpMessage();
    return 1;
  }

  // Inicializo las variables necesarias para analizar el fichero de entrada
  std::string rutaIn;
  rutaIn = argv[1];

  // Inicializo las variables necesarias para analizar el fichero de salida
  std::string rutaOut;
  rutaOut = argv[2];
  // Abro el fichero de salida de datos
  int defout = dup(1);
  int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
  if (fd < 0) {
    std::cerr << "No se puedo abrir el fichero" << std::endl;
    return 1;
  }
  dup2(fd, STDOUT_FILENO);
  
  // Almaceno la opcion que se va a imprimir en el fichero en la variable opcion
  int opcion;
  opcion = std::strtol(argv[3], nullptr, 10);

  try {
    // Abro el fichero leo los datos y luego imprimo los resultados 
    fileReaderMenu(rutaIn, opcion, fd, defout);
  }
  catch(char const* errorMessage) {
    dup2(defout, 1);
    close(fd);
    close(defout);
    std::cerr << errorMessage << std::endl;
    return 1;
  }

  // Cierro los ficheros de entrada y salida
  close(fd);

  return 0;
}

void helpMessage(void) {
  system("clear");
  std::cerr << "El modo de uso de este programa es el siguiente:" << std::endl
  << "./p02_strings filein.txt fileout.txt opcode" << std::endl
  << "-Teniendo en cuenta que:" << std::endl
  << "\tfilein.txt : es el nombre de el fichero de entrada de datos" 
  << std::endl << "\tfilout.txt : es el nombre de el fichero de salida"
  << std::endl << "\topcode : es la opcion que regula la salida de datos"
  << std::endl << "\tPara opcode igual a:" << std::endl
  << "\t\t1 : Longitud" << std::endl
  << "\t\t2 : Inversa" << std::endl
  << "\t\t3 : Prefijos" << std::endl
  << "\t\t4 : Sufijos" << std::endl
  << "\t\t5 : Subcadenas" << std::endl
  << "\t\t6 : Comparación de cadenas" << std::endl
  << "\t\t7 : Concatenacion" << std::endl
  << "\t\t8 : Potencia" << std::endl;

  std::cerr << std::endl << "PRESIONE ENTER PARA SALIR ..." << std::endl;
  getchar();  
  system("clear");
}

void
comparacion(Cadena cadena, int fd, int &defout) {
  Alfabeto auxAlfabeto;
  Cadena comparaCadena;
  std::string auxCadena;
  std::string inCadena;

  dup2(defout, 1);
  close(fd);
  close(defout);
  std::cout << "Introduzca la cadena con la que va a comparar" << std::endl;
  std::cin >> inCadena;

  for(int i = 0; i < inCadena.size(); i++) {
    auxCadena.push_back(inCadena[i]);
    auxAlfabeto.addSimbolo(auxCadena);
    auxCadena.clear();
  }

  comparaCadena.setCadena(inCadena, auxAlfabeto);

  defout = dup(1);
  fd = open("salida.txt", O_WRONLY | O_APPEND, 0664);
  if(fd < 0) {
    std::cerr << "No se puedo abrir el fichero" << std::endl;
    exit(1);
  }
  dup2(fd, STDOUT_FILENO);

  cadena.printCadena();
  if(cadena == comparaCadena) {
    std::cout << " = ";
  } else if(cadena > comparaCadena) {
    std::cout << " > ";
  } else if(cadena < comparaCadena) {
    std::cout << " < ";
  } else {
    std::cout << " != ";
  }

  comparaCadena.printCadena();
  std::cout << std::endl;
}

void
concatenacion(Cadena cadena, int fd, int &defout) {
  Alfabeto auxAlfabeto;
  Cadena concatenaCadena;
  Cadena resultado;
  std::string auxCadena;
  std::string inCadena;

  dup2(defout, 1);
  close(fd);
  close(defout);
  std::cout << "Introduzca la cadena con la que va a concatenar" << std::endl;
  std::cin >> inCadena;

  for(int i = 0; i < inCadena.size(); i++) {
    auxCadena.push_back(inCadena[i]);
    auxAlfabeto.addSimbolo(auxCadena);
    auxCadena.clear();
  }

  concatenaCadena.setCadena(inCadena, auxAlfabeto);

  defout = dup(1);
  fd = open("salida.txt", O_WRONLY | O_APPEND, 0664);
  if(fd < 0) {
    std::cerr << "No se puedo abrir el fichero" << std::endl;
    exit(1);
  }
  dup2(fd, STDOUT_FILENO);

  resultado = cadena * concatenaCadena;

  resultado.printCadena();
  std::cout << std::endl;
}

void
potencia(Cadena cadena, int fd, int &defout) {
  int exponente;
  Cadena resultado;

  dup2(defout, 1);
  close(fd);
  close(defout);
  do {
    std::cout << "Introduzca el exponente de la potencia" << std::endl;
    std::cin >> exponente;
    if(exponente < 0) {
      std::cout << "El exponente tiene que ser mayor o igual a 0" << std::endl;
    }
  } while(exponente < 0);

  defout = dup(1);
  fd = open("salida.txt", O_WRONLY | O_APPEND, 0664);
  if(fd < 0) {
    std::cerr << "No se puedo abrir el fichero" << std::endl;
    exit(1);
  }
  dup2(fd, STDOUT_FILENO);

  resultado = cadena ^ exponente;

  if (resultado.getSize() == 0) {
    std::cout << "&" << std::endl;
  } else {
    resultado.printCadena();
    std::cout << std::endl;
  }

}

void
printOption(int opcion, Cadena cadena, int fd, int &defout) {
  Alfabeto alfabeto;
  alfabeto.addSimbolo("a");
  switch(opcion) {
    case 1 :  
      std::cout << cadena.getSize(alfabeto) << std::endl;
      break;

    case 2 :
      cadena.printReverseCadena();
      break;
    
    case 3 :  
      cadena.printPrefijo();
      break;

    case 4 :
      cadena.printSufijo();
      break;

    case 5 :  
      cadena.printSubcadena();
      break;

    case 6 :  
      comparacion(cadena, fd, defout);
      break;

    case 7 :
      concatenacion(cadena, fd, defout);
      break;

    case 8 :
      potencia(cadena, fd, defout);
      break;

    default :
      throw "ERROR al insertar la opcion. Revise el manual usando ./p02_strings";
  }
}

void
fileReaderMenu(std::string rutaIn, int opcion, int fd, int &defout) {

  // Abro el fichero de entrada de datos
  std::ifstream inFile(rutaIn);
  if(!inFile.is_open()) {
    throw "ERROR al abrir el fichero de entrada";
  }

  // Inicializo las variables que voy a utilizar para almacenar datos temporalmente
  std::string chain;
  std::string auxCadena;
  std::string auxAlfabet;
  Alfabeto alfabeto;
  Cadena cadena;
  
  // Leo los datos y los almaceno en las cadenas pertinentes
  while (getline(inFile, chain)){
    for(int i = 0; i < chain.size(); i++ ){
      if(chain[i] != ' ') {
        auxCadena.push_back(chain[i]);
      }
      else {
        alfabeto.addSimbolo(auxCadena);
        auxCadena.clear();
      }
    }
    // Si no se han almacenado ninguna cadena antes, 
    // entonces la primera palabra es el alfabeto
    if(alfabeto.getSize() == 0) {
      for(int i = 0; i < auxCadena.size(); i++) {
        auxAlfabet.push_back(auxCadena[i]);
        alfabeto.addSimbolo(auxAlfabet);
        auxAlfabet.clear();
      }
    }
    // Si uno de los elementos de el alfabeto es subcadena de otro da error
    if(alfabeto.Subcadena()) {
      throw "En el alfabeto un simbolo es sublenguaje de otro";
    }
    
    cadena.setCadena(auxCadena, alfabeto);

    // Aqui va la opcion a elegir
    //std::cout << "Size: " << cadena.getSize(alfabeto) << std::endl;
    printOption(opcion, cadena, fd, defout);
      
    // Limpio la cadena y el alfabeto
    cadena.clear();
    alfabeto.clear();
    auxCadena.clear();
  }

  // Cierro el fichero de entrada de datos
  inFile.close();
}