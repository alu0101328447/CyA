// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo state.h: alphabet.cc state.cc symbol.cc chain.cc 
// Contiene el nombre, transiciones y características de un estado
// Además contiene los metodos para gesionarlo
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

#ifndef STATE 
#define STATE 

#include "symbol.h"

#include <map>

class State {
  public:
  
    State();
    State(std::string, bool);
    ~State();

    std::string name(void) const;
    std::vector <State> get_transition(Symbol);
    std::vector <State> get_transition(Symbol) const;

    bool Is_Acceptance(void);
    bool Is_Acceptance(void) const;

    void name(std::string);
    void set_transition(std::multimap <Symbol, State>);

    void Add_Transition(Symbol, State);

    void Is_Acceptance(bool);

    bool operator<(const State&) const;

  private:
    std::string name_;
    std::multimap <Symbol, State> transition_;

    bool acceptance_;
};

#endif