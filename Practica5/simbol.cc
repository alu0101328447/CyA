#include "simbol.h"

Simbol::Simbol() 
{}

Simbol::Simbol(std::string simbol) {
  set_simbol(simbol);
}

Simbol::~Simbol()
{}

std::string
Simbol::get_simbol(void) const {
  return simbol_;
}

void
Simbol::set_simbol(std::string simbol) {
  simbol_ = simbol;
} 

bool 
Simbol::operator <(const Simbol& simbol) const {
  return simbol_ < simbol.get_simbol();
}

bool 
Simbol::operator ==(Simbol simbol) {
  return simbol_ == simbol.get_simbol();
}

bool 
Simbol::operator ==(Simbol simbol) const {
  return simbol_ == simbol.get_simbol();
}

std::ostream &operator <<(std::ostream& os, const Simbol& simbol) {
  return os << simbol.get_simbol();
}