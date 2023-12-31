// Archivo M_Tripulacion.cpp
#include "M_Tripulacion.h"
// Implementación de los métodos de la clase M_Tripulacion
M_Tripulacion::M_Tripulacion(int id, string nombre, string fechaNacimiento, char genero, string direccion, int telefono, string correo, string puesto, int exp, int horasMax)
    : Persona(id, nombre, fechaNacimiento, genero, direccion, telefono, correo), Puesto(puesto), Exp(exp), Horas_Max(horasMax) {}

M_Tripulacion::M_Tripulacion()
    : Persona(0, "NA", "NA", 'N', "NA", 0, "NA"), Puesto("NA"), Exp(0), Horas_Max(0) {}


string M_Tripulacion::getPuesto() const {
    return Puesto;
}

void M_Tripulacion::setPuesto(const string& puesto) {
    Puesto = puesto;
}

int M_Tripulacion::getExp() const {
    return Exp;
}

void M_Tripulacion::setExp(int exp) {
    Exp = exp;
}

int M_Tripulacion::getHorasMax() const {
    return Horas_Max;
}

void M_Tripulacion::setHorasMax(int horasMax) {
    Horas_Max = horasMax;
}

void M_Tripulacion::Show_Info_M(){
	cout << "La informacion del miembro de la tripulacion es: " << endl;
	Show_Info();
	cout << "Puesto: " << Puesto << endl;
	cout << "Experiencia: " << Exp << " años" << endl;
	cout << "Horas Máximas: " << Horas_Max << " horas" << endl;
}