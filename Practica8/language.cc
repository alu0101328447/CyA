// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo language.cc:alphabet.cc symbol.cc chain.cc language.cc
// Contiene un conjunto de cadenas y los metodos para gestionarlas
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

#include "language.h"

/**
*
*  @brief  Language constructor -> initialize Language objects-
*
*/
Language::Language()
{}

/**
*
*  @brief  Language constructor -> initialize Language objects-
*  @param  std::vector <Chain> -> all the chains from the language
*
*/
Language::Language(std::vector <Chain> in_language) {
  language(in_language);
}

/**
*
*  @brief  Language destructor -> destroys Language objects-
*
*/
Language::~Language()
{}

/**
*
*  @brief  Language getter 
*  @return  std::set <Chain> -> all the chains from the language
*
*/
std::set <Chain> 
Language::language(void) {
  return language_;
}

/**
*
*  @brief  Language setter 
*  @param  std::vector <Chain> -> all the chains from the language
*
*/
void 
Language::language(std::vector <Chain> language) {
  for (int i = 0; i < language.size(); i++) {
    Add_Language(language[i]);
  }
}

/**
*
*  @brief  Language function that allows to insert another chain 
*  @return  Chain -> the new chain of the language
*
*/
void 
Language::Add_Language(Chain chain) {
  language_.insert(chain);
}

