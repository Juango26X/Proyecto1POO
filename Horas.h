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
		void SetHora(int hora, int min);
		Horas GetHora();
};


#endif
