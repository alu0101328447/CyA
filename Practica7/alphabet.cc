// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo alphabet.cc:  alphabet.cc symbol.cc
// Contiene un conjunto de symbolos
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

#include "alphabet.h"

/**
*
*  @brief  Alphabet constructor -> initialize Alphabet objects-
*
*/
Alphabet::Alphabet() 
{
  std::string empty;
  empty.push_back(EMPTY);
  Symbol symbol((empty));
  alphabet_.insert(symbol);
}

/**
*
*  @brief  Alphabet constructor -> initialize Alphabet objects-
*  @param  std::vector <Symbol> vector of symbols that make up the alphabet.
*
*/
Alphabet::Alphabet(std::vector <Symbol> alphabet) {
  std::string empty;
  empty.push_back(EMPTY);
  Symbol symbol((empty));
  alphabet_.insert(symbol);
  
  for (int i = 0; i < alphabet.size(); i++) {
    Add_Symbol(alphabet[i]);
  }
}


/**
*
*  @brief  Alphabet destructor -> destroys Alphabet objects-
*
*/
Alphabet::~Alphabet()
{}


/**
*
*  @brief  Alphabet getter -> return the alphabet
*  @return std::set <Symbol> -> the alphabet
*
*/
std::set <Symbol>
Alphabet::get_alphabet(void) {
  return alphabet_;
}

/**
*
*  @brief  const Alphabet getter -> return the alphabet
*  @return std::set <Symbol> const -> the alphabet
*
*/
std::set <Symbol>
Alphabet::get_alphabet(void) const{
  return alphabet_;
}

/**
*
*  @brief  Alphabet setter -> return the alphabet
*  @param  Symbol -> adds the symbol to the Alphabet
*
*/
void
Alphabet::Add_Symbol(Symbol symbol) {
  alphabet_.insert(symbol);
}

/**
*
*  @brief  Alphabet getter -> return the size
*  @return int -> the alphabet size
*
*/
int
Alphabet::size(void) {
  return alphabet_.size();
}

/**
*
*  @brief  const Alphabet getter -> return the size
*  @return int -> the alphabet size in const type
*
*/
int
Alphabet::size(void) const {
  return alphabet_.size();
}

/**
*
*  @brief  Alphabet bool function -> true if contains the symbol
*  @param Symbol& -> the symbol we are looking if the alphabet contains
*  @return bool -> if the symbol is into the alphabet -> true
*
*/
bool
Alphabet::Contains(Symbol& symbol) {
  return alphabet_.find(symbol) != alphabet_.end();
}


/**
*
*  @brief  Alphabet operator -> allows print the alphabet using <<
*
*/
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