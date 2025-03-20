//
// Created by david on 19/03/2025.
//

#include "Cliente.h"

using namespace std;

// Constructor de Cliente
Cliente::Cliente(string idC, string nom) {
    idCliente = idC;
    nombre = nom;
}

// Método para registrar una compra en el historial
void Cliente::registrarCompra(string codigoProducto) {
    historialCompras.push_back(codigoProducto);
}

// Método para obtener información del cliente
void Cliente::getInfo() {
    cout << "ID Cliente: " << idCliente << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Historial de Compras: " << endl;
    for (const string& compra : historialCompras) {
        cout << "- " << compra << endl;
    }
}
