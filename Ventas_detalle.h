#pragma once
#include <string>
#include <iostream>
#include <mysql.h>
#include "Conexion_BD.h"

using namespace std;

class VentasDetalle {
private:
    int idDetalle, idVenta, idProducto, cantidad;
    double precioUnitario;

public:
    // Constructor por defecto
    VentasDetalle() {}

    // Constructor con parámetros
    VentasDetalle(int idVenta, int idProducto, int cantidad, double precioUnitario)
        : idVenta(idVenta), idProducto(idProducto), cantidad(cantidad), precioUnitario(precioUnitario) {}

    // Setters
    void setIdDetalle(int idDetalle) { this->idDetalle = idDetalle; }
    void setIdVenta(int idVenta) { this->idVenta = idVenta; }
    void setIdProducto(int idProducto) { this->idProducto = idProducto; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }
    void setPrecioUnitario(double precioUnitario) { this->precioUnitario = precioUnitario; }

    // Getters
    int getIdDetalle() { return idDetalle; }
    int getIdVenta() { return idVenta; }
    int getIdProducto() { return idProducto; }
    int getCantidad() { return cantidad; }
    double getPrecioUnitario() { return precioUnitario; }

    // Crear
    void Crear() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string insertar = "INSERT INTO ventas_detalle(idVenta, idProducto, cantidad, precio_unitario) VALUES (" +
                to_string(idVenta) + ", " + to_string(idProducto) + ", " + to_string(cantidad) + ", " + to_string(precioUnitario) + ")";
            const char* i = insertar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Ingreso Exitoso" << endl;
            }
            else {
                cout << "Error al insertar: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Error en la conexión" << endl;
        }
        cn.cerrar_conexion();
    }

    // Leer
    void Leer() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string consulta = "SELECT * FROM ventas_detalle";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << "ID Detalle: " << fila[0] << ", ID Venta: " << fila[1] << ", ID Producto: " << fila[2]
                        << ", Cantidad: " << fila[3] << ", Precio Unitario: " << fila[4] << endl;
                }
            }
            else {
                cout << "Error al consultar: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Error en la conexión" << endl;
        }
        cn.cerrar_conexion();
    }

    // Actualizar
    void Actualizar() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string actualizar = "UPDATE ventas_detalle SET idVenta = " + to_string(idVenta) +
                ", idProducto = " + to_string(idProducto) +
                ", cantidad = " + to_string(cantidad) +
                ", precio_unitario = " + to_string(precioUnitario) +
                " WHERE idDetalle = " + to_string(idDetalle);
            const char* a = actualizar.c_str();
            q_estado = mysql_query(cn.getConectar(), a);
            if (!q_estado) {
                cout << "Actualización Exitosa" << endl;
            }
            else {
                cout << "Error al actualizar: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Error en la conexión" << endl;
        }
        cn.cerrar_conexion();
    }

    // Borrar
    void Borrar() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string borrar = "DELETE FROM ventas_detalle WHERE idDetalle = " + to_string(idDetalle);
            const char* d = borrar.c_str();
            q_estado = mysql_query(cn.getConectar(), d);
            if (!q_estado) {
                cout << "Eliminación Exitosa" << endl;
            }
            else {
                cout << "Error al eliminar: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Error en la conexión" << endl;
        }
        cn.cerrar_conexion();
    }
};


