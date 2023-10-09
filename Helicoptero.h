// Archivo Helicoptero.h
#include "Vehiculos_Aereos.h"

class Helicoptero : public Vehiculos_Aereos {
private:
    int No_Rotores;
    int Capa_Elevacion;
    string uso;

public:
    // Constructor
    Helicoptero(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado, int no_rotores, int capa_elevacion, string uso);

    virtual void dummy() override {}

    int getNo_Rotores() const;
    void setNo_Rotores(int No_Roto);
    int getCapa_Elevacion() const;
    void setCapa_Elevacion(int New_Ele);
    void Show_Uso();
    void Show_Info_H();
};