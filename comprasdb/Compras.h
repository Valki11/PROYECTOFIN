#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Compras.h"
#include "ConexionDB.h"
using namespace std;

class Compras
{
	public: string fecha_orden, fechaingreso;
		int idcompra, no_orden_compra, idproveedor, idproducto, cantidad;
		float precio_costo_unitario;

	public:
		Compras(){}
		Compras(int idcompra_,int no_orden_compra_, int idproveedor_, string fecha_orden_, string fechaingreso_, int idproducto_, int cantidad_, float precio_costo_unitario_) {
			idcompra = idcompra_;
			no_orden_compra = no_orden_compra_;
			idproveedor = idproveedor_;
			fecha_orden = fecha_orden_;
			fechaingreso = fechaingreso_;
			idproducto = idproducto_;
			cantidad = cantidad_;
			cantidad = cantidad_;
			precio_costo_unitario = precio_costo_unitario_;
		}

		// Getters
		string getFechaOrden() const { return fecha_orden; }
		string getFechaIngreso() const { return fechaingreso; }
		int getIdCompra() const { return idcompra; }
		int getNoOrdenCompra() const { return no_orden_compra; }
		int getIdProveedor() const { return idproveedor; }
		int getIdProducto() const { return idproducto; }
		int getCantidad() const { return cantidad; }
		float getPrecioCostoUnitario() const { return precio_costo_unitario; }

		// Setters
		void setFechaOrden(const string& fecha_orden) { this->fecha_orden = fecha_orden; }
		void setFechaIngreso(const string& fecha_ingreso) { this->fechaingreso = fecha_ingreso; }
		void setIdCompra(int id_compra) { this->idcompra = id_compra; }
		void setNoOrdenCompra(int no_orden_compra) { this->no_orden_compra = no_orden_compra; }
		void setIdProveedor(int id_proveedor) { this->idproveedor = id_proveedor; }
		void setIdProducto(int id_producto) { this->idproducto = id_producto; }
		void setCantidad(int cantidad) { this->cantidad = cantidad; }
		void setPrecioCostoUnitario(float precio_costo_unitario) { this->precio_costo_unitario = precio_costo_unitario; }

		void borrar() {
			int q_estado;
			conexiondb cn = conexiondb();

			cn.abrir_conexion();
			string ii = (idcompra);
			if (cn.getConectar()) {
				string  borrar =
					"delete from Compras where idcompra = " + ii + "; DELETE FROM Compras_detalle where idcompra = "+ to_string(idcompra) + " AND idproducto = " + to_string(idproducto);
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
					"update Compras set no_orden_compra = '" + to_string(no_orden_compra) + "', idproveedor = '" + to_string(idproveedor) + "', fecha_orden = '" + fecha_orden + "', fechaingreso = '" + fechaingreso + "' where idCompra ="+ to_string(idcompra) + "; ";
				actualizar += " UPDATE Compras_detalle SET cantidad = " + to_string(cantidad) + ", precio_costo_unitario = "+ to_string(precio_costo_unitario) + " where idcompra = " + to_string(idcompra) + " AND idproducto = " + to_string(idproducto);
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
					"INSERT INTO Compras(no_orden_compra, idproveedor, fecha_orden, fechaingreso) VALUES ('" + to_string(no_orden_compra) + "', '" + to_string(idproveedor) + "', '" + fecha_orden + "', '" + fechaingreso + "'); ";
				insertar += "INSERT INTO Compras_detalle(idcompra, idproducto, cantidad, precio_costo_unitario) VALUES("+ to_string(idcompra) + ", " + to_string(idproducto) + "," + to_string(cantidad) + ", " + to_string(precio_costo_unitario) + ", )"
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

				cout << "/// Datos de Compras///" << endl;
				string consulta = "select c.*, cd.cantidad, cd.precio_costo_unitario FROM Compras c INNER JOIN Compras_detalle cd ON c.idcompra = cd.idcompra; ";
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