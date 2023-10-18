#ifndef DIAGRAMAT_HPP
#define DIAGRAMAT_HPP

#include "ConexionLenguaje.hpp"
#include "Interprete.hpp"
#include "Traductor.hpp"
#include "Programa.hpp"
#include "ProgramaBase.hpp"
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

class DiagramaT {
public:
    /**
     * Constructor de la clase DiagramaT.
     */
    DiagramaT();

    /**
     * Verifica si un lenguaje puede ejecutarse en el diagrama.
     *
     * - lenguaje: El nombre del lenguaje que se desea verificar.
     * - retorna True si el lenguaje puede ejecutarse, False en caso contrario.
     */
    bool puedeEjecutarse(const string& lenguaje);

    /**
     * Define un intérprete en el diagrama.
     *
     * - lenguajeBase: El lenguaje en el que está escrito el intérprete.
     * - lenguajeDestino: El lenguaje al que se interpreta.
     * - retorna True si el intérprete se define correctamente, False si ya existe o no se puede aplicar.
     */
    bool definirInterprete(const string& lenguajeBase, const string& lenguajeDestino);

    /**
     * Define un traductor en el diagrama.
     *
     * - lenguajeBase: El lenguaje en el que está escrito el traductor.
     * - lenguajeOrigen: El lenguaje desde el que se traduce.
     * - lenguajeDestino: El lenguaje al que se traduce.
     * - retorna True si el traductor se define correctamente, False si ya existe o no se puede aplicar.
     */
    bool definirTraductor(const string& lenguajeBase, const string& lenguajeOrigen, const string& lenguajeDestino);

    /**
     * Define un programa en el diagrama.
     *
     * - nombre: El nombre del programa.
     * - lenguaje: El lenguaje en el que está escrito el programa.
     * - retorna True si el programa se define correctamente, False si ya existe.
     */
    bool definirPrograma(const string& nombre, const string& lenguaje);

    /**
     * Intenta ejecutar un programa en el diagrama.
     *
     * - nombre: El nombre del programa que se desea ejecutar.
     * - retorna True si el programa se ejecuta con éxito, False si no lo hizo.
     */
    bool ejecutarPrograma(const string& nombre);

    /**
     * // Procesa un intérprete, agregando el lenguaje de destino como adyacente al lenguaje base.
     *
     * - interprete: El intérprete que se desea procesar.
     * - retorna True si el intérprete se procesar con éxito, False si no lo hizo.
     */
    bool procesarInterprete(Interprete* interprete);

    /**
     * // Procesa un traductor, agregando el lenguaje de destino como adyacente al lenguaje base.
     *
     * - traductor: El traductor que se desea procesar.
     * - retorna True si el traductor se procesa con éxito, False si no lo hizo.
     */
    bool procesarTraductor(Traductor* traductor);
private:
    unordered_map<string, ConexionLenguaje*> lenguajes;
    unordered_map<string, vector<Interprete*>> interpretes;
    unordered_map<string, vector<Traductor*>> traductores;
    unordered_map<string, Programa*> programas;
    vector<ProgramaBase*> porAplicar;
    unordered_map<string, bool> rutaALocal;

    /**
     * Intenta aplicar intérpretes y traductores que aún no se han aplicado al diagrama.
     */
    void InterpreteATraductor();

    /**
     * Intenta encontrar una ruta hacia el lenguaje local (LOCAL) desde un lenguaje dado.
     *
     * - lenguaOrigen: El lenguaje de origen.
     * - retorna True si se puede alcanzar el lenguaje local, False en caso contrario.
     */
    bool esEjecutableLocal(const string& lenguaOrigen);

    /**
     * Actualiza las rutas de lenguaje que pueden ejecutarse en el diagrama.
     */
    void actualizarRutasDeLenguaje();
};

#endif  // DIAGRAMAT_HPP

