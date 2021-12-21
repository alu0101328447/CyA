#include "fileReader.h"

FileReader::FileReader(std::string rutaIn, std::string rutaOut) {
  // Guardo el nombre de el fichero de salida
  setOutFile(rutaOut);

  // Abro el fichero de entrada de datos
  std::ifstream inFile(rutaIn);
  if(!inFile.is_open()) {
    throw "ERROR al abrir el fichero";
  }

  // Inicializo las variables que voy a utilizar para almacenar datos temporalmente
  std::string cadena;
  std::vector <std::string> linea;
  // Leo los datos y los almaceno en las cadenas pertinentes
  while (getline(inFile, cadena)){
    linea.push_back(cadena);
  }

  // Inicializo las variables que voy a utilizar
  std::vector <std::string> vectorCadena;
  std::string auxCadena;
  // Paso las lineas de datos a un formato posible de transformar en alfabetos y cadenas
  for(int i = 0; i < linea.size(); i++) {
    for(int j = 0; j < linea[i].size(); j++ ){
      if(linea[i][j] != ' ') {
        auxCadena.push_back(linea[i][j]);
      }
      else {
        vectorCadena.push_back(auxCadena);
        auxCadena.clear();
        // Lo alamaceno en el alfabeto o en la cadena
      }
    }
    // Si no se han almacenado ninguna cadena antes, entonces la primera es el alfabeto
    if(vectorCadena.size() == 0) {
      vectorCadena.push_back(auxCadena);
    }
    
    alfabeto_.push_back(vectorCadena);
    if(Subcadena()) {
      throw "En el alfabeto un simbolo es sublenguaje de otro";
    }
    setCadena(auxCadena);
    vectorCadena.clear();
  }

  inFile.close();
}

FileReader::~FileReader()
{}

std::string
FileReader::getAlfabeto(int linea, int posicion) {
  if ((linea < alfabeto_.size()) && (linea >= 0)) {
    if ((posicion < alfabeto_[linea].size()) && (posicion >= 0)) {
      return alfabeto_[linea][posicion];
    }
  }
  throw "ERROR al intentar acceder al alfabeto";
}

int 
FileReader::getCadenaSize(int posicion) {
  if ((posicion < cadena_.size()) && (posicion >= 0)) {
    return cadena_[posicion].size();;
  }
  throw "ERROR al intentar acceder al alfabeto";
}

std::string
FileReader::getOutFile(void) {
  return outFile_;
}

void
FileReader::setCadena(std::string cadena) {
  std::string auxCadena;
  std::vector <std::string> auxVectorCadena;
  int size = alfabeto_.size() - 1;

  for(int i = 0; i < cadena.size(); i++) {
    for(int j = 0; j < alfabeto_[size].size(); j++) {
      if(alfabeto_[size][j].size() <= cadena.size() + i) {
        for(int z = 0; z < alfabeto_[size][j].size(); z++) {
          auxCadena.push_back(cadena[z + i]);
        }
      }
      if(auxCadena == alfabeto_[size][j]) {
        auxVectorCadena.push_back(alfabeto_[size][j]);
      }
      auxCadena.clear();
    }
  }
  cadena_.push_back(auxVectorCadena);
}

void
FileReader::setOutFile(std::string outFile) {
  outFile_ = outFile;
}

bool 
FileReader::Subcadena() {
  for(int i = 0; i < alfabeto_.size(); i++) {
    for(int j = 0; j < alfabeto_[i].size() - 1; j++) {
      for(int k = j + 1; k < alfabeto_[i].size(); k++) {
        if(alfabeto_[i][j] == alfabeto_[i][k]) {
          return 1;
        }
      }
    }
  }
  return 0;
}

void
FileReader::printCadena(int linea) {
  for (int i = 0; i < cadena_[linea].size(); i++) {
    std::cout << cadena_[linea][i];
  }
  std::cout << std::endl;
}

void
FileReader::printReverseCadena(int linea) {
  for (int i = cadena_[linea].size() - 1; i >= 0; i--) {
    std::cout << cadena_[linea][i];
  }
  std::cout << std::endl;
}

void
FileReader::printAlfabeto(int linea) {
  std::cout << "{ ";
  for(int i = 0; i < alfabeto_[linea].size(); i++) {
    std::cout << alfabeto_[linea][i];
    if(i != alfabeto_[linea].size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "}" << std::endl;
}

void
FileReader::printPrefijo(int linea) {
  std::cout << VACIA << " ";
  for(int i = 0; i < cadena_[linea].size(); i++) {
    for(int j = 0; j <= i; j++) {
      std::cout << cadena_[linea][j];
    }
    std::cout << " ";
  }
  std::cout << std::endl;
}

void
FileReader::printSufijo(int linea) { 
  std::cout << VACIA << " ";
  for(int i = cadena_[linea].size() - 1; i >= 0; i--) {
    for(int j = cadena_[linea].size() - 1; j >= i; j--) {
      std::cout << cadena_[linea][j];
    }
    std::cout << " ";
  }
  std::cout << std::endl;
}

void
FileReader::printSubcadena(int linea) {
  for(int i = 0; i < cadena_[linea].size(); i++) {
    for(int j = 0; j < cadena_[linea].size() - i; j++) {
      for(int k = j; k <= i + j; k++) {
        std::cout << cadena_[linea][k];
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}
