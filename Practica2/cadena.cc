#include "cadena.h"

Cadena::Cadena()
{
  cadena_.clear();
}

Cadena::Cadena(std::string cadena, Alfabeto alfabeto) {
  setCadena(cadena, alfabeto);
}

Cadena::~Cadena()
{}

std::vector<Simbolo> 
Cadena::getCadena(void) {
  return cadena_;
}

int
Cadena::getSize(void) {
  return cadena_.size();
}

int
Cadena::getSize(Alfabeto alfabeto) {
  std::string auxCadena;
  int resultado = 0;

  for(int i = 0; i < cadena_.size(); i++) {
    for(int j = 0; j < alfabeto.getSize(); j++) {
      if(alfabeto.getSimbolo(j).getSimbolo() == cadena_[i].getSimbolo()) {
        resultado ++;
      }
    }
  }

  return resultado;
}

void 
Cadena::setCadena(std::string cadena, Alfabeto alfabeto) {
  std::string auxCadena;
  //std::vector <std::string> auxVectorCadena;
  int aux;

  for(int i = 0; i < cadena.size(); i++) {
    aux = i;
    for(int j = 0; j < alfabeto.getSize(); j++) {
      if(alfabeto.getSimbolo(j).getSize() <= cadena.size() + i) {
        for(int z = 0; z < alfabeto.getSimbolo(j).getSize(); z++) {
          auxCadena.push_back(cadena[z + i]);
        }
      }
      if(auxCadena == alfabeto.getSimbolo(j).getSimbolo()) {
        cadena_.push_back(alfabeto.getSimbolo(j));
        i = i + auxCadena.size() - 1;
      }
      auxCadena.clear();
    }
    if(cadena_.size() <= i) {
      throw "ERROR la cadena contiene un elemento que no pertenece al alfabeto";
    }
  }
}

void
Cadena::addSimbolo(Simbolo simbolo) {
  cadena_.push_back(simbolo);
}

void
Cadena::clear(void) {
  cadena_.clear();
}

void
Cadena::printCadena(void) {
  for (int i = 0; i < cadena_.size(); i++) {
    std::cout << cadena_[i].getSimbolo();
  }
  std::cout << std::endl;
}

void
Cadena::printReverseCadena(void) {
  for (int i = cadena_.size() - 1; i >= 0; i--) {
    std::cout << cadena_[i].getSimbolo();
  }
  std::cout << std::endl;
}

void
Cadena::printPrefijo(void) {
  std::cout << VACIA << " ";
  for(int i = 0; i < cadena_.size(); i++) {
    for(int j = 0; j <= i; j++) {
      std::cout << cadena_[j].getSimbolo();
    }
    std::cout << " ";
  }
  std::cout << std::endl;
}

void
Cadena::printSufijo(void) { 
  std::cout << VACIA << " ";
  for(int i = cadena_.size() - 1; i >= 0; i--) {
    for(int j = cadena_.size() - 1; j >= i; j--) {
      std::cout << cadena_[j].getSimbolo();
    }
    std::cout << " ";
  }
  std::cout << std::endl;
}

void
Cadena::printSubcadena(void) {
  for(int i = 0; i < cadena_.size(); i++) {
    for(int j = 0; j < cadena_.size() - i; j++) {
      for(int k = j; k <= i + j; k++) {
        std::cout << cadena_[k].getSimbolo();
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}


