// Archivo Vehiculos_Aereos.h

#ifndef VEHICULOS_AEREOS_H
#define VEHICULOS_AEREOS_H

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include "Vuelo.h"
#include "Fecha.h"
#include <windows.h>

using namespace std;

class Vuelo;

class Vehiculos_Aereos {
private:
    string Tipo;
    string Marca;
    string Modelo;
    map<int, bool> Asientos;
    int Num_asientos;
    int Velo_Max;
    int Autonomia;
    int Agno;
    string Estado;
    deque<Vuelo*> Vuelos_Act;

public:
    // Constructor
    Vehiculos_Aereos(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado);

    virtual ~Vehiculos_Aereos() = default; // Agrega un destructor virtual para asegurar la polimorfia
    virtual void dummy() {}

    string Get_Tipo();
    string getMarca() const;
    string getModelo() const;
    int getCapacidad_Pasajeros() const;
    int getVelo_Max() const;
    int getAutonomia() const;
    int getAgno() const;
    string getEstado() const;
    void Show_Asientos_D();
    void Asignar_Pasajero(int pos);
    void Vaciar_Vuelo();
    void addVuelo_T(Vuelo* Valor);
    Vuelo* GetVuelo_T(int pos);
    bool Verificar_Vuelo(int Id);
    bool Verificar_Fecha(Fecha* fecha);
    bool Verificar_Destino(string Destino);
    int Get_No_Vuelos();
    void showVuelos();
    void elimViuelo(int pos);
    void Show_Info();
};


#endif // VEHICULOS_AEREOS_H
