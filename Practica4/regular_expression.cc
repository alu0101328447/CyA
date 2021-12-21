// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 4: Expresiones regulares 
// Autor: José Pablo Ruiz Galván
// Correo: alu0101328447@ull.edu.es
// Fecha: 25/10/2021
//
// Archivo regular_expression.cc: clase Regular_Expression
//
// Esta clase se encarga de la gestión de las expresiones 
// regulares para permitir su búsqueda y almacenamiento
//
// Historial de revisiones
// 25/10/2021 - Creación (primera versión) del código
// 27/10/2021 - Finalización del código

#include "regular_expression.h"

Regular_Expression::Regular_Expression()
{}

Regular_Expression::Regular_Expression(std::string expression, std::string tipe) {
  set_expression(expression);
  set_tipe(tipe);
}

Regular_Expression::~Regular_Expression()
{}

std::string
Regular_Expression::get_expression(void) {
  return expression_;
}

std::regex
Regular_Expression::get_regular(void) {
  return regular_expression_;
}

std::vector <std::string>
Regular_Expression::get_result(void) {
  return result_;
}

std::string
Regular_Expression::get_tipe(void) {
  return tipe_;
}

std::vector <int> 
Regular_Expression::get_line(void) {
  return line_;
}

std::string
Regular_Expression::get_name(int pos) {
  return name_[pos];
}

std::string
Regular_Expression::get_value(int pos) {
  return value_[pos];
}

void 
Regular_Expression::set_expression(std::string expression) {
  expression_ = expression;
  set_regular(expression);
}

void
Regular_Expression::set_regular(std::string regular_expression) {
  regular_expression_.assign(regular_expression);
}

void
Regular_Expression::set_result(std::vector <std::string> result) {
  result_ = result;
}

void
Regular_Expression::set_tipe(std::string tipe) {
  tipe_ = tipe;
}

void
Regular_Expression::set_line(int line) {
  line_.push_back(line);
}

void
Regular_Expression::add_name(std::string name) {
  name_.push_back(name);
}

void
Regular_Expression::add_value(std::string value) {
  value_.push_back(value);
}

void
Regular_Expression::AddResult(std::string result) {
  result_.push_back(result);
}

bool
Regular_Expression::Search(std::string line) {
  std::__cxx11::smatch matches;
  std::__cxx11::smatch aux_matches;
  std::regex aux_name(Name);
  std::regex aux_value(Value);

  std::string match;

  regex_search(line, matches, regular_expression_);
  if (matches.size() > 1) {
    match = matches[1];
    if ( match != "" ) {
      if ((tipe_ == "INT") || (tipe_ == "DOUBLE")) {
        regex_search(match, aux_matches, aux_name);
        add_name(aux_matches[1]);
        regex_search(match, aux_matches, aux_value);
        add_value(aux_matches[1]);
      }
      AddResult(match);
      return true;
    }
  } else if (matches.size() == 1) {
    match = matches[0];
    if ((tipe_ == "INT") || (tipe_ == "DOUBLE")) {
      regex_search(match, aux_matches, aux_name);
      add_name(aux_matches[1]);
      regex_search(match, aux_matches, aux_value);
      add_value(aux_matches[1]);
    }
    AddResult(match);
    return true;
  }
  return false;
}


