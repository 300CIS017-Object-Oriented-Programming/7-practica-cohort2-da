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
  Inventario inventario;
  std::vector<Cliente> clientes;  // Lista de clientes
  std::vector<Venta> ventas;      // Lista de ventas

public:
  void registrarCliente(Cliente nuevoCliente);
  void realizarVenta(std::string idCliente, std::vector<std::pair<Producto, int>> productosVendidos);
  void getInfo();
};

#endif //TIENDA_H

