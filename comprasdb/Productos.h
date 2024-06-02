#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Productos.h"
#include "ConexionDB.h"
using namespace std;

class Productos
{
	public: string producto, Descripcion, Imagen, fecha_ingreso;
			int idProducto, idMarca, existencia;
			float precio_costo, precio_venta;

	public: 
		Productos() {}
		Productos(int idProducto_, string producto_,int idMarca_, string Descripcion_, string Imagen_, float precio_costo_, float precio_venta_, int existencia_, string fecha_ingreso_) {
			idProducto = idProducto_;
			producto = producto_;
			Descripcion = Descripcion_;
			Imagen = Imagen_;
			precio_costo = precio_costo_;
			precio_venta = precio_venta_;
			existencia = existencia_;
			fecha_ingreso = fecha_ingreso_;
		}

		string getNombre() const { return producto; }
		string getDescripcion() const { return Descripcion; }
		string getImagen() const { return Imagen; }
		string getFechaIngreso() const { return fecha_ingreso; }
		int getIdProducto() const { return idProducto; }
		int getIdMarca() const { return idMarca; }
		int getExistencia() const { return existencia; }
		float getPrecioCosto() const { return precio_costo; }
		float getPrecioVenta() const { return precio_venta; }

		// Setters
		void setNombre(const string& nombre) { producto = nombre; }
		void setDescripcion(const string& descripcion) { this->Descripcion = descripcion; }
		void setImagen(const string& imagen) { this->Imagen = imagen; }
		void setFechaIngreso(const string& fecha_ingreso) { this->fecha_ingreso = fecha_ingreso; }
		void setIdProducto(int idProducto) { this->idProducto = idProducto; }
		void setIdMarca(int idMarca) { this->idMarca = idMarca; }
		void setExistencia(int existencia) { this->existencia = existencia; }
		void setPrecioCosto(float precio_costo) { this->precio_costo = precio_costo; }
		void setPrecioVenta(float precio_venta) { this->precio_venta = precio_venta; }

		void borrar() {
			int q_estado;
			conexiondb cn = conexiondb();

			cn.abrir_conexion();
			string ii = (idProducto);
			if (cn.getConectar()) {
				string  borrar =
					"delete from Productos where idProducto = " + ii + "";
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
					"update Productos set producto = '" + producto + "', idMarca = '" + to_string(idMarca) + "', Descripcion = '" + Descripcion + "', Imagen = '" + Imagen + "', precio_costo = '" + to_string(precio_costo) + "', precio_venta = '" + to_string(precio_venta) + "', existencia = '" + to_string(existencia) + "', fecha_ingreso = '" + fecha_ingreso + "' where idProducto = "+ to_string(idProducto);
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
					"INSERT INTO Productos(producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES ('" + producto + "', '" + to_string(idMarca) + "', '" + Descripcion + "', '" + Imagen + "', '" + to_string(precio_costo) + "', '" + to_string(precio_venta) + "', '" + to_string(existencia) + "', '" + fecha_ingreso + "')";
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

				cout << "/// Datos de Productos///" << endl;
				string consulta = "select * from Productos";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					while (fila = mysql_fetch_row(resultado)) {
						cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
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

