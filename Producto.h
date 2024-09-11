#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string nombre;
    double precio;

public:
    Producto(const std::string& nombre, double precio);

    const std::string& getNombre() const;
    double getPrecio() const;
};

#endif // PRODUCTO_H
