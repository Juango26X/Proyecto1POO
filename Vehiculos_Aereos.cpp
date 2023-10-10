// Archivo Vehiculos_Aereos.cpp

#include "Vehiculos_Aereos.h"

// Implementación de los métodos de la clase Vehiculos_Aereos
Vehiculos_Aereos::Vehiculos_Aereos(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado)
    : Tipo (tipo), Marca(marca), Modelo(modelo), Num_asientos(Num_Asientos), Velo_Max(velo_max), Autonomia(autonomia), Agno(agno), Estado(estado) {
        for(int i = 1; i <= Num_Asientos; ++i) {
            Asientos[i] = false;
        }
    }

string Vehiculos_Aereos::Get_Tipo(){
    return Tipo;
}

string Vehiculos_Aereos::getMarca() const {
    return Marca;
}

string Vehiculos_Aereos::getModelo() const {
    return Modelo;
}

int Vehiculos_Aereos::getCapacidad_Pasajeros() const {
    return Asientos.size();
}

int Vehiculos_Aereos::getVelo_Max() const {
    return Velo_Max;
}

int Vehiculos_Aereos::getAutonomia() const {
    return Autonomia;
}

int Vehiculos_Aereos::getAgno() const {
    return Agno;
}

string Vehiculos_Aereos::getEstado() const {
    return Estado;
}


void Vehiculos_Aereos::Show_Asientos_D(){
    map<int, bool>::iterator it = Asientos.begin();
    printf("Estos son los asientos que se encuentran disponibles:\n");
    while(it != Asientos.end()){
        if(it->second == false){
            cout << "El asiento " << it->first << endl;
        }
        it++;
    }
}

void Vehiculos_Aereos::Asignar_Pasajero(int pos) {
    map<int, bool>::iterator it = Asientos.find(pos);
    int intentos = 0;
    bool salida = false;
    while(intentos < 2 && it != Asientos.end() && salida == false){
        if(it->second == false){
            cout << "Usted ha sido asignado al asiento: " << it->first << endl;
            it->second = true;
            salida = true;
            Sleep(3000);
        }
        else{
            cout << "Ese asiento no se encuentra disponible" << endl;
            cout << "Estos son los asientos disponibles:" << endl;
            Show_Asientos_D();
            cout << "Porfavor intentelo nuevamente" << endl;
            intentos++;
            cin >> pos;
        }
    }
    if(intentos == 2 || it == Asientos.end()){
        cout << "Los asientos que intento reservar no se encuentran disponibles, porfavor intentelo nuevamente o en otro vuelo." << endl;
        Sleep(3000);
    }

}

void Vehiculos_Aereos::Vaciar_Vuelo(){
    map<int, bool>::iterator it = Asientos.begin();
    while(it != Asientos.end()){
        it->second == false;
        it++;
    }
}

void Vehiculos_Aereos::addVuelo_T(Vuelo* Valor) {
    // Implementación de la adición de vuelo
    if(Vuelos_Act.size() != 3){
        Vuelos_Act.push_back(Valor);
    }
    else{
        cout << "El avion se encuentra totalmente asignado" << endl;
        Sleep(3000);
    }
    if(Vuelos_Act.size() == 3){
        Estado = "Totalmente Asignado";
        Sleep(3000);
    }
}

Vuelo* Vehiculos_Aereos::GetVuelo_T(int pos) {
    return Vuelos_Act[pos];
}

int Vehiculos_Aereos::Get_No_Vuelos(){
    int tam = Vuelos_Act.size();
    return tam;
}

void Vehiculos_Aereos::showVuelos() {
    int tam = Vuelos_Act.size(), i = 0;
    if(tam != 0){
        if(tam > 1){
            cout << "Un vuelo disponible: " << endl;
            while(i < tam){
                Vuelos_Act[i]->Show_Info();
                i++;
            }
        }
            else{
                cout << "Un vuelo disponible: " << endl;
                Vuelos_Act[0]->Show_Info();
            }
    }
    else{
        cout << "No hay vuelos disponibles" << endl;
    }
}

void Vehiculos_Aereos::elimViuelo(int pos) {
    if (pos >= 0 && pos < Vuelos_Act.size()) {
        deque<Vuelo*>::iterator it = Vuelos_Act.begin() + pos;
        Vuelos_Act.erase(it); 
    }
    else {
        cout << "La posición especificada no es válida." << endl;
    }
}

void Vehiculos_Aereos::Show_Info() {
    cout << "Marca: " << Marca << endl;
    cout << "Modelo: " << Modelo << endl;
    cout << "Numero de Asientos: " << Num_asientos << endl;
    cout << "Velocidad Maxima: " << Velo_Max << endl;
    cout << "Autonomia: " << Autonomia << endl;
    cout << "Agno de Fabricacion: " << Agno << endl;
    cout << "Estado: " << Estado << endl;
}


bool Vehiculos_Aereos::Verificar_Vuelo(int Id){
    bool salida = false;
    if(!Vuelos_Act.empty()){
        int tam = Vuelos_Act.size();
        for (int i = 0; i < tam; ++i){
            if(Vuelos_Act[i]->getNo_Identificacion() == Id){
                salida = true;
            }
        }
    }
    return salida;
}

bool Vehiculos_Aereos::Verificar_Fecha(Fecha* fecha){
    bool salida = false;
    if(!Vuelos_Act.empty()){
        int tam = Vuelos_Act.size();
        for (int i = 0; i < tam ; ++i){
            if(Vuelos_Act[i]->getFecha() == *fecha){
                Vuelos_Act[i]->Show_Info();
            }
        }
    }
    return salida;
}

bool Vehiculos_Aereos::Verificar_Destino(string Destino){
    bool salida = false;
    if(!Vuelos_Act.empty()){
        int tam = Vuelos_Act.size();
        for (int i = 0; i < tam ; ++i){
            if(Vuelos_Act[i]->getDestino() == Destino){
                Vuelos_Act[i]->Show_Info();
            }
        }
    }
    return salida;
}

