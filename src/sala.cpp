#include "sala.h"
#include "obra.h"
#include <iostream>
#include <cctype>

Sala::Sala() {
}
void Sala::init() {
    std::cout << "\n\t\tAgregar Sala." << std::endl
              << "Nombre: ";
    getline(std::cin, nombre);
    char response;
    do {
        if (cont_obras + 1 == MAX_OBRAS) {
            std::cout << LIMIT;
            return;
        }
        std::cout << "Desea añadir una obra (y/N): ";
        std::cin >> response;
        std::cin.ignore();
        response = tolower(response);
        switch (response) {
            case 'y':
                obras[cont_obras].init();
                    ++cont_obras;
                break;
        }
    } while (response == 'y');

}
std::string Sala::get_name() {
    return nombre;
}
void Sala::set_name(std::string valor) {
    nombre = valor;
}
void Sala::consult_obra(Obra obra) {
    std::cout << "Título: " << obra.get_titulo() << std::endl
              << "Autor: " << obra.get_autor() << std::endl
              << "Tipo: " << obra.get_tipo() << std::endl
              << "Año: " << obra.get_anio() << std::endl
              << "Descripción: " << obra.get_desc() << std::endl;
}
void Sala::consult_obras() {
    if (cont_obras == 0) {
        std::cout << EMPTY;
        return;
    }
    for (int i(0); i < cont_obras; ++i) {
        std::cout << "\n\t- Obra " << i + 1 << "." << std::endl;
        consult_obra(obras[i]);
    }
}
void Sala::edit_obra() {
    if (cont_obras == 0) {
        std::cout << EMPTY;
        return;
    }
    std::cout << "\nInserte el numero de obra que desea editar: ";
    int num;
    std::cin >> num;
    std::cin.ignore();
    if (num < 1 || num > cont_obras) {
        std::cout << INVALID;
        return;
    }
    obras[num - 1].menu();
}
void Sala::show() {
    std::cout << "Nombre: " << nombre << std::endl;
    consult_obras();
}
void Sala::menu() {
    int opc;
    do {
        std::cout << "\nMenú de Sala " << nombre << std::endl
                  << AGREGAR << ") Agregar obra." << std::endl
                  << CONSULTAR << ") Consultar obras." << std::endl
                  << EDITAR << ") Editar obra." << std::endl
                  << REGRESAR << ") Regresar" << std::endl
                  << SELECT;
        std::cin >> opc;
        std::cin.ignore();
        switch (opc){
            case AGREGAR:
                if (cont_obras + 1 == MAX_OBRAS) {
                    std::cout << LIMIT;
                    break;
                }
                obras[cont_obras].init();
                ++cont_obras;
                break;
            case CONSULTAR:
                consult_obras();
                break;
            case EDITAR:
                edit_obra();
                break;
            case REGRESAR:
                break;
            default:
                std::cout << INVALID;
                break;
        }
    } while(opc != REGRESAR);
}