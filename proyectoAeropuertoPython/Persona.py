class Persona:
    def __init__(self, id, nombre, fecha_nacimiento, genero, direccion, telefono, correo):
        self.Tipo = "Persona"  
        self.Id = id
        self.Nombre = nombre
        self.Fecha_Nacimiento = fecha_nacimiento
        self.Genero = genero
        self.Direccion = direccion
        self.Telefono = telefono
        self.Correo = correo

    def Show_Info(self):
        print("Tipo:", self.Tipo)
        print("ID:", self.Id)
        print("Nombre:", self.Nombre)
        print("Fecha de Nacimiento:", self.Fecha_Nacimiento)
        print("Género:", self.Genero)
        print("Dirección:", self.Direccion)
        print("Teléfono:", self.Telefono)
        print("Correo:", self.Correo)

