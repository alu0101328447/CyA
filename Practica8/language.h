// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulacion de DFAs
// Autor: Jose Pablo Ruiz Galván
// Correo: alu0101328447@ull.es
// Fecha: 08/10/2021
// Archivo language.h:alphabet.cc symbol.cc chain.cc language.cc
// Contiene un conjunto de cadenas y los metodos para gestionarlas
//
// Historial de revisiones
// 06/11/2021 - Creación (primera versión) del código
// 09/10/2021 - Revisión (ultima versión) del código
// 

/**
 * @author: José Pablo Ruiz Galván
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 3º Ingeniería Informática
 * Práctica 7: NFA 
 */

#ifndef LANGUAGE 
#define LANGUAGE 

#include "chain.h"

class Language {
  public: 
    Language();
    Language(std::vector <Chain>);
    ~Language();

    std::set <Chain> language(void);
    void language(std::vector <Chain>);
    void Add_Language(Chain);

  private:
    std::set <Chain> language_;
};

#endif