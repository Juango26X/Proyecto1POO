from VehiculosAereos import VehiculosAereos  # Importa la clase Vehiculos_Aereos desde el archivo correspondiente

class Helicoptero(VehiculosAereos):
    def __init__(self, id,tipo, marca, modelo, num_asientos, velo_max, autonomia, agno, estado, no_rotores, capa_elevacion, uso):
        super().__init__(id,tipo, marca, modelo, num_asientos, velo_max, autonomia, agno, estado)
        self.No_Rotores = no_rotores
        self.Capa_Elevacion = capa_elevacion
        self.uso = uso
        self.Puerta="sin asignar"

    def getNo_Rotores(self):
        return self.No_Rotores

    def setNo_Rotores(self, No_Roto):
        self.No_Rotores = No_Roto

    def getCapa_Elevacion(self):
        return self.Capa_Elevacion

    def setCapa_Elevacion(self, New_Ele):
        self.Capa_Elevacion = New_Ele
    def get_Uso(self):
        return self.uso

    def Show_Uso(self):
        print(self.uso)

    def Show_Info_H(self):
        self.Show_Info()
        print("Numero de Rotores:", self.No_Rotores)
        print("Capacidad de Elevación:", self.Capa_Elevacion)
        print("Uso específico:", self.uso)
