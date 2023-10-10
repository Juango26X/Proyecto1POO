//Archivo horas.h

#ifndef HORAS_H
#define HORAS_H

#include <iostream>
using namespace std;

class Horas{
	private:
		int Hora;
		int Min;
	public:
		Horas(int hora, int min);
		Horas();
		void Add_Min();
		void SetHora(int hora, int min);
		Horas GetHora();
		int Get_H();
		int Get_M();
		void Show_Hora();
		bool operator>=(Horas hora);
		bool operator==(Horas hora);
};


#endif
