#include "Mesero.h"

Mesero::Mesero(const std::string& nombre, const std::string& password)
    : nombre(nombre), password(password) {}

bool Mesero::verificarCredenciales(const std::string& inputPassword) const {
    return inputPassword == password;
}

const std::string& Mesero::getNombre() const {
    return nombre;
}
