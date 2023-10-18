#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include "../headers/BuddySystem.hpp"

vector<string> split(const string &s) {
    vector<string> result;
    istringstream iss(s);
    string token;

    while (iss >> token) {
        result.push_back(token);
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Debe especificar la cantidad de bloque en memoria\n");
        return -1;
    }
    int num_blocks = atoi(argv[1]);
    if (num_blocks <= 0) {
        printf("Debe ingresar un numero positivo\n");
        return -1;
    }

    BuddySystem my_buddy(num_blocks);
    while (true) {
        printf("> ");
        string linea;
        getline(cin, linea);
        vector<string> tokens = split(linea);
        if (tokens.size() == 1) {
            if (tokens[0] == "MOSTRAR") {
                my_buddy.mostrar();
            }
            else if (tokens[0] == "SALIR") {
                break;
            } else {
                printf("Accion no permitida, las acciones permitidas son:\n");
                printf("\tRESERVAR <cantidad> <nombre>\n");
                printf("\tLIBERAR <nombre>\n");
                printf("\tMOSTRAR\n");
                printf("\tSALIR\n");
            }
        } else if (tokens.size() == 2 && tokens[0] == "LIBERAR") {
            if(tokens[1].length() > 0) {
                my_buddy.liberar(tokens[1]);
            } else {
                printf("Accion no permitida, las acciones permitidas son:\n");
                printf("\tRESERVAR <cantidad> <nombre>\n");
                printf("\tLIBERAR <nombre>\n");
                printf("\tMOSTRAR\n");
                printf("\tSALIR\n");
            }
        } else if (tokens.size() == 3 && tokens[0] == "RESERVAR") {
            if(tokens[1].length() > 0 && tokens[2].length() > 0) {
                int size = atoi(tokens[1].data());
                if (size <= 0) {
                    printf("Debe ingresar un numero positivo\n");
                    continue;
                }
                my_buddy.reservar(tokens[2], size);
            } else {
                printf("Accion no permitida, las acciones permitidas son:\n");
                printf("\tRESERVAR <cantidad> <nombre>\n");
                printf("\tLIBERAR <nombre>\n");
                printf("\tMOSTRAR\n");
                printf("\tSALIR\n");
            }
        } else{
            printf("Accion no permitida, las acciones permitidas son:\n");
            printf("\tRESERVAR <cantidad> <nombre>\n");
            printf("\tLIBERAR <nombre>\n");
            printf("\tMOSTRAR\n");
            printf("\tSALIR\n");
        }
    }
    return 0;
}