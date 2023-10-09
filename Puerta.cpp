// Archivo Puerta.cpp

#include "Puerta.h"

// Constructor
Puerta::Puerta(int id, string ubicacion, string disponibilidad)
    : Id(id), Ubicacion(ubicacion), Disponibilidad(disponibilidad){}

int Puerta::getId() {
    return Id;
}

void Puerta::setId(int newId) {
    Id = newId;
}

string Puerta::getUbicacion() {
    return Ubicacion;
}

void Puerta::setUbicacion(string newUbicacion) {
    Ubicacion = newUbicacion;
}

string Puerta::getDisponibilidad() {
    return Disponibilidad;
}

void Puerta::setDisponibilidad(string newDisponibilidad) {
    Disponibilidad = newDisponibilidad;
}

string Puerta::getHora_Embarque() {
    return Hora_Embarque;
}

void Puerta::setHoraDeEmbarque(string newH_Embarque) {
    Hora_Embarque = newH_Embarque;
}

void Puerta::getHistorial() {
    // Implementación de la función para obtener historial
    int tam = historial.size(), Info = 0, vuelo_Sel = 0;
    if(tam != 0){
        if(tam > 1){
            cout << "Los vuelos que han sido asignados a esta puerta son:" << endl;
            for(int i = 0; i < tam; i++){
                cout << i + 1 << ". " << historial[i]->getNo_Identificacion() << "." << endl;
            }
            cout << "Desea conocer mas informacion de alguno de los vuelos? \n1. Si.\n2. No.";
            switch(Info){
                case 1:
                    cout << "Sobre que vuelo desea recibir informacion? (Indique el numero del indice)" << endl;
                    cin >> vuelo_Sel;
                    if(vuelo_Sel > 0 && vuelo_Sel < tam){
                        historial[vuelo_Sel - 1]->Show_Info();
                    }
                    break;
                case 2:
                    cout << "Entendido" << endl;
                    break;
                default:
                    cout << "Valor indefinido" << endl;
                    break;
            }
        }
        else{
            cout << "El unico vuelo que ha sido asignado a esta puerta es el vuelo: " << historial[0]->getNo_Identificacion() << "\nDesea conocer mas informacion? \n1. Si.\n2. No." << endl;
            cin >> Info;
            switch(Info){
                case 1:
                    historial[0]->Show_Info();
                    break;
                case 2:
                    cout << "Entendido" << endl;
                    break;
                default:
                    cout << "Valor indefinido" << endl;
                    break;
            }
        }
    }
    else{
        cout << "No se ha asignado ningun vuelo a esta puerta" << endl;
    }
}

void Puerta::addVuelo(Vuelo* newVuelo) {
    act = newVuelo;
    historial.push_back(newVuelo);
}

void Puerta::setV_Asignado(bool Valor) {
    Asignado = Valor;
}

bool Puerta::getV_Asignado() {
    return Asignado;
}
/*
Vuelo* Puerta::getVuelo() {
    return act;
}
*/
void Puerta::setVuelo(Vuelo* newVuelo) {
    act = newVuelo;
    setV_Asignado(true);
}

void Puerta::Show_Info() {
    cout << Id << " " << Ubicacion << " " << Disponibilidad << " " << Hora_Embarque << " " <<  Asignado << endl;
}
