// Archivo Helicoptero.cpp
#include "Helicoptero.h"

// Implementación de los métodos de la clase Helicoptero
Helicoptero::Helicoptero(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado,  int no_rotores, int capa_elevacion, string uso)
    : Vehiculos_Aereos(tipo, marca, modelo, Num_Asientos, velo_max, autonomia, agno, estado), No_Rotores(no_rotores), Capa_Elevacion(capa_elevacion), uso(uso) {}

int Helicoptero::getNo_Rotores() const {
    return No_Rotores;
}

void Helicoptero::setNo_Rotores(int No_Roto) {
    No_Rotores = No_Roto;
}

int Helicoptero::getCapa_Elevacion() const {
    return Capa_Elevacion;
}

void Helicoptero::setCapa_Elevacion(int New_Ele) {
    Capa_Elevacion = New_Ele;
}

void Helicoptero::Show_Uso() {
    cout << uso << endl;
}

void Helicoptero::Show_Info_H(){
	Show_Info();
	cout << "Numero de Rotores: " << No_Rotores << endl;
	cout << "Capacidad de Elevacion: " << Capa_Elevacion << endl;
	cout << "Uso especifico: " << uso << endl;
	cout << endl;
}