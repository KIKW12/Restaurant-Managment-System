#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& nombre, const std::string& password)
    : nombre(nombre), password(password) {
    // Inicialización
}

bool Admin::verificarCredenciales(const std::string& inputPassword) const {
    return inputPassword == password;
}

const std::string& Admin::getNombre() const {
    return nombre;
}

void Admin::verTodasLasOrdenes(const std::map<std::string, Mesa>& mesas) const {
    std::cout << "Órdenes de todas las mesas:" << std::endl;
    for (const auto& par : mesas) {
        const std::string& numeroMesa = par.first;
        const Mesa& mesa = par.second;

        std::cout << "Mesa " << numeroMesa << ":" << std::endl;
        mesa.imprimirOrden();
    }
}
