#include "../headers/Interprete.hpp"

// Constructor de la clase Interprete
// Parámetros:
// - lenguajeBase: El lenguaje base en el que está escrito el intérprete.
// - lenguaje: El nombre del lenguaje que se interpreta.
Interprete::Interprete(const string& lenguajeBase, const string& lenguaje)
        : ProgramaBase(lenguajeBase), lenguaje(lenguaje) {
    // El constructor inicializa el atributo heredado lenguajeBase con el valor pasado en lenguajeBase
    // e inicializa el atributo lenguaje con el valor pasado en lenguaje.
}
