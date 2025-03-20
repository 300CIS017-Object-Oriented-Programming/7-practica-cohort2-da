cmake_minimum_required(VERSION 3.16)
project(TiendaEcologica)

set(CMAKE_CXX_STANDARD 17)

add_executable(TiendaEcologica 
    main.cpp
    Tienda.cpp
    Inventario.cpp
    Cliente.cpp
    Producto.cpp
    Venta.cpp
)
