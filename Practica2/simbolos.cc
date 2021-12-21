#include "simbolos.h"

Simbolo::Simbolo() 
{}

Simbolo::Simbolo(std::string simbolo) {
  setSimbolo(simbolo);
}

Simbolo::~Simbolo()
{}

std::string
Simbolo::getSimbolo(void) {
  return simbolo_;
}

int 
Simbolo::getSize(void) {
  return size_;
}

void
Simbolo::setSimbolo(std::string simbolo) {
  simbolo_ = simbolo;
  setSize(simbolo_.size());
} 

void
Simbolo::setSize(int size) {
  size_ = size;
}



