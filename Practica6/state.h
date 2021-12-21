// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo state.h: alphabet.cc state.cc simbol.cc chain.cc 
// Contiene el nombre, transiciones y características de un estado
// Además contiene los metodos para gesionarlo
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#ifndef STATE 
#define STATE 

#include "simbol.h"

#include <map>

class State {
  public:
    State();
    State(std::string, bool, bool);
    ~State();

    std::string name(void) const;
    std::map <Simbol, State> get_transition(void);
    std::map <Simbol, State> get_transition(void) const;
    State get_transition(Simbol);
    State get_transition(Simbol) const;

    bool Is_Start(void);
    bool Is_Start(void) const;
    bool Is_Acceptance(void);
    bool Is_Acceptance(void) const;

    void name(std::string);
    void set_transition(std::map <Simbol, State>);

    void Add_Transition(Simbol, State);

    void Is_Start(bool);
    void Is_Acceptance(bool);

    bool operator<(const State&) const;

  private:
    std::string name_;
    std::map <Simbol, State> transition_;

    bool start_;
    bool acceptance_;
};

#endif