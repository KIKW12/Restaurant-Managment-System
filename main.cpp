#include <iostream>
#include "Restaurante.h"
#include "Mesero.h"
#include "Admin.h"

using namespace std;

int main() {
    Restaurante restaurante("admin", "adminpassword");
    restaurante.agregarMesa("Mesa1");
    restaurante.agregarMesa("Mesa2");

    Mesero mesero1("Paco", "paco123");
    Mesero mesero2("Luis", "luis123");

    // Agregar meseros al restaurante
    restaurante.agregarMesero(mesero1);
    restaurante.agregarMesero(mesero2);

    bool salir = false;

    while (!salir) {
        string nombreUsuario;
        string password;

        cout << "Inicio de Sesión" << endl;
        cout << "Nombre de usuario: ";
        cin >> nombreUsuario;
        cout << "Contraseña: ";
        cin >> password;

        if (restaurante.esAdmin(nombreUsuario, password)) {
            cout << "Sesión iniciada como administrador." << endl;
            cout << "Seleccione una mesa para ver la orden:" << endl;
            string numeroMesa;
            cin >> numeroMesa;

            if (restaurante.obtenerMesa(numeroMesa).getTotal() > 0) {
                restaurante.obtenerMesa(numeroMesa).imprimirOrden();
            } else {
                cout << "La mesa no tiene órdenes registradas." << endl;
            }
        } else {
            Mesero* mesero = restaurante.iniciarSesion(nombreUsuario, password);

            if (mesero) {
                cout << "Sesión iniciada como " << mesero->getNombre() << endl;
                string numeroMesa;

                while (true) {
                    cout << "Número de mesa: ";
                    cin >> numeroMesa;

                    Mesa& mesa = restaurante.obtenerMesa(numeroMesa);

                    cout << "1. Agregar producto" << endl;
                    cout << "2. Imprimir orden" << endl;
                    cout << "3. Eliminar producto" << endl;
                    cout << "4. Cerrar sesión" << endl;

                    int opcion;
                    cin >> opcion;

                    if (opcion == 1) {
                        string nombreProducto;
                        double precioProducto{0.0};

                        cout << "Nombre del producto: ";
                        cin >> nombreProducto;
                        cout << "Precio del producto: ";
                        cin >> precioProducto;

                        Producto producto(nombreProducto, precioProducto);
                        mesa.agregarProducto(producto);
                    } else if (opcion == 2) {
                        mesa.imprimirOrden();
                    } else if (opcion == 3) {
                        int numeroProducto;
                        cout << "Número del producto a eliminar: ";
                        cin >> numeroProducto;

                        if (numeroProducto > 0 && numeroProducto <= mesa.getTotal()) {
                            mesa.eliminarProducto(numeroProducto - 1);
                            cout << "Producto eliminado correctamente." << endl;
                        } else {
                            cout << "Número de producto inválido." << endl;
                        }
                    } else if (opcion == 4) {
                        break;
                    }
                }
            } else {
                cout << "Inicio de sesión fallido. Credenciales incorrectas." << endl;
            }
        }

        char continuar;
        cout << "¿Desea continuar? (s/n): ";
        cin >> continuar;
        if (continuar == 'n' || continuar == 'N') {
            salir = true;
        }
    }

    return 0;
}
