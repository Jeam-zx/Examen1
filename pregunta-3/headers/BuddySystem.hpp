#ifndef BUDDY_SYSTEM_HPP
#define BUDDY_SYSTEM_HPP
#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <math.h>

using namespace std;


class BuddySystem{
    private:
        // potencia maxima de 2 que es menor o igual al numero de bloques
        int max_potencia;

        // vector de conjuntos, free_blocks[i] es el conjunto de bloques
        // de tamaño 2^i que estan libres
        vector< set<int> > bloques_libres;

        // vector de booleanos, representacion de la memoria donde cada posición es un un bloque de tamaño 1 en la memoria
        // es true cuando esta libre y false cuando esta reservado.
        vector< bool > memory_is_free;

        // mapa de identificadores, reserved_identificators[id] es un par (i, j) que indica que
        // el bloque de tamaño j que empieza en la posicion i esta reservado
        map< string, pair<int, int> > identificadores;

    public:
        BuddySystem(int num_bloques);
        string getMemoryRepresentation();
        int getMaxPotencia();
        vector< set<int> > getFreeBlocks();
        bool reservar(const string& id, int size);
        bool liberar(const string& id);
        void mostrar();
        
};


#endif //BUDDY_SYSTEM_HPP
