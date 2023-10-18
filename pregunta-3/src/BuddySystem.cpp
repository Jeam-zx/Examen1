#include "../headers/BuddySystem.hpp"

using namespace std;

/*
 * Constructor:
 *    Inicializa la estructura del buddy system para manejar la memoria
 * Parametros:
 *    num_bloques: int que representa el tamaño total de la memoria a manejar
 *
 */
BuddySystem::BuddySystem(int num_bloques) {
    if (num_bloques <= 0) return;

    max_potencia = ceil(log2(num_bloques));
    bloques_libres.resize(max_potencia+1);
    memory_is_free.resize(num_bloques, true);

    // Guardamos el numero de bloques libres de cada tamaño correspondiente
    // a su descomposición en base 2. Por ejemplo, un bloque de tamaño 15 = 1111(base 2) puede ser guardado
    // en 1 bloque de tamaño 2^3 = 8, uno de tamaño 2^2 = 4, uno de tamaño 2^1 = 2 y uno de tamaño 2^0 = 1.
    // Por lo tanto, basta irnos a la representacion en base 2 del numero y ver que digitos son 1.
    for (int bit = max_potencia, ind = 0; bit >= 0; --bit) {
        // Se realiza la comprobacion del bit encendido mediante el operador bitwise &. Si consideramos
        // la representación binaria de ambos operandos de &, se retorna el numero correspondiente a poner
        // 1 en las posiciones donde ambos numeros son 1 y 0 en otro caso. Por ejemplo 111 & 100 = 100 (binario) ya que
        // solo en la posición 3 de derecha a izquierda ambos numeros tienen un uno. El operado << solo representa
        // un desplazamiento de digitos en binarios, así que 1 <<bit = 2^bit. Por lo tanto, no da la posición de
        // los digitos que son 1 en num_bloque.
        if ((num_bloques & (1 << bit)) != 0) {
            // Se guarda el bloque en los bloques de tamaño 2^bit, dado que sabemos de que tamaño es el bloque al estar
            // almacenado en bloques_libres[bit], solo guardamos el indice en el que se encuentra en memoria
            bloques_libres[bit].insert(ind);
            // Dado que el anterior bloque ocupa espacio a partir de la posición ind, el siguiente bloque deberá estar
            // en la posición ind + 2^bit (ya que el bloque pasado ocupaba 2^bit de espacio).
            ind += (1 << bit);
        }
    }
};

/*
 * getFreeBlocks:
 *    Funcion que retorna los bloques libres
 */
vector< set<int> > BuddySystem::getFreeBlocks() {
    return bloques_libres;
}

/*
 * liberar:
 *    Funcion que libera el bloque de memoria asociado al identificador id de existir
 * Parametros:
 *    id: string que representa el identificador del bloque de memoria
 */
bool BuddySystem::liberar(const string& id) {
    // Verificar si el identificador existe en el conjunto de identificadores
    auto it = identificadores.find(id);
    if (it == identificadores.end()) {
        // Si no se encuentra el identificador, no se puede liberar
        printf("El identificador dado no existe\n");
        return false;
    }

    // Obtener la posición y el tamaño del bloque a partir del iterador
    int index, potencia;
    tie(index, potencia) = it->second;

    // Liberar el bloque marcando las posiciones correspondientes en memory_is_free y borrarlo de la lista de identificadores
    identificadores.erase(id);
    for (int i = index; i < index + (1 << potencia); ++i) {
        memory_is_free[i] = true;
    }
    // Agregar la posición liberada al conjunto de bloques libres del tamaño 2^potencia
    bloques_libres[potencia].insert(index);

    // Fusionar bloques adyacentes del mismo tamaño mientras sea posible
    while (potencia <= max_potencia) {
        // Se verifica si es posible fusionar con un bloque a la izquierda o a la derecha mediante count, si hay
        // un bloque en la posición index - (1 << potencia) o index + (1 << potencia) respectivamente de tamaño (1 << potencia),
        // count retorna 1 y 0 en otro caso. Observese que se tiene que revisar en el indice index +/- (1 << potencia)
        // ya que el bloque ocupa (1 << potencia) espacio en memoria. Ya que la suma de dos bloques de un mismo tamaño
        // cuya potencia es 2 da la siguiente potencia de dos (por ejemplo 2^2 + 2^2 = 2^3), se puede realizar la fusión
        // de bloques de tamaño 2^potencia con bloques de tamaño 2^(potencia + 1) (siempre y cuando esten adyacentes).

        // Verificar si es posible fusionar con un bloque a la izquierda
        bool left_merge = (bloques_libres[potencia].count(index - (1 << potencia)) > 0);
        // Verificar si es posible fusionar con un bloque a la derecha
        bool right_merge = (bloques_libres[potencia].count(index + (1 << potencia)) > 0);

        // Si es posible fusionar con un bloque a la izquierda o a la derecha, realizar la fusión
        if (left_merge || right_merge) {
            // Realizar la fusión con el bloque a la izquierda
            // Elimina los bloques de tamaño 2^potencia de los bloques libres para crear un bloque libre de
            // tamaño 2^(potencia + 1)
            if (left_merge) {
                bloques_libres[potencia].erase(index);
                bloques_libres[potencia].erase(index - (1 << potencia));
                bloques_libres[potencia + 1].insert(index - (1 << potencia));
                index = index - (1 << potencia);
            } else if (right_merge) { // Realizar la fusión con el bloque a la derecha
                bloques_libres[potencia].erase(index);
                bloques_libres[potencia].erase(index + (1 << potencia));
                bloques_libres[potencia + 1].insert(index);
            }
            // Incrementar el tamaño del bloque fusionado, ya que ahora es de tamaño 2^(potencia + 1), si encontramos
            // otro bloque de tamaño 2^(potencia + 1) adyacente al actual podemos fusionarlo con el bloque actual para
            // crear un bloque de tamaño 2^(potencia + 2)
            ++potencia;

        } else {
            break; // No es posible fusionar más bloques
        }
    }

    return true; // La liberación del bloque fue exitosa
}

/*
 *  reservar:
 *    Funcion que asigna un bloque de memoria de tamaño size (al menos) a un identificador id si es posible
 *  Parametros:
 *    id: string que representa el identificador del bloque de memoria
 *    size: int que representa el tamaño del bloque de memoria
 */
bool BuddySystem::reservar(const string& id, int size) {
    // error: ya existe un identificador con ese nombre
    if (identificadores.find(id) != identificadores.end()) {
        printf("%s ya tiene memoria reservada\n", id.data());
        return false;
    }
    // error2: el tamaño a asignar es negativo
    if (size <= 0) {
        printf("No se puede asignar un numero de bloques negativos\n");
        return false;
    }

    // Se busca el bloque de memoria más pequeño que pueda contener el tamaño a asignar a id
    int potencia = ceil(log2(size));
    // Se verifica que exista un bloque de memoria de tamaño 2^potencia, si no se debe buscar en un bloque de tamaño
    // mayor. Si no existe un bloque de tamaño 2^potencia, se busca en un bloque de tamaño 2^(potencia + 1), y así
    // sucesivamente hasta encontrar un bloque de tamaño 2^max_potencia, en cuyo caso no hay suficiente memoria para
    // asignar el tamaño solicitado.
    while (potencia <= max_potencia && bloques_libres[potencia].empty()) {
        ++potencia;
    };
    // error3: no hay un bloque del tamaño necesario para asignar
    if (potencia > max_potencia) {
        printf("No hay un bloque del tamano necesario para asignar\n");
        return false;
    }

    // Se obtiene el indice del bloque de memoria de tamaño 2^potencia que se va a asignar a id
    int index = *bloques_libres[potencia].begin();
    // Se elimina el bloque de memoria de tamaño 2^potencia de los bloques libres
    bloques_libres[potencia].erase(index);

    // Se divide el bloque de memoria de tamaño 2^potencia en bloques de tamaño 2^(potencia - 1), 2^(potencia - 2), ...,
    // hasta que el tamaño del bloque sea la potencia más grande de 2 que sea menor o igual al tamaño solicitado.
    while ((1 << (potencia - 1)) >= size) {
        --potencia;
        bloques_libres[potencia].insert(index + (1 << potencia));
    }

    // Se guarda el identificador id junto con el indice y la potencia del tamaño del bloque de memoria asignado
    identificadores[id] = {index, potencia};
    // Se marca cada bloque de tamaño 1 de memoria que conforman al bloque asignado como reservado en memory_is_free
    for (int i = index; i < index + (1 << potencia); ++i) {
        memory_is_free[i] = false;
    }
    return true;
}

/*
 * getMaxPotencia:
 *   Funcion que retorna la potencia maxima de 2 que es menor o igual al numero de bloques
 */
int BuddySystem::getMaxPotencia() {
    return max_potencia;
}

/*
 * getMemoryRepresentation:
 *   Funcion que retorna la representacion de la memoria en un string
 */
string BuddySystem::getMemoryRepresentation() {
    string representation = "";
    for (bool f : memory_is_free) {
        if (f) representation += "| F ";
        else representation += "| R ";
    }
    representation += "|";
    return representation;
}

/*
 * mostrar:
 *   Funcion que imprime la representacion de la memoria y los bloques reservados
 */
void BuddySystem::mostrar() {
    string representation = getMemoryRepresentation();
    printf("REPRESENTACION DE LA MEMORIA:\n");
    printf("%s\n\n", representation.data());

    printf("MEMORIA RESERVADA:\n");
    for (auto info : identificadores) {
        printf("\tNombre: %s \n", info.first.data());
        printf("\t\tTamaño : %d\n", (1 << info.second.second));
        printf("\t\tPosicion en memoria (inicio) : %d\n", info.second.first);
    }
    printf("\n");

    printf("BLOQUES LIBRES:\n");
    for (int i = 0; i <= max_potencia; ++i) {
        for (int index : bloques_libres[i]) {
            printf("\tEl bloque empieza en %d, es de tamaño %d\n", index, (1 << i));
        }
    }
    printf("\n");
}
