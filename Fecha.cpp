// Archivo Fecha.cpp

#include "Fecha.h"

Fecha::Fecha() : Dia(1), Mes(1), Agno(2023) {}

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

bool Fecha::operator==(Fecha& otraFecha){
    return (Dia == otraFecha.Dia) && (Mes == otraFecha.Mes) && (Agno == otraFecha.Agno);
}


