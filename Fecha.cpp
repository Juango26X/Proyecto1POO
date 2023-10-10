// Archivo Fecha.cpp

#include "Fecha.h"

Fecha::Fecha() : Dia(9), Mes(10), Agno(2023) {}

Fecha::Fecha(int dia, int mes, int agno) : Dia(dia), Mes(mes), Agno(agno) {}

int Fecha::getDia(){
	return Dia;
}

int Fecha::getMes(){
	return Mes;
}

int Fecha::getAgno(){
	return Agno;
}

void Fecha::setDia(int dia) {
	Dia = dia;
}

void Fecha::setMes(int mes) {
	Mes = mes;
}

void Fecha::setAgno(int agno) {
	Agno = agno;
}

Fecha Fecha::Get_Fecha(){
	return *this;
}

bool Fecha::operator==(Fecha* fecha){
    return (Dia == fecha->getDia()) && (Mes == fecha->getMes()) && (Agno == fecha->getAgno());
}


void Fecha::Show_Fecha(){
	cout << Dia << "/" << Mes << "/" << Agno << endl;
}

void Fecha::AddDia(){
	Dia ++;
	if(Dia >= 31){
		Dia = 1;
		Mes++;
	}
	if(Mes >= 12 && Dia >= 31){
		Mes = 1;
		Dia = 1;
		Agno++;
	}
}


