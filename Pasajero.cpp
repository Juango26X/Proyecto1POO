// Archivo Pasajero.cpp
#include "Pasajero.h"

// Implementación de los métodos de la clase Pasajero
Pasajero::Pasajero(int id, string nombre, string fechaNacimiento, char genero, string direccion, int telefono, string correo, string nacionalidad, int noMaletas, string infoMedica)
    : Persona(id, nombre, fechaNacimiento, genero, direccion, telefono, correo), Nacionalidad(nacionalidad), No_Maletas(noMaletas), Info_Medica(infoMedica) {}

Pasajero::Pasajero()
    : Persona(0, "NA", "NA", 'N', "NA", 0, "NA"), Nacionalidad("NA"), No_Maletas(0), Info_Medica("NA") {}


string Pasajero::getNacionalidad() const {
    return Nacionalidad;
}

void Pasajero::setNacionalidad(const string& New_Nacio) {
    Nacionalidad = New_Nacio;
}

int Pasajero::getNo_Maletas() const {
    return No_Maletas;
}

void Pasajero::setNo_Maletas(int NewNo_Maletas) {
    No_Maletas = NewNo_Maletas;
}

string Pasajero::getInfo_Medica() const {
    return Info_Medica;
}

void Pasajero::setInfo_Medica(const string& New_Info_Med) {
    Info_Medica = New_Info_Med;
}

void Pasajero::Show_Info_P(){
	cout << "Informacion del pasajero: " << endl;
	Show_Info();
	cout << "Nacionalidad: " << Nacionalidad << endl;
    cout << "Número de Maletas: " << No_Maletas << endl;
    cout << "Información Médica: " << Info_Medica << endl;
}