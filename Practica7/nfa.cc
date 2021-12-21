// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de NFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo nfa.cc: nfa.cc alphabet.cc state.cc symbol.cc chain.cc
// Contiene los estados, las transiciones y symbolos que permiten definir 
// un nfa. Además contiene el alfabeto que define los symbolos
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

/**
*
*  @brief  NFA constructor -> initialize NFA objects-
*
*/
Nfa::Nfa()
{}

/**
*
*  @brief  NFA constructor -> initialize NFA objects-
*  @param std::vector <State> -> the states of the Nfa
*  @param Alphabet -> the alphabet of the Nfa
*
*/
Nfa::Nfa(std::vector <State> states, Alphabet alphabet) {
  this->state(states);
  this->alphabet(alphabet);
}

/**
*
*  @brief  NFA destructor -> destroys NFA objects-
*
*/
Nfa::~Nfa()
{}

/**
*
*  @brief  NFA getter
*  @return std::set <State> -> the states of the Nfa
*
*/
std::set <State>
Nfa::state(void) {
  return states_;
}

/**
*
*  @brief  NFA getter
*  @return Alphabet -> the alphabet of the Nfa
*
*/
Alphabet
Nfa::alphabet(void) {
  return alphabet_;
}

/**
*
*  @brief  NFA setter
*  @param std::vector <State> -> the states of the Nfa
*
*/
void
Nfa::state(std::vector <State> state) {
  for (auto& s : state) {
    this->Add_State(s);
  }
}

/**
*
*  @brief  NFA function that inserts a new state to the Nfa
*  @param State -> the new state of the Nfa
*
*/
void 
Nfa::Add_State(State state) {
  states_.insert(state);
}

/**
*
*  @brief  NFA setter
*  @param Alphabet -> the alphabet of the Nfa
*
*/
void 
Nfa::alphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}

/**
*
*  @brief  NFA setter 
*  @param State -> the new initial state for the Nfa
*
*/
void 
Nfa::Initial(State state) {
  initial_ = state;
}

/**
*
*  @brief  NFA getter 
*  @return State -> the initial state of the Nfa
*
*/
State 
Nfa::Initial(void) {
    return initial_;
}

/**
*
*  @brief  NFA function that inspect if a chain is acceptable by this Nfa
*  @param Chain -> the chain we are testing if is acceptable
*  @return bool -> the result -> if is acceptable -> true
*
*/
bool 
Nfa::Transition(Chain chain) {
  Symbol Epsilon("&");
  std::set <State> nfa_states;
  std::set <State> aux_nfa;
  State aux_state;
  aux_state.name("NULL");
  std::string state_name;

  // Compruebo si todos los symbolos pertenecen al alfabeto
  for(int i = 0; i < chain.size(); i++) {
    if(!alphabet_.Contains(chain.chain()[i])) {
      std::cerr << "La cadena: " << chain 
      << " tiene un caracter que no pertenece al alfabeto" << std::endl;
      return false;
    }
  }

  nfa_states.insert(initial_);
  for (auto& c : chain.chain()) {
    // Hago las epsilon transiciones del estado
    for (auto& s : nfa_states) {
      for (auto& v : s.get_transition(Epsilon)) {
        state_name = v.name();
        for (const auto& d : states_) {
          if (state_name == d.name()) {
            aux_state = d;
            nfa_states.insert(aux_state);
          }
        }
      }
    }
    // Transito al siguiente estado
    aux_nfa = nfa_states;
    for (auto s : aux_nfa) {
      nfa_states.erase(aux_state);
      for (auto& v : s.get_transition(c)) {
        state_name = v.name();
        for (const auto& d : states_) {
          if (state_name == d.name()) {
            aux_state = d;
            nfa_states.insert(aux_state);
          }
        }
      }
    }
  }

  for (auto& s : nfa_states) {
    if (s.Is_Acceptance()) {
      return true;
    }
  }
  return false;
}



