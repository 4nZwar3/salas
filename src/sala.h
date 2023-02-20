#ifndef SALA_H
#define SALA_H
#include "obra.h"
const int MAX_OBRAS(10);
enum SALA {
    REGRESAR,
    AGREGAR,
    CONSULTAR,
    EDITAR,
};
class Sala {
    private:
        std::string nombre;
        Obra obras[MAX_OBRAS];
        int cont_obras;
    public:
        Sala();
        void init();
        std::string get_name();
        void set_name(std::string valor);
        void consult_obra(Obra obra);
        void consult_obras();
        void edit_obra();
        void show();
        void menu();
};
#endif