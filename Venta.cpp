//
// Created by david on 19/03/2025.
//

#include "Venta.h"

using namespace std;

// Constructor de Venta
Venta::Venta(string idV, Cliente cli) : idVenta(idV), cliente(cli) {}

// Método para registrar un producto en la venta
void Venta::registrarVenta(Producto producto, int cantidad) {
    productosVendidos.push_back(make_pair(producto, cantidad));
}

// Método para calcular el total de la venta
double Venta::totalVenta() {
    double total = 0;
    for (const auto& item : productosVendidos) {
        total += item.first.getPrecio() * item.second; // Precio * cantidad
    }
    return total;
}

// Método para mostrar información de la venta
void Venta::getInfo() {
    cout << "ID Venta: " << idVenta << endl;
    cout << "Cliente: " << cliente.getNombre() << endl;
    cout << "Productos vendidos:" << endl;
    for (const auto& item : productosVendidos) {
        cout << "- " << item.first.getNombre() << " (x" << item.second << ")" << endl;
    }
    cout << "Total de la venta: $" << totalVenta() << endl;
}
