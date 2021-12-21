// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo languaje.h:alphabet.cc simbol.cc chain.cc languaje.cc
// Contiene un conjunto de cadenas y los metodos para gestionarlas
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#ifndef LANGUAJE 
#define LANGUAJE 

#include "chain.h"

class Languaje {
  public: 
    Languaje();
    Languaje(std::vector <Chain>);
    ~Languaje();

    std::set <Chain> languaje(void);
    void languaje(std::vector <Chain>);
    void Add_Languaje(Chain);

  private:
    std::set <Chain> languaje_;
};

#endif