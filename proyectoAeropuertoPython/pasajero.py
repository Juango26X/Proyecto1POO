from Persona import Persona
class Pasajero(Persona):
    def __init__(self, id, nombre, fechaNacimiento, genero, direccion, telefono, correo, nacionalidad, noMaletas, infoMedica):
        super().__init__(id, nombre, fechaNacimiento, genero, direccion, telefono, correo)
        self.Nacionalidad = nacionalidad
        self.NoMaletas = noMaletas
        self.InfoMedica = infoMedica

    def ShowInfoP(self):
        print("Información del pasajero:")
        self.ShowInfo()
        print(f"Nacionalidad: {self.Nacionalidad}")
        print(f"Número de Maletas: {self.NoMaletas}")
        print(f"Información Médica: {self.InfoMedica}")
