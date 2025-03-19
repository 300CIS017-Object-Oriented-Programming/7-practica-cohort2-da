//
// Created by david on 19/03/2025.
//

#include "Producto.h"
#include <iostream>

using namespace std;

// Constructor de Producto
Producto::Producto(string cod, string nom, double prec, int cant) {
    codigo = cod;
    nombre = nom;
    precio = prec;
    cantidad = cant;
}

// Método para actualizar la cantidad en stock
void Producto::actualizarStock(int cantidadNueva) {
    cantidad += cantidadNueva;
}

// Método para obtener información del producto
void Producto::getInfo() {
    cout << "Código: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Cantidad en stock: " << cantidad << endl;
}

