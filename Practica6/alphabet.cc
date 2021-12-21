// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo alphabet.cc:  alphabet.cc simbol.cc
// Contiene un conjunto de simbolos
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#include "alphabet.h"

Alphabet::Alphabet() 
{
  std::string empty;
  empty.push_back(EMPTY);
  Simbol simbol((empty));
  alphabet_.insert(simbol);
}

Alphabet::Alphabet(std::vector <Simbol> alphabet) {
  std::string empty;
  empty.push_back(EMPTY);
  Simbol simbol((empty));
  alphabet_.insert(simbol);
  
  for (int i = 0; i < alphabet.size(); i++) {
    Add_Simbol(alphabet[i]);
  }
}

Alphabet::~Alphabet()
{}

std::set <Simbol>
Alphabet::get_alphabet(void) {
  return alphabet_;
}


std::set <Simbol>
Alphabet::get_alphabet(void) const{
  return alphabet_;
}

void
Alphabet::Add_Simbol(Simbol simbol) {
  alphabet_.insert(simbol);
}

int
Alphabet::size(void) {
  return alphabet_.size();
}


int
Alphabet::size(void) const {
  return alphabet_.size();
}

bool
Alphabet::Contains(Simbol& simbol) {
  return alphabet_.find(simbol) != alphabet_.end();
}

std::ostream& operator <<(std::ostream& os, const Alphabet& alphabet) {
  int pos = 0;
  os << "{ ";
  for(const auto& a : alphabet.get_alphabet()) {
    pos ++;
    os << a;
    if(pos != alphabet.size()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}