#ifndef SIMBOL
#define SIMBOL

#include <vector>
#include <iostream>
#include <string>

const char EMPTY = '&';
const char ESPACE = ' ';

class Simbol {
  public:
    // Constructor, copy and destructor
    Simbol();
    Simbol(std::string);
    ~Simbol();

    // getters
    std::string get_simbol(void) const;

    // setters
    void set_simbol(std::string);

    // Sobrecarga de operador de comparación
    bool operator <(const Simbol&) const;
    bool operator ==(Simbol);
    bool operator ==(Simbol) const;
    friend std::ostream& operator <<(std::ostream& os, const Simbol&);

  private:
    std::string simbol_;
};

#endif