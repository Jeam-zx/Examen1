#ifndef CONEXION_LENGUAJE_HPP
#define CONEXION_LENGUAJE_HPP

#include <string>
#include <vector>

using namespace std;

// Clase que representa los lenguajes conectados en el diagrama de traducción.
class ConexionLenguaje {
public:
    string lenguaje; // Nombre del lenguaje representado por este objeto.
    vector<ConexionLenguaje*> lenguajesAdyacentes;  // Vector de lenguajes adyacentes a este lenguaje.

    // Constructor de la clase ConexionLenguaje.
    // Parámetros:
    // - lenguaje: El nombre del lenguaje que representa este objeto.
    ConexionLenguaje(const string& lenguaje);

    // Método para agregar un lenguaje adyacente a la lista de lenguajes adyacentes.
    // Parámetros:
    // - lenguajeAdyacente: Puntero al objeto de ConexionLenguaje que representa un lenguaje adyacente.
    void agregarAdyacente(ConexionLenguaje* lenguajeAdyacente);
};

#endif //CONEXION_LENGUAJE_HPP
