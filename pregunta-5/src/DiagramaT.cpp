#include "../headers/DiagramaT.hpp"
#include <iostream>

// Constructor de la clase DiagramaT
DiagramaT::DiagramaT() {
    rutaALocal["LOCAL"] = true;
    lenguajes["LOCAL"] = new ConexionLenguaje("LOCAL");
}

// Verifica si un programa escrito en un lenguaje dado puede ejecutarse.
bool DiagramaT::puedeEjecutarse(const string& lenguaje) {
    return lenguajes.find(lenguaje) != lenguajes.end() && rutaALocal[lenguaje];
}

// Procesa un intérprete, agregando el lenguaje de destino como adyacente al lenguaje base.
bool DiagramaT::procesarInterprete(Interprete *interprete) {
    if(!puedeEjecutarse(interprete->lenguajeBase)) {
        return false;
    }

    lenguajes[interprete->lenguaje]->agregarAdyacente(lenguajes[interprete->lenguajeBase]);
    return true;
}

// Procesa un traductor, agregando el lenguaje de destino como adyacente al lenguaje base.
bool DiagramaT::procesarTraductor(Traductor *traductor) {
    if(!puedeEjecutarse(traductor->lenguajeBase)) {
        return false;
    }

    lenguajes[traductor->lenguajeOrigen]->agregarAdyacente(lenguajes[traductor->lenguajeDestino]);
    return true;
}

// Define un nuevo intérprete para un lenguaje base y lenguaje de destino.
bool DiagramaT::definirInterprete(const string& lenguajeBase, const string& lenguajeDestino) {
    // Verifica si el lenguaje base existe
    if (lenguajes.find(lenguajeBase) == lenguajes.end()) {
        lenguajes[lenguajeBase] = new ConexionLenguaje(lenguajeBase);
        rutaALocal[lenguajeBase] = false;
    }

    // Verifica si el lenguaje destino existe
    if (lenguajes.find(lenguajeDestino) == lenguajes.end()) {
        lenguajes[lenguajeDestino] = new ConexionLenguaje(lenguajeDestino);
        rutaALocal[lenguajeDestino] = false;
    }

    // Verifica si el intérprete ya existe
    for (Interprete* interprete : interpretes[lenguajeBase]) {
        if (interprete->lenguaje == lenguajeDestino) {
            printf("El intérprete de '%s' escrito en '%s' ya existe\n", lenguajeDestino.c_str(), lenguajeBase.c_str());
            return false;
        }
    }

    // Crea el nuevo intérprete y lo agrega a la lista de intérpretes por aplicar
    Interprete* nuevoInterprete = new Interprete(lenguajeBase, lenguajeDestino);
    porAplicar.push_back(nuevoInterprete);
    interpretes[lenguajeBase].push_back(nuevoInterprete);

    printf("Se definió un interprete para '%s', escrito en '%s'\n", lenguajeDestino.c_str(), lenguajeBase.c_str());

    // Intenta aplicar los intérpretes y traductores pendientes
    InterpreteATraductor();

    return true;
}

// Define un nuevo traductor para un lenguaje base, lenguaje de origen y lenguaje de destino.
bool DiagramaT::definirTraductor(const string& lenguajeBase, const string& lenguajeOrigen, const string& lenguajeDestino) {
    // Verifica si el lenguaje base existe
    if (lenguajes.find(lenguajeBase) == lenguajes.end()) {
        lenguajes[lenguajeBase] = new ConexionLenguaje(lenguajeBase);
        rutaALocal[lenguajeBase] = false;
    }

    // Verifica si el lenguaje de origen existe
    if (lenguajes.find(lenguajeOrigen) == lenguajes.end()) {
        lenguajes[lenguajeOrigen] = new ConexionLenguaje(lenguajeOrigen);
        rutaALocal[lenguajeOrigen] = false;
    }

    // Verifica si el lenguaje de destino existe
    if (lenguajes.find(lenguajeDestino) == lenguajes.end()) {
        lenguajes[lenguajeDestino] = new ConexionLenguaje(lenguajeDestino);
        rutaALocal[lenguajeDestino] = false;
    }

    // Verifica si el traductor ya existe
    for (Traductor* traductor : traductores[lenguajeBase]) {
        if (traductor->lenguajeOrigen == lenguajeOrigen && traductor->lenguajeDestino == lenguajeDestino) {
            printf("El traductor de '%s' a '%s' escrito en '%s' ya existe\n", lenguajeOrigen.c_str(), lenguajeDestino.c_str(), lenguajeBase.c_str());
            return false;
        }
    }

    // Crea el nuevo traductor y lo agrega a la lista de traductores por aplicar
    Traductor* nuevoTraductor = new Traductor(lenguajeBase, lenguajeOrigen, lenguajeDestino);
    porAplicar.push_back(nuevoTraductor);
    traductores[lenguajeBase].push_back(nuevoTraductor);

    printf("Se definió un traductor de '%s' hacia '%s', escrito en '%s'\n", lenguajeOrigen.c_str(), lenguajeDestino.c_str(), lenguajeBase.c_str());

    // Intenta aplicar los intérpretes y traductores pendientes
    InterpreteATraductor();

    return true;
}

