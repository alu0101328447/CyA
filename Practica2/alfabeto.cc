#include "alfabeto.h"

Alfabeto::Alfabeto()
{
  alfabeto_.clear();
}

Alfabeto::~Alfabeto()
{}

std::vector <Simbolo>
Alfabeto::getAlfabeto(void) {
  return alfabeto_;
}

int
Alfabeto::getSize(void) {
  return alfabeto_.size();
}

Simbolo 
Alfabeto::getSimbolo(int posicion) {
  if ((posicion < alfabeto_.size()) && (posicion >= 0)) {
    return alfabeto_[posicion];
  }
  throw "ERROR al intentar acceder al alfabeto";
}

void
Alfabeto::setAlfabeto(std::vector<Simbolo> alfabeto) {
  for(int i = 0; i < alfabeto.size(); i++) {
    alfabeto_.push_back(alfabeto[i]);
  }
}

void 
Alfabeto::addSimbolo(std::string simbol) {
  Simbolo simbolo;
  simbolo.setSimbolo(simbol);
  alfabeto_.push_back(simbolo);
}

void 
Alfabeto::addSimbolo(Simbolo simbolo) {
  alfabeto_.push_back(simbolo);
}

void
Alfabeto::clear(void) {
  alfabeto_.clear();
}

bool 
Alfabeto::Subcadena() {
  /*
  for(int i = 0; i < alfabeto_.size() - 1; i++) {
    for(int j = i + 1; j < alfabeto_.size(); j++) {
      if(alfabeto_[i].getSimbolo() == alfabeto_[j].getSimbolo()) {
        std::cout << "Si devolvimos el error";
        return 1;
      }
    }
  }
  */
  std::string auxCadena;
  for(int i = 0; i < alfabeto_.size(); i++) {
    for(int j = 0; j < alfabeto_.size(); j++) {
      if(alfabeto_[i].getSize() < alfabeto_[j].getSize()) {
        for(int k = 0; k < alfabeto_[i].getSize(); k++) {
          auxCadena.push_back(alfabeto_[j].getSimbolo()[k]);
        }
        if(alfabeto_[i].getSimbolo() == auxCadena) {
          return 1;
        }
        auxCadena.clear();
      }
    }
  }

  return 0;
}

void 
Alfabeto::printAlfabeto(void) {
  std::cout << "{" << VACIA << ",";
  for(int i = 0; i < alfabeto_.size(); i++) {
    std::cout << alfabeto_[i].getSimbolo();
    if(i != alfabeto_.size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "}" << std::endl;
}
