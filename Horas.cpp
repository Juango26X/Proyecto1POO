//Archivo Hora.cpp

#include "Horas.h"

Horas::Horas(int hora, int min) : Hora(hora), Min(min){}
	

Horas::Horas(){
	Hora = 0;
	Min = 0;
}

void Horas::SetHora(int hora, int min){
	Hora = hora;
	Min = min;
}

Horas Horas::GetHora(){
	Horas tmp(Hora, Min);
	return tmp;
}