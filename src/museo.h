#ifndef MUSEO_H
#define MUSEO_H
#include "sala.h"
const int MAX_SALAS(10);
enum MUSEO {
    EXIT,
    ADD,
    EDIT,
    SHOW,
    SEARCH
};
class Museo {
    private:
        std::string nombre_museo;
        Sala salas[MAX_SALAS];
        int cont_salas;
        void editar_sala();
        void mostrar_salas();
        void buscar_sala();
    public:
        Museo();
        void menu();
};
#endif