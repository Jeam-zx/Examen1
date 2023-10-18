#include "../headers/Traductor.hpp"

// Constructor de la clase Traductor
// Parámetros:
// - lenguajeBase: El lenguaje base en el que está escrito el traductor.
// - lenguajeOrigen: El lenguaje de origen al que se traduce.
// - lenguajeDestino: El lenguaje de destino al que se traduce.
Traductor::Traductor(const string& lenguajeBase, const string& lenguajeOrigen, const string& lenguajeDestino)
        : ProgramaBase(lenguajeBase), lenguajeOrigen(lenguajeOrigen), lenguajeDestino(lenguajeDestino) {
    // Constructor que inicializa los atributos lenguajeBase, lenguajeOrigen y lenguajeDestino.
}
