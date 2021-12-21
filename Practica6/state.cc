// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo state.cc: alphabet.cc state.cc simbol.cc chain.cc 
// Contiene el nombre, transiciones y características de un estado
// Además contiene los metodos para gesionarlo
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#include "state.h"

State::State()
{}

State::State(std::string name, bool start, bool acceptance) {
  name_ = name;
  Is_Start(start);
  Is_Acceptance(acceptance);
}

State::~State()
{}

std::string
State::name(void) const {
  return name_;
}

std::map <Simbol, State>
State::get_transition(void) {
  return transition_;
}

std::map <Simbol, State>
State::get_transition(void) const {
  return transition_;
}

State 
State::get_transition(Simbol simbol) {
  if (transition_[simbol].name() != "") {
    return transition_[simbol];
  }
  return *this;
}

State 
State::get_transition(Simbol simbol) const {
  for (auto& t : transition_) {
    if (t.first == simbol) {
      return t.second;
    }
  }
  return *this;
}

bool
State::Is_Start(void) {
  return start_;
}

bool
State::Is_Start(void) const{
  return start_;
}

bool
State::Is_Acceptance(void) {
  return acceptance_;
}

bool
State::Is_Acceptance(void) const{
  return acceptance_;
}

void
State::name(std::string name) {
  name_ = name;
}

void
State::set_transition(std::map <Simbol, State> transition) {
  transition_ = transition;
}

void
State::Add_Transition(Simbol simbol, State state) {
  transition_[simbol] = state;
}

void
State::Is_Start(bool start) {
  start_ = start;
}

void
State::Is_Acceptance(bool acceptance) {
  acceptance_ = acceptance;
}

bool
State::operator <(const State& states) const {
  return name_ < states.name();
}

