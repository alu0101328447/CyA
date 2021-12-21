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

#include "nfa.h"
#include "chain.h"
#include "language.h"

#include <fstream>
#include <cstring>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string>
#include <iostream>

void Help_Message(void);
Language In_Chain(std::string);
Nfa Simulate_Nfa(std::string in_file);
std::vector <std::string> Nfa_Line(std::string);


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
      std::cerr << "Modo de empleo: p06_dfa_simulation [FICHERO.dfa] "
      << "[IN_FICHERO.txt] [OUT.FICHERO.txt]" 
      << std::endl << "Pruebe ./ 'p06_dfa_simulation --help' para más información."
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

  Language language;
  language = In_Chain(argv[2]);
  Nfa nfa;
  nfa = Simulate_Nfa(argv[1]);

  for (auto& sc : language.language()) {
    out_file << sc;
    if (nfa.Transition(sc)) {
      out_file << " -- Accepted" << std::endl;
    } else {
      out_file << " -- Rejected" << std::endl;
    }
  }

  
  out_file.close();
  return 0;
}

void Help_Message(void) {
  system("clear");
  std::cerr << "El modo de uso de este programa es el siguiente:" << std::endl
  << "./ p06_dfa_simulation file.dfa filein.txt fileout.txt" << std::endl
  << "-Teniendo en cuenta que:" << std::endl
  << "\tfile.dfa : fichero que define el dfa" 
  << std::endl << "\tfilein.txt : es el nombre de el fichero "
  << "que contiene las cadenas a analizar"
  << std::endl << "\tfilout.txt : es el nombre de el fichero de salida"
  << std::endl;

  std::cerr << std::endl << "PRESIONE ENTER PARA SALIR ..." << std::endl;
  getchar();  
  system("clear");
}

std::vector <std::string>
Nfa_Line(std::string line) {
  std::vector <std::string> result;
  std::string aux_string;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] != ' ') {
      aux_string.push_back(line[i]);
    } else {
      result.push_back(aux_string);
      aux_string.clear();
    }
  }
  if (aux_string.size() != 0) {
    result.push_back(aux_string);
    aux_string.clear();
  }
  return result;
}

Nfa 
Simulate_Nfa(std::string in_file) {
  int nfa_size;
  std::string nfa_initial;

  std::string chain;
  std::vector <std::string> line;

  std::vector <State> states;
  bool acceptance;

  std::vector <int> state_reference;
  Symbol symbol;
  Chain t_chain;
  Alphabet alphabet;
  std::vector <std::pair <std::vector<int>, Chain>> transitions;

  std::ifstream file(in_file);
  if (!file.is_open()) {
    std::cerr << "Error con la apertura del fichero del dfa" << std::endl;
    exit (1);
  }

  getline(file, chain);
  nfa_size = stoi(chain);
  getline(file, chain);
  nfa_initial = chain;

  for (int i = 0; i < nfa_size; i++) {
    if (!getline(file, chain)) {
      std::cerr << "Error: El formato del fichero del "
      << "nfa no cumple con el estandar" << std::endl;
      exit(1);
    }

    acceptance = false;
    line = Nfa_Line(chain);

    if (stoi(line[1]) == 1) {
      acceptance = true;
    }

    for (int i = 0; i < stoi(line[2]); i++) {
      int j = i * 2;    
      if (line.size() <= stoi(line[2]) + j) {
        std::cerr << "Error: el numero de estados no corresponde"
        << " con los marcados" << std::endl;
        exit(1);
      }
      state_reference.push_back(stoi(line[j + 4]));
      symbol.set_symbol(line[j + 3]);
      t_chain.Add_Symbol(symbol);
      alphabet.Add_Symbol(symbol);
    }
  
    std::pair <std::vector <int>, Chain> aux_transition;
    aux_transition.first = state_reference;
    aux_transition.second = t_chain;
    transitions.push_back(aux_transition);

    state_reference.clear();
    t_chain.clear();
    State state(line[0], acceptance);
    states.push_back(state);

  }
  
  for (int i = 0; i < states.size(); i++) {
    for (int j = 0; j < transitions[i].first.size(); j++) {
      states[i].Add_Transition(transitions[i].second.chain()[j]
      , states[transitions[i].first[j]]);
    }
  }

  Nfa nfa(states, alphabet);

  for (auto& s : states) {
    if (s.name() == nfa_initial) {
      nfa.Initial(s);
    }
  }
  
  return nfa;
} 


Language 
In_Chain(std::string in_file) {
  std::string in_chain;
  std::string aux_chain;
  Symbol symbol;
  Chain chain;
  Language language;

  std::ifstream file(in_file);
  if (!file.is_open()) {
    std::cerr << "Error con la apertura del fichero de entrada" << std::endl;
    exit (1);
  }

  while (getline(file, in_chain)) {
    for (int i = 0; i < in_chain.size(); i++) {
      aux_chain.push_back(in_chain[i]);
      symbol.set_symbol(aux_chain);
      chain.Add_Symbol(symbol);
      aux_chain.clear();
    }
    language.Add_Language(chain);
    chain.clear();
  }
  
  return language;
}