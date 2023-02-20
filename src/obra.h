#ifndef OBRA_H
#define OBRA_H
#include <string>
const char SELECT[]("Selecciona una opción: ");
const char INVALID[]("\nOpción inválida.\n");
const char LIMIT[]("\nLímite excedido.\n");
const char EMPTY[]("\nVacío.\n");
enum OBRA {
    TITULO = 1,
    AUTOR,
    TIPO,
    ANIO,
    DESC
};
class Obra {
    private:
        std::string titulo;
        std::string autor;
        std::string tipo;
        int anio;
        std::string desc;
    public:
        Obra();
        void init();
        std::string get_titulo();
        void set_titulo(std::string valor);
        std::string get_autor();
        void set_autor(std::string valor);
        std::string get_tipo();
        void set_tipo(std::string valor);
        int get_anio();
        void set_anio(int valor);
        std::string get_desc();
        void set_desc(std::string valor);
        void menu();
};
#endif