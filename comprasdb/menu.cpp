#include <iostream>
#include "Marcas.h"
#include "Proveedores.h"
#include "Compras.h"
#include "Productos.h"

using namespace std;

int main() {
    int opcion;

    while (true) {
        system("clear"); // Limpiar la pantalla

        cout << "\n\t\t\tMENÚ PRINCIPAL\n\n";
        cout << "1. Marcas\n";
        cout << "2. Proveedores\n";
        cout << "3. Productos\n";
        cout << "4. Compras\n";
        cout << "5. Salir\n";
        cout << "\nIngrese una opción: ";

        cin >> opcion;

        switch (opcion) {
        case 1:
            // Implementar la funcionalidad para la opción "Marcas"
            cout << "\nHa seleccionado la opción Marcas\n";
            while (true) {
                system("clear"); // Limpiar la pantalla

                cout << "\n\t\t\tMENÚ CRUD\n\n";
                cout << "1. Ver Marcas\n";
                cout << "2. Crear Marcas\n";
                cout << "3. Editar Marcas\n";
                cout << "4. Eliminar Marcas\n";
                cout << "5. Salir\n";
                cout << "\nIngrese una opción: ";
                cin >> opcion;

                
                int idmarca = 0;
                string marca;
                Marcas marca_ = Marcas();
                Marcas marc = Marcas(idmarca, marca);

                switch (opcion) {
                case 1:
                    marca_.leer();
                    break;
                case 2:
                    cout << "Ingrese la marca: ";
                    cin >> marca;

                    marc.setmarca(marca);
                    marc.crear();
                    break;
                case 3:
                    cout << "Ingrese el id marca: ";
                    cin >> idmarca;
                    
                    cout << "Ingrese la marca: ";
                    cin >> marca;

                    marc.setmarca(marca);
                    marc.setidmarca(idmarca);
                    marc.crear();
                    break;
                case 4:
                    cout << "Ingrese el id marca: ";
                    cin >> idmarca;

                    marc.setidmarca(idmarca);
                    marc.borrar();
                    break;
                case 5:
                    cout << "\nSaliendo del programa...\n";
                    exit(0); // Salir del programa
                default:
                    cout << "\nOpción no válida. Intente nuevamente.\n";
                }

                cin.ignore(); // Ignorar la entrada anterior (tecla Enter)
                cout << "\nPresione Enter para continuar...";
                cin.get(); // Esperar a que el usuario presione Enter
            }
            break;
        case 2:
            // Implementar la funcionalidad para la opción "Proveedores"
            cout << "\nHa seleccionado la opción Proveedores\n";
            while (true) {
                system("clear"); // Limpiar la pantalla

                cout << "\n\t\t\tMENÚ CRUD\n\n";
                cout << "1. Ver Proveedores\n";
                cout << "2. Crear Proveedores\n";
                cout << "3. Editar Proveedores\n";
                cout << "4. Eliminar Proveedores\n";
                cout << "5. Salir\n";
                cout << "\nIngrese una opción: ";
                cin >> opcion;

                int idProveedore;
                string proveedor, nit, direccion, telefono;
                Proveedores prov = Proveedores();
                Proveedores proveedores_ = Proveedores(idProveedore, proveedor, nit, direccion, telefono);


                switch (opcion) {
                case 1:
                    prov.leer();
                    break;
                case 2:
                    cout << "Ingrese el Proveedor: ";
                    cin.ignore(); // Ignorar la entrada anterior (salto de línea)
                    getline(cin, proveedor); // Leer la línea completa para nombres con espacios
                    cout << "Ingrese el NIT: ";
                    cin >> nit;
                    cout << "Ingrese la Dirección: ";
                    cin.ignore();
                    getline(cin, direccion);
                    cout << "Ingrese el Teléfono: ";
                    cin >> telefono;

                    proveedores_.setProveedor(proveedor);
                    proveedores_.setNit(nit);
                    proveedores_.setDireccion(direccion);
                    proveedores_.setTelefono(telefono);
                    proveedores_.crear();
                    break;
                case 3:
                    cout << "Ingrese el ID Proveedor: ";
                    cin >> idProveedore;
                    cout << "Ingrese el Proveedor: ";
                    cin.ignore(); // Ignorar la entrada anterior (salto de línea)
                    getline(cin, proveedor); // Leer la línea completa para nombres con espacios
                    cout << "Ingrese el NIT: ";
                    cin >> nit;
                    cout << "Ingrese la Dirección: ";
                    cin.ignore();
                    getline(cin, direccion);
                    cout << "Ingrese el Teléfono: ";
                    cin >> telefono;

                    proveedores_.setIdProveedore(idProveedore);
                    proveedores_.setProveedor(proveedor);
                    proveedores_.setNit(nit);
                    proveedores_.setDireccion(direccion);
                    proveedores_.setTelefono(telefono);
                    proveedores_.actualizar();
                    break;
                case 4:
                    cout << "Ingrese el ID Proveedor: ";
                    cin >> idProveedore;

                    proveedores_.setIdProveedore(idProveedore);
                    proveedores_.borrar();
                    break;
                case 5:
                    cout << "\nSaliendo del programa...\n";
                    exit(0); // Salir del programa
                default:
                    cout << "\nOpción no válida. Intente nuevamente.\n";
                }

                cin.ignore(); // Ignorar la entrada anterior (tecla Enter)
                cout << "\nPresione Enter para continuar...";
                cin.get(); // Esperar a que el usuario presione Enter
            }
            break;
        case 3:
            // Implementar la funcionalidad para la opción "Productos"
            cout << "\nHa seleccionado la opción Productos\n";
            while (true) {
                system("clear"); // Limpiar la pantalla

                cout << "\n\t\t\tMENÚ CRUD\n\n";
                cout << "1. Ver productos\n";
                cout << "2. Crear producto\n";
                cout << "3. Editar producto\n";
                cout << "4. Eliminar producto\n";
                cout << "5. Salir\n";
                cout << "\nIngrese una opción: ";
                cin >> opcion;

                string producto, Descripcion, Imagen, fecha_ingreso;
                int idProducto, idMarca, existencia;
                float precio_costo, precio_venta;

                Productos producto_ = Productos();
                Productos produ = Productos(idProducto, producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso);

                switch (opcion) {
                case 1:
                    producto_.leer();
                    break;
                case 2:
                    cout << "Ingrese el Producto: ";
                    getline(cin, producto); // Utilizar getline para leer líneas completas con espacios

                    cout << "Ingrese la Descripción: ";
                    getline(cin, Descripcion);

                    cout << "Ingrese la Imagen: ";
                    getline(cin, Imagen);

                    cout << "Ingrese la Fecha de ingreso (formato AAAA-MM-DD): ";
                    cin >> fecha_ingreso;

                    cout << "Ingrese el ID de marca: ";
                    cin >> idMarca;

                    cout << "Ingrese si hay Existencia: ";
                    cin >> existencia;

                    cout << "Ingrese el Precio de costo: ";
                    cin >> precio_costo;

                    cout << "Ingrese el Precio de venta: ";
                    cin >> precio_venta;

                    produ.setNombre(producto);
                    produ.setDescripcion(Descripcion);
                    produ.setImagen(Imagen);
                    produ.setFechaIngreso(fecha_ingreso);
                    produ.setIdMarca(idMarca);
                    produ.setExistencia(existencia);
                   /* produ.precio_costo(precio_costo);
                    produ.precio_venta(precio_venta);*/
                    produ.crear();
                    break;
                case 3:
                    cout << "Ingrese el ID de producto: ";
                    cin >> idProducto;

                    cout << "Ingrese el Producto: ";
                    getline(cin, producto); // Utilizar getline para leer líneas completas con espacios

                    cout << "Ingrese la Descripción: ";
                    getline(cin, Descripcion);

                    cout << "Ingrese la Imagen: ";
                    getline(cin, Imagen);

                    cout << "Ingrese la Fecha de ingreso (formato AAAA-MM-DD): ";
                    cin >> fecha_ingreso;

                    cout << "Ingrese el ID de marca: ";
                    cin >> idMarca;

                    cout << "Ingrese si hay Existencia: ";
                    cin >> existencia;

                    cout << "Ingrese el Precio de costo: ";
                    cin >> precio_costo;

                    cout << "Ingrese el Precio de venta: ";
                    cin >> precio_venta;

                    produ.setNombre(producto);
                    produ.setDescripcion(Descripcion);
                    produ.setImagen(Imagen);
                    produ.setFechaIngreso(fecha_ingreso);
                    produ.setIdMarca(idMarca);
                    produ.setExistencia(existencia);
                    produ.setIdProducto(idProducto);
                    /*produ.precio_costo(precio_costo);
                     produ.precio_venta(precio_venta);*/
                    produ.actualizar();
                    break;
                case 4:
                    cout << "Ingrese el ID de producto: ";
                    cin >> idProducto;

                    produ.setIdProducto(idProducto);
                    produ.borrar();
                    break;
                case 5:
                    cout << "\nSaliendo del programa...\n";
                    exit(0); // Salir del programa
                default:
                    cout << "\nOpción no válida. Intente nuevamente.\n";
                }

                cin.ignore(); // Ignorar la entrada anterior (tecla Enter)
                cout << "\nPresione Enter para continuar...";
                cin.get(); // Esperar a que el usuario presione Enter
            }
            break;
        case 4:
            // Implementar la funcionalidad para la opción "Compras"
            cout << "\nHa seleccionado la opción Compras\n";
            while (true) {
                system("clear"); // Limpiar la pantalla

                cout << "\n\t\t\tMENÚ CRUD\n\n";
                cout << "1. Ver Compras\n";
                cout << "2. Crear Compras\n";
                cout << "3. Editar Compras\n";
                cout << "4. Eliminar Compras\n";
                cout << "5. Salir\n";
                cout << "\nIngrese una opción: ";
                cin >> opcion;

                string fecha_orden, fechaingreso;
                int idcompra, no_orden_compra, idproveedor, idproducto, cantidad;
                float precio_costo_unitario;

                Compras compras_ = Compras();
                Compras comp = Compras(idcompra, no_orden_compra, idproveedor, fecha_orden, fechaingreso, idproducto, cantidad, precio_costo_unitario);

                switch (opcion) {
                case 1:
                    compras_.leer();
                    break;
                case 2:
                    cout << "Ingresa la Fecha de orden (formato AAAA-MM-DD): ";
                    getline(cin, fecha_orden); // Utilizar getline para leer líneas completas

                    cout << "Ingresa la Fecha de ingreso (formato AAAA-MM-DD): ";
                    getline(cin, fechaingreso);

                    cout << "Ingresa el Número de orden de compra: ";
                    cin >> no_orden_compra;

                    cout << "Ingresa el ID de proveedor: ";
                    cin >> idproveedor;

                    cout << "Ingresa el ID de producto: ";
                    cin >> idproducto;

                    cout << "Ingresa la Cantidad: ";
                    cin >> cantidad;

                    cout << "Ingresa el Precio de costo unitario: ";
                    cin >> precio_costo_unitario;

                    comp.setFechaOrden(fecha_orden);
                    comp.setFechaIngreso(fechaingreso);
                    comp.setNoOrdenCompra(no_orden_compra);
                    comp.setIdProveedor(idproveedor);
                    comp.setIdProducto(idproducto);
                    comp.setCantidad(cantidad);
                    comp.setPrecioCostoUnitario(precio_costo_unitario);
                    comp.crear();
                    break;
                case 3:
                    cout << "Ingrese el ID de compra: ";
                    cin >> idcompra;

                    cout << "Ingresa la Fecha de orden (formato AAAA-MM-DD): ";
                    getline(cin, fecha_orden); // Utilizar getline para leer líneas completas

                    cout << "Ingresa la Fecha de ingreso (formato AAAA-MM-DD): ";
                    getline(cin, fechaingreso);

                    cout << "Ingresa el Número de orden de compra: ";
                    cin >> no_orden_compra;

                    cout << "Ingresa el ID de proveedor: ";
                    cin >> idproveedor;

                    cout << "Ingresa el ID de producto: ";
                    cin >> idproducto;

                    cout << "Ingresa la Cantidad: ";
                    cin >> cantidad;

                    cout << "Ingresa el Precio de costo unitario: ";
                    cin >> precio_costo_unitario;

                    comp.setIdCompra(idcompra);
                    comp.setFechaOrden(fecha_orden);
                    comp.setFechaIngreso(fechaingreso);
                    comp.setNoOrdenCompra(no_orden_compra);
                    comp.setIdProveedor(idproveedor);
                    comp.setIdProducto(idproducto);
                    comp.setCantidad(cantidad);
                    comp.setPrecioCostoUnitario(precio_costo_unitario);
                    comp.actualizar();
                    break;
                case 4:
                    cout << "Ingrese el ID de compra: ";
                    cin >> idcompra;

                    cout << "Ingresa el ID de producto: ";
                    cin >> idproducto;

                    comp.setIdCompra(idcompra);
                    comp.setIdProducto(idproducto);
                    comp.borrar()
                    break;
                case 5:
                    cout << "\nSaliendo del programa...\n";
                    exit(0); // Salir del programa
                default:
                    cout << "\nOpción no válida. Intente nuevamente.\n";
                }

                cin.ignore(); // Ignorar la entrada anterior (tecla Enter)
                cout << "\nPresione Enter para continuar...";
                cin.get(); // Esperar a que el usuario presione Enter
            }
            break;
        case 5:
            cout << "\nSaliendo del programa...\n";
            exit(0); // Salir del programa
        default:
            cout << "\nOpción no válida. Intente nuevamente.\n";
        }

        cin.ignore(); // Ignorar la entrada anterior (tecla Enter)
        cout << "\nPresione Enter para continuar...";
        cin.get(); // Esperar a que el usuario presione Enter
    }

    return 0;
}
