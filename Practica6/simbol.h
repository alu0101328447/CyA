// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo simbol.h: simbol.cc
// Contiene metodos para gestionar los simbolos
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

#ifndef SIMBOL
#define SIMBOL

#include <vector>
#include <iostream>
#include <string>

const char EMPTY = '&';
const char ESPACE = ' ';

class Simbol {
  public:
    // Constructor, copy and destructor
    Simbol();
    Simbol(std::string);
    ~Simbol();

    // getters
    std::string get_simbol(void) const;

    // setters
    void set_simbol(std::string);

    // Sobrecarga de operador de comparación
    bool operator <(const Simbol&) const;
    bool operator ==(Simbol);
    bool operator ==(Simbol) const;
    friend std::ostream& operator <<(std::ostream& os, const Simbol&);

  private:
    std::string simbol_;
};

#endif