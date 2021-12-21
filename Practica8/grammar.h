#ifndef GRAMMAR
#define GRAMMAR

#include <map>

#include "alphabet.h"
#include "language.h"

class Grammar {
  public:
    // Constructores y destructor
    Grammar();
    Grammar(Alphabet, Alphabet, Symbol);
    ~Grammar();

    Alphabet get_terminals(void);
    Alphabet get_non_terminals(void);
    Symbol get_start(void);
    std::vector <Chain> get_production(Symbol);

    // Setteres
    void set_terminals(Alphabet);
    void set_non_terminals(Alphabet);
    void set_start(Symbol);
    void set_production(std::map <Symbol, std::vector <Chain>>);

    // Función para añadir simbolos a mis 
    // cadenas de terminales o no terminales
    void Add_Terminal(Symbol);
    void Add_Non_Terminal(Symbol);
    void Add_Production(Symbol, Chain);

    Chain Product(Chain, Chain);
    std::string Derivations(Chain, std::vector <int>);

  private:
    Alphabet terminals_;
    Alphabet non_terminals_;

    Symbol start_;
    std::map <Symbol, std::vector <Chain>> productions_;

};

#endif