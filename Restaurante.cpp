#include "Restaurante.h"
#include <iostream>

Restaurante::Restaurante(const std::string& adminNombre, const std::string& adminPassword)
    : admin(adminNombre, adminPassword) {
    // Inicialización
}

void Restaurante::agregarMesa(const std::string& numeroMesa) {
    mesas.emplace(numeroMesa, Mesa());
}

void Restaurante::agregarMesero(const Mesero& mesero) {
    meseros.push_back(mesero);
}

Mesa& Restaurante::obtenerMesa(const std::string& numeroMesa) {
    return mesas[numeroMesa];
}

Mesero* Restaurante::iniciarSesion(const std::string& nombre, const std::string& password) {
    for (Mesero& mesero : meseros) {
        if (mesero.getNombre() == nombre && mesero.verificarCredenciales(password)) {
            return &mesero;
        }
    }
    return nullptr;
}

bool Restaurante::esAdmin(const std::string& nombre, const std::string& password) {
    return admin.getNombre() == nombre && admin.verificarCredenciales(password);
}
