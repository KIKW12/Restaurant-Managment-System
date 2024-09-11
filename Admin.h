#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <map>
#include "Mesa.h"

class Admin {
private:
    std::string nombre;
    std::string password;

public:
    Admin(const std::string& nombre, const std::string& password);

    bool verificarCredenciales(const std::string& inputPassword) const;
    const std::string& getNombre() const;
    void verTodasLasOrdenes(const std::map<std::string, Mesa>& mesas) const;
};

#endif // ADMIN_H
