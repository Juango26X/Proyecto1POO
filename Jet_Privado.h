// Archivo Jet_Privado.h
#include "Vehiculos_Aereos.h"

class Jet_Privado : public Vehiculos_Aereos {
private:
    string Propietario;
    deque<string> Servicios;
    deque<string> Destinos;

public:
    // Constructor
    Jet_Privado(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado, string propietario);

    virtual void dummy() override {}

    string GetPropietario();
    void SetPropietario(const string& nuevoPropietario);
    void Show_Servicios();
    void SetServicios();
    void Add_Servicio(const string& New_Servicio);
    void Delete_Servicio(int pos);
    void Show_Destinos();
    void SetDestinos();
    void Add_Destino(const string& New_Destino);
    void Delete_Destino(int pos);
    void Show_Info_J();
};

