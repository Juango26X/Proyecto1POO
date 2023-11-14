from Persona import Persona
class Pasajero(Persona):
    def __init__(self, id, nombre, fechaNacimiento, genero, direccion, telefono, correo, nacionalidad, noMaletas, infoMedica):
        super().__init__(id, nombre, fechaNacimiento, genero, direccion, telefono, correo)
        self.Nacionalidad = nacionalidad
        self.NoMaletas = noMaletas
        self.InfoMedica = infoMedica

    def ShowInfoP(self):
        info = self.ShowInfo()
        return{
            "info" : info,
            "Nacionalidad" : self.Nacionalidad,
            "Informacion Médica" : self.InfoMedica
        }
