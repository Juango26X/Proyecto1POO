    // Archivo Avion.h

    #ifndef AVION_H
    #define AVION_H
    #include "Vehiculos_Aereos.h"

    class Avion : public Vehiculos_Aereos {
    private:
        int Altura_Max;
        int No_Motores;
        string categoria;

    public:
        // Constructor
        Avion(string tipo, string marca, string modelo, int Num_Asientos, int velo_max, int autonomia, int agno, string estado, int altura_max, int no_motores, string cat);
        virtual void dummy() override {}

        
        int get_Altura_Max() const;
        void set_Altura_Max(int New_Alt);
        int get_No_Motores() const;
        void set_No_Motores(int New_Mot);
        string get_categoria();
        void set_categoria(bool New_Cat);
        void Show_Info_A();
    };

    #endif 