#include "languaje.h"

Languaje::Languaje()
{}

Languaje::Languaje(std::vector <Chain> in_languaje) {
  languaje(in_languaje);
}

Languaje::~Languaje()
{}

std::set <Chain> 
Languaje::languaje(void) {
  return languaje_;
}

void 
Languaje::languaje(std::vector <Chain> languaje) {
  for (int i = 0; i < languaje.size(); i++) {
    Add_Languaje(languaje[i]);
  }
}

void 
Languaje::Add_Languaje(Chain chain) {
  languaje_.insert(chain);
}

