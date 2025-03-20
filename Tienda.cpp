//
// Created by david on 19/03/2025.
//

#include "Tienda.h"

using namespace std;

// Constructor: Inicializa el inventario dinámicamente
Tienda::Tienda() {
    inventario = new Inventario();
    cout << "Tienda inicializada correctamente." << endl;
}

// Destructor: Libera memoria
Tienda::~Tienda() {
    delete inventario;

    for (auto cliente : clientes) {
        delete cliente;
    }

    for (auto venta : ventas) {
        delete venta;
    }
}

// Registrar cliente dinámicamente
void Tienda::registrarCliente(Cliente* nuevoCliente) {
    clientes.push_back(nuevoCliente);
}

// Realizar venta con punteros
void Tienda::realizarVenta(string idCliente, vector<pair<Producto*, int>> productosVendidos) {
    Cliente* cliente = nullptr;
    for (auto c : clientes) {
        if (c->getNombre() == idCliente) {
            cliente = c;
            break;
        }
    }

    if (cliente == nullptr) {
        cout << "Error: Cliente no encontrado." << endl;
        return;
    }

    Venta* nuevaVenta = new Venta("V" + to_string(ventas.size() + 1), *cliente);

    for (auto& item : productosVendidos) {
        Producto* producto = inventario->getProducto(item.first->getCodigo());

        if (producto == nullptr) {
            cout << "Producto " << item.first->getNombre() << " no encontrado en inventario." << endl;
            continue;
        }

        if (producto->getCantidad() < item.second) {
            cout << "Stock insuficiente para " << item.first->getNombre() << "." << endl;
            continue;
        }

        nuevaVenta->registrarVenta(*producto, item.second);
        producto->actualizarStock(producto->getCantidad() - item.second);
    }

    ventas.push_back(nuevaVenta);
}

// Mostrar información de la tienda
void Tienda::getInfo() {
    cout << "----- INFORMACIÓN DE LA TIENDA -----" << endl;

    cout << "\n--- Inventario ---\n";
    inventario->getInfo();

    cout << "\n--- Clientes ---\n";
    for (const auto& cliente : clientes) {
        cliente->getInfo();
        cout << "----------------------" << endl;
    }

    cout << "\n--- Ventas ---\n";
    for (const auto& venta : ventas) {
        venta->getInfo();
        cout << "----------------------" << endl;
    }
}
Inventario* Tienda::getInventario() {
    return inventario;
}
