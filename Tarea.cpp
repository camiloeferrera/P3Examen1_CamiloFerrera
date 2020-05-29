#include "Tarea.h"

Tarea::Tarea(string descripcion, int nivel, int carga){
	this->descripcion = descripcion;
	this->nivel = nivel;
	this->carga = carga;
}
Tarea::~Tarea(){
}

string Tarea::getDescripcion(){
	return this->descripcion;
}
int Tarea::getNivel(){
	return this->nivel;
}
int Tarea::getCarga(){
	return this->carga;
}

void Tarea::restarCarga(){
	this->carga--;
}
