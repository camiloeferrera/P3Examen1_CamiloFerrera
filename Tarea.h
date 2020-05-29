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
		void restarCarga();
	private:
		string descripcion;
		int nivel,carga;
};

#endif
