#include "museo.h"
#include "obra.h"
#include "sala.h"
#include <iostream>
Museo::Museo() {
}
void Museo::editar_sala() {
    if (cont_salas == 0) {
        std::cout << EMPTY;
        return;
    }
    mostrar_salas();
    std::cout << "\nInserte el numero de sala a editar: ";
    int num;
    std::cin >> num;
    std::cin.ignore();
    if (num < 1 || num > cont_salas) {
        std::cout << INVALID;
        return;
    }
    salas[num - 1].menu();
}
void Museo::mostrar_salas() {
    for (int i(0); i < cont_salas; ++i) {
        std::cout << "\n\tSala " << i + 1 << std::endl;
        salas[i].show();
    }
}
void Museo::buscar_sala() {
    std::cout << "\nInserte el nombre de la sala a buscar: ";
    std::string patron;
    int cont(0);
    getline(std::cin, patron);
    for (int i(0); i < cont_salas; ++i) {
        if (salas[i].get_name().find(patron) < salas[i].get_name().size()) {
            salas[i].show();
            ++cont;
        }
    }
    std::cout << "Se encontraron " << cont << " ingredientes." << std::endl;
}
void Museo::menu() {
    int opc;
    do {
        std::cout << "\nMenú de Museo " << nombre_museo << std::endl
                  << ADD << ") Agregar sala." << std::endl
                  << EDIT << ") Editar sala." << std::endl
                  << SHOW << ") Mostrar salas." << std::endl
                  << SEARCH << ") Buscar sala." << std::endl
                  << EXIT << ") Salir." << std::endl
                  << SELECT;
        std::cin >> opc;
        std::cin.ignore();
        switch (opc) {
            case ADD:
                if (cont_salas + 1 == MAX_SALAS) {
                    std::cout << LIMIT;
                    break;
                }
                salas[cont_salas].init();
                ++cont_salas;
                break;
            case EDIT:
                editar_sala();
                break;
            case SHOW:
                mostrar_salas();
                break;
            case SEARCH:
                buscar_sala();
                break;
            case EXIT:
                break;
            default:
                std::cout << INVALID;
                break;
        }
    } while (opc != EXIT);
}