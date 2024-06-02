#pragma once
#include<iostream>
#include<string>
#include"Persona.h"
#include<mysql.h>
#include"Conexion_BD.h"
using namespace std;
class Cliente : Persona{
private:
	string nit;
	string correo_electronico;
	string fechaingreso;
	
public:
	Cliente() {
        }
	Cliente(string n, string nom, string ape, string gen, int tel, string coe, string fi) : Persona(nom, ape, "", tel, "", gen) {
		nit = n;
		correo_electronico = coe;
		fechaingreso = fi;
	}
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setGenero(string gen) { genero = gen; }
	void setTelefono(int tel) { telefono = tel; }
	void setCorreo_electronico(string coe) { correo_electronico = coe; }
	void setFecha_ingreso(string fi) { fechaingreso = fi; }

	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getGenero() { return genero; }
	int getTelefono() { return telefono; }
	string getCorreo_electronico() { return correo_electronico; }
	string getFecha_ingreso() { return fechaingreso; }

	void Crear() {
		int q_estado;
		Conexion_BD cn = Conexion_BD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string insertar = "INSERT INTO supermercado.clientes(nit,nombres,apellidos,genero,telefono,correo_electronico,fechaingreso) VALUES ('" + nit + "','" + nombres + "','" + apellidos + "'," + genero + ",'" + t + "','" + correo_electronico + "','" + fechaingreso + "')";
			cout << insertar;
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso" << endl ;
			}
			else {
				cout << "Creacion Incorrecta" << endl;
			}
		}else {
			cout << "Conexion fallida";
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

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from supermercado.clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void Actualizar() {
		int q_estado;
		Conexion_BD cn = Conexion_BD();
		cn.abrir_conexion();

		string t = to_string(telefono);
		if (cn.getConectar()) {
			string actualizar = "UPDATE supermercado.clientes SET nit='" + nit + "', nombres='" + nombres +"', apellidos='" + apellidos +"', genero=" + genero +", telefono='" + t +"', correo_electronico='" + correo_electronico +"', fechaingreso='" + fechaingreso +"' WHERE nit='" + nit + "'";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);

			if (!q_estado) {
				cout << "Actualización Exitosa ..." << endl;
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
			string borrar = "DELETE FROM supermercado.clientes WHERE nit='" + nit + "'";
			const char* d = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				cout << "Eliminación Exitosa ..." << endl;
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


