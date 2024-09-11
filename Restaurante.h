#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <map>
#include <vector>
#include "Mesa.h"
#include "Mesero.h"
#include "Admin.h"

class Restaurante {
private:
    std::map<std::string, Mesa> mesas;
    std::vector<Mesero> meseros;
    Admin admin;

public:
    Restaurante(const std::string& adminNombre, const std::string& adminPassword);

    void agregarMesa(const std::string& numeroMesa);
    void agregarMesero(const Mesero& mesero);
    Mesa& obtenerMesa(const std::string& numeroMesa);
    Mesero* iniciarSesion(const std::string& nombre, const std::string& password);
    bool esAdmin(const std::string& nombre, const std::string& password);
};

#endif // RESTAURANTE_H
