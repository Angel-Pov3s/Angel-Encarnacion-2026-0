#include "SistemaPedidos.h"

#include <iostream>

#include "Cliente.h"
#include "../modelos/Cliente.h"
#include "../modelos/Producto.h"
#include "../modelos/Pedido.h"

using namespace std;

SistemaPedidos::SistemaPedidos()
{
    inventario = make_shared<Inventario>();
}

void SistemaPedidos::inicializarSistema()
{
    cout << "Inicializando sistema de pedidos..." << endl;
}

void SistemaPedidos::registrarCliente()
{
    cout << "Registro de cliente en desarrollo..." << endl;
}

void SistemaPedidos::listarClientes() const
{
    cout << "Lista de clientes:" << endl;

    for (const auto& cliente : clientes)
    {
        cout << "Cliente registrado" << endl;
    }
}

void SistemaPedidos::registrarProducto()
{
    cout << "Registro de producto en desarrollo..." << endl;
}

void SistemaPedidos::listarProductos() const
{
    cout << "Lista de productos:" << endl;

    for (const auto& producto : productos)
    {
        cout << "Producto registrado" << endl;
    }
}

void SistemaPedidos::crearPedido()
{
    cout << "Creación de pedido en desarrollo..." << endl;
}

void SistemaPedidos::listarPedidos() const
{
    cout << "Lista de pedidos:" << endl;

    for (const auto& pedido : pedidos)
    {
        cout << "Pedido registrado" << endl;
    }
}

void SistemaPedidos::mostrarMenuPrincipal()
{
    cout << "\n=== SISTEMA DE PEDIDOS ===" << endl;
    cout << "1. Registrar cliente" << endl;
    cout << "2. Registrar producto" << endl;
    cout << "3. Crear pedido" << endl;
    cout << "4. Listar clientes" << endl;
    cout << "5. Listar productos" << endl;
    cout << "6. Listar pedidos" << endl;
    cout << "0. Salir" << endl;
}

void SistemaPedidos::ejecutar()
{
    int opcion;

    do
    {
        mostrarMenuPrincipal();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                registrarCliente();
                break;

            case 2:
                registrarProducto();
                break;

            case 3:
                crearPedido();
                break;

            case 4:
                listarClientes();
                break;

            case 5:
                listarProductos();
                break;

            case 6:
                listarPedidos();
                break;

            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);
}