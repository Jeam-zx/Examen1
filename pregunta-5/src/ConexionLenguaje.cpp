#include "../headers/ConexionLenguaje.hpp"

// Constructor de la clase ConexionLenguaje
// Parámetros:
// - lenguaje: El nombre del lenguaje para el que se crea la instancia de ConexionLenguaje.
ConexionLenguaje::ConexionLenguaje(const string& lenguaje) : lenguaje(lenguaje) {
    // El constructor inicializa la clase con el nombre del lenguaje proporcionado.
}

// Método para agregar un lenguaje adyacente
// Parámetros:
// - lenguajeAdyacente: Puntero al objeto de ConexionLenguaje que representa un lenguaje adyacente.
void ConexionLenguaje::agregarAdyacente(ConexionLenguaje* lenguajeAdyacente) {
    lenguajesAdyacentes.push_back(lenguajeAdyacente);
    // Este método agrega un lenguaje adyacente al vector de lenguajes adyacentes.
}
