// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo dfa.h: dfa.cc alphabet.cc state.cc simbol.cc chain.cc
// Contiene los estados, las transiciones y simbolos que permiten definir 
// un dfa. Además contiene el alfabeto que define los simbolos
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#ifndef DFA
#define DFA

#include "alphabet.h"
#include "state.h"
#include "chain.h"

class Dfa {
  public:
    Dfa();
    Dfa(std::vector <State>, Alphabet);
    ~Dfa();

    std::set <State> state(void);
    Alphabet alphabet(void);

    void state(std::vector <State>);
    void Add_State(State);
    void alphabet(Alphabet);

    void Initial(State);
    State Initial(void);

    State Transition(Chain);

  private:
    State initial_;
    Alphabet alphabet_;
    std::set <State> states_;


};

#endif