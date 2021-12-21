#include <iostream>
#include <vector>
#include <string>

void helpMessage(void);
bool Perfect(int);

int main(int argc, char **argv) {
    int numero;

    if( argc != 2 ) {
        helpMessage();
        return 0;
    }

    // Transformo el string a entero
    numero = std::strtol(argv[1], nullptr, 10);

    std::cout << "El numero " << (Perfect(numero) ? "es" : "no es")
    << " un numero perfecto" << std::endl;

    return 0;
}

void
helpMessage(void) {
    std::cout << "El modo de uso de este programa es el siguiente"
    << std::endl << "perfecto n" << std::endl
    << "Teniendo en cuenta que n es igual a un numero entero" << std::endl;
}

bool 
Perfect(int num) {
    int resultado = 0;

    // Calculo los divisore de num y los almaceno en divisores
    for(int i = 1; i <= num/2; i++) {
        if( num % i == 0 ) {
            resultado += i;
        }
    }
    
    return (resultado == num);
}