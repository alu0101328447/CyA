#ifndef LANGUAJE 
#define LANGUAJE 

#include "chain.h"

class Languaje {
  public: 
    Languaje();
    Languaje(std::vector <Chain>);
    ~Languaje();

    std::set <Chain> languaje(void);
    void languaje(std::vector <Chain>);
    void Add_Languaje(Chain);

  private:
    std::set <Chain> languaje_;
};

#endif