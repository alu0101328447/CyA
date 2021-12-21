// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo cadena.h: cadena.cc cadena.h alfabeto.cc 
// alfabeto.h simbolos.cc simbolos.h
// Contiene la clase cadena que se encarga de la construccion de la cadena
// a partir de el alfabeto y su posterior gestión de la cadena para 
// imprimir los datos segun se pida
//
// Historial de revisiones
// 08/10/2021 - Creación (primera versión) del código
// 13/10/2021 - Revisión (ultima versión) del código

#ifndef CADENA 
#define CADENA 

#include "simbolos.h"
#include "alfabeto.h"

class Cadena {  
  public:
    // Constructor, constructor de copia y destructor por defecto
    Cadena();
    Cadena(std::string, Alfabeto);
    ~Cadena();

    // getters
    std::vector<Simbolo> getCadena(void);
    int getSize(void);
    int getSize(Alfabeto);

    // setters
    void setCadena(std::string, Alfabeto);

    // Funcion que es como un setter pero solo añade simbolos al final de la cadena
    void addSimbolo(Simbolo);

    // Funcion que limpia la cadena de los elementos
    void clear(void);


    // Funciones que se encargan de imprimir la cadena de las formas que se necesitan
    void printCadena(void);
    void printReverseCadena(void);
    void printPrefijo(void);
    void printSufijo(void);
    void printSubcadena(void);

  private:
    // Variables que almacena la cadena
    std::vector <Simbolo> cadena_;
    Alfabeto alfabeto_;
};

#endif