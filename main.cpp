#include <iostream>
#include <deque>
#include "Puerta.h"
#include "Torre_Control.h"
#include "Vehiculos_Aereos.h"
#include "Vuelo.h"
#include "Persona.h"
#include "Fecha.h"
#include "Pasajero.h"
#include "Horas.h"
#include <windows.h>

using namespace std;
void Accion_Pasajero(Torre_Control* torre_control, deque<Pasajero*>& personas);
void Accion_Areolinea(Torre_Control* torre_control);
void Accion_Areopuerto(Torre_Control* torre_control);
Torre_Control* Torre_De_Control = new Torre_Control();
Horas* Referencia = new Horas(0, 0);
Fecha* Hoy = new Fecha();
Horas* Ahora= new Horas();

int main(){
	system("cls");
	int seleccion1 = 0;
	bool salida = false, Cliente = false, Tripulacion = false;
	deque<Pasajero*> Pasajeros_Registrados;
	while(!salida){
		if(Ahora == Referencia){
			Hoy->AddDia();
		}
		Ahora->Add_Min();
		Hoy->Show_Fecha();
		Ahora->Show_Hora();
		printf("\n");
		cout << "Bienvenido al areopuerto Alfonso Bonilla Aragon\nSeleccione la opcion de su preferencia:" << endl;
		cout << "1. Ingresar como pasajero." << endl;
		cout << "2. Ingresar como areolinea." << endl;
		cout << "3. Consultar informacion de vuelos." << endl;
		cout << "4. Ver informacion de puertas." << endl;
		cout << "5. Editar informacion de areopueto" << endl;
		cout << "0. Salir" << endl;
		cout << "\n";
		Torre_De_Control->Show_Notificaciones(Hoy, Ahora);
		cin >> seleccion1;
		switch(seleccion1){
			case 1:
				Accion_Pasajero(Torre_De_Control, Pasajeros_Registrados);
				break;
			case 2:
				Accion_Areolinea(Torre_De_Control);
				break;
			case 3:
				Torre_De_Control->Show_Vuelos("All", "Na", false);
				break;
			case 4:
				Torre_De_Control->Show_Puertas_Embarque();
				break;
			case 5:
				Accion_Areopuerto(Torre_De_Control);
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
		if(Ahora == Referencia){
			Hoy->AddDia();
		}
		Ahora->Add_Min();
		Hoy->Show_Fecha();
		Ahora->Show_Hora();
		printf("\n");
		cout << "MODULO DE PASAJERO\nSeleccione la opcion de su preferencia:" << endl;
		cout << "1. Registrar pasajero." << endl;
		cout << "2. Ver todos los vuelos." << endl;
		cout << "3. Ver los vuelos por filtro de fecha" << endl;
		cout << "4. Ver todos los vuelos por filtro de destino" << endl;
		cout << "0. Salir" << endl;
		cin >> seleccion;
		switch(seleccion){
			case 1:
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
				Pasajero_Tmp = new Pasajero(id, nombre, fechaNacimiento, genero, direccion, telefono, correo, nacionalidad, noMaletas, infoMedica);
				personas.push_back(Pasajero_Tmp);
				break;
			case 2:
				if(personas.empty()){
					cout << "Aun no hay un cliente registrado en el areopuerto" << endl;
					Sleep(3000);
				}
				else{
					torre_control->Show_Vuelos("Avion", "Comercial", false);
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
				cout << "Entrada invalida" << endl;
				break;
		}
	}
	
}

void Accion_Areolinea(Torre_Control* torre_control){
	system("cls");
	
	bool salida = false;
	int seleccion, noIdentificacion, dia, mes, agno, sel2, sel3, i, tam, id, telefono, exp, horasMax;
	string origen, destino, nombre, fechaNacimiento, direccion, correo, puesto;
	char genero;
	Fecha* fecha = nullptr;
	Vuelo* vuelo = nullptr;
	M_Tripulacion* tripu = nullptr;
	deque<M_Tripulacion*> tripulacion;
	while(!salida){
		if(Ahora == Referencia){
			Hoy->AddDia();
		}
		Ahora->Add_Min();
		Hoy->Show_Fecha();
		Ahora->Show_Hora();
		printf("\n");
		cout << "MODULO DE AREOLINEA\nSeleccione la opcion de su preferencia:" << endl;
		cout << "1. Ver todas las areonaves disponibles." << endl;
		cout << "2. Crear un vuelo y asignarlo a un vuelo" << endl;
		cout << "3. Ver todos los vuelos." << endl;
		cout << "4. Eliminar un vuelo." << endl;
		cout << "0. Salir" << endl;
		cin >> seleccion;
		switch(seleccion){
			case 1:
				cout << "Estos son las areonaves registradas en el areopuerto: ";
				torre_control->show_Vehiculos();
				break;
			case 2:
				cout << "Desea registrar un vuelo para:\n1. Un avion.\n2. Un helicoptero." << endl;
				cin >> sel2;
				switch(sel2){
					case 1:
						cout << "Ingrese el numero de identificacion del vuelo: ";
					    cin >> noIdentificacion;
					    cout << "Ingrese la fecha de salida (dia mes agno): ";
					    cin >> dia >> mes >> agno;
					    cout << "Ingrese el origen: ";
					    cin.ignore();
					    getline(cin, origen);
					    cout << "Ingrese el destino: ";
					    getline(cin, destino);
					    fecha = new Fecha(dia, mes, agno);
					    cout << "Desea agregar Tripulacion en este momento?\n1. Si.\n2. No." << endl;
					    cin >> sel3;
					    switch(sel3){
					    	case 1:
					    		cout << "Cuanta tripulacion desea agregar a este vuelo?" << endl;
					    		cin >> tam;
					    		i = 0;
					    		while(i < tam){
					    			system("cls");
					    			cout << "Porfavor indique la siguiente informacion para el miembro de la tripulacion No. " << i + 1 << endl;
					    			cout << "ID: ";
					    			cin >> id;
					    			cin.ignore();
					    			cout << "Nombre: ";
					    			getline(cin, nombre);
					    			cout << "Fecha de Nacimiento (dd/mm/aaaa): ";
					    			getline(cin, fechaNacimiento);
					    			cout << "Genero (M/F): ";
					    			cin >> genero;
					    			cin.ignore();
					    			cout << "Direccion: ";
					    			getline(cin, direccion);
					    			cout << "Telefono: ";
					    			cin >> telefono;
					    			cin.ignore();
					    			cout << "Correo: ";
					    			getline(cin, correo);
					    			cout << "Puesto: ";
					    			getline(cin, puesto);
					    			cout << "Experiencia (agnos): ";
					    			cin >> exp;
					    			cout << "Horas Maximas: ";
					    			cin >> horasMax;
					    			tripu = new M_Tripulacion(id, nombre, fechaNacimiento, genero, direccion, telefono, correo, puesto, exp, horasMax);
					    			tripulacion.push_back(tripu);
					    			i++;
					    		}
					    	break;
					    	case 2:
					    		cout << "Entendido" << endl;
					    		break;
					    	default:
					    		cout << "Valor invalido" << endl;
					    		break;
					    }
					    vuelo = new Vuelo(noIdentificacion, *fecha, origen, destino, tripulacion);
					    torre_control->Set_Vuelos(vuelo, "Avion");
					    torre_control->setPuertas_Embarque(vuelo);
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
					    cout << "Desea agregar Tripulacion en este momento?\n1. Si.\n2. No." << endl;
					    cin >> sel3;
					    switch(sel3){
					    	case 1:
					    		cout << "Cuanta tripulacion desea agregar a este vuelo?" << endl;
					    		cin >> tam;
					    		i = 0;
					    		while(i < tam){
					    			system("cls");
					    			cout << "Porfavor indique la siguiente informacion para el miembro de la tripulacion No. " << i + 1 << endl;
					    			cout << "ID: ";
					    			cin >> id;
					    			cin.ignore();
					    			cout << "Nombre: ";
					    			getline(cin, nombre);
					    			cout << "Fecha de Nacimiento (dd/mm/aaaa): ";
					    			getline(cin, fechaNacimiento);
					    			cout << "Género (M/F): ";
					    			cin >> genero;
					    			cin.ignore();
					    			cout << "Direccion: ";
					    			getline(cin, direccion);
					    			cout << "Telefono: ";
					    			cin >> telefono;
					    			cin.ignore();
					    			cout << "Correo: ";
					    			getline(cin, correo);
					    			cout << "Puesto: ";
					    			getline(cin, puesto);
					    			cout << "Experiencia (agnos): ";
					    			cin >> exp;
					    			cout << "Horas Maximas: ";
					    			cin >> horasMax;
					    			tripu = new M_Tripulacion(id, nombre, fechaNacimiento, genero, direccion, telefono, correo, puesto, exp, horasMax);
					    			tripulacion.push_back(tripu);
					    			i++;
					    		}
					    	break;
					    	case 2:
					    		cout << "Entendido" << endl;
					    		break;
					    	default:
					    		cout << "Valor invalido" << endl;
					    		break;
					    }
					    vuelo = new Vuelo(noIdentificacion, *fecha, origen, destino, tripulacion);
					    torre_control->Set_Vuelos(vuelo, "Helicoptero");
						break;
						default:
							cout << "Valor invalido" << endl;
							break;
				}

				break;
			case 3:
				torre_control->Show_Vuelos("All", "Na", true);
				break;
			case 4:
				torre_control->Show_Vuelos("All", "Na", false);
				cout << "Ingrese el codigo del vuelo que desea eliminar" << endl;
				cin >> sel2;
				torre_control->Elim_Vuelo(sel2);
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

void Accion_Areopuerto(Torre_Control* torre_control){
	int num = 0, id_tmp, num_areonaves, tmp = 0, Num_Asientos_tmp, velo_max_tmp, autonomia_tmp, agno_tmp, altura_max_tmp, no_motores_tmp, no_rotores_tmp, capa_elevacion_tmp;
	string disponibilidad_tmp, ubicacion_tmp, marca_tmp, modelo_tmp, estado_tmp, propietario_tmp, cat_tmp, uso_tmp, tipo;
	bool asignado_tmp, admitido = false;
	Avion* Avion_tmp = nullptr;
	Jet_Privado* Jet_tmp = nullptr;
	Helicoptero* Helicoptero_tmp = nullptr;
	cout << "Desea registrar areonaves en este areopuerto en este momento? (Num)\n1. Si.\n2. No" << endl;
	cin >> num;
	switch (num){
		case 1:
			cout << "Cuantas areonaves desea regitrar? (Num)" << endl;
			cin >> num_areonaves;
			if(num_areonaves > 0){
				for(int i = 0; i < num_areonaves; i++){
					cout << "Que tipo de areonave desea registrar? (Num)\n1. Avion\n2. Jet Privado\n3. Helicoptero\n0. Ninguno" << endl;
					cin >> tmp;
					switch (tmp){
						case 1:
							cout << "Porfavor indique la siguiente informacion:" << endl;
							cout << "Indique la marca del avion (El nombre de la marca del avion)" << endl;
							cin >> marca_tmp;
							cout << "Indique el modelo del avion (El nombre del modelo del avion)" << endl;
							cin >> modelo_tmp;
							cout << "Indique el numero de asientos del avion (Num)" << endl;
							cin >> Num_Asientos_tmp;
							cout << "Indique la velocidad maxima del avion (Num)" << endl;
							cin >> velo_max_tmp;
							cout << "Indique la autonomia del avion (Num)" << endl;
							cin >> autonomia_tmp;
							cout << "Indique el agno de fabricacion del avion (Num)" << endl;
							cin >> agno_tmp;
							cout << "Indique el estado actual del avion (Servicio, Totalmente Asignada o Mantenimiento)" << endl;
							cin >> estado_tmp;
							cout << "Indique la altura maxima del avion (Num)" << endl;
							cin >> altura_max_tmp;
							cout << "Indique el numero de motores del avion (Num)" << endl;
							cin >> no_motores_tmp;
							cout << "Indique la categoria del avion (Comercial, Carga)" << endl;
							cin >> cat_tmp;
							tipo = "Avion";
							Avion_tmp = new Avion(tipo, marca_tmp, modelo_tmp, Num_Asientos_tmp, velo_max_tmp, autonomia_tmp, agno_tmp, estado_tmp, altura_max_tmp, no_motores_tmp, cat_tmp);
							torre_control->addVehiculo(Avion_tmp);
							break;
						case 2:
							cout << "Porfavor indique la siguiente informacion:" << endl;
							cout << "Indique la marca del Jet (El nombre de la marca del Jet)" << endl;
							cin >> marca_tmp;
							cout << "Indique el modelo del Jet (El nombre del modelo del Jet)" << endl;
							cin >> modelo_tmp;
							cout << "Indique el numero de asientos del Jet (Num)" << endl;
							cin >> Num_Asientos_tmp;
							cout << "Indique la velocidad maxima del Jet (Num)" << endl;
							cin >> velo_max_tmp;
							cout << "Indique la autonomia del Jet (Num)" << endl;
							cin >> autonomia_tmp;
							cout << "Indique el agno de fabricacion (Num)" << endl;
							cin >> agno_tmp;
							cout << "Indique el estado actual del Jet (Servicio, Totalmente Asignada o Mantenimiento)" << endl;
							cin >> estado_tmp;
							cout << "Indique el nombre del propietario" << endl;
							cin >> propietario_tmp;
							tipo = "Jet";
							Jet_tmp = new Jet_Privado(tipo, marca_tmp, modelo_tmp, Num_Asientos_tmp, velo_max_tmp, autonomia_tmp, agno_tmp, estado_tmp, propietario_tmp);
							torre_control->addVehiculo(Jet_tmp);
							break;
						case 3:
							cout << "Porfavor indique la siguiente informacion:" << endl;
							cout << "Indique la marca del Helicoptero (El nombre de la marca del Helicoptero)" << endl;
							cin >> marca_tmp;
							cout << "Indique el modelo del Helicoptero(El nombre del modelo del Helicoptero)" << endl;
							cin >> modelo_tmp;
							cout << "Indique el numero de asientos del Helicoptero (Num)" << endl;
							cin >> Num_Asientos_tmp;
							cout << "Indique la velocidad maxima del Helicoptero (Num)" << endl;
							cin >> velo_max_tmp;
							cout << "Indique la autonomia del Helicoptero (Num)" << endl;
							cin >> autonomia_tmp;
							cout << "Indique el agno de fabricacion del Helicoptero (Num)" << endl;
							cin >> agno_tmp;
							cout << "Indique el estado actual del Jet (Servicio, Totalmente Asignada o Mantenimiento)" << endl;
							cin >> estado_tmp;
							cout << "Indique el  numero de rotores del Helicoptero (Num)" << endl;
							cin >> no_rotores_tmp;
							cout << "Indique la capa de elevacion del Helicoptero (Num)" << endl;
							cin >> capa_elevacion_tmp;
							cout << "Indique para que se usa el Helicoptero (Rescate, Turismo, Transporte, etc.)" << endl;
							cin >> uso_tmp;
							tipo = "Helicoptero";
							Helicoptero_tmp = new Helicoptero(tipo, marca_tmp, modelo_tmp, Num_Asientos_tmp, velo_max_tmp, autonomia_tmp, agno_tmp, estado_tmp, no_motores_tmp, capa_elevacion_tmp, uso_tmp);
							torre_control->addVehiculo(Helicoptero_tmp);
							break;
						case 0:
							cout << "Entendido\nRecuerde que puede registrar un vehiculo en cualquier momento" << endl;
							break;
						default:
							cout << "Valor invalido\nRecuerde que puede registrar un vehiculo en cualquier momento" << endl;
							break;
					}
				}
			}
			else{
				cout << "Valor invalido\nEn otro momento puede registrar areonaves";
			}
			break;
		case 2:
			cout << "Entendido\nRecuerde que puede registrar un vehiculo en cualquier momento" << endl;
			break;
		default:
			cout << "Valor invalido\nRecuerde que puede registrar un vehiculo en cualquier momento" << endl;
			break;
	}
}

