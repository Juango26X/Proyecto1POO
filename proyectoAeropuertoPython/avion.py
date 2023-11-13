from VehiculosAereos import VehiculosAereos  
class Avion(VehiculosAereos):
    def __init__(self, tipo, marca, modelo, num_asientos, velo_max, autonomia, agno, estado, altura_max, no_motores, cat):
        super().__init__(tipo, marca, modelo, num_asientos, velo_max, autonomia, agno, estado)
        self.Altura_Max = altura_max
        self.No_Motores = no_motores
        self.categoria = cat

    def get_Altura_Max(self):
        return self.Altura_Max

    def set_Altura_Max(self, new_alt):
        self.Altura_Max = new_alt

    def get_No_Motores(self):
        return self.No_Motores

    def set_No_Motores(self, new_mot):
        self.No_Motores = new_mot

    def get_categoria(self):
        return self.categoria

    def set_categoria(self, new_cat):
        self.categoria = new_cat

    def Show_Info_A(self):
        self.Show_Info()
        print("Altura Maxima:", self.Altura_Max)
        print("Numero de Motores:", self.No_Motores)
        print("Categoria:", self.categoria)