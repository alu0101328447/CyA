// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo chain.h: alphabet.cc symbol.cc chain.cc
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

#ifndef CHAIN  
#define CHAIN

#include "symbol.h"
#include "alphabet.h"

class Chain {
  public:
    // Constructor, constructor de copia y destructor por defecto
    Chain();
    Chain(std::vector <Symbol>, Alphabet);
    ~Chain();

    // getters
    std::vector<Symbol> chain(void);
    std::vector<Symbol> chain(void) const;
    int size(void);
    int size(void) const;
    int size(Alphabet);

    // setters
    void chain(std::vector <Symbol>, Alphabet);

        // Funcion que es como un setter pero solo añade symbol al final de la chain
    void Add_Symbol(Symbol);

    // Funcion que limpia la chain de los elementos
    void clear(void);

    std::vector <Chain> Sub_Chain(void);
    std::vector <Chain> Sub_Chain(void) const;
    bool Is_Sub_Chain(std::vector <Chain>);
    bool Is_Sub_Chain(std::vector <Chain>) const;

    // Operadores de comparacion
    bool operator >(Chain);
    bool operator <(Chain);
    bool operator <(const Chain&) const;
    bool operator ==(Chain);

    // Operador de salida
    friend std::ostream& operator <<(std::ostream&, const Chain&);

  private:
    // Variables que almacena la Chain
    std::vector <Symbol> chain_;
    Alphabet alphabet_;

    void set_alphabet(Alphabet);
};

#endif
