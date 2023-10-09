#include <iostream>
#include <deque>
#include "Puerta.h"
#include "Torre_Control.h"
#include "Vehiculos_Aereos.h"
#include "Vuelo.h"
#include "Persona.h"
#include "Horas.h"
#include "Fecha.h"
#include "Pasajero.h"
#include "M_Tripulacion.h"
#include <windows.h>

using namespace std;
void Accion_Pasajero(Torre_Control* torre_control, deque<Pasajero*>& personas);
void Accion_Areolinea(Torre_Control* torre_control);
Torre_Control* Torre_De_Control = new Torre_Control();

int main(){
	
	system("cls");
	int seleccion1 = 0;
	bool salida = false, Cliente = false, Tripulacion = false;
	deque<Pasajero*> Pasajeros_Registrados;

	while(!salida){
		cout << "Bienvenido al areopuerto Alfonso Bonilla Aragon\nSeleccione la opcion de su preferencia:" << endl;
		cout << "1. Ingresar como pasajero." << endl;
		cout << "2. Ingresar como areolinea." << endl;
		cout << "3. Consultar informacion de vuelos." << endl;
		cout << "4. Ingresar como propietario de Jet Privado" << endl;
		cout << "0. Salir" << endl;
		cin >> seleccion1;
		switch(seleccion1){
			case 1:
				Accion_Pasajero(Torre_De_Control, Pasajeros_Registrados);
				break;
			case 2:
				Accion_Areolinea(Torre_De_Control);
				break;
			case 3:
				Torre_De_Control->Show_Vuelos("All", "Na");
				break;
			case 4:
				break;
			case 0:
				salida = true;
				break;
			default:
				break;
		}

	}	
	delete Torre_De_Control;
	return 0;
}

void Accion_Pasajero(Torre_Control* torre_control, deque<Pasajero*>& personas){

	bool salida = false;
	int seleccion, id, telefono, noMaletas, sel2, Id_Vuelo, dia, mes, agno;
	Pasajero* Pasajero_Tmp = nullptr;
	Fecha* fecha = nullptr;
	string tipo, nombre, fechaNacimiento, direccion, correo, nacionalidad, infoMedica, destino;
	char genero;
	while(!salida){
		system("cls");
		cout << "MODULO DE PASAJERO\nSeleccione la opcion de su preferencia:" << endl;
		cout << "1. Registrar pasajero." << endl;
		cout << "2. Ver todos los vuelos." << endl;
		cout << "3. Ver los vuelos por filtro de fecha" << endl;
		cout << "4. Ver todos los vuelos por filtro de destino" << endl;
		cout << "0. Salir" << endl;
		cin >> seleccion;
		switch(seleccion){
			case 1:
				tipo = "Pasajero";
				cout << "Ingrese su ID: ";
				cin >> id;
				cout << "Ingrese su nombre: "; 
				cin >> nombre;
				cout << "Ingrese su fecha de nacimiento: "; 
				cin >> fechaNacimiento;
				cout << "Ingrese su genero (M/F): "; 
				cin >> genero;
				cout << "Ingrese su direccion: "; 
				cin >> direccion;
				cout << "Ingrese su telefono: "; 
				cin >> telefono;
				cout << "Ingrese su correo: "; 
				cin >> correo;
				cout << "Ingrese su nacionalidad: "; 
				cin >> nacionalidad;
				cout << "Ingrese su numero de maletas: "; 
				cin >> noMaletas;
				cout << "Ingrese su informacion medica: "; 
				cin >> infoMedica;
				Pasajero_Tmp = new Pasajero(tipo, id, nombre, fechaNacimiento, genero, direccion, telefono, correo, nacionalidad, noMaletas, infoMedica);
				personas.push_back(Pasajero_Tmp);
				break;
			case 2:
				if(personas.empty()){
					cout << "Aun no hay un cliente registrado en el areopuerto" << endl;
					Sleep(3000);
				}
				else{
					torre_control->Show_Vuelos("Avion", "Comercial");
					cout << "\nDesea reservar comprar un tiquete para alguno de los vuelos?\n1. Si.\n2.No" << endl;
					cin >> sel2;
					if(sel2 == 1){
						cout << "Indique el ID del vuelo que desea comprar  (Ponga un Id correcto)" << endl;
						cin >> Id_Vuelo;
						torre_control->Buy_Vuelos_D(Id_Vuelo);
					}
				}
				break;
			case 3:
				if(personas.empty()){
					cout << "Aun no hay un cliente registrado en el areopuerto" << endl;
					Sleep(3000);
				}
				else{
					cout << "\nPara que fecha desea hacer una busqueda?" << endl;
					cin >> dia >> mes >> agno;
					fecha = new Fecha(dia, mes, agno);
					torre_control->Show_Vuelos_Fecha(fecha);
					cout << "\nDesea reservar comprar un tiquete para alguno de los vuelos?\n1. Si.\n2.No" << endl;
					cin >> sel2;
					if(sel2 == 1){
						cout << "Indique el ID del vuelo que desea comprar (Ponga un Id correcto)" << endl;
						cin >> Id_Vuelo;
						torre_control->Buy_Vuelos_D(Id_Vuelo);
					}
				}
				break;
			case 4:
				if(personas.empty()){
					cout << "Aun no hay un cliente registrado en el areopuerto" << endl;
					Sleep(3000);
				}
				else{
					cout << "\nPara que destino desea hacer una busqueda?" << endl;
					cin >> destino;
					torre_control->Show_Vuelos_Destino(destino);
					cout << "\nDesea reservar comprar un tiquete para alguno de los vuelos?\n1. Si.\n2.No" << endl;
					cin >> sel2;
					if(sel2 == 1){
						cout << "Indique el ID del vuelo que desea comprar (Ponga un Id correcto)" << endl;
						cin >> Id_Vuelo;
						torre_control->Buy_Vuelos_D(Id_Vuelo);
					}
				}
				break;
			case 0:
				salida = true;
				main();
				break;
			default:
				break;
		}
	}
	
}

void Accion_Areolinea(Torre_Control* torre_control){
	system("cls");
	bool salida = false;
	int seleccion, noIdentificacion, dia, mes, agno, sel2;
	string origen, destino;
	Fecha* fecha = nullptr;
	Vuelo* vuelo = nullptr;
	while(!salida){
		cout << "MODULO DE AREOLINEA\nSeleccione la opcion de su preferencia:" << endl;
		cout << "1. Ver todas las areonaves disponibles." << endl;
		cout << "2. Crear un vuelo y asignarlo a un vuelo" << endl;
		cout << "3. Ver todos los vuelos.";
		cout << "4. Eliminar un vuelo." << endl;
		cout << "0. Salir" << endl;
		cin >> seleccion;
		switch(seleccion){
			case 1:
				cout << "Estos son las areonaves registradas en el areopuerto: ";
				torre_control->show_Vehiculos();
				break;
			case 2:
				cout << "Estos son las areonaves registradas en el areopuerto: ";
				torre_control->show_Vehiculos();
				cout << "Desea registrar un vuelo para:\n1. Un avion.\n2. Un helicoptero." << endl;
				cin >> sel2;
				switch(sel2){
					case 1:
						cout << "Ingrese el numero de identificacion del avion: ";
					    cin >> noIdentificacion;
					    cout << "Ingrese la fecha de salida (dia mes agno): ";
					    cin >> dia >> mes >> agno;
					    cout << "Ingrese el origen: ";
					    cin.ignore();
					    getline(cin, origen);
					    cout << "Ingrese el destino: ";
					    getline(cin, destino);
					    fecha = new Fecha(dia, mes, agno);
					    vuelo = new Vuelo(noIdentificacion, *fecha, origen, destino);
					    torre_control->Set_Vuelos(vuelo, "Avion");
					    break;
					case 2:
						cout << "Ingrese el numero de identificacion del helicoptero: ";
					    cin >> noIdentificacion;
					    cout << "Ingrese la fecha de salida (dia mes agno): ";
					    cin >> dia >> mes >> agno;
					    cout << "Ingrese el origen: ";
					    cin.ignore();
					    getline(cin, origen);
					    cout << "Ingrese el destino: ";
					    getline(cin, destino);
					    fecha = new Fecha(dia, mes, agno);
					    vuelo = new Vuelo(noIdentificacion, *fecha, origen, destino);
					    torre_control->Set_Vuelos(vuelo, "Helicoptero");
						break;
				}
				break;
			case 3:
				break;
			case 4:
				break;
			case 0:
				salida = true;
				main();
				break;
			default:
				break;
		}
	}
	
}

