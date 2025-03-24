cmake_minimum_required(VERSION 3.10)
project(TiendaEco)

set(CMAKE_CXX_STANDARD 17)

add_executable(TiendaEco main.cpp Tienda.cpp Producto.cpp Inventario.cpp Cliente.cpp)
