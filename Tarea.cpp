#include "Tarea.h"

Tarea::Tarea(string descripcion, int nivel, int carga){
	this->descripcion = descripcion;
	this->nivel = nivel;
	this->carga = carga;
	this->disponible = true;
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
bool Tarea::isDisponible(){
	return this->disponible;
}

void Tarea::restarCarga(){
	this->carga--;
}

void Tarea::setDisponible(bool disponible){
	this->disponible = disponible;
}