// Define un nuevo programa escrito en un lenguaje dado.
bool DiagramaT::definirPrograma(const string& nombre, const string& lenguaje) {
    // Verifica si el lenguaje existe
    if (lenguajes.find(lenguaje) == lenguajes.end()) {
        lenguajes[lenguaje] = new ConexionLenguaje(lenguaje);
        rutaALocal[lenguaje] = false;
    }

    // Verifica si el programa ya existe
    if (programas.find(nombre) != programas.end()) {
        printf("El programa '%s' ya existe\n", nombre.c_str());
        return false;
    }

    // Crea el nuevo programa y lo agrega a la lista de programas
    Programa* nuevoPrograma = new Programa(lenguaje, nombre);
    programas[nombre] = nuevoPrograma;
    printf("Se definió el programa '%s', ejecutable en '%s'\n", nombre.c_str(), lenguaje.c_str());
    return true;
}

// Mueve los intérpretes y traductores pendientes a las listas correspondientes.
void DiagramaT::InterpreteATraductor() {

    // Mientras se pueda aplicar un intérprete o traductor, se intenta aplicar
    bool procesado = false;
    bool cambio = true;
    int i = 0;

    // Se itera hasta que no se pueda aplicar ningún intérprete o traductor
    while (cambio) {
        // Se itera sobre los intérpretes y traductores por aplicar
        i = 0;
        cambio = false;
        while (i < porAplicar.size()) {
            // Se intenta aplicar el intérprete o traductor
            ProgramaBase* programa = porAplicar[i];

            // Se verifica si es intérprete o traductor
            if (Interprete* interprete = dynamic_cast<Interprete*>(programa)) {
                // Se intenta procesar el intérprete
                procesado = procesarInterprete(interprete);
            } else if (Traductor* traductor = dynamic_cast<Traductor*>(programa)) {
                // Se intenta procesar el traductor
                procesado = procesarTraductor(traductor);
            }

            // Si se pudo procesar, se remueve de la lista de intérpretes y traductores por aplicar
            if (procesado) {
                porAplicar.erase(porAplicar.begin() + i);
                actualizarRutasDeLenguaje();
                cambio = true;
                i--;
            }

            i++;
        }
    }
}

// Intenta determinar si se puede ejecutar el lenguaje local a partir de un lenguaje de origen.
bool DiagramaT::esEjecutableLocal(const string& lenguajeOrigen) {
    // Se utiliza una búsqueda en profundidad (DFS) para determinar si se puede alcanzar el lenguaje local
    unordered_set<string> visitados;
    // Se utiliza una pila para la búsqueda en profundidad
    vector<ConexionLenguaje*> siguiente = {lenguajes[lenguajeOrigen]};
    // Se marca el lenguaje de origen como visitado
    visitados.insert(lenguajeOrigen);

    // Se itera hasta que se hayan visitado todos los lenguajes adyacentes
    while (!siguiente.empty()) {
        // Se obtiene el lenguaje actual
        ConexionLenguaje* actual = siguiente.back();
        // Se remueve el lenguaje actual de la pila
        siguiente.pop_back();

        // Si el lenguaje actual es el lenguaje local, se puede alcanzar el lenguaje local
        if (actual->lenguaje == "LOCAL") {
            return true;
        }

        // Se itera sobre los lenguajes adyacentes al lenguaje actual
        for (ConexionLenguaje* adyacente : actual->lenguajesAdyacentes) {
            if (visitados.find(adyacente->lenguaje) == visitados.end()) {
                visitados.insert(adyacente->lenguaje);
                siguiente.push_back(adyacente);
            }
        }
    }

    return false;
}

// Actualiza las rutas de lenguaje marcando si se puede alcanzar "LOCAL" desde cada lenguaje.
void DiagramaT::actualizarRutasDeLenguaje() {
    // Se itera sobre todos los lenguajes
    for (const auto& lenguaje : lenguajes) {
        // Si ya se puede alcanzar el lenguaje local, no se hace nada
        if (rutaALocal[lenguaje.first]) {
            // printf("Ya se puede alcanzar LOCAL desde %s\n", lenguaje.first.c_str());
            continue;
        }

        // Se intenta alcanzar el lenguaje local desde el lenguaje actual
        if (esEjecutableLocal(lenguaje.first)) {
            rutaALocal[lenguaje.first] = true;
        }
    }
}

// Ejecuta un programa dado, verificando si se puede ejecutar con las rutas disponibles.
bool DiagramaT::ejecutarPrograma(const string& nombre) {
    // Verifica si el programa existe
    if (programas.find(nombre) == programas.end()) {
        printf("El programa '%s' no existe.\n", nombre.c_str());
        return false;
    }

    // Verifica si el programa se puede ejecutar
    Programa* programa = programas[nombre];
    if (rutaALocal[programa->lenguajeBase]) {
        printf("Si, es posible ejecutar el programa '%s'\n", nombre.c_str());
        return true;
    }

    // No se puede ejecutar el programa
    printf("No es posible ejecutar el programa '%s'\n", nombre.c_str());
    return false;
}
