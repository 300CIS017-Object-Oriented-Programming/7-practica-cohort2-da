//
// Created by david on 19/03/2025.
//

#include "Inventario.h"

using namespace std;

// Constructor
Inventario::Inventario() {}

// Destructor: Libera memoria de cada producto
Inventario::~Inventario() {
    for (auto producto : productos) {
        delete producto; // Elimina cada producto dinámico
    }
}

// Agrega un producto al inventario
void Inventario::agregarProducto(Producto* nuevoProducto) {
    productos.push_back(nuevoProducto);
}

// Buscar producto por código
Producto* Inventario::getProducto(string codigo) {
    for (auto producto : productos) {
        if (producto->getCodigo() == codigo) {
            return producto; // Retorna puntero al producto encontrado
        }
    }
    return nullptr;
}

// Calcular el valor total del inventario
double Inventario::calcularValorTotalInventario() {
    double total = 0;
    for (auto producto : productos) {
        total += producto->getPrecio() * producto->getCantidad();
    }
    return total;
}

// Mostrar información del inventario
void Inventario::getInfo() {
    cout << "Inventario de la tienda:" << endl;
    for (auto producto : productos) {
        producto->getInfo();
        cout << "----------------------" << endl;
    }
    cout << "Valor total del inventario: $" << calcularValorTotalInventario() << endl;
}
