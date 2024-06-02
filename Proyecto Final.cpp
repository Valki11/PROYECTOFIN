#pragma once
#include<iostream>
#include "Cliente.h"
#include "Puestos.h"
#include "Empleados.h"
#include "Ventas.h"
#include "Windows.h"
#include "Ventas_detalle.h"
//#include<mysql.h>
using namespace std;
Cliente cl;
Puestos p;
Empleados e;
Ventas v;
VentasDetalle vd;
//int q_estado;
int main() {
	int tabla;
	cout << "1-Clientes, 2-Puestos, 3-Empleados, 4-Ventas y Ventas detalle" << endl;
	cout << "Que tabla desea verificar: ";
	cin >> tabla;
	switch (tabla) {
	case 1:
		system("cls");
		int opcion;
		cout << "1-Crear, 2-Leer, 3-Actualizar, 4-Borrar" << endl;
		cout << "Que desea realizar en la BD clientes: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			string nit, nombres, apellidos, genero, correo_electronico, fechaingreso;
			int telefono;
			cout << "Ingrese Nit: ";
			cin.ignore();
			getline(cin, nit);
			cout << "Ingrese Nombres: ";
			getline(cin, nombres);
			cout << "Ingrese Apellidos: ";
			getline(cin, apellidos);
			do {
				cout << "Ingrese Genero (M/F): ";
				cin >> genero;
			} while (genero != "M" && genero != "F");
			genero = (genero == "M") ? "1" : "0";
			cout << "Ingrese Telefono: ";
			cin >> telefono;
			cin.ignore();
			cout << "Ingrese Correo Electronico: ";
			cin >> correo_electronico;
			cout << "Fecha Ingreso: ";
			cin >> fechaingreso;

			Cliente cl(nit, nombres, apellidos, genero, telefono, correo_electronico, fechaingreso);
			cl.Crear();
			break;
		}
		case 2:
			cl.Leer();
			break;
		case 3:
		{
			string nit, nombres, apellidos, genero, correo_electronico, fechaingreso;
			int telefono;

			cout << "Ingrese Nit del cliente a actualizar: ";
			cin.ignore();
			getline(cin, nit);

			cout << "Ingrese Nombres: ";
			getline(cin, nombres);
			cout << "Ingrese Apellidos: ";
			getline(cin, apellidos);
			do {
				cout << "Ingrese Genero (M/F): ";
				cin >> genero;
			} while (genero != "M" && genero != "F");
			genero = (genero == "M") ? "1" : "0";
			cout << "Ingrese Telefono: ";
			cin >> telefono;
			cin.ignore();

			cout << "Ingrese Correo Electronico: ";
			cin.ignore();
			getline(cin, correo_electronico);

			cout << "Fecha Ingreso (YYYY-MM-DD): ";
			getline(cin, fechaingreso);

			Cliente cl(nit, nombres, apellidos, genero, telefono, correo_electronico, fechaingreso);

			cl.Actualizar();
			break;
		}
		case 4:
		{
			string nit;

			cout << "Ingrese Nit del cliente a Borrar: ";
			cin.ignore();
			getline(cin, nit);

			cl.setNit(nit);
			cl.Borrar();
			break;
		}

		}
		break;
	case 2:
		system("cls");
		int opcio;
		cout << "1-Crear, 2-Leer, 3-Actualizar, 4-Borrar" << endl;
		cout << "Que desea realizar en la BD clientes: ";
		cin >> opcio;
		switch (opcio) {
		case 1: {
			string puesto;
			cout << "Ingrese Puesto: ";
			cin.ignore();
			getline(cin, puesto);

			Puestos p(puesto);
			p.Crear();
			break;
		}
		case 2:
			p.Leer();
			break;
		case 3:
		{
			string puesto;

			cout << "Ingrese puesto a actualizar: ";
			cin.ignore();
			getline(cin, puesto);

			Puestos p(puesto);

			p.Actualizar();
			break;
		}
		case 4:
		{
			string puesto;

			cout << "Ingrese Puesto a Borrar: ";
			cin.ignore();
			getline(cin, puesto);

			p.setPuesto(puesto);
			p.Borrar();
			break;
		}
		}
	case 3:
		system("cls");
		int opci;
		cout << "1-Crear, 2-Leer, 3-Actualizar, 4-Borrar" << endl;
		cout << "Que desea realizar en la BD clientes: ";
		cin >> opci;
		switch (opci) {
		case 1: {
			string nombres, apellidos, direccion, dpi, genero, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso;
			int telefono, id_puesto;

			cout << "Ingrese Nombres: ";
			cin.ignore();
			getline(cin, nombres);
			e.setNombres(nombres);

			cout << "Ingrese Apellidos: ";
			getline(cin, apellidos);
			e.setApellidos(apellidos);

			cout << "Ingrese Direccion: ";
			getline(cin, direccion);
			e.setDireccion(direccion);

			cout << "Ingrese Telefono: ";
			cin >> telefono;
			e.setTelefono(telefono);

			cout << "Ingrese DPI: ";
			cin.ignore();
			getline(cin, dpi);
			e.setDPI(dpi);

			do {
				cout << "Ingrese Genero (M/F): ";
				cin >> genero;
			} while (genero != "M" && genero != "F");
			genero = (genero == "M") ? "1" : "0";
			e.setGenero(genero);


			cout << "Ingrese Fecha de Nacimiento (YYYY-MM-DD): ";
			cin.ignore();
			getline(cin, fecha_nacimiento);
			e.setFecha_nacimiento(fecha_nacimiento);

			cout << "Ingrese ID del Puesto: ";
			cin >> id_puesto;
			e.setIdpuesto(id_puesto);

			cout << "Ingrese Fecha de Inicio de Labores (YYYY-MM-DD): ";
			cin.ignore();
			getline(cin, fecha_inicio_labores);
			e.setFecha_de_ingreso(fecha_inicio_labores);

			cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD): ";
			getline(cin, fecha_ingreso);
			e.setFechaingreso(fecha_ingreso);


			e.Crear();
			break;
		}
		case 2:
			e.Leer();
			break;
		case 3: {
			string dpi;
			cout << "Ingrese DPI del Empleado a actualizar: ";
			cin.ignore();
			getline(cin, dpi);

			Empleados emp;
			e.setDPI(dpi);

			string nom, ape, dir, gen, fn, fil, fi;
			int tel, idp;

			cout << "Ingrese Nuevos Nombres: ";
			getline(cin, nom);
			cout << "Ingrese Nuevos Apellidos: ";
			getline(cin, ape);
			cout << "Ingrese Nueva Direccion: ";
			getline(cin, dir);
			cout << "Ingrese Nuevo Telefono: ";
			cin >> tel;
			do {
				cout << "Ingrese Genero (M/F): ";
				cin >> gen;
			} while (gen != "M" && gen != "F");
			gen = (gen == "M") ? "1" : "0";
			cout << "Ingrese Nueva Fecha de Nacimiento (YYYY-MM-DD): ";
			cin.ignore();
			getline(cin, fn);
			cout << "Ingrese Nuevo ID del Puesto: ";
			cin >> idp;
			cout << "Ingrese Nueva Fecha de Inicio de Labores (YYYY-MM-DD): ";
			cin.ignore();
			getline(cin, fil);
			cout << "Ingrese Nueva Fecha de Ingreso (YYYY-MM-DD): ";
			getline(cin, fi);

			e.setNombres(nom);
			e.setApellidos(ape);
			e.setDireccion(dir);
			e.setTelefono(tel);
			e.setGenero(gen);
			e.setFecha_nacimiento(fn);
			e.setIdpuesto(idp);
			e.setFecha_de_ingreso(fil);
			e.setFechaingreso(fi);

			e.Actualizar();
			break;
		}
		case 4: {
			string dpi;
			cout << "Ingrese DPI del Empleado a borrar: ";
			cin.ignore();
			getline(cin, dpi);

			Empleados e;
			e.setDPI(dpi);
			e.Borrar();
			break;
		}

		}
	case 4:
		int opc;
		cout << "1-Crear, 2-Leer, 3-Actualizar, 4-Borrar" << endl;
		cout << "Que desea realizar en la BD ventas: ";
		cin >> opc;

		switch (opc) {
		case 1: {
			// Crear una nueva venta
			int nof, idc, ide;
			string ser, fef, fei;

			cout << "Ingrese el numero de factura: ";
			cin >> nof;
			cout << "Ingrese la serie: ";
			cin >> ser;
			cout << "Ingrese la fecha de factura (YYYY-MM-DD): ";
			cin >> fef;
			cout << "Ingrese el ID del cliente: ";
			cin >> idc;
			cout << "Ingrese el ID del puesto: ";
			cin >> ide;
			cout << "Ingrese la fecha de ingreso (YYYY-MM-DD): ";
			cin >> fei;

			Ventas v(nof, ser, fef, idc, ide, fei);
			v.Crear();
			break;
		}
		case 2: {
			// Leer todas las ventas
			v.Leer();
			break;
		}
		case 3: {
			// Actualizar una venta
			int nof, idc, ide;
			string ser, fef, fei;

			cout << "Ingrese el numero de factura a actualizar: ";
			cin >> nof;
			v.setNofactura(nof);

			cout << "Ingrese la nueva serie: ";
			cin >> ser;
			cout << "Ingrese la nueva fecha de factura (YYYY-MM-DD): ";
			cin >> fef;
			cout << "Ingrese el nuevo ID del cliente: ";
			cin >> idc;
			cout << "Ingrese el nuevo ID del puesto: ";
			cin >> ide;
			cout << "Ingrese la nueva fecha de ingreso (YYYY-MM-DD): ";
			cin >> fei;

			v.setSerie(ser);
			v.setFechafactura(fef);
			v.setIdcliente(idc);
			v.setIdpuesto(ide);
			v.setFechaingreso(fei);
			v.Actualizar();
			break;
		}
		case 4: {
			// Borrar una venta
			int nof;
			cout << "Ingrese el numero de factura a borrar: ";
			cin >> nof;
			v.setNofactura(nof);
			v.Borrar();
			break;
		}
		}
		case 5:
			int op;
				cout << "1. Crear Venta Detalle" << endl;
				cout << "2. Leer Venta Detalle" << endl;
				cout << "3. Actualizar Venta Detalle" << endl;
				cout << "4. Borrar Venta Detalle" << endl;
				cout << "5. Salir" << endl;
				cout << "Ingrese una opcion: ";
				cin >> op;

				switch (op) {
				case 1: {
					int idVenta, idProducto, cantidad;
					double precioUnitario;

					cout << "Ingrese ID Venta: ";
					cin >> idVenta;
					cout << "Ingrese ID Producto: ";
					cin >> idProducto;
					cout << "Ingrese Cantidad: ";
					cin >> cantidad;
					cout << "Ingrese Precio Unitario: ";
					cin >> precioUnitario;

					VentasDetalle vd(idVenta, idProducto, cantidad, precioUnitario);
					vd.Crear();
					break;
				}
				case 2:
					vd.Leer();
					break;
				case 3: {
					int idDetalle, idVenta, idProducto, cantidad;
					double precioUnitario;

					cout << "Ingrese ID Detalle: ";
					cin >> idDetalle;
					cout << "Ingrese Nuevo ID Venta: ";
					cin >> idVenta;
					cout << "Ingrese Nuevo ID Producto: ";
					cin >> idProducto;
					cout << "Ingrese Nueva Cantidad: ";
					cin >> cantidad;
					cout << "Ingrese Nuevo Precio Unitario: ";
					cin >> precioUnitario;

					VentasDetalle vd;
					vd.setIdDetalle(idDetalle);
					vd.setIdVenta(idVenta);
					vd.setIdProducto(idProducto);
					vd.setCantidad(cantidad);
					vd.setPrecioUnitario(precioUnitario);
					vd.Actualizar();
					break;
				}
				case 4: {
					int idDetalle;
					cout << "Ingrese ID Detalle a borrar: ";
					cin >> idDetalle;

					VentasDetalle vd;
					vd.setIdDetalle(idDetalle);
					vd.Borrar();
					break;
				}
					  system("pause");
					  return 0;
				}

			}
		
	}

