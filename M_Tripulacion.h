// Archivo M_Tripulacion.h
#include "Persona.h"

class M_Tripulacion : public Persona {
private:
    string Puesto;
    int Exp;
    int Horas_Max;

public:
    M_Tripulacion(string tipo, int id, string nombre, string fechaNacimiento, char genero, string direccion, int telefono, string correo, string puesto, int exp, int horasMax);
    M_Tripulacion();
    string getPuesto() const;
    void setPuesto(const string& puesto);
    int getExp() const;
    void setExp(int exp);
    int getHorasMax() const;
    void setHorasMax(int horasMax);
};

