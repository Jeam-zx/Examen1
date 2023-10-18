#ifndef INTERPRETE_HPP
#define INTERPRETE_HPP

#include <string>
#include "ProgramaBase.hpp"

using namespace std;

// Declaración de la clase Interprete
class Interprete : public ProgramaBase {
public:
    string lenguaje;

    // Constructor de la clase Interprete
    // Parámetros:
    // - lenguajeBase: El lenguaje base en el que está escrito el intérprete.
    // - lenguaje: El nombre del lenguaje que se interpreta.
    Interprete(const string& lenguajeBase, const string& lenguaje);
};

#endif  // INTERPRETE_HPP


