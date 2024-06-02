#pragma once
#include <string>
#include <iostream>
#include <mysql.h>
#include "Conexion_BD.h"
using namespace std;

class Empleados {
private:
    string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, fecha_inicio_labores, FechaIngreso;
    int telefono, idPuesto;

public:
    Empleados() {
    }

    Empleados(string nom, string ape, string dir, int tel, string dpi, string gen, string fn, int idp, string fil, string fi)
        : nombres(nom), apellidos(ape), direccion(dir), telefono(tel), DPI(dpi), genero(gen), fecha_nacimiento(fn), idPuesto(idp), fecha_inicio_labores(fil), FechaIngreso(fi) {
    }

    void setNombres(string nom) { nombres = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setDireccion(string dir) { direccion = dir; }
    void setTelefono(int tel) { telefono = tel; }
    void setDPI(string dpi) { DPI = dpi; }
    void setGenero(string gen) { genero = gen; }
    void setFecha_nacimiento(string fn) { fecha_nacimiento = fn; }
    void setIdpuesto(int idp) { idPuesto = idp; }
    void setFecha_de_ingreso(string fil) { fecha_inicio_labores = fil; }
    void setFechaingreso(string fi) { FechaIngreso = fi; }

    string getNombres() { return nombres; }
    string getApellidos() { return apellidos; }
    string getDireccion() { return direccion; }
    int getTelefono() { return telefono; }
    string getDPI() { return DPI; }
    string getGenero() { return genero; }
    string getFecha_nacimiento() { return fecha_nacimiento; }
    int getidPuestos() { return idPuesto; }
    string getFecha_inicio_labores() { return fecha_inicio_labores; }
    string getFechaingreso() { return FechaIngreso; }

    void Crear() {
        int q_estado;
        Conexion_BD cn = Conexion_BD();
        string t = to_string(telefono);
        string ip = to_string(idPuesto);
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string insertar = "INSERT INTO supermercado.empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, FechaIngreso) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + DPI + "'," + genero + ",'" + fecha_nacimiento + "'," + ip + ",'" + fecha_inicio_labores + "','" + FechaIngreso + "')";
            cout << insertar;
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
            cout << "------------ Datos de Empleados ------------" << endl;
            string consulta = "select * from supermercado.empleados";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << endl;
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
            string t = to_string(telefono);
            string ip = to_string(idPuesto);
            string actualizar = "UPDATE supermercado.empleados SET nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "', telefono='" + t + "', DPI='" + DPI + "', genero=" + genero + ", fecha_nacimiento='" + fecha_nacimiento + "', idPuesto=" + ip + ", fecha_inicio_labores='" + fecha_inicio_labores + "', FechaIngreso='" + FechaIngreso + "' WHERE DPI='" + DPI + "'";
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
            string borrar = "DELETE FROM supermercado.empleados WHERE DPI='" + DPI + "'";
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

