#include <iostream>
#include "Tienda.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- MENU DE LA TIENDA ECOLOGICA ---\n";
    cout << "1. Registrar nuevo producto\n";
    cout << "2. Registrar nuevo cliente\n";
    cout << "3. Realizar una venta\n";
    cout << "4. Mostrar valor total del inventario\n";
    cout << "5. Mostrar informacion de la tienda\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Tienda* tienda = new Tienda();
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                // Registrar producto
                string codigo, nombre;
                double precio;
                int cantidad;

                cout << "Ingrese codigo del producto: ";
                getline(cin, codigo);
                cout << "Ingrese nombre del producto: ";
                getline(cin, nombre);
                cout << "Ingrese precio del producto: ";
                cin >> precio;
                cout << "Ingrese cantidad inicial: ";
                cin >> cantidad;
                cin.ignore();

                Producto* nuevoProducto = new Producto(codigo, nombre, precio, cantidad);
                tienda->getInventario()->agregarProducto(nuevoProducto);
                cout << "Producto registrado exitosamente.\n";
                break;
            }
            case 2: {
                // Registrar cliente
                string idCliente, nombre;
                cout << "Ingrese ID del cliente: ";
                getline(cin, idCliente);
                cout << "Ingrese nombre del cliente: ";
                getline(cin, nombre);

                Cliente* nuevoCliente = new Cliente(idCliente, nombre);
                tienda->registrarCliente(nuevoCliente);
                cout << "Cliente registrado exitosamente.\n";
                break;
            }
            case 3: {
                // Realizar venta
                string idCliente;
                cout << "Ingrese el ID del cliente que realiza la compra: ";
                getline(cin, idCliente);

                vector<pair<Producto*, int>> productosVendidos;
                string codigoProducto;
                int cantidad;

                cout << "Ingrese codigo del producto a comprar (o '0' para terminar): ";
                while (getline(cin, codigoProducto) && codigoProducto != "0") {
                    Producto* producto = tienda->getInventario()->getProducto(codigoProducto);
                    if (!producto) {
                        cout << "Producto no encontrado. Intente nuevamente.\n";
                        continue;
                    }

                    cout << "Ingrese cantidad a comprar: ";
                    cin >> cantidad;
                    cin.ignore();

                    if (producto->getCantidad() < cantidad) {
                        cout << "Stock insuficiente. Solo hay " << producto->getCantidad() << " disponibles.\n";
                    } else {
                        productosVendidos.push_back({producto, cantidad});
                    }

                    cout << "Ingrese codigo del siguiente producto (o '0' para terminar): ";
                }

                if (!productosVendidos.empty()) {
                    tienda->realizarVenta(idCliente, productosVendidos);
                    cout << "Venta realizada exitosamente.\n";
                } else {
                    cout << "No se realizó ninguna venta.\n";
                }
                break;
            }
            case 4: {
                // Mostrar valor total del inventario
                cout << "Valor total del inventario: $" << tienda->getInventario()->calcularValorTotalInventario() << endl;
                break;
            }
            case 5: {
                // Mostrar información de la tienda
                tienda->getInfo();
                break;
            }
            case 6: {
                // Salir
                cout << "Saliendo del sistema...\n";
                break;
            }
            default:
                cout << "Opción no válida, intente nuevamente.\n";
        }

    } while (opcion != 6);

    delete tienda;  // Liberar memoria antes de salir
    return 0;
}
