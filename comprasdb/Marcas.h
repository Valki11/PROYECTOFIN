#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Marcas.h"
#include "conexiondb.h"
using namespace std;

class Marcas{
public: int idmarca;
	    string marca;


public:
	Marcas() {
	}
	Marcas( int idmarc, string mar) {
		idmarca = idmarc;
		marca = mar;
	}

	// Getters  
	int getidmarca() { return idmarca; }
	string getmarca() {
		return marca;
	}
	// Setters
	void setidmarca(const int& idmarca) { this->idmarca = idmarca; }
	void setmarca(const string& ) { this->marca = marca; }
	
	void borrar() {
		int q_estado;
		conexiondb cn = conexiondb();

		cn.abrir_conexion();
		string ii = (idmarca);
		if (cn.getConectar()) {
			string  borrar =
				"delete from Marcas where idmarca = " + ii + "";
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
				"update Marcas set marca = '" + marca + "' where idmarca ="+ to_string(idmarca);
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
				"INSERT INTO Marcas(marca) VALUES ('" + marca+ "')";
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

			cout << "/// Datos de Marcas///" << endl;
			string consulta = "select * from Marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] <<endl;
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
