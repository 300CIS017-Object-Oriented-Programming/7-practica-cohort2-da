//
// Created by david on 19/03/2025.
//

#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <vector>
#include "Inventario.h"
#include "Cliente.h"
#include "Venta.h"

class Tienda {
private:
    Inventario* inventario;       // Ahora es puntero
    std::vector<Cliente*> clientes;
    std::vector<Venta*> ventas;

public:
    Tienda();   // Constructor
    ~Tienda();  // Destructor

    void registrarCliente(Cliente* nuevoCliente);
    void realizarVenta(std::string idCliente, std::vector<std::pair<Producto*, int>> productosVendidos);
    void getInfo();

    Inventario* getInventario();
};

#endif //TIENDA_H
