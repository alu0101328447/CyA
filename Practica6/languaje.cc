// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo languaje.cc:alphabet.cc simbol.cc chain.cc languaje.cc
// Contiene un conjunto de cadenas y los metodos para gestionarlas
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#include "languaje.h"

Languaje::Languaje()
{}

Languaje::Languaje(std::vector <Chain> in_languaje) {
  languaje(in_languaje);
}

Languaje::~Languaje()
{}

std::set <Chain> 
Languaje::languaje(void) {
  return languaje_;
}

void 
Languaje::languaje(std::vector <Chain> languaje) {
  for (int i = 0; i < languaje.size(); i++) {
    Add_Languaje(languaje[i]);
  }
}

void 
Languaje::Add_Languaje(Chain chain) {
  languaje_.insert(chain);
}

