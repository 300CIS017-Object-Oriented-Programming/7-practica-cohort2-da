//
// Created by david on 19/03/2025.
//

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <vector>
#include "Producto.h"

class Inventario {
private:
  std::vector<Producto*> productos;

public:
  Inventario();  // Constructor
  ~Inventario(); // Destructor para liberar memoria
  void agregarProducto(Producto* nuevoProducto);
  Producto* getProducto(std::string codigo); // Devuelve puntero para modificar el producto
  double calcularValorTotalInventario();
  void getInfo();
};

#endif //INVENTARIO_H

