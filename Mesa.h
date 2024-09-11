#ifndef MESA_H
#define MESA_H

#include <vector>
#include "Producto.h"

class Mesa {
private:
    std::vector<Producto> orden;
    double total;

public:
    Mesa();

    void agregarProducto(const Producto& producto);
    void eliminarProducto(size_t indice);
    void imprimirOrden() const;
    double getTotal() const;

private:
    void recalcularTotal();
};

#endif // MESA_H
