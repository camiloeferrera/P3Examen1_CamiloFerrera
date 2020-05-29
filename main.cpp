#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include "Empleado.h"
#include "Tarea.h"

using namespace std;

void Simulacion();

vector<Empleado> empleados;
vector<Tarea> backlog;

int main() {
	empleados.push_back(Empleado("camilo",20,3,90,10));
	empleados.push_back(Empleado("juda",20,2,80,20));
	empleados.push_back(Empleado("paulina",20,1,70,30));
	
	int opcion;
	while (true){
		cout << "1. Contratar Empleado" << endl
		<< "2. Despedir Empleado" << endl
		<< "3. Listar Empleados" << endl
		<< "4. Crear Tarea" << endl
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
					cout << endl 
					<< "Rango no valido..." << endl << endl
					<< "Ingrese nivel (1-3): "; cin >> nivel;
				}
				
				cout << "Ingrese porcentaje de habilidad: "; cin >> habilidad;
				cout << "Ingrese porcentaje de pereza: "; cin >> pereza;
				
				empleados.push_back(Empleado(nombre,edad,nivel,habilidad,pereza));
				cout << endl << "Empleado contratado exitosamente!" << endl;
				
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
						cout << (i+1) << ". Nombre: " << empleados[i].getNombre() << ", Nivel: " << empleados[i].getNivel() << ", Porcentaje de Habilidad: " << empleados[i].getHabilidad() << "%, Porcentaje de Pereza: " << empleados[i].getPereza() << "%" << endl;
					}
				}
				break;
			}
			case 4:{
				string descripcion;
				int nivel,carga;
				cout << "Ingrese descripcion: "; cin >> descripcion;
				cout << "Ingrese nivel (1-3): "; cin >> nivel;
				
				while (nivel < 1 || nivel > 3){
					cout << endl
					<< "Rango no valido..." << endl << endl
					<< "Ingrese nivel (1-3): "; cin >> nivel;
				}
				
				cout << "Ingrese carga de tarea: "; cin >> carga;
				
				while (carga <= 0){
					cout << endl
					<< "La carga debe ser mayor que 0..." << endl << endl
					<< "Ingrese carga de tarea: "; cin >> carga;
				}
				
				backlog.push_back(Tarea(descripcion,nivel,carga));
				cout << endl << "Tarea agregada exitosamente al backlog!" << endl;
				
				break;
			}
			case 5:{
				if (backlog.size() == 0){
					cout << "No hay tareas agregadas al backlog..." << endl;
				} else {
					for (int i = 0; i < backlog.size(); i++){
						cout << (i+1) << ". Descripcion: " << backlog[i].getDescripcion() << ", Nivel: " << backlog[i].getNivel() << ", Carga: " << backlog[i].getCarga() << " dias" << endl;
					}
				}
				
				break;
			}
			case 6:{
				if (backlog.size() == 0){
					cout << "No hay tareas creadas para iniciar el proyecto." << endl;
				}
				if (empleados.size() == 0){
					cout << "No hay empleados contratados para iniciar el proyecto." << endl;
				}
				
				if (backlog.size() != 0 && empleados.size() != 0){
					Simulacion();
				}
				
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

void Simulacion(){
	int opcion,n = 0;
	
	for (int i = 0; i < backlog.size(); i++){
		n += backlog[i].getCarga();
	}
	
	double dias_esperados = n + n*0.20;
	
	int tareas_en_progreso = 0, empleados_perezosos = 0 , empleados_fallidos = 0, empleados_exitosos = 0;
	
	while (true){
		if(backlog.size() == 0){
			cout << "PROYECTO TERMINADO" << endl;
		}								
		cout << "Dias para terminar el proyecto: " << n << endl << endl
		<< "1. Siguiente dia" << endl
		<< "2. Generar Reporte" << endl
		<< "3. Salir" << endl
		<< "Ingrese opcion: "; cin >> opcion;
		cout << endl;
		
		switch (opcion){
			case 1:{
				tareas_en_progreso = 0;
			    empleados_perezosos = 0;
				empleados_fallidos = 0;
				empleados_exitosos = 0;
				
				for (int i = 0; i < empleados.size(); i++){
					for (int j = 0; j < backlog.size(); j++){
						if (backlog[i].isDisponible() == true){
							if (empleados[i].getNivel() >= backlog[i].getNivel()){
								srand((int)time(0));
								int hint = rand() % 100;
								
								backlog[i].setDisponible(false);
								
								if (empleados[i].getPereza() < hint){
									if (empleados[i].getHabilidad() >= hint){
										empleados_exitosos++;
										
										backlog[i].restarCarga();
										if (backlog[i].getCarga() == 0){
											backlog.erase(backlog.begin()+j);	
										}
										
										
									} else {
										empleados_fallidos++;
									}
								} else {
									empleados_perezosos++;
								}
								
								tareas_en_progreso++;
							}
							break;
						}
							
					}
				}
				cout << endl;
				n--;
				
				for (int i = 0; i < backlog.size(); i++){
					backlog[i].setDisponible(true);
				}
				
				break;
			}
			case 2:{
				cout << "Tareas en el backlog: " << backlog.size() << endl
				<< "Tareas en progreso: " << tareas_en_progreso << endl
				<< "Empleados perezosos: " << empleados_perezosos << endl
				<< "Empleados que fallaron: " << empleados_fallidos << endl
				<< "Empleados que lograron el dia: " << empleados_exitosos << endl;
				break;
			}
			case 3:{
				
				break;
			}
			default:{
				cout << "Opcion Incorrecta..." << endl;
				break;
			}
		}
		
		if (opcion == 3){
			break;
		} else {
			cout << endl;
		}
		
	}
}

