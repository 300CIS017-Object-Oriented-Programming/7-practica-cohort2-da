//
// Created by david on 19/03/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <vector>

class Cliente {
  private:
    std::string idCliente;
    std::string nombre;
    std::vector<std::string> historialCompras;
  public:
    Cliente(std::string idC, std::string nom);
    void registrarCompra(std::string codigoProducto);
    void getInfo();
};



#endif //CLIENTE_H
