// Archivo Torre_Control.h

#ifndef TORRE_CONTROL_H
#define TORRE_CONTROL_H

#include <iostream>
#include <deque>
#include "Puerta.h"  // Asegúrate de incluir el archivo de encabezado de la clase Puerta
#include "Vehiculos_Aereos.h"  // Asegúrate de incluir el archivo de encabezado de la clase Vehiculos_Aereos
#include "Jet_Privado.h"
#include "Avion.h"
#include "Helicoptero.h"
#include "Vuelo.h"
#include "Horas.h"
#include <windows.h>

using namespace std;

class Torre_Control {
private:
    deque<Puerta*> Puertas_Embarque;
    deque<Avion*> Aviones;  
    deque<Jet_Privado*> Jets;
    deque <Helicoptero*> Helicopteros;

public:
    // Constructor
    Torre_Control();

    void Show_Puertas_Embarque();
    void setPuertas_Embarque(Vuelo* newVuelo);
    void Show_Vuelos(string tipo, string Cat, bool Tripu);
    void Set_Vuelos(Vuelo* vuelo, string Tipo);
    void Elim_Vuelo(int Id);
    void show_Vehiculos();
    void addVehiculo(Vehiculos_Aereos* newVehiculo);
    void elimVehiculo(int pos);
    void setVuelo_V(Vuelo* newVuelo, int pos);
    void Buy_Vuelos_D(int Id);
    void Show_Vuelos_Fecha(Fecha* fecha);
    void Show_Vuelos_Destino(string Destino);
    void Show_Notificaciones(Fecha* hoy, Horas* ahora);
};

#endif // TORRE_CONTROL_H
