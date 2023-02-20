#include "obra.h"
#include "sala.h"
#include <iostream>

Obra::Obra() {
}
void Obra::init() {
    std::cout << "\n\t\tAgregar Obra." << std::endl;
    std::cout << "Titulo: ";
    getline(std::cin, titulo);
    std::cout << "Autor: ";
    getline(std::cin, autor);
    std::cout << "Tipo: ";
    getline(std::cin, tipo);
    std::cout << "Año: ";
    std::cin >> anio;
    std::cin.ignore();
    std::cout << "Descripción: ";
    getline(std::cin, desc);

}
std::string Obra::get_titulo() {
    return titulo;
}
void Obra::set_titulo(std::string valor) {
    titulo = valor;
}
std::string Obra::get_autor() {
    return autor;
}
void Obra::set_autor(std::string valor) {
    autor = valor;
}
std::string Obra::get_tipo() {
    return tipo;
}
void Obra::set_tipo(std::string valor) {
    tipo = valor;
}
int Obra::get_anio() {
    return anio;
}
void Obra::set_anio(int valor) {
    anio = valor;
}
std::string Obra::get_desc() {
    return desc;
}
void Obra::set_desc(std::string valor) {
    desc = valor;
}
void Obra::menu() {
    std::cout << "\nMenú de Obra " << get_titulo() << std::endl
              << TITULO << ") Editar título." << std::endl
              << AUTOR << ") Editar Autor." << std::endl
              << TIPO << ") Editar Tipo." << std::endl
              << ANIO << ") Editar Año." << std::endl
              << DESC << ") Editar Descripción." << std::endl
              << SELECT;
    int opc;
    std::cin >> opc;
    std::cin.ignore();
    if (opc < TITULO || opc > DESC) {
        std::cout << INVALID;
        return;
    }
    std::string svalor;
    int ivalor;
    std::cout << "Inserte el nuevo valor: ";
    if (opc == ANIO) {
        std::cin >> ivalor;
        std::cin.ignore();
    } else {
        getline(std::cin, svalor);
    }
    switch (opc){
        case TITULO:
            set_titulo(svalor);
            break;
        case AUTOR:
            set_autor(svalor);
            break;
        case TIPO:
            set_tipo(svalor);
            break;
        case ANIO:
            set_anio(ivalor);
            break;
        case DESC:
            set_desc(svalor);
            break;
    }

}