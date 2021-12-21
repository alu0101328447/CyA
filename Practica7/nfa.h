// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de NFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo nfa.h: nfa.cc alphabet.cc state.cc symbol.cc chain.cc
// Contiene los estados, las transiciones y symbolos que permiten definir 
// un nfa. Además contiene el alfabeto que define los symbolos
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

#ifndef NFA
#define NFA

#include "alphabet.h"
#include "state.h"
#include "chain.h"

class Nfa {
  public:
    Nfa();
    Nfa(std::vector <State>, Alphabet);
    ~Nfa();

    std::set <State> state(void);
    Alphabet alphabet(void);

    void state(std::vector <State>);
    void Add_State(State);
    void alphabet(Alphabet);

    void Initial(State);
    State Initial(void);

    bool Transition(Chain);

  private:
    State initial_;
    Alphabet alphabet_;
    std::set <State> states_;

};

#endif