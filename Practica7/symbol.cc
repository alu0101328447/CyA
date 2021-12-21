// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo symbol.cc: symbol.cc
// Contiene metodos para gestionar los symbolos
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

#include "symbol.h"

/**
*
*  @brief  Symbol constructor -> initialize Symbol objects-
*
*/
Symbol::Symbol() 
{}

/**
*
*  @brief  Symbol constructor -> initialize Symbol objects-
*  @param  std::string -> the symbol
*
*/
Symbol::Symbol(std::string symbol) {
  set_symbol(symbol);
}

/**
*
*  @brief  Symbol destructor -> destroys Symbol objects-
*
*/
Symbol::~Symbol()
{}

/**
*
*  @brief  const Symbol getter 
*  @param  std::string -> the symbol
*
*/
std::string
Symbol::get_symbol(void) const {
  return symbol_;
}

/**
*
*  @brief  Symbol setter 
*  @param  std::string -> the symbol
*
*/
void
Symbol::set_symbol(std::string symbol) {
  symbol_ = symbol;
} 

/**
*
*  @brief  const Symbol function that allows to compare two simbols
*  @param  Symbol -> the symbol we compare
*
*/
bool 
Symbol::operator <(const Symbol& symbol) const {
  return symbol_ < symbol.get_symbol();
}

/**
*
*  @brief  Symbol function that allows to compare two simbols
*  @param  Symbol -> the symbol we compare
*
*/
bool 
Symbol::operator ==(Symbol symbol) {
  return symbol_ == symbol.get_symbol();
}

/**
*
*  @brief  const Symbol function that allows to compare two simbols
*  @param  Symbol -> the symbol we compare
*
*/
bool 
Symbol::operator ==(Symbol symbol) const {
  return symbol_ == symbol.get_symbol();
}

/**
*
*  @brief  Symbol function that allows to print a symbol using <<
*
*/
std::ostream &operator <<(std::ostream& os, const Symbol& symbol) {
  return os << symbol.get_symbol();
}