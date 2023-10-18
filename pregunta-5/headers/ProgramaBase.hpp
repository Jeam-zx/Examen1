#ifndef PROGRAMABASE_HPP
#define PROGRAMABASE_HPP

#include <string>

using namespace std;

class ProgramaBase {
public:
    string lenguajeBase;
    // Constructor de la clase ProgramaBase
    // Parámetros:
    // - lenguajeBase: El lenguaje base en el que está escrito el programa.
    ProgramaBase(const string& lenguajeBase);

    // Destructor virtual predeterminado
    virtual ~ProgramaBase() = default;
};

#endif // PROGRAMABASE_HPP
