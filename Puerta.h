// Archivo Puerta.h

#ifndef PUERTA_H
#define PUERTA_H

#include <iostream>
#include <string>
#include <deque>
#include "Vuelo.h"

using namespace std;

class Puerta {
private:
    int Id;
    string Ubicacion;
    string Disponibilidad;
    string Hora_Embarque;
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
    string getHora_Embarque();
    void setHoraDeEmbarque(string newH_Embarque);
    void getHistorial();
    void addVuelo(Vuelo* newVuelo);
    void setV_Asignado(bool Valor);
    bool getV_Asignado();
    //Vuelo* getVuelo();
    void setVuelo(Vuelo* newVuelo);
    void Show_Info();
};

#endif // PUERTA_H
