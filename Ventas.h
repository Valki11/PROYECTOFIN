#pragma once
#include <string>
#include <iostream>
#include <mysql.h>
#include "Empleados.h"
#include "Cliente.h"
#include "Conexion_BD.h"
using namespace std;

class Ventas {
private:
    string serie, fechafactura, fechaingreso;
    int nofactura, idCliente, idEmpleado;

public:
    Ventas() {}

    Ventas(int nof, string ser, string fef, int idc, int ide, string fei)
        : nofactura(nof), serie(ser), fechafactura(fef), idCliente(idc), idEmpleado(ide), fechaingreso(fei) {}

    void setNofactura(int nof) { nofactura = nof; }
    void setSerie(string ser) { serie = ser; }
    void setFechafactura(string fef) { fechafactura = fef; }
    void setIdcliente(int idc) { idCliente = idc; }
    void setIdpuesto(int idp) { idEmpleado = idp; }
    void setFechaingreso(string fei) { fechaingreso = fei; }

    int getNofactura() { return nofactura; }
    string getSerie() { return serie; }
    string getFechafactura() { return fechafactura; }
    int getIdcliente() { return idCliente; }
    int getIdpuesto() { return idEmpleado; }
    string getFechaingreso() { return fechaingreso; }

    void Crear() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        string n = to_string(nofactura);
        string ic = to_string(idCliente);
        string ie = to_string(idEmpleado);
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string insertar = "INSERT INTO supermercado.ventas(nofactura, serie, fechafactura, idCliente, idEmpleado, fechaingreso) VALUES ("
                + n + ", '" + serie + "', '" + fechafactura + "', " + ic + ", " + ie + ", '" + fechaingreso + "')";
            cout << insertar << endl;
            const char* i = insertar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Ingreso Exitoso" << endl;
            }
            else {
                cout << "Creacion Incorrecta: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Conexion fallida" << endl;
        }
        cn.cerrar_conexion();
    }

    void Leer() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "------------ Datos de Ventas ------------" << endl;
            string consulta = "SELECT * FROM supermercado.ventas";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while ((fila = mysql_fetch_row(resultado))) {
                    cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << endl;
                }
            }
            else {
                cout << "Error al Consultar: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Error en la Conexion" << endl;
        }
        cn.cerrar_conexion();
    }

    void Actualizar() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string n = to_string(nofactura);
            string ic = to_string(idCliente);
            string ie = to_string(idEmpleado);
            string actualizar = "UPDATE supermercado.ventas SET serie='" + serie + "', fechafactura='" + fechafactura
                + "', idCliente=" + ic + ", idEmpleado=" + ie + ", fechaingreso='" + fechaingreso + "' WHERE nofactura=" + n;
            const char* a = actualizar.c_str();
            q_estado = mysql_query(cn.getConectar(), a);
            if (!q_estado) {
                cout << "Actualización Exitosa" << endl;
            }
            else {
                cout << "Error al Actualizar: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Error en la Conexion" << endl;
        }
        cn.cerrar_conexion();
    }

    void Borrar() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string n = to_string(nofactura);
            string borrar = "DELETE FROM supermercado.ventas WHERE nofactura=" + n;
            const char* d = borrar.c_str();
            q_estado = mysql_query(cn.getConectar(), d);
            if (!q_estado) {
                cout << "Eliminación Exitosa" << endl;
            }
            else {
                cout << "Error al Eliminar: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << "Error en la Conexion" << endl;
        }
        cn.cerrar_conexion();
    }
};

