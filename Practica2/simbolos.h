// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo simbolos.cc: simbolos.cc simbolos.h
// Contiene la clase simbolos que forma el alfabeto y la cadena
//
// Historial de revisiones
// 08/10/2021 - Creación (primera versión) del código
// 13/10/2021 - Revisión (ultima versión) del código

#ifndef SIMBOLO
#define SIMBOLO

#include <vector>
#include <iostream>
#include <string>

const char VACIA = '&';

class Simbolo {
  public:
    // Constructor, constructor de copia y destructor
    Simbolo();
    Simbolo(std::string);
    ~Simbolo();

    // getters
    std::string getSimbolo(void);
    int getSize(void);

    // setters
    void setSimbolo(std::string);

  private:
    // Variables de simbolo y de tamaño
    std::string simbolo_;
    int size_;

    // setter privado que regula el tamaño
    void setSize(int);
};

#endif