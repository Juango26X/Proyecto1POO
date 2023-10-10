// Archivo Puerta.h

#ifndef PUERTA_H
#define PUERTA_H

#include <iostream>
#include <string>
#include <deque>
#include "Vuelo.h"
#include "Horas.h"

using namespace std;

class Puerta {
private:
    int Id;
    string Ubicacion;
    string Disponibilidad;
    Horas Hora_Embarque;
    Vuelo* act;
    bool Asignado;
    deque<Vuelo*> historial;

public:
    // Constructor
    Puerta(int id, string ubicacion, string disponibilidad);

    int getId();
    void setId(int newId);
    string getUbicacion();
    void setUbicacion(string newUbicacion);
    string getDisponibilidad();
    void setDisponibilidad(string newDisponibilidad);
    Horas getHora_Embarque();
    void setHoraDeEmbarque(Horas hora);
    void getHistorial();
    void addVuelo(Vuelo* newVuelo);
    void setV_Asignado(bool Valor);
    bool getV_Asignado();
    Vuelo* getVuelo();
    void setVuelo(Vuelo* newVuelo);
    void Show_Info();
    void Clear_Vuelo();
};

#endif // PUERTA_H
