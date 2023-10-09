// Archivo Avion.cpp

#include "Avion.h"


// Implementación de los métodos de la clase Avion
Avion::Avion(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado, int altura_max, int no_motores, string cat)
    : Vehiculos_Aereos(tipo, marca, modelo, Num_Asientos, velo_max, autonomia, agno, estado), Altura_Max(altura_max), No_Motores(no_motores), categoria(cat) {
    }

int Avion::get_Altura_Max() const {
    return Altura_Max;
}

void Avion::set_Altura_Max(int New_Alt) {
    Altura_Max = New_Alt;
}

int Avion::get_No_Motores() const {
    return No_Motores;
}

void Avion::set_No_Motores(int New_Mot) {
    No_Motores = New_Mot;
}

string Avion::get_categoria() {
    return categoria;
}

void Avion::set_categoria(bool New_Cat) {
    categoria = New_Cat;
}

void Avion::Show_Info_A(){
	Show_Info();
	cout << "Altura Maxima: " << Altura_Max << endl;
    cout << "Numero de Motores: " << No_Motores << endl;
    cout << "Categoria: " << categoria << endl;
    cout << endl;
}