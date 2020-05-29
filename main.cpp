#include <iostream>
#include <vector>
#include "Empleado.h"
#include "Tarea.h"

using namespace std;

vector<Empleado> empleados;

int main() {
	int opcion;
	while (true){
		cout << "1. Contratar Empleado" << endl
		<< "2. Despedir Empleado" << endl
		<< "3. Listar Empleados" << endl
		<< "4. Iniciar Proyecto" << endl
		<< "5. Listar Tareas" << endl
		<< "6. Inicar Proyecto" << endl
		<< "7. Salir" << endl
		<< "Ingrese opcion: "; cin >> opcion;
		cout << endl;
		
		switch(opcion){
			case 1:{
				string nombre;
				int edad,nivel;
				double habilidad,pereza;
				
				cout << "Ingrese nombre: "; cin >> nombre;
				cout << "Ingrese edad: "; cin >> edad;
				cout << "Ingrese nivel (1-3): "; cin >> nivel;
				
				while (nivel < 1 || nivel > 3){
					cout << endl <<
					"Rango no valido..." << endl << endl
					<< "Ingrese nivel (1-3): "; cin >> nivel;
				}
				
				cout << "Ingrese porcentaje de habilidad: "; cin >> habilidad;
				cout << "Ingrese porcentaje de pereza: "; cin >> pereza;
				
				cout << endl << "Empleado contratado exitosamente!" << endl;
				empleados.push_back(Empleado(nombre,edad,nivel,habilidad,pereza));
				
				break;
			}
			case 2:{
				if (empleados.size() == 0){
					cout << "No hay empleados contratados..." << endl;
				} else {
					for (int i = 0; i < empleados.size(); i++){
						cout << (i+1) << ". " << empleados[i].getNombre() << endl;
					}
					cout << "Seleccione empleado a despedir: "; cin >> opcion;
					cout << endl;
					
					if (opcion < 1 || opcion > empleados.size()){
						cout << "Empleado no encontrado..." << endl;
					} else {
						opcion--;
						empleados.erase(empleados.begin() + opcion);
						cout << "Empleado DESPEDIDO!" << endl;
					}
					
				}
				
				break;
			}
			case 3:{
				if (empleados.size() == 0){
					cout << "No hay empleados contratados..." << endl;
				} else {
					for (int i = 0; i < empleados.size(); i++){
						cout << (i+1) << ". " << empleados[i].getNombre() << endl;
					}
				}
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				
				break;
			}
			case 6:{
				
				break;
			}
			case 7:{
				return 0;
			}
			default:{
				cout << "Opcion Incorrecta..." << endl;
				break;
			}
		}
		
		cout << endl;
	}
}
