//Archivo Fecha.h

#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha{
	int Dia;
	int Mes;
	int Agno;
public:
	Fecha();
	Fecha(int dia, int mes, int agno);
	int getDia();
	int getMes();
	int getAgno();
	void setDia(int dia);
	void setMes(int mes);
	void setAgno(int agno);
	bool operator==(Fecha* fecha);
	void Show_Fecha();
	void AddDia();
	Fecha Get_Fecha();
};

#endif