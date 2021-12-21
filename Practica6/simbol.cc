// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo simbol.cc: simbol.cc
// Contiene metodos para gestionar los simbolos
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 


#include "simbol.h"

Simbol::Simbol() 
{}

Simbol::Simbol(std::string simbol) {
  set_simbol(simbol);
}

Simbol::~Simbol()
{}

std::string
Simbol::get_simbol(void) const {
  return simbol_;
}

void
Simbol::set_simbol(std::string simbol) {
  simbol_ = simbol;
} 

bool 
Simbol::operator <(const Simbol& simbol) const {
  return simbol_ < simbol.get_simbol();
}

bool 
Simbol::operator ==(Simbol simbol) {
  return simbol_ == simbol.get_simbol();
}

bool 
Simbol::operator ==(Simbol simbol) const {
  return simbol_ == simbol.get_simbol();
}

std::ostream &operator <<(std::ostream& os, const Simbol& simbol) {
  return os << simbol.get_simbol();
}