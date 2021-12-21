#include "alphabet.h"

Alphabet::Alphabet() 
{}

Alphabet::Alphabet(std::vector <Simbol> alphabet) {
  for (int i = 0; i < alphabet.size(); i++) {
    Add_Simbol(alphabet[i]);
  }
}

Alphabet::~Alphabet()
{}

std::set <Simbol>
Alphabet::get_alphabet(void) {
  return alphabet_;
}


std::set <Simbol>
Alphabet::get_alphabet(void) const{
  return alphabet_;
}

void
Alphabet::Add_Simbol(Simbol simbol) {
  alphabet_.insert(simbol);
}

int
Alphabet::size(void) {
  return alphabet_.size();
}


int
Alphabet::size(void) const {
  return alphabet_.size();
}

bool
Alphabet::Contains(Simbol& simbol) {
  return alphabet_.find(simbol) != alphabet_.end();
}

std::ostream& operator <<(std::ostream& os, const Alphabet& alphabet) {
  int pos = 0;
  os << "{ ";
  for(const auto& a : alphabet.get_alphabet()) {
    pos ++;
    os << a;
    if(pos != alphabet.size()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}