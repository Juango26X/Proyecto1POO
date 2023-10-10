// Archivo Vuelo.cpp

#include "Vuelo.h"

// Constructor
Vuelo::Vuelo(int noIdentificacion, Fecha fecha, string origen, string destino, deque<M_Tripulacion*>& tripulacion)
    : No_Identificacion(noIdentificacion), Fecha_Programada(fecha), Origen(origen), Destino(destino), Tripulacion(tripulacion) {}

int Vuelo::getNo_Identificacion() const {
    return No_Identificacion;
}

void Vuelo::setNo_Identificacion(int New_Id) {
    No_Identificacion = New_Id;
}

Fecha Vuelo::getFecha(){
    return Fecha_Programada;
}

void Vuelo::setFecha(Fecha New_Fecha) {
    Fecha_Programada = New_Fecha;
}

string Vuelo::getOrigen() const {
    return Origen;
}

void Vuelo::setOrigen(const string& New_Origen) {
    Origen = New_Origen;
}

string Vuelo::getDestino() {
    return Destino;
}

void Vuelo::setDestino(const string& value) {
    Destino = value;
}


void Vuelo::Show_Info(){
    cout << "Numero de Identificacion: " << No_Identificacion << endl;
    cout << "Fecha Programada: " << Fecha_Programada.getDia() << "/" << Fecha_Programada.getMes() << "/" << Fecha_Programada.getAgno() << endl;
    cout << "Origen: " << Origen << endl;
    cout << "Destino: " << Destino << endl;
    if(!Tripulacion.empty()){
        int tam = Tripulacion.size(), i = 0;
        while(i < tam){
            Tripulacion[i]->Show_Info_M();
            i++;
        }
    }
}

