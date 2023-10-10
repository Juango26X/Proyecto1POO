// Archivo Vuelo.h

#ifndef VUELO_H
#define VUELO_H

#include <string>
#include <iostream>
#include <deque>
#include "Fecha.h"
#include "M_Tripulacion.h"
using namespace std;

class Vuelo {
private:
    int No_Identificacion;
    Fecha Fecha_Programada;
    string Origen;
    string Destino;
    deque<M_Tripulacion*> Tripulacion;
public:
    // Constructor
    Vuelo(int noIdentificacion, Fecha fecha, string origen, string destino, deque<M_Tripulacion*>& tripulacion);
    Vuelo();
    int getNo_Identificacion() const;
    void setNo_Identificacion(int New_Id);
    Fecha getFecha();
    void setFecha(Fecha New_Fecha);
    string getOrigen() const;
    void setOrigen(const string& New_Origen);
    string getDestino();
    void setDestino(const string& value);
    void Show_Info();
};

#endif // VUELO_H
