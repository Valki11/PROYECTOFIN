#pragma once
#include<iostream>
using namespace std;
class Persona{
protected: string nombres, apellidos, direccion, fecha_nacimiento, genero;
		 int telefono = 0;
protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, string fn, string gen) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		genero = gen;
	}
};

