Manual de Usuario para la Gestión de Base de Datos de Supermercado
Índice
Introducción
Requisitos Previos
Gestión de Clientes
Gestión de Productos
Gestión de Ventas y Ventas_detalle
Gestión de Compras y Compras_detalle
Conclusiones
1. Introducción
Este manual está diseñado para ayudar a los usuarios a gestionar una base de datos de un supermercado mediante la creación y manipulación de tablas usando operaciones CRUD (Crear, Leer, Actualizar, Eliminar). Abordaremos la gestión de clientes, productos, ventas y detalles de ventas, compras y detalles de compras.

2. Requisitos Previos
Antes de comenzar, asegúrate de tener lo siguiente:

Un sistema de gestión de bases de datos (DBMS) como MySQL, PostgreSQL o SQL Server.
Herramientas de gestión de bases de datos como phpMyAdmin, DBeaver, o pgAdmin.
Conocimientos básicos de SQL.
3. Gestión de Clientes
La tabla Clientes almacena información sobre los clientes del supermercado.

Estructura de la Tabla Clientes
Campo	Tipo de Dato	Descripción
id_cliente	INT	Identificador único
nombre	VARCHAR	Nombre del cliente
direccion	VARCHAR	Dirección del cliente
telefono	VARCHAR	Teléfono del cliente
email	VARCHAR	Correo electrónico
Crear (Insertar un Cliente)
sql
Copiar código
INSERT INTO Clientes (nombre, direccion, telefono, email)
VALUES ('Juan Perez', 'Calle Falsa 123', '555-1234', 'juanperez@example.com');
Leer (Consultar Clientes)
sql
Copiar código
SELECT * FROM Clientes;
Actualizar (Modificar un Cliente)
sql
Copiar código
UPDATE Clientes
SET direccion = 'Calle Verdadera 456', telefono = '555-5678'
WHERE id_cliente = 1;
Eliminar (Borrar un Cliente)
sql
Copiar código
DELETE FROM Clientes
WHERE id_cliente = 1;
4. Gestión de Productos
La tabla Productos almacena información sobre los productos disponibles en el supermercado.

Estructura de la Tabla Productos
Campo	Tipo de Dato	Descripción
id_producto	INT	Identificador único
nombre	VARCHAR	Nombre del producto
descripcion	VARCHAR	Descripción del producto
precio	DECIMAL	Precio del producto
stock	INT	Cantidad en stock
Crear (Insertar un Producto)
sql
Copiar código
INSERT INTO Productos (nombre, descripcion, precio, stock)
VALUES ('Leche', 'Leche descremada 1L', 1.50, 100);
Leer (Consultar Productos)
sql
Copiar código
SELECT * FROM Productos;
Actualizar (Modificar un Producto)
sql
Copiar código
UPDATE Productos
SET precio = 1.75, stock = 150
WHERE id_producto = 1;
Eliminar (Borrar un Producto)
sql
Copiar código
DELETE FROM Productos
WHERE id_producto = 1;
5. Gestión de Ventas y Ventas_detalle
Las tablas Ventas y Ventas_detalle se usan para registrar las ventas realizadas.

Estructura de la Tabla Ventas
Campo	Tipo de Dato	Descripción
id_venta	INT	Identificador único
id_cliente	INT	Identificador del cliente
fecha	DATE	Fecha de la venta
total	DECIMAL	Total de la venta
Estructura de la Tabla Ventas_detalle
Campo	Tipo de Dato	Descripción
id_detalle	INT	Identificador único
id_venta	INT	Identificador de la venta
id_producto	INT	Identificador del producto
cantidad	INT	Cantidad vendida
precio	DECIMAL	Precio del producto
subtotal	DECIMAL	Subtotal (cantidad * precio)
Crear (Insertar una Venta y sus Detalles)
Primero, insertar la venta en la tabla Ventas:

sql
Copiar código
INSERT INTO Ventas (id_cliente, fecha, total)
VALUES (1, '2023-06-01', 30.00);
Luego, insertar los detalles en la tabla Ventas_detalle:

sql
Copiar código
INSERT INTO Ventas_detalle (id_venta, id_producto, cantidad, precio, subtotal)
VALUES (1, 1, 2, 15.00, 30.00);
Leer (Consultar Ventas y Detalles de Ventas)
Para consultar todas las ventas:

sql
Copiar código
SELECT * FROM Ventas;
Para consultar los detalles de una venta específica:

sql
Copiar código
SELECT * FROM Ventas_detalle
WHERE id_venta = 1;
Actualizar (Modificar una Venta y sus Detalles)
Primero, actualizar la venta en la tabla Ventas:

sql
Copiar código
UPDATE Ventas
SET total = 35.00
WHERE id_venta = 1;
Luego, actualizar los detalles en la tabla Ventas_detalle:

sql
Copiar código
UPDATE Ventas_detalle
SET cantidad = 3, subtotal = 45.00
WHERE id_detalle = 1;
Eliminar (Borrar una Venta y sus Detalles)
Primero, borrar los detalles de la venta en la tabla Ventas_detalle:

sql
Copiar código
DELETE FROM Ventas_detalle
WHERE id_venta = 1;
Luego, borrar la venta en la tabla Ventas:

sql
Copiar código
DELETE FROM Ventas
WHERE id_venta = 1;
6. Gestión de Compras y Compras_detalle
Las tablas Compras y Compras_detalle se usan para registrar las compras realizadas.

Estructura de la Tabla Compras
Campo	Tipo de Dato	Descripción
id_compra	INT	Identificador único
id_proveedor	INT	Identificador del proveedor
fecha	DATE	Fecha de la compra
total	DECIMAL	Total de la compra
Estructura de la Tabla Compras_detalle
Campo	Tipo de Dato	Descripción
id_detalle	INT	Identificador único
id_compra	INT	Identificador de la compra
id_producto	INT	Identificador del producto
cantidad	INT	Cantidad comprada
precio	DECIMAL	Precio del producto
subtotal	DECIMAL	Subtotal (cantidad * precio)
Crear (Insertar una Compra y sus Detalles)
Primero, insertar la compra en la tabla Compras:

sql
Copiar código
INSERT INTO Compras (id_proveedor, fecha, total)
VALUES (1, '2023-06-01', 500.00);
Luego, insertar los detalles en la tabla Compras_detalle:

sql
Copiar código
INSERT INTO Compras_detalle (id_compra, id_producto, cantidad, precio, subtotal)
VALUES (1, 1, 10, 50.00, 500.00);
Leer (Consultar Compras y Detalles de Compras)
Para consultar todas las compras:

sql
Copiar código
SELECT * FROM Compras;
Para consultar los detalles de una compra específica:

sql
Copiar código
SELECT * FROM Compras_detalle
WHERE id_compra = 1;
Actualizar (Modificar una Compra y sus Detalles)
Primero, actualizar la compra en la tabla Compras:

sql
Copiar código
UPDATE Compras
SET total = 550.00
WHERE id_compra = 1;
Luego, actualizar los detalles en la tabla Compras_detalle:

sql
Copiar código
UPDATE Compras_detalle
SET cantidad = 11, subtotal = 550.00
WHERE id_detalle = 1;
Eliminar (Borrar una Compra y sus Detalles)
Primero, borrar los detalles de la compra en la tabla Compras_detalle:

sql
Copiar código
DELETE FROM Compras_detalle
WHERE id_compra = 1;
Luego, borrar la compra en la tabla Compras:

sql
Copiar código
DELETE FROM Compras
WHERE id_compra = 1;
7. Conclusiones
Este manual proporciona una guía completa para gestionar una base de datos de supermercado, incluyendo las operaciones CRUD para las tablas más comunes. Siguiendo estos pasos, podrás administrar eficientemente la información de clientes, productos, ventas y compras en tu sistema de base de datos.
