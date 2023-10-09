// Archivo Pasajero.h
#include "Persona.h"
class Pasajero : public Persona {
private:
    string Tipo;
    string Nacionalidad;
    int No_Maletas;
    string Info_Medica;

public:
    Pasajero(string tipo, int id, string nombre, string fechaNacimiento, char genero, string direccion, int telefono, string correo, string nacionalidad, int noMaletas, string infoMedica);
    Pasajero();
    string Get_Tipo();
    string getNacionalidad() const;
    void setNacionalidad(const string& New_Nacio);
    int getNo_Maletas() const;
    void setNo_Maletas(int NewNo_Maletas);
    string getInfo_Medica() const;
    void setInfo_Medica(const string& New_Info_Med);
};