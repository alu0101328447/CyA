// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo dfa.cc: dfa.cc alphabet.cc state.cc simbol.cc chain.cc
// Contiene los estados, las transiciones y simbolos que permiten definir 
// un dfa. Además contiene el alfabeto que define los simbolos
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 


#include "dfa.h"

Dfa::Dfa()
{}

Dfa::Dfa(std::vector <State> states, Alphabet alphabet) {
  this->state(states);
  this->alphabet(alphabet);
}

Dfa::~Dfa()
{}

std::set <State>
Dfa::state(void) {
  return states_;
}

Alphabet
Dfa::alphabet(void) {
  return alphabet_;
}

void
Dfa::state(std::vector <State> state) {
  for (auto& s : state) {
    this->Add_State(s);
  }
}

void 
Dfa::Add_State(State state) {
  states_.insert(state);
}

void 
Dfa::alphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}

void 
Dfa::Initial(State state) {
  initial_ = state;
}

State 
Dfa::Initial(void) {
  if (initial_.name() != "") {
    return initial_;
  } else {
    for (auto& s : states_) {
      if (s.Is_Start()) {
        initial_ = s;
        return initial_;
      }
    }
  }
  std::cerr << "Error: Falta un estado de inicio" << std::endl;
  exit (1);
}

State 
Dfa::Transition(Chain chain) {
  State aux_state;
  std::string state_name;

  aux_state = Initial();
  for(int i = 0; i < chain.size(); i++) {
    if(!alphabet_.Contains(chain.chain()[i])) {
      return State("Do not belong", false, false);
    }
  }
  
  for (auto& c : chain.chain()) {
    state_name = aux_state.get_transition(c).name();
    for (const auto& d : states_) {
      if (state_name == d.name()) {
        aux_state = d;
      }
    }
  }

  return aux_state;
}



