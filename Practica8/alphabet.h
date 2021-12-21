// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo alphabet.h:  alphabet.cc symbol.cc
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

#ifndef ALPHABET 
#define ALPHABET

#include "symbol.h"
#include <set>

class Alphabet {
  public:
    // Constructor y destructor por defecto
    Alphabet();
    Alphabet(std::vector <Symbol>);
    ~Alphabet();

    // getters
    std::set <Symbol> get_alphabet(void);
    std::set <Symbol> get_alphabet(void) const;
    int size(void);
    int size(void) const;

    // Funciones que añaden al final del alphabet un Symbol 
    void Add_Symbol(Symbol);

    // Comprueba si el elemento se encuentra en el alfabeto
    bool Contains(Symbol);

    // Sobrecarga del operador de salida
    friend std::ostream& operator <<(std::ostream& os, const Alphabet&);

  private: 
    std::set <Symbol> alphabet_;
};

#endif