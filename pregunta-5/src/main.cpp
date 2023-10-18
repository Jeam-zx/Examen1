#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include "../headers/DiagramaT.hpp"

using namespace std;

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
    DiagramaT diagrama;
    const regex expresion("^[a-zA-Z0-9]+$");
    while (true){
        printf("> ");
        string linea;
        getline(cin, linea);
        vector<string> tokens = split(linea);

        if(tokens.size() > 2) {
            if (tokens[0] == "DEFINIR") {
                if (tokens[1] == "PROGRAMA") {
                    if (tokens.size() == 4) {
                        if (regex_match(tokens[2], expresion) && regex_match(tokens[3], expresion)) {
                            diagrama.definirPrograma(tokens[2], tokens[3]);
                        } else {
                            printf("<lenguaje> y <nombre> deben se cadenas alfanumericas");
                        }
                    } else {
                        printf("USO: DEFINIR PROGRAMA <nombre> <lenguaje>\n");
                        printf("<nombre> o <lenguaje> no pueden ser vacios");
                    }

                } else if (tokens[1] == "INTERPRETE") {
                    if (tokens.size() == 4) {
                        if (regex_match(tokens[2], expresion) && regex_match(tokens[3], expresion)) {
                            diagrama.definirInterprete(tokens[2], tokens[3]);
                        } else {
                            printf("<lenguaje> y <lenguaje_base> deben se cadenas alfanumericas");
                        }
                    } else {
                        printf("USO: DEFINIR INTERPRETE <lenguaje_base> <lenguaje>\n");
                        printf("<lenguaje_base> o <lenguaje> no pueden ser vacios");
                    }
                } else if (tokens[1] == "TRADUCTOR") {
                    if (tokens.size() == 5) {
                        if (regex_match(tokens[2], expresion) && regex_match(tokens[3], expresion) &&
                            regex_match(tokens[4], expresion)) {
                            diagrama.definirTraductor(tokens[2], tokens[3], tokens[4]);
                        } else {
                            printf("<lenguaje_base>, <lenguaje_origen> y <lenguaje_destino> deben se cadenas alfanumericas");
                        }
                    } else {
                        printf("USO: DEFINIR TRADUCTOR <lenguaje_base> <lenguaje_origen> <lenguaje_destino>\n");
                        printf("<lenguaje_base>, <lenguaje_origen> o <lenguaje_destino> no pueden ser vacios");
                    }
                } else {
                    printf("Tipo no permitido, los tipos permitidos son:\n");
                    printf("\tPROGRAMA\n");
                    printf("\tINTERPRETE\n");
                    printf("\tTRADUCTOR\n");
                }
            }
        } else if (tokens.size() > 0) {
            if (tokens[0] == "EJECUTABLE") {
                if (tokens.size() == 2) {
                    if (regex_match(tokens[1], expresion)) {
                        diagrama.ejecutarPrograma(tokens[1]);
                    } else {
                        printf("<nombre> debe ser una cadena alfanumerica");
                    }
                } else {
                    printf("USO: EJECUTABLE <nombre>\n");
                    printf("<nombre> no puede ser vacio");
                }
            } else if (tokens[0] == "SALIR") {
                break;
            } else {
                printf("Accion no permitida\n");
                printf("USO: \n");
                printf("\tDEFINIR <tipo> [<argumentos>]\n");
                printf("\tEJECUTABLE <nombre>\n");
                printf("\tSALIR\n");
            }
        } else {
            printf("Accion no permitida\n");
            printf("USO: \n");
            printf("\tDEFINIR <tipo> [<argumentos>]\n");
            printf("\tEJECUTABLE <nombre>\n");
            printf("\tSALIR\n");
        }
    }
    return 0;
}