// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo main.cc: main.cc dfa.cc alphabet.cc state.cc simbol.cc chain.cc languaje.cc
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


#include "dfa.h"
#include "chain.h"
#include "languaje.h"

#include <fstream>
#include <cstring>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string>
#include <iostream>

void Help_Message(void);
Dfa Simulate_Dfa(std::string);
Languaje In_Chain(std::string);


int main(int argc, char** argv) {

  std::string in_chain;
  std::string out_chain;
  std::string aux_chain;
  Simbol simbol;
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

  Languaje languaje;
  languaje = In_Chain(argv[2]);

  Dfa dfa;
  dfa = Simulate_Dfa(argv[1]);
  
  for (auto& sc : languaje.languaje()) {
    out_file << sc;
    if (dfa.Transition(sc).Is_Acceptance()) {
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

Dfa 
Simulate_Dfa(std::string in_file) {
  int t_pos;
  int v_pos;

  std::string chain;
  std::string aux_chain;
  std::vector <std::string> line;

  std::vector <State> states;
  std::string pos;
  bool initial;
  bool acceptance;

  std::vector <int> state_reference;
  Simbol simbol;
  Chain t_chain;
  Alphabet alphabet;


  std::ifstream file(in_file);
  if (!file.is_open()) {
    std::cerr << "Error con la apertura del fichero del dfa" << std::endl;
    exit (1);
  }
  getline(file, chain);
  getline(file, chain);
  pos = chain;

  while (getline(file, chain)) {
    acceptance = false;
    initial = false;
    for (int i = 0; i < chain.size(); i++) {
      if (chain[i] != ' ') {
        aux_chain.push_back(chain[i]);
      } else {
        line.push_back(aux_chain);
        aux_chain.clear();
      }
    }

    if (stoi(line[1]) == 1) {
      acceptance = true;
    }
    if (stoi(line[0]) == stoi(pos)) {
      initial = true;
    }

    state_reference.push_back(std::__cxx11::stoi(line[4]));
    simbol.set_simbol(line[3]);
    t_chain.Add_Simbol(simbol);
    alphabet.Add_Simbol(simbol);
    state_reference.push_back(std::__cxx11::stoi(line[6]));
    simbol.set_simbol(line[5]);
    t_chain.Add_Simbol(simbol);
    alphabet.Add_Simbol(simbol);

    State state(line[0], initial, acceptance);
    states.push_back(state);

    line.clear();
  }

  // Añado las transiciones
  t_pos = 0;
  v_pos = 0;
  
  for (int i = 0; i < states.size(); i++) {
    states[i].Add_Transition(t_chain.chain()[t_pos++], states[state_reference[v_pos++]]);
    states[i].Add_Transition(t_chain.chain()[t_pos++], states[state_reference[v_pos++]]);
  }

  Dfa dfa(states, alphabet);
  return dfa;
}


Languaje 
In_Chain(std::string in_file) {
  std::string in_chain;
  std::string aux_chain;
  Simbol simbol;
  Chain chain;
  Languaje languaje;

  std::ifstream file(in_file);
  if (!file.is_open()) {
    std::cerr << "Error con la apertura del fichero de entrada" << std::endl;
    exit (1);
  }

  while (getline(file, in_chain)) {
    for (int i = 0; i < in_chain.size(); i++) {
      aux_chain.push_back(in_chain[i]);
      simbol.set_simbol(aux_chain);
      chain.Add_Simbol(simbol);
      aux_chain.clear();
    }
    languaje.Add_Languaje(chain);
    chain.clear();
  }
  
  return languaje;
}