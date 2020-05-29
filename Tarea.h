#ifndef TAREA_H
#define TAREA_H
#include <string>

using namespace std;

class Tarea
{
	public:
		Tarea(string,int,int);
		~Tarea();
	private:
		string descripcion;
		int nivel,carga;
};

#endif
