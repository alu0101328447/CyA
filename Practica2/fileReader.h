#ifndef FILEREADER
#define FILEREADER

#include <vector>
#include <fstream>
#include <cstring>
#include "simbolos.h"



class FileReader {
  public:
    FileReader(std::string, std::string);
    ~FileReader();

    //std::string getCadena(int);
    std::string getAlfabeto(int, int);
    int getCadenaSize(int);
    std::string getOutFile(void);

    void setCadena(std::string);

    bool Subcadena(void);

    void printCadena(int);
    void printReverseCadena(int);
    void printAlfabeto(int);
    void printPrefijo(int);
    void printSufijo(int);
    void printSubcadena(int);

  private:
    std::string outFile_;
    //std::vector Simbolo> cadena_;
    //std::vector <Simbolo> alfabeto_
    std::vector<std::vector <std::string>> cadena_;
    std::vector<std::vector <std::string>> alfabeto_;

    void setOutFile(std::string);
};

#endif