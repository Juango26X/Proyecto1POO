// Archivo Persona.cpp

#include "Persona.h"

// Implementación de los métodos de la clase Persona
Persona::Persona(int id, string nombre, string fechaNacimiento, char genero, string direccion, int telefono, string correo)
    :Id(id), Nombre(nombre), Fecha_Nacimiento(fechaNacimiento), Genero(genero), Direccion(direccion), Telefono(telefono), Correo(correo) {}

Persona::Persona()
    :Id(0), Nombre("NA"), Fecha_Nacimiento("NA"), Genero('N'), Direccion("NA"), Telefono(0), Correo("NA") {}

int Persona::getId() const {
    return Id;
}

void Persona::setId(int New_Id) {
    Id = New_Id;
}

string Persona::getNombre() const {
    return Nombre;
}

void Persona::setNombre(const string& New_Nombre) {
    Nombre = New_Nombre;
}

string Persona::getFechaNacimiento() const {
    return Fecha_Nacimiento;
}

void Persona::setFechaNacimiento(const string& New_Fecha) {
    Fecha_Nacimiento = New_Fecha;
}

char Persona::getGenero() const {
    return Genero;
}

void Persona::setGenero(char New_Genero) {
    Genero = New_Genero;
}

string Persona::getDireccion() const {
    return Direccion;
}

void Persona::setDireccion(const string& New_Direccion) {
    Direccion = New_Direccion;
}

int Persona::getTelefono() const {
    return Telefono;
}

void Persona::setTelefono(int New_Tel) {
    Telefono = New_Tel;
}

string Persona::getCorreo() const {
    return Correo;
}

void Persona::setCorreo(const string& New_Correo) {
    Correo = New_Correo;
}

void Persona::Show_Info(){
    cout << "Tipo: " << Tipo << endl;
    cout << "ID: " << Id << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Fecha de Nacimiento: " << Fecha_Nacimiento << endl;
    cout << "Género: " << Genero << endl;
    cout << "Dirección: " << Direccion << endl;
    cout << "Teléfono: " << Telefono << endl;
    cout << "Correo: " << Correo << endl;
}


