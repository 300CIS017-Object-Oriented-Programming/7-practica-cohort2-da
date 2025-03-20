//
// Created by david on 19/03/2025.
//

#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <vector>
#include "Cliente.h"
#include "Producto.h"

class Venta {
private:
  std::string idVenta;
  Cliente cliente;
  std::vector<std::pair<Producto, int>> productosVendidos; // Producto y cantidad comprada

public:
  Venta(std::string idVenta, Cliente cliente);

  void registrarVenta(Producto producto, int cantidad);
  double totalVenta();
  void getInfo();
};

#endif //VENTA_H

