// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo chain.cc: alphabet.cc symbol.cc chain.cc
// Contiene la un vector de symbolos y el alfabeto que los define
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

/**
*
*  @brief  Chain constructor -> initialize Chain objects-
*
*/
Chain::Chain()
{}

/**
*
*  @brief  Chain constructor -> initialize Chain objects-
*  @param  std::vector <Symbol> -> simbols of the chain
*  @param  Alphabet -> alphabet that describes this chain
*
*/
Chain::Chain(std::vector <Symbol> in_chain, Alphabet alphabet) {
  chain(in_chain, alphabet);
}

/**
*
*  @brief  Chain destructor -> destroys Chain objects-
*
*/
Chain::~Chain()
{}

/**
*
*  @brief  Chain getter -> return the chain
*  @return  std::vector<Symbol> -> the chain
*
*/
std::vector<Symbol> 
Chain::chain(void) {
  return chain_;
}

/**
*
*  @brief  const Chain getter -> return the const chain
*  @return  std::vector<Symbol> -> the const chain
*
*/
std::vector<Symbol> 
Chain::chain(void) const {
  return chain_;
}

/**
*
*  @brief  Chain getter -> return the chain size
*  @return  int -> the chain size
*
*/
int
Chain::size(void) {
  return chain_.size();
}

/**
*
*  @brief  const Chain getter -> return the const chain size
*  @return  int -> the cosnt chain size
*
*/
int
Chain::size(void) const {
  return chain_.size();
}

/**
*
*  @brief  Chain getter -> return the size of the chain if the alphabet was param
*  @param  Alphabet another alphabet
*  @return  int -> the chain
*
*/
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

/**
*
*  @brief  Chain function that constructs the alphabet and the chain
*  @param  std::vector <Symbol> all the simbols of the chain
*  @param  Alphabet of the chain
*
*/
void 
Chain::chain(std::vector <Symbol> chain, Alphabet alphabet) {
  set_alphabet(alphabet);

  for (int i = 0; i < chain.size(); i++) {
    if (alphabet.Contains(chain[i])) {
      Add_Symbol(chain[i]);
    } else {
      std::cout << "El symbolo " << chain[i] 
      << " no pertenece al alfabeto" << std::endl;
    }
  }
}

/**
*
*  @brief  Chain function that inserts a new symbol
*  @param  Symbol new symbol of the chain
*
*/
void
Chain::Add_Symbol(Symbol symbol) {
  chain_.push_back(symbol);
}

/**
*
*  @brief  Chain function that equals the alphabet with our class alphabet
*  @param  Alphabet the new alphabet of the chain
*
*/
void
Chain::set_alphabet(Alphabet alphabet) {
  for(const auto& a : alphabet.get_alphabet()) {
    alphabet_.Add_Symbol(a);
  }
}

/**
*
* @brief  Chain function to clear the chain symbols
*
*/
void
Chain::clear(void) {
  chain_.clear();
}

/**
*
*  @brief  Chain function that compares two Chains
*  @param  std::vector <Chain> the Chain we are comparing to
*  @return bool -> if @param is a subchain -> true
*
*/
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

/**
*
*  @brief  const Chain function that compares two Chains
*  @param  std::vector <Chain> the Chain we are comparing to
*  @return bool -> if @param is a subchain -> true
*
*/
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

/**
*
*  @brief  Chain function that makes all the subchains
*  @return  std::vector <Chain> all the subchains of this class
*
*/
std::vector <Chain>
Chain::Sub_Chain(void) {
  Chain aux_chain;
  std::vector <Chain> vector_chain;
  bool belongs;
  int confirm;

  for (int i = 0; i < chain_.size(); i++) {
    for (int j = 0; j < chain_.size() - i; j++) {
      for (int k = j; k <= i + j; k++) {
         aux_chain.Add_Symbol(chain_[k]);
      }
      vector_chain.push_back(aux_chain);
      aux_chain.clear();
    }
  }
  return vector_chain;
}

/**
*
*  @brief  const Chain function that makes all the subchains
*  @return  std::vector <Chain> all the subchains of this class
*
*/
std::vector <Chain>
Chain::Sub_Chain(void) const {
  Chain aux_chain;
  std::vector <Chain> vector_chain;
  bool belongs;
  int confirm;

  for (int i = 0; i < chain_.size(); i++) {
    for (int j = 0; j < chain_.size() - i; j++) {
      for (int k = j; k <= i + j; k++) {
         aux_chain.Add_Symbol(chain_[k]);
      }
      vector_chain.push_back(aux_chain);
      aux_chain.clear();
    }
  }
  return vector_chain;
}

/**
*
*  @brief  Chain operator to compare two Chains
*
*/
bool
Chain::operator >(Chain chain) {
  if (Is_Sub_Chain(chain.Sub_Chain())) {
    return true;
  }
  return false;
}

/**
*
*  @brief  Chain operator to compare two Chains
*
*/
bool
Chain::operator <(Chain chain) {
  if (chain.Is_Sub_Chain(this->Sub_Chain())) {
    return true;
  }
  return false;
}

/**
*
*  @brief  const Chain operator to compare two Chains
*
*/
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

/**
*
*  @brief  Chain operator to compare two Chains
*
*/
bool
Chain::operator ==(Chain chain) {
  if ((Is_Sub_Chain(chain.Sub_Chain())) && (chain.Is_Sub_Chain(this->Sub_Chain()))) {
    return true;
  }
  return false;
} 

/**
*
*  @brief  Chain operator to compare two Chains
*
*/
std::ostream& operator <<(std::ostream& os, const Chain& chain) {
  for(const auto& c : chain.chain()) {
    os << c;
  }
  return os;
}