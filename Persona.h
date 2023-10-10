// Archivo Persona.h

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    string Tipo;
    int Id;
    string Nombre;
    string Fecha_Nacimiento;
    char Genero;
    string Direccion;
    int Telefono;
    string Correo;

public:
    Persona(int id, string nombre, string fechaNacimiento, char genero, string direccion, int telefono, string correo);
    Persona();

    string Get_Tipo();
    int getId() const;
    void setId(int New_Id);
    string getNombre() const;
    void setNombre(const string& New_Nombre);
    string getFechaNacimiento() const;
    void setFechaNacimiento(const string& New_Fecha);
    char getGenero() const;
    void setGenero(char New_Genero);
    string getDireccion() const;
    void setDireccion(const string& New_Direccion);
    int getTelefono() const;
    void setTelefono(int New_Tel);
    string getCorreo() const;
    void setCorreo(const string& New_Correo);
    void Show_Info();
};


#endif // PERSONA_H
