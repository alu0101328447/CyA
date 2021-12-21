#include "cadena.h"

Cadena::Cadena()
{
  cadena_.clear();
}

Cadena::Cadena(std::string cadena, Alfabeto alfabeto) {
  cadena_.clear();
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
  setAlfabeto(alfabeto);
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
Cadena::setAlfabeto(Alfabeto alfabeto) {
  alfabeto_.clear();
  alfabeto_.setAlfabeto(alfabeto.getAlfabeto());
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

bool
Cadena::Subcadena(Cadena cadena) {
  bool resultado;
  std::string auxCadena;
  for(int i = 0; i < cadena.getSize(); i++) {
    resultado = false;
    for(int j = 0; j < getSize(); j++) {
      if(cadena.getCadena()[i].getSize() < cadena_[j].getSize()) {
        for(int k = 0; k < cadena.getCadena()[i].getSize(); k++) {
          auxCadena.push_back(cadena_[j].getSimbolo()[k]);
        }
        if(cadena.getCadena()[i].getSimbolo() == auxCadena) {
          resultado = true;
        }
        auxCadena.clear();
      }
    }
    if(!resultado) {
      return resultado;
    }
  }
  return true;
}

Cadena
Cadena::operator *(Cadena cadena) {
  Cadena auxCadena;
  for(int i = 0; i < getSize(); i++) {
    auxCadena.addSimbolo(cadena_[i]);
  }
  for(int j = 0; j < cadena.getSize(); j++) {
    auxCadena.addSimbolo(cadena.getCadena()[j]);
  }

  return auxCadena;
}

Cadena
Cadena::operator ^(int exponente) {
  Cadena auxCadena;
  if (exponente == 0) {
    auxCadena.clear();
    return auxCadena;
  }
  for (int i = 0; i < exponente; i++) {
    for (int j = 0; j < getSize(); j++) {
      auxCadena.addSimbolo(cadena_[j]);
    }
  }
  
  return auxCadena;
}

bool
Cadena::operator >(Cadena cadena) {
  if (Subcadena(cadena)) {
    return true;
  }
  return false;
}

bool
Cadena::operator <(Cadena cadena) {
  if (cadena.Subcadena(*this)) {
    return true;
  }
  return false;
}

bool
Cadena::operator ==(Cadena cadena) {
  if((Subcadena(cadena)) && (cadena.Subcadena(*this))) {
    return true;
  }
  return false;
}


Cadena
Cadena::operator =(Cadena cadena) {
  clear();
  for(int i = 0; i < cadena.getSize(); i++) {
    addSimbolo(cadena.getCadena()[i]);
  }
  return *this;
}