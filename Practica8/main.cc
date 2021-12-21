// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo main.cc: main.cc dfa.cc alphabet.cc state.cc symbol.cc chain.cc language.cc
// Contiene la función main del proyecto que se encarga de generar un dfa a partir 
// de un fichero de entrada y comprobar si las cadenas que se encuentran en otro 
// fichero de entrada pertenecen a este lengueje regular. 
// La salida son el nombre de la cadena y si son aceptadas por un tercer fichero de 
// salida
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

/**
 * @author: José Pablo Ruiz Galván
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 3º Ingeniería Informática
 * Práctica 7: NFA 
 */

#include "chain.h"
#include "language.h"
#include "grammar.h"

#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string>
#include <iostream>

void Help_Message(void);
std::pair <Chain, std::vector <int>>  In_Chain(std::string, Alphabet);
Grammar Simulate_Grammar(std::string);


int main(int argc, char** argv) {

  std::string in_chain;
  std::string out_chain;
  std::string aux_chain;
  Symbol symbol;
  Chain chain;

  if (argc != 4) {
    if ((argv[1] == "-h") || (argv[1] == "--help")) {
      Help_Message();
      return 1;
    } else {
      std::cerr << "Modo de empleo: p07_nfa_simulation [FICHERO.nfa] "
      << "[IN_FICHERO.txt] [OUT.FICHERO.txt]" 
      << std::endl << "Pruebe ./ 'p07_nfa_simulation --help' para más información."
      << std::endl;
      return 1;
    }
  }


  out_chain = argv[3];
  std::ofstream out_file(argv[3]);
  if (!out_file.is_open()) {
    std::cerr << "Error con la apertura del fichero de salida" << std::endl;
    return 1;
  }

  in_chain = argv[2];


  Grammar grammar;
  grammar = Simulate_Grammar(argv[1]);
  std::pair <Chain, std::vector <int>> grammar_aux;
  grammar_aux =  In_Chain(argv[2], grammar.get_non_terminals());
  std::string grammar_string = grammar.Derivations(grammar_aux.first, grammar_aux.second);

  out_file << "Resultado: " << std::endl << grammar_string << std::endl;
  
  out_file.close();
  return 0;
}

void Help_Message(void) {
  system("clear");
  std::cerr << "El modo de uso de este programa es el siguiente:" << std::endl
  << "./ p07_dfa_simulation file.nfa filein.txt fileout.txt" << std::endl
  << "-Teniendo en cuenta que:" << std::endl
  << "\tfile.nfa : fichero que define el nfa" 
  << std::endl << "\tfilein.txt : es el nombre de el fichero "
  << "que contiene las cadenas a analizar"
  << std::endl << "\tfilout.txt : es el nombre de el fichero de salida"
  << std::endl;

  std::cerr << std::endl << "PRESIONE ENTER PARA SALIR ..." << std::endl;
  getchar();  
  system("clear");
}

Grammar 
Simulate_Grammar(std::string in_file) {
  Alphabet terminal;
  Alphabet non_terminal;
  Symbol start;
  Symbol n_terminal;
  Chain product;
  std::string chain;
  
  // Compruebo que puedo abrir bien el fichero  
  std::ifstream file(in_file);
  if (!file.is_open()) {
    std::cerr << "Error con la apertura del fichero del dfa" << std::endl;
    exit (1);
  }

  // Leo el alfabeto de terminales
  if (getline(file, chain)) {
    for (auto& t : chain) {
      if (t != ' ' ) {
        terminal.Add_Symbol(Symbol(t));
      }
    }
  } else {
    std::cerr << "ERROR en el fichero .cfg" << std::endl;
    exit(1);
  }

  // Leo el alfabeto de no terminales
  if (getline(file, chain)) {
    for (auto& nt : chain) {
      if (nt != ' ') {
        non_terminal.Add_Symbol(Symbol(nt));
      }
    }
  } else {
    std::cerr << "ERROR en el fichero .cfg" << std::endl;
    exit(1);
  }

  // Leo la primera línea y obtengo el estado de inicio
  if (getline(file, chain)) {
    bool aux = true;
    for (auto& e : chain) {
      if ((aux) && (non_terminal.Contains(Symbol(e)))) {
        start.set_symbol(e);
        n_terminal.set_symbol(e);
        aux = false;
      } else if ((non_terminal.Contains(Symbol(e))) || (terminal.Contains(Symbol(e)))) {
        product.Add_Symbol(Symbol(e));
      } else if ((e != '-' ) && (e != '>') && (e != ' ')) {
        std::cerr << "ERROR: caracter " << e << " no perteneciente al alfabeto"
        << std::endl;
        exit(1);
      }
    }
  } else {
    std::cerr << "ERROR en el fichero .cfg" << std::endl;
    exit(1);
  }

  // Creo la gramática
  Grammar grammar_in(terminal, non_terminal, start);
  grammar_in.Add_Production(n_terminal, product);
  product.clear();

  // Comienzo a añadir las transiciones
  while (getline(file, chain)) {
    bool aux = true;
    for (auto& e : chain) {
      if ((aux) && (non_terminal.Contains(Symbol(e)))) {
        start.set_symbol(e);
        n_terminal.set_symbol(e);
        aux = false;
      } else if ((non_terminal.Contains(Symbol(e))) || (terminal.Contains(Symbol(e)))) {
        product.Add_Symbol(Symbol(e));
      } else if ((e != '-' ) && (e != '>') && (e != ' ')) {
        std::cerr << "ERROR: caracter " << e << " no perteneciente al alfabeto"
        << std::endl;
        exit(1);
      }
    }
    grammar_in.Add_Production(n_terminal, product);
    product.clear();
  }

  // Devuelvo la gramática
  return grammar_in;
} 


std::pair <Chain, std::vector <int>> 
In_Chain(std::string in_file, Alphabet non_terminal) {
  std::string in_chain;
  std::string aux_chain;
  Symbol symbol;
  Chain chain;
  std::vector <int> prod;
  int aux_int;
  std::pair <Chain, std::vector <int>> result;

  // Compruebo que el fichero se abre sin problemas
  std::ifstream file(in_file);
  if (!file.is_open()) {
    std::cerr << "Error con la apertura del fichero de entrada" << std::endl;
    exit (1);
  }

  // Guardo las cadenas
  while (getline(file, in_chain)) {
    bool aux = true;
    for (auto& e : in_chain) {
      if ((aux) && (non_terminal.Contains(Symbol(e)))) {
        symbol.set_symbol(e);
        aux = false;
      } else if (e != ':') {
        aux_chain.push_back(e);
      } 
    }
    chain.Add_Symbol(symbol);
    //aux_chain >> std::hex >> aux_int;
    //prod.push_back(aux_int);
    prod.push_back(stoi(aux_chain, nullptr, 16));
    aux_chain.clear();
  }

  result.first = chain;
  result.second = prod;
  
  return result;
} 