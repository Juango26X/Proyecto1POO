// Archivo Jet_Privado.cpp
#include "Jet_Privado.h"

// Implementación de los métodos de la clase Jet_Privado
Jet_Privado::Jet_Privado(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado,   string propietario)
    : Vehiculos_Aereos(tipo, marca, modelo, Num_Asientos, velo_max, autonomia, agno, estado), Propietario(propietario) {
        cout << "Cuantos servicios a bordo tiene el Jet Privado?" << endl;
        int Num_Servicios = 0, intentos = 0;
        cin >> Num_Servicios;
        /*
        while (intentos < 3) {
        try {
            cin >> Num_Servicios;

            if (std::cin.fail()) {
                throw "Ingreso no es un número válido.";
                intentos++;
            }

            break; // Si se ingresó un número válido, salir del bucle
            }
            catch (const char* mensaje) {
                std::cerr << mensaje << endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar el resto de la línea
            }
        }
        */

        for (int i = 0; i < Num_Servicios; i++) {
            string servicio;
            cout << "Ingrese el servicio " << i + 1 << ": ";
            cin >> servicio;
            Servicios.push_back(servicio);
        }
        for (int i = 0; i < 3; i++) {
            string destino;
            cout << "Ingrese un destino frecunte del jet privado" << ": ";
            cin >> destino;
            Destinos.push_back(destino);
        }
    }

string Jet_Privado::GetPropietario() {
    return Propietario;
}

void Jet_Privado::SetPropietario(const string& nuevoPropietario) {
    Propietario = nuevoPropietario;
}

void Jet_Privado::Show_Servicios() {
    int tam = Servicios.size();
    cout << "El Jet cuenta con los servicios de: ";
    for(int i = 0; i < tam; i++){
        cout << Servicios[i] << endl;
    }
}

void Jet_Privado::SetServicios() {
    bool salida = true;
    int value, pos;
    string New_Servicio;
    while(salida){
        cout << "Desea " << endl;
        cout << "1. Agregar un nuevo servicio." << endl;
        cout << "2. Remplazar un servicio existente" << endl;
        cout << "0. No desea agregar un nuevo servicio" << endl;
        cin >> value;
        switch(value){
            case 1:
                cout << "Que servicio desea agregar? " << endl;
                cin >> New_Servicio;
                Add_Servicio(New_Servicio);
                break;
            case 2:
                Show_Servicios();
                cout << "Que servicio desea eliminar?" << endl;
                cin >> pos;
                Delete_Servicio(pos);
                cout << "Que servicio desea agregar? " << endl;
                cin >> New_Servicio;
                Add_Servicio(New_Servicio);
                break;
            case 0:
                salida = false;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }
}

void Jet_Privado::Add_Servicio(const string& New_Servicio) {
    Servicios.push_back(New_Servicio);
}

void Jet_Privado::Delete_Servicio(int pos) {
    deque<string>::iterator it = Servicios.begin() + pos;
    cout << "El servicio " << *it << " ha sido eliminado" << endl;
    Servicios.erase(it); 
}

void Jet_Privado::Show_Destinos() {
    int tam = Destinos.size();
    cout << "Los destinos frecuentes del Jet son: ";
    for(int i = 0; i < tam; i++){
        cout << Destinos[i] << endl;
    }
}

void Jet_Privado::SetDestinos() {
    bool salida = true;
    int value, pos;
    string New_Destino;
    while(salida){
        cout << "Desea " << endl;
        cout << "1. Agregar un nuevo destino frecuente." << endl;
        cout << "2. Remplazar un destino existente" << endl;
        cout << "0. No desea agregar un nuevo destino" << endl;
        cin >> value;
        switch(value){
            case 1:
                cout << "Que destino desea agregar? " << endl;
                cin >> New_Destino;
                Add_Servicio(New_Destino);
                break;
            case 2:
                Show_Destinos();
                cout << "Que destino desea eliminar?" << endl;
                cin >> pos;
                Delete_Destino(pos);
                cout << "Que destino desea agregar? " << endl;
                cin >> New_Destino;
                Add_Servicio(New_Destino);
                break;
            case 0:
                salida = false;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }
}

void Jet_Privado::Add_Destino(const string& New_Destino) {
    Destinos.push_back(New_Destino);
}

void Jet_Privado::Delete_Destino(int pos) {
    deque<string>::iterator it = Destinos.begin() + pos;
    cout << "El destino " << *it << " ha sido eliminado" << endl;
    Destinos.erase(it); 
}

void Jet_Privado::Show_Info_J(){
    Show_Info();
    cout << "Propietario: " << Propietario << endl;
    Show_Servicios();
    Show_Destinos();
    cout << endl;
}