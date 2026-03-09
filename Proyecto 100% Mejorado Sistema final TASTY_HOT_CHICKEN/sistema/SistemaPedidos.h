#ifndef SISTEMA_PEDIDOS_H
#define SISTEMA_PEDIDOS_H

#include <vector>
#include <memory>

// Forward declarations
class Cliente;
class Producto;
class Pedido;
class Inventario;

class SistemaPedidos
{
private:

    std::vector<std::shared_ptr<Cliente>> clientes;
    std::vector<std::shared_ptr<Producto>> productos;
    std::vector<std::shared_ptr<Pedido>> pedidos;

    std::shared_ptr<Inventario> inventario;

public:

    // Constructor
    SistemaPedidos();

    // Inicialización del sistema
    void inicializarSistema();

    // Gestión de clientes
    void registrarCliente();
    void listarClientes() const;

    // Gestión de productos
    void registrarProducto();
    void listarProductos() const;

    // Gestión de pedidos
    void crearPedido();
    void listarPedidos() const;

    // Sistema general
    void mostrarMenuPrincipal();
    void ejecutar();

};

#endif