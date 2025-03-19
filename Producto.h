//
// Created by david on 19/03/2025.
//

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>


class Producto {
  private:
    std::string codigo;
    std::string nombre;
    double precio;
    int cantidad;
  public:
    Producto(std::string cod, std::string nom, double prec, int cant);
    void actualizarStock(int cantidadNueva);
    void getInfo();
    };





#endif //PRODUCTO_H
