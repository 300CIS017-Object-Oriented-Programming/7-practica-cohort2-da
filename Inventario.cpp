//
// Created by david on 19/03/2025.
//

#include "Inventario.h"

using namespace std;

// Método para agregar un producto al inventario
void Inventario::agregarProducto(Producto nuevoProducto) {
    productos.push_back(nuevoProducto);
}

// Método para buscar un producto por su código
Producto* Inventario::getProducto(string codigo) {
    for (auto& producto : productos) {
        if (producto.getCodigo() == codigo) {
            return &producto; // Devuelve la dirección de memoria del producto encontrado
        }
    }
    return nullptr; // Retorna nullptr si el producto no existe
}

// Método para calcular el valor total del inventario
double Inventario::calcularValorTotalInventario() {
    double total = 0;
    for (const auto& producto : productos) {
        total += producto.getPrecio() * producto.getCantidad();
    }
    return total;
}

// Método para mostrar todos los productos del inventario
void Inventario::getInfo() {
    cout << "Inventario de la tienda:" << endl;
    for (const auto& producto : productos) {
        producto.getInfo(); // Llama al método getInfo() de Producto
        cout << "----------------------" << endl;
    }
    cout << "Valor total del inventario: $" << calcularValorTotalInventario() << endl;
}

