#include "../headers/Programa.hpp"

// Constructor de la clase Programa.
// Parámetros:
// - lenguaje: El lenguaje en el que está escrito el programa.
// - nombre: El nombre del programa.
Programa::Programa(const string& lenguaje, const string& nombre) : ProgramaBase(lenguaje),
                                                                   nombre(nombre) {
    // Constructor que inicializa los atributos lenguaje y nombre.
}