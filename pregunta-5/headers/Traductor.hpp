#ifndef TRADUCTOR_HPP
#define TRADUCTOR_HPP

#include <string>
#include "ProgramaBase.hpp"

using namespace std;

class Traductor : public ProgramaBase {
public:
    // Atributos de la clase Traductor
    string lenguajeOrigen;    // Lenguaje de origen al que se traduce
    string lenguajeDestino;   // Lenguaje de destino al que se traduce

    // Constructor de la clase Traductor
    // Parámetros:
    // - lenguajeBase: El lenguaje base en el que está escrito el traductor.
    // - lenguajeOrigen: El lenguaje de origen al que se traduce.
    // - lenguajeDestino: El lenguaje de destino al que se traduce.
    Traductor(const string& lenguajeBase, const string& lenguajeOrigen, const string& lenguajeDestino);
};

#endif  // TRADUCTOR_HPP
