#ifndef ALPHABET 
#define ALPHABET

#include "simbol.h"
#include <set>

class Alphabet {
  public:
    // Constructor y destructor por defecto
    Alphabet();
    Alphabet(std::vector <Simbol>);
    ~Alphabet();

    // getters
    std::set <Simbol> get_alphabet(void);
    std::set <Simbol> get_alphabet(void) const;
    int size(void);
    int size(void) const;

    // Funciones que añaden al final del alphabet un Simbol 
    void Add_Simbol(Simbol);

    // Comprueba si el elemento se encuentra en el alfabeto
    bool Contains(Simbol&);

    // Sobrecarga del operador de salida
    friend std::ostream& operator <<(std::ostream& os, const Alphabet&);

  private: 
    std::set <Simbol> alphabet_;
};

#endif