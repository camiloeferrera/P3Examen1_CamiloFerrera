#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

using namespace std;

class Empleado
{
	public:
		Empleado(string,int,int,double,double);
		~Empleado();
		
		string getNombre();
		int getNivel();
		double getHabilidad();
		double getPereza();
	private:
		string nombre;
		int edad,nivel;
		double habilidad,pereza;
};

#endif
