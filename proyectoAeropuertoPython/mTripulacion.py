from Persona import Persona
class MTripulacion(Persona):
    def __init__(self, id, nombre, fechaNacimiento, genero, direccion, telefono, correo, puesto, exp, horasMax):
        super().__init__(id, nombre, fechaNacimiento, genero, direccion, telefono, correo)
        self.Puesto = puesto
        self.Exp = exp
        self.HorasMax = horasMax

    def ShowInfoM(self):
        print("La información del miembro de la tripulación es:")
        self.ShowInfo()
        print(f"Puesto: {self.Puesto}")
        print(f"Experiencia: {self.Exp} años")
        print(f"Horas Máximas: {self.HorasMax} horas")
