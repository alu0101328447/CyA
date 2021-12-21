// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo chain.cc: alphabet.cc simbol.cc chain.cc
// Contiene la un vector de simbolos y el alfabeto que los define
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#include "chain.h"

Chain::Chain()
{}

Chain::Chain(std::vector <Simbol> in_chain, Alphabet alphabet) {
  chain(in_chain, alphabet);
}

Chain::~Chain()
{}

std::vector<Simbol> 
Chain::chain(void) {
  return chain_;
}

std::vector<Simbol> 
Chain::chain(void) const {
  return chain_;
}

int
Chain::size(void) {
  return chain_.size();
}

int
Chain::size(void) const {
  return chain_.size();
}

int
Chain::size(Alphabet alphabet) {
  int resultado = 0;

  for (int i = 0; i < chain_.size(); i++) {
    if (alphabet.Contains(this->chain()[i])) {
      resultado ++;
    }
  }

  return resultado;
}

void 
Chain::chain(std::vector <Simbol> chain, Alphabet alphabet) {
  set_alphabet(alphabet);

  for (int i = 0; i < chain.size(); i++) {
    if (alphabet.Contains(chain[i])) {
      Add_Simbol(chain[i]);
    } else {
      std::cout << "El simbolo " << chain[i] 
      << " no pertenece al alfabeto" << std::endl;
    }
  }
}

void
Chain::Add_Simbol(Simbol simbol) {
  chain_.push_back(simbol);
}

void
Chain::set_alphabet(Alphabet alphabet) {
  for(const auto& a : alphabet.get_alphabet()) {
    alphabet_.Add_Simbol(a);
  }
}

void
Chain::clear(void) {
  chain_.clear();
}

bool
Chain::Is_Sub_Chain(std::vector <Chain> chain) {
  bool result;
  std::vector <Chain> aux_chain;
  aux_chain = this->Sub_Chain();
  for (int i = 0; i < chain.size(); i++) {
    result = false;
    for (int j = 0; j < aux_chain.size(); j++) {
      if(aux_chain[j] == chain[i]) {
        result = true;
      }
    }
    if (result == false) {
      return false;
    }
  }
  return true;
}

bool
Chain::Is_Sub_Chain(std::vector <Chain> chain) const {
  bool result;
  std::vector <Chain> aux_chain;
  aux_chain = this->Sub_Chain();
  int confirm;

  for (int i = 0; i < chain.size(); i++) {
    result = false;
    for (int j = 0; j < aux_chain.size(); j++) {
      for (auto& c : chain) {
      confirm = 0;
        if (c.size() == aux_chain[j].size()) {
          for (int x = 0; x < aux_chain[j].size(); x++) {
            if (c.chain()[x] == aux_chain[j].chain()[x]) {
              confirm++;
            }
          }
          if (confirm == aux_chain[j].size()) {
            result = true;
          }
        } 
      }
    }
    if (result == false) {
      return false;
    }
  }
  return true;
}

std::vector <Chain>
Chain::Sub_Chain(void) {
  Chain aux_chain;
  std::vector <Chain> vector_chain;
  bool belongs;
  int confirm;

  for (int i = 0; i < chain_.size(); i++) {
    for (int j = 0; j < chain_.size() - i; j++) {
      for (int k = j; k <= i + j; k++) {
         aux_chain.Add_Simbol(chain_[k]);
      }
      vector_chain.push_back(aux_chain);
      aux_chain.clear();
    }
  }
  return vector_chain;
}

std::vector <Chain>
Chain::Sub_Chain(void) const {
  Chain aux_chain;
  std::vector <Chain> vector_chain;
  bool belongs;
  int confirm;

  for (int i = 0; i < chain_.size(); i++) {
    for (int j = 0; j < chain_.size() - i; j++) {
      for (int k = j; k <= i + j; k++) {
         aux_chain.Add_Simbol(chain_[k]);
      }
      vector_chain.push_back(aux_chain);
      aux_chain.clear();
    }
  }
  return vector_chain;
}

bool
Chain::operator >(Chain chain) {
  if (Is_Sub_Chain(chain.Sub_Chain())) {
    return true;
  }
  return false;
}

bool
Chain::operator <(Chain chain) {
  if (chain.Is_Sub_Chain(this->Sub_Chain())) {
    return true;
  }
  return false;
}

bool
Chain::operator <(const Chain& chain) const {
  int pos;

  if (chain.size() > this->size()) {
    return true;
  } else if (chain.size() == this->size()) {
    pos = 0;
    for (auto& c : chain.chain()) {
      if (chain_[pos] < c) {
        return true;
      } else if (c < chain_[pos]) {
        return false;
      }
      pos ++;
    }
  }
  return false;
}


bool
Chain::operator ==(Chain chain) {
  if ((Is_Sub_Chain(chain.Sub_Chain())) && (chain.Is_Sub_Chain(this->Sub_Chain()))) {
    return true;
  }
  return false;
} 

std::ostream& operator <<(std::ostream& os, const Chain& chain) {
  for(const auto& c : chain.chain()) {
    os << c;
  }
  return os;
}