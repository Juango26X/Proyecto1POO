// Archivo Torre_Control.cpp

#include "Torre_Control.h"

// Constructor
Torre_Control::Torre_Control() {
    // Abre el archivo en modo lectura


	int num = 0, id_tmp, num_areonaves, tmp = 0, Num_Asientos_tmp, velo_max_tmp, autonomia_tmp, agno_tmp, altura_max_tmp, no_motores_tmp, no_rotores_tmp, capa_elevacion_tmp;
	string disponibilidad_tmp, ubicacion_tmp, marca_tmp, modelo_tmp, estado_tmp, propietario_tmp, cat_tmp, uso_tmp, tipo;
	bool asignado_tmp, admitido = false;
	Avion* Avion_tmp = nullptr;
	Jet_Privado* Jet_tmp = nullptr;
	Helicoptero* Helicoptero_tmp = nullptr;
	cout << "Ha continuacion se le solicitara informacion relevante sobre el estado del areopuerto\nPara el exito del areopuerto sea muy claro al momento de ingresar lo que se esta solicitando\nEsto quiere decir que donde se especifique (Num) use numeros, y donde se especifiquen palabras debe ponerlas con mayusculas y minusculas" << endl;
	while(!admitido){
		cout << "Cuantas puertas hay en el areopuerto?" << endl;
		cin >> num;
		if(num > 0){
			for(int i = 0; i < num; i++){
				cout << "A continuacion porfavor indique la informacion general de la puerta " << i + 1 << "\n" << endl;
				cout << "Indique el numero de identificacion de la puerta (Num)" << i + 1 << endl;
				cin >> id_tmp;
				cout << "Indique en que plataforma se encuenta la puerta (Num)" << i + 1 << endl;
				cin >> ubicacion_tmp;
				cout << "Indique si la puerta " << i + 1 << " se encuentra disponible (Disponible, Mantenimiento, Cerrada)" <<  endl;
				cin >> disponibilidad_tmp;
				Puerta* Puerta_tmp = new Puerta(id_tmp, ubicacion_tmp, disponibilidad_tmp);
				Puertas_Embarque.push_back(Puerta_tmp);
			}
			admitido = true;
		}
		else if(num == 0){
			cout << "Entendido, recuerde que las puede agregar en otro momento";
			admitido = true;
		}
		else{
			cout << "Ingreso un valor indeterminado, porfavor indique ";
		}
	}
	num = 0;
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
							addVehiculo(Avion_tmp);
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
							addVehiculo(Jet_tmp);
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
							addVehiculo(Helicoptero_tmp);
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


void Torre_Control::Show_Puertas_Embarque() {
    int tam = Puertas_Embarque.size(), i = 0;
    while(i < tam){
    	Puertas_Embarque[i]->Show_Info();
    	i++;
    }
    Sleep(3000);
}
/*
void Torre_Control::addPuertas_Embarque() {
    // Implementación de la función para agregar puertas de embarque
}
*/
void Torre_Control::setPuertas_Embarque(Vuelo* newVuelo) {
    int tam = Puertas_Embarque.size(), i = 0, Id_Tmp, Hora, Min;
    bool disponibles = false, agregado = false;
    Horas* hora = nullptr;
    cout << "Estas son las puertas que se encuentran disponibles: " << endl;
    while(i < tam){
    	if(!Puertas_Embarque[i]->getV_Asignado()){
    		disponibles = true;
    		Puertas_Embarque[i]->Show_Info();
    	}
    	i++;
    }
    if(!disponibles){
    	cout << "Aun no hay puertas" << endl;
    }
    else{
	    cout << "Indique el Id de la puerta que desea reservar para este vuelo" << endl;
	    cin >> Id_Tmp;
	    i = 0;
		while(i < tam && !agregado){
	    	if(Puertas_Embarque[i]->getId() == Id_Tmp){
	    		agregado = true;
	    		cout << "Indique la hora de salida del vuelo (HH MM): ";
	    		cin >> Hora >> Min;
	    		hora = new Horas(Hora, Min);
	    		Puertas_Embarque[i]->setHoraDeEmbarque(hora->GetHora());
	    		Puertas_Embarque[i]->addVuelo(newVuelo);
	    	}
	    	i++;
	    }
    }
    
}

void Torre_Control::show_Vehiculos() {
	bool existen = false;
    int tam = Aviones.size();
    for (int i = 0; i < tam; i++) {
    	existen = true;
        Aviones[i]->Show_Info_A();
    }
    tam = Jets.size();
    for (int i = 0; i < tam; i++) {
    	existen = true;
        Jets[i]->Show_Info_J();
    }
    tam = Helicopteros.size();
    for (int i = 0; i < tam; i++) {
    	existen = true;
        Helicopteros[i]->Show_Info_H();
    }
    if(!existen){
    	cout << "Aun no hay areonaves registradas" << endl;
    }
}


void Torre_Control::addVehiculo(Vehiculos_Aereos* newVehiculo) {
    if (Avion* avion = dynamic_cast<Avion*>(newVehiculo)) {
        Aviones.push_back(avion);
    }
    else if (Jet_Privado* jet = dynamic_cast<Jet_Privado*>(newVehiculo)) {
        Jets.push_back(jet);
    }
    else if (Helicoptero* helicoptero = dynamic_cast<Helicoptero*>(newVehiculo)) {
        Helicopteros.push_back(helicoptero);
    }
}


void Torre_Control::elimVehiculo(int pos) {
    // Implementación de la función para eliminar vehículos aéreos
}

void Torre_Control::setVuelo_V(Vuelo* newVuelo, int pos) {
    // Implementación de la función para establecer vuelo a un vehículo aéreo
}

void Torre_Control::Buy_Vuelos_D(int Id) {
	bool existen = false;
    int tam = Aviones.size(), sel;
    for (int i = 0; i < tam && !existen; i++) {
        existen = Aviones[i]->Verificar_Vuelo(Id);
        if(existen){
        	Aviones[i]->Show_Asientos_D();
        	cout << "Seleccione uno" << endl;
        	cin >> sel;
        	Aviones[i]->Asignar_Pasajero(sel);
        }
    }
    tam = Jets.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Jets[i]->Verificar_Vuelo(Id);
        if(existen){
        	Jets[i]->Show_Asientos_D();
        	cout << "Seleccione uno" << endl;
        	cin >> sel;
        	Jets[i]->Asignar_Pasajero(sel);
        }
    }
    tam = Helicopteros.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Helicopteros[i]->Verificar_Vuelo(Id);
        if(existen){
        	Jets[i]->Show_Asientos_D();
        	cout << "Seleccione uno" << endl;
        	cin >> sel;
        	Jets[i]->Asignar_Pasajero(sel);
        }
    }
    if(!existen){
    	cout << "Aun no vuelos registrados con ese codigo" << endl;
    }
}

void Torre_Control::Show_Vuelos(string tipo, string cat, bool Trupi) {
    bool Hay_Vuelos = false;

    for (int i = 0; i < Aviones.size(); ++i) {
        if (tipo == "Avion" && cat == "Comercial" && Aviones[i]->get_categoria() == "Comercial") {
            if (Aviones[i]->Get_No_Vuelos() > 0) {
                Aviones[i]->showVuelos(Trupi);
                Hay_Vuelos = true;
            }
        }
        else if (tipo == "Avion" && cat == "Carga" &&  Aviones[i]->get_categoria() == "Carga") {
            if (Aviones[i]->Get_No_Vuelos() > 0 && Aviones[i]->get_categoria() == "Carga") {
                Aviones[i]->showVuelos(Trupi);
                Hay_Vuelos = true;
            }
        }
    }

    for (int i = 0; i < Jets.size(); ++i) {
        if (tipo == "Jet" && Jets[i]->Get_Tipo() == "Jet") {
            if (Jets[i]->Get_No_Vuelos() > 0) {
                Jets[i]->showVuelos(Trupi);
                Hay_Vuelos = true;
            }
        }
    }

    for (int i = 0; i < Helicopteros.size(); ++i) {
        if (tipo == "Helicoptero" && Helicopteros[i]->Get_Tipo() == "Helicoptero") {
            if (Helicopteros[i]->Get_No_Vuelos() > 0) {
                Helicopteros[i]->showVuelos(Trupi);
                Hay_Vuelos = true;
            }
        }
    }

    if (!Hay_Vuelos) {
        cout << "Aun no hay vuelos asignados en este aeropuerto" << endl;
    }
}

void Torre_Control::Set_Vuelos(Vuelo* vuelo, string tipo){
	system("cls");
	bool existen = false;
	int sel = 0;
	if(tipo == "Avion"){
		int tam = Aviones.size();
	    for (int i = 0; i < tam; i++){
	    	existen = true;
	    	cout << i + 1 << ". ";
	        Aviones[i]->Show_Info_A();
	    }
	    if(!existen){
	    	cout << "No hay aviones registrados en el areopuerto" <<  endl;
	    }
	    else{
	    	cout << "A que avion desea agregar este vuelo? (Digite el numero correspodiente en la lista)" << endl;
	    	cin >> sel;
	    	sel--;
	    	Aviones[sel]->addVuelo_T(vuelo);
	    	cout << "El vuelo ha sido asignado con exito" << endl;
	    }
	}
	else if(tipo == "Helicoptero"){
		int tam = Helicopteros.size();
	    for (int i = 0; i < tam; i++){
	    	existen = true;
	    	cout << i + 1 << ". ";
	        Helicopteros[i]->Show_Info_H();
	    }
	    if(!existen){
	    	cout << "No hay helicopteros registrados en el areopuerto" <<  endl;
	    }
	    else{
	    	cout << "A que avion desea agregar este vuelo? (Digite el numero correspodiente en la lista)" << endl;
	    	cin >> sel;
	    	sel--;
	    	Helicopteros[sel]->addVuelo_T(vuelo);
	    	cout << "El vuelo ha sido asignado con exito" << endl;

	    }
	}

}

void Torre_Control::Show_Vuelos_Fecha(Fecha* fecha){
	bool existen = false;
    int tam = Aviones.size(), sel;
    for (int i = 0; i < tam && !existen; i++) {
        existen = Aviones[i]->Verificar_Fecha(fecha);
    }
    tam = Jets.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Jets[i]->Verificar_Fecha(fecha);
    }
    tam = Helicopteros.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Helicopteros[i]->Verificar_Fecha(fecha);
        }
    if(!existen){
    	cout << "Aun no vuelos registrados con en esa fecha" << endl;
    }
}
void Torre_Control::Show_Vuelos_Destino(string Destino){
	bool existen = false;
    int tam = Aviones.size(), sel;
    for (int i = 0; i < tam && !existen; i++) {
        existen = Aviones[i]->Verificar_Destino(Destino);
    }
    tam = Jets.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Jets[i]->Verificar_Destino(Destino);
    }
    tam = Helicopteros.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Helicopteros[i]->Verificar_Destino(Destino);

        }
    if(!existen){
    	cout << "Aun no vuelos registrados con en esa fecha" << endl;
    }
}    

void Torre_Control::Elim_Vuelo(int Id){
	bool existen = false;
    int tam = Aviones.size(), sel;
    for (int i = 0; i < tam && !existen; i++) {
        existen = Aviones[i]->Verificar_Vuelo(Id);
        if(existen){
        	Aviones[i]->elimViuelo(i);
        }
    }
    tam = Jets.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Jets[i]->Verificar_Vuelo(Id);
        if(existen){
        	Jets[i]->elimViuelo(i);
        }
    }
    tam = Helicopteros.size();
    for (int i = 0; i < tam && !existen; i++) {
        existen = Helicopteros[i]->Verificar_Vuelo(Id);
        if(existen){
        	Jets[i]->elimViuelo(i);
        }
    }
    if(!existen){
    	cout << "Aun no vuelos registrados con ese codigo" << endl;
    }
    else{
    	cout << "Vuelo eliminado" << endl;
    	Sleep(3000);
    }
}

void Torre_Control::Show_Notificaciones(Fecha* hoy, Horas* ahora){
	cout << "notificaciones recientes del areopuerto:" << endl;
	int tam = Puertas_Embarque.size(), Id_Vuelo;
	Vuelo* tmp =nullptr;
	bool entro = false;
	for(int i = 0; i < tam; i++){
		if( ahora->GetHora() >= Puertas_Embarque[i]->getHora_Embarque()){
			entro = true;
			tmp = Puertas_Embarque[i]->getVuelo();
			if(tmp->getFecha() == hoy){
				Id_Vuelo = tmp->getNo_Identificacion();
				cout << "El vuelo " << Id_Vuelo << " ha despegado" << endl;
				Elim_Vuelo(Id_Vuelo);
				Puertas_Embarque[i]->Clear_Vuelo();
			}
			
		}
	}
	if(!entro){
		cout << "No hay notificaciones" << endl;
	}
}
