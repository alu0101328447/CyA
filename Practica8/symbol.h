// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo symbol.h: symbol.cc
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

#ifndef SYMBOL
#define SYMBOL

#include <vector>
#include <iostream>
#include <string>

const char EMPTY = '&';
const char ESPACE = ' ';

class Symbol {
  public:
    // Constructor, copy and destructor
    Symbol();
    Symbol(char);
    Symbol(std::string);
    ~Symbol();

    // getters
    std::string get_symbol(void) const;

    // setters
    void set_symbol(std::string);
    void set_symbol(char);

    // Sobrecarga de operador de comparación
    bool operator <(const Symbol&) const;
    bool operator ==(Symbol);
    bool operator ==(Symbol) const;
    friend std::ostream& operator <<(std::ostream& os, const Symbol&);

  private:
    std::string symbol_;
};

#endif