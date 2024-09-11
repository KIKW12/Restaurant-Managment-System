#include "Producto.h"

Producto::Producto(const std::string& nombre, double precio)
    : nombre(nombre), precio(precio) {
    // Inicialización
}

const std::string& Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}
