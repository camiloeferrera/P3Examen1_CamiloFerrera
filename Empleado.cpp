#include "Empleado.h"

Empleado::Empleado(string nombre,int edad, int nivel, double habilidad, double pereza){
	this->nombre = nombre;
	this->edad = edad;
	this->nivel = nivel;
	this->habilidad = habilidad;
	this->pereza = pereza;
}

Empleado::~Empleado(){
	
}

string Empleado::getNombre(){
	return this->nombre;
}
