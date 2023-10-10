//Archivo Hora.cpp

#include "Horas.h"

Horas::Horas(int hora, int min) : Hora(hora), Min(min){}
	

Horas::Horas(){
	Hora = 6;
	Min = 0;
}
void Horas::Show_Hora(){
	cout << Hora << ":" << Min << endl;
}
void Horas::SetHora(int hora, int min){
	Hora = hora;
	Min = min;
}

Horas Horas::GetHora(){
	return *this;
}

int Horas::Get_H(){
	return Hora;
}

int Horas::Get_M(){
	return Min;
}

void Horas::Add_Min(){
	Min += 10;
	if(Min >= 60){
		Hora += 1;
		Min = 0;
		if(Hora >= 24){
			Hora = 0;
		}
	}
}

bool Horas::operator>=(Horas hora){
    cout << "Hora: " << Hora << ", Hora de referencia: " << hora.Get_H() << endl;
    cout << "Min: " << Min << ", Min de referencia: " << hora.Get_M() << endl;
    return (Hora >= hora.Get_H()) && (Min >= hora.Get_M());
}




bool Horas::operator==(Horas hora){
    return (Hora == hora.Get_H()) && (Min == hora.Get_M());
}

