#include "Mesa.h"
#include <iostream>

Mesa::Mesa() : total(0.0) {
    // Inicialización
}

void Mesa::agregarProducto(const Producto& producto) {
    orden.push_back(producto);
    total += producto.getPrecio();
}

void Mesa::eliminarProducto(size_t indice) {
    if (indice < orden.size()) {
        total -= orden[indice].getPrecio();
        orden.erase(orden.begin() + indice);
        recalcularTotal();
    }
}

void Mesa::imprimirOrden() const {
    std::cout << "Detalles de la orden:" << std::endl;
    for (size_t i = 0; i < orden.size(); ++i) {
        const Producto& producto = orden[i];
        std::cout << i + 1 << ". " << producto.getNombre() << " - $" << producto.getPrecio() << std::endl;
    }
    std::cout << "Total de la orden: $" << total << std::endl;
}

double Mesa::getTotal() const {
    return total;
}

void Mesa::recalcularTotal() {
    total = 0.0;
    for (const Producto& producto : orden) {
        total += producto.getPrecio();
    }
}
