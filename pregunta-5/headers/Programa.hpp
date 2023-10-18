#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include <string>
#include "ProgramaBase.hpp"

using namespace std;

class Programa : public ProgramaBase {
public:
    string nombre;

    // Constructor de la clase Programa.
    // Parámetros:
    // - lenguaje: El lenguaje en el que está escrito el programa.
    // - nombre: El nombre del programa.
    Programa(const string& lenguaje, const string& nombre);
};

#endif // PROGRAMA_HPP
