#include <iostream>
#include <limits>

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
    cout << "Seleccione una opcion: ";
}

int main() {
    auto* tienda = new Tienda();
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
                while (!(cin >> precio) || precio < 0) {
                    cout << "Precio inválido. Ingrese nuevamente: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Ingrese cantidad inicial: ";
                while (!(cin >> cantidad) || cantidad < 0) {
                    cout << "Cantidad inválida. Ingrese nuevamente: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore();

                auto* nuevoProducto = new Producto(codigo, nombre, precio, cantidad);
                Inventario* inventario = tienda->getInventario();
                if (inventario) {
                    inventario->agregarProducto(nuevoProducto);
                    cout << "Producto registrado exitosamente.\n";
                } else {
                    cout << "Error: Inventario no disponible.\n";
                    delete nuevoProducto;
                }
                break;
            }
            case 2: {
                // Registrar cliente
                string idCliente, nombre;
                cout << "Ingrese ID del cliente: ";
                getline(cin, idCliente);
                cout << "Ingrese nombre del cliente: ";
                getline(cin, nombre);

                auto* nuevoCliente = new Cliente(idCliente, nombre);
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
                Inventario* inventario = tienda->getInventario();

                if (!inventario) {
                    cout << "Error: Inventario no disponible.\n";
                    break;
                }

                cout << "Ingrese codigo del producto a comprar (o '0' para terminar): ";
                while (getline(cin, codigoProducto) && codigoProducto != "0") {
                    Producto* producto = inventario->getProducto(codigoProducto);
                    if (!producto) {
                        cout << "Producto no encontrado. Intente nuevamente.\n";
                        continue;
                    }

                    cout << "Ingrese cantidad a comprar: ";
                    while (!(cin >> cantidad) || cantidad <= 0) {
                        cout << "Cantidad inválida. Ingrese nuevamente: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore();

                    if (producto->getCantidad() < cantidad) {
                        cout << "Stock insuficiente. Solo hay " << producto->getCantidad() << " disponibles.\n";
                    } else {
                        productosVendidos.emplace_back(producto, cantidad);
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
                Inventario* inventario = tienda->getInventario();
                if (inventario) {
                    cout << "Valor total del inventario: $" << inventario->calcularValorTotalInventario() << endl;
                } else {
                    cout << "Error: Inventario no disponible.\n";
                }
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

