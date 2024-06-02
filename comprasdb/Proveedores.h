#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Proveedores.h"
#include "conexiondb.h"
using namespace std;

class Proveedores
{
public: int idProveedore;
	  string proveedor, nit, direccion, telefono;


public:
	Proveedores() {
	}
	Proveedores(int idProveedore_, string proveedor_, string nit_, string direccion_, string telefono_) {
		idProveedore = idProveedore_;
		proveedor = proveedor_;
		nit = nit_;
		direccion = direccion_;
		telefono = telefono_;
	}

	// Getters  
	int getIdProveedore() const {
		return idProveedore;
	}

	// Setter para idProveedore
	void setIdProveedore(int id) {
		idProveedore = id;
	}

	// Getter para proveedor
	string getProveedor() const {
		return proveedor;
	}

	// Setter para proveedor
	void setProveedor(const string& nombre) {
		proveedor = nombre;
	}

	// Getter para nit
	string getNit() const {
		return nit;
	}

	// Setter para nit
	void setNit(const string& nitProveedor) {
		nit = nitProveedor;
	}

	// Getter para direccion
	string getDireccion() const {
		return direccion;
	}

	// Setter para direccion
	void setDireccion(const string& dirProveedor) {
		direccion = dirProveedor;
	}

	// Getter para telefono
	string getTelefono() const {
		return telefono;
	}

	// Setter para telefono
	void setTelefono(const string& telProveedor) {
		telefono = telProveedor;
	}

	void borrar() {
		int q_estado;
		conexiondb cn = conexiondb();

		cn.abrir_conexion();
		string ii = (idProveedore);
		if (cn.getConectar()) {
			string  borrar =
				"delete from Proveedores where idProveedore = " + ii + "";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "se ha eliminado " << endl;
			}
			else {
				cout << " ---- Error ingreso----" << endl;
			}
		}
		else {
			cout << " ---- Error conexion ----" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizar() {
		int q_estado;
		conexiondb cn = conexiondb();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  actualizar =
				"update Proveedores set proveedor = '" + proveedor + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = '" + telefono + "' where idProveedore = " + to_string(idProveedore);
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion con exito..." << endl;
			}
			else {
				cout << "---- Error al Ingreso ---" << endl;
			}
		}
		else {
			cout << " ---- Conexion con error ----" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		conexiondb cn = conexiondb();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar =
				"INSERT INTO Proveedores(proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "', '" + nit + "', '" + direccion + "', '" + telefono + "')";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso con exito" << endl;
			}
			else {
				cout << "--- Error al Ingresar ----- " << endl;
			}
		}
		else {
			cout << "----  Error con la Conexion-- " << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "/// Datos de Proveedores///" << endl;
			string consulta = "select * from Proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
				}

			}
			else {
				cout << "---Error en la consulta----" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion--------" << endl;
		}
		cn.cerrar_conexion();
	}
};

