#ifndef CHAIN  
#define CHAIN

#include "simbol.h"
#include "alphabet.h"

class Chain {
  public:
    // Constructor, constructor de copia y destructor por defecto
    Chain();
    Chain(std::vector <Simbol>, Alphabet);
    ~Chain();

    // getters
    std::vector<Simbol> chain(void);
    std::vector<Simbol> chain(void) const;
    int size(void);
    int size(Alphabet);

    // setters
    void chain(std::vector <Simbol>, Alphabet);

        // Funcion que es como un setter pero solo añade simbol al final de la chain
    void Add_Simbol(Simbol);

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
    std::vector <Simbol> chain_;
    Alphabet alphabet_;

    void set_alphabet(Alphabet);
};

#endif
