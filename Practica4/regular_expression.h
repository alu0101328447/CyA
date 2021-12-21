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
// Archivo regular_expression.h: clase Regular_Expression
//
// Esta clase se encarga de la gestión de las expresiones 
// regulares para permitir su búsqueda y almacenamiento
//
// Historial de revisiones
// 25/10/2021 - Creación (primera versión) del código
// 27/10/2021 - Finalización del código

#ifndef REGULAR_EXPRESSION
#define REGULAR_EXPRESSION

#include <iostream>
#include <string>
#include <vector>
#include <regex>

const int number_expression = 7;

const std::string Name = "(\\w+)\\s?=\\s*.*";
const std::string Value = "\\s*[A −Za −z0 −9]*\\s?=\\s*(.*)";
const std::string Int = "^\\s*int (.*);";
const std::string Double = "^\\s*double (.*);";
const std::string For = "^\\s*(for) \\(.*\\) \\{";
const std::string While = "^\\s*(while) \\(.*\\) \\{";
const std::string Loop = "^\\s*(for|while) \\(.*\\) \\{";
const std::string LineComment = "^(//\\s*.*)";
const std::string MultiCommentIni = "(/\\*.*)";
const std::string MultiCommentLast = "(.*\\*/)";
const std::string Main = "^\\s*[a-zA-Z]+ (main)\\s?\\(.*\\) \\{?";


class Regular_Expression {
  public:
    Regular_Expression();
    Regular_Expression(std::string, std::string);
    ~Regular_Expression();

    std::string get_expression(void);
    std::regex get_regular(void);
    std::vector <std::string> get_result(void);
    std::string get_tipe(void);
    std::vector <int> get_line(void);
    std::string get_name(int);
    std::string get_value(int);

    void set_expression(std::string);
    void set_regular(std::string);
    void set_result(std::vector <std::string>);
    void set_tipe(std::string);
    void set_line(int);
    void add_name(std::string);
    void add_value(std::string);

    void AddResult(std::string);

    bool Search(std::string);



  private:
    std::vector <std::string> name_;
    std::vector <std::string> value_;
    std::string expression_;
    std::regex regular_expression_; 
    std::vector <std::string> result_;
    std::string tipe_;
    std::vector <int> line_;
};

#endif