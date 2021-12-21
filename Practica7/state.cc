// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo state.cc: alphabet.cc state.cc symbol.cc chain.cc 
// Contiene el nombre, transiciones y características de un estado
// Además contiene los metodos para gesionarlo
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

#include "state.h"

/**
*
*  @brief  State constructor -> initialize State objects-
*
*/
State::State()
{}

/**
*
*  @brief  State constructor -> initialize State objects-
*  @param  std::string -> name of the state
*  @param  bool -> true if is an acceptance state
*
*/
State::State(std::string name, bool acceptance) {
  name_ = name;
  Is_Acceptance(acceptance);
}

/**
*
*  @brief  State destructor -> destroys State objects-
*
*/
State::~State()
{}

/**
*
*  @brief  State getter 
*  @return  std::string -> name of the state
*
*/
std::string
State::name(void) const {
  return name_;
}

/**
*
*  @brief  State function that return the transitions the state go with that symbol
*  @param  Symbol -> Transition symbol
*  @return  std::vector <State>   -> the transition state
*
*/
std::vector <State>  
State::get_transition(Symbol symbol) {
  std::vector <State>  result;
  auto range = transition_.equal_range(symbol);
  if (transition_.count(symbol) == 0) {
    return result;
  }
  
  for (auto i = range.first; i != range.second; ++i) {
    result.push_back(i->second);
  }

  result.push_back(*this);
  return result;
}

/**
*
*  @brief  const State function that return the transitions the state go with that symbol
*  @param  Symbol -> Transition symbol
*  @return  std::vector <State>   -> the transition state
*
*/
std::vector <State> 
State::get_transition(Symbol symbol) const {

  std::vector <State>  result;
  auto range = transition_.equal_range(symbol);
  if (transition_.count(symbol) == 0) {
    return result;
  }
  
  for (auto i = range.first; i != range.second; ++i) {
    result.push_back(i->second);
  }

  result.push_back(*this);
  return result;
}

/**
*
*  @brief  State getter
*  @return  bool -> true if is an acceptance state
*
*/
bool
State::Is_Acceptance(void) {
  return acceptance_;
}

/**
*
*  @brief  const State getter
*  @return  bool -> true if is an acceptance state
*
*/
bool
State::Is_Acceptance(void) const{
  return acceptance_;
}

/**
*
*  @brief  State setter
*  @param  std::string -> name of the state
*
*/
void
State::name(std::string name) {
  name_ = name;
}

/**
*
*  @brief  State setter
*  @param  std::multimap <Symbol, State> -> the transition
*
*/
void
State::set_transition(std::multimap <Symbol, State> transition) {
  transition_ = transition;
}

/**
*
*  @brief  State function that allows to add a new transition
*  @param  Symbol -> the symbol of the transition
*  @param  State -> the transition state
*
*/
void
State::Add_Transition(Symbol symbol, State state) {
  transition_.insert(decltype(transition_)::value_type(symbol, state));
}

/**
*
*  @brief  State setter
*  @param  bool -> true if is an acceptance state
*
*/
void
State::Is_Acceptance(bool acceptance) {
  acceptance_ = acceptance;
}

/**
*
*  @brief  const State operator that allows to compare two states
*
*/
bool
State::operator <(const State& states) const {
  return name_ < states.name();
}

