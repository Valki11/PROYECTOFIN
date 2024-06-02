#pragma once
#include <string>
#include <iostream>
#include <mysql.h>
#include"Conexion_BD.h"
using namespace std;
class Puestos{
protected: string puesto;
	   int idPuestos;
	
public:
	Puestos() {
	}
	Puestos(string pue /*int idp*/) {
		puesto = pue;
		//idPuestos = idp;
	}
	//void setidPuestos(int idp) { idPuestos = idp; }
	void setPuesto(string pue) { puesto = pue; }

	//int getidPuestos() { return idPuestos; }
	string getPuesto() { return puesto; }

	void Crear() {
		int q_estado;
		Conexion_BD ps = Conexion_BD();
		ps.abrir_conexion();
		if (ps.getConectar()) {
			string insertar = "INSERT INTO supermercado.puestos(Puesto) VALUES ('" + puesto + "')";
			cout << insertar;
			const char* i = insertar.c_str();
			q_estado = mysql_query(ps.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso" << endl;
			}
			else {
				cout << "Creacion Incorrecta" << endl;
			}
		}
		else {
			cout << "Conexion fallida";
		}
		ps.cerrar_conexion();
	}

	void Leer() {
		int q_estado;
		Conexion_BD ps = Conexion_BD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ps.abrir_conexion();

		if (ps.getConectar()) {

			cout << "------------ Datos de Puestos ------------" << endl;
			string consulta = "select * from supermercado.puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(ps.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(ps.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		ps.cerrar_conexion();
	}
	void Actualizar() {
		int q_estado;
		Conexion_BD ps = Conexion_BD();
		ps.abrir_conexion();

		if (ps.getConectar()) {
			string actualizar = "UPDATE supermercado.puestos SET Puesto='" + puesto + "' WHERE Puesto='" + puesto + "'";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(ps.getConectar(), a);

			if (!q_estado) {
				cout << "Actualización Exitosa ..." << endl;
			}
			else {
				cout << "Error al Actualizar: " << mysql_error(ps.getConectar()) << endl;
			}
		}
		else {
			cout << "Error en la Conexion" << endl;
		}
		ps.cerrar_conexion();
	}
	void Borrar() {
		int q_estado;
		Conexion_BD cn = Conexion_BD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			// Mostrar el valor de puesto para depuración
			cout << "Valor de puesto a borrar: " << puesto << endl;

			string borrar = "DELETE FROM supermercado.puestos WHERE Puesto='" + puesto + "'";
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

