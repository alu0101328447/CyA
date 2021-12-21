// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo alfabeto.h:  alfabeto.cc alfabeto.h simbolos.cc simbolos.h
// Contiene la clase alfabeto que es la encargada de almacenar los simbolos
// del alfabeto pertinentes para posteriormente crear la cadena
//
// Historial de revisiones
// 08/10/2021 - Creación (primera versión) del código
// 13/10/2021 - Revisión (ultima versión) del código

#ifndef ALFABETO 
#define ALFABETO

#include "simbolos.h"

class Alfabeto {
  public:
    // Constructor y destructor por defecto
    Alfabeto();
    ~Alfabeto();

    // getters
    std::vector<Simbolo> getAlfabeto(void);
    int getSize(void);
    Simbolo getSimbolo(int);

    // setters
    void setAlfabeto(std::vector<Simbolo>);

    // Funciones que añaden al final del alfabeto un Simbolo 
    // o un string que convierte en simbolo
    void addSimbolo(std::string);
    void addSimbolo(Simbolo);

    // Funcion que limpia/vacia el alfabeto
    void clear(void);

    // Funcion que comprueba si alguno de los 
    //elementos del alfabeto es subcadena de otro
    bool Subcadena(void);

    // Funcion que imprime el alfabeto
    void printAlfabeto(void);

  private:
    std::vector<Simbolo> alfabeto_;
};

#endif