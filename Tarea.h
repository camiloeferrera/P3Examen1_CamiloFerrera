#ifndef TAREA_H
#define TAREA_H
#include <string>

using namespace std;

class Tarea
{
	public:
		Tarea(string,int,int);
		~Tarea();
		
		string getDescripcion();
		int getNivel();
		int getCarga();
		bool isDisponible();
		void restarCarga();
		void setDisponible(bool);
		
	private:
		string descripcion;
		int nivel,carga;
		bool disponible;
};

#endif
