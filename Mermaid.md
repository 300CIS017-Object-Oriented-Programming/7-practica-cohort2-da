classDiagram
    class Producto {
        -string codigo
        -string nombre
        -double precio
        -int cantidad
        +void actualizarStock(int cantidadNueva)
        +getInfo()
    }

    class Cliente {
        -string idCliente
        -string nombre
        -vector<string> historialCompras
        +void registrarCompra(string codigoProducto)
        +getInfo()
    }

    class Venta {
        -string idVenta
        -Cliente cliente
        -Producto productosVendido
        -int cantidad
        +double totalVenta
        +void registrarVenta(Cliente cliente, Producto productos, int cantidad)
        +getinfo()
    }

    class Inventario {
        -Producto productos
        +void agregarProducto(Producto nuevoProducto)
        +Producto getProducto(string codigo)
        +double calcularValorTotalInventario()
    }

    class Tienda {
        -Inventario inventario
        -Cliente clientes
        -Venta ventas
        +void registrarCliente(Cliente nuevoCliente)
        +void realizarVenta(string idCliente, Producto productos, int cantidad)
    }

    Cliente --> Venta
    Venta --> Producto
    Tienda --> Inventario
    Tienda --> Cliente
    Tienda --> Venta
    Inventario --> Producto