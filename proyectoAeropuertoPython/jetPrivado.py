from VehiculosAereos import VehiculosAereos
class JetPrivado(VehiculosAereos):
    def __init__(self, tipo, marca, modelo, Num_Asientos, velo_max, autonomia, agno, estado, propietario):
        super().__init__(tipo, marca, modelo, Num_Asientos, velo_max, autonomia, agno, estado)
        self.Propietario = propietario
        self.Servicios = []
        self.Destinos = []

        Num_Servicios = int(input("Cuantos servicios a bordo tiene el Jet Privado? "))
        for i in range(Num_Servicios):
            servicio = input(f"Ingrese el servicio {i + 1}: ")
            self.Servicios.append(servicio)

        for i in range(3):
            destino = input("Ingrese un destino frecuente del jet privado: ")
            self.Destinos.append(destino)

    def GetPropietario(self):
        return self.Propietario

    def SetPropietario(self, nuevoPropietario):
        self.Propietario = nuevoPropietario

    def Show_Servicios(self):
        print("El Jet cuenta con los servicios de:")
        for servicio in self.Servicios:
            print(servicio)

    def SetServicios(self):
        salida = True
        while salida:
            print("Desea:")
            print("1. Agregar un nuevo servicio.")
            print("2. Remplazar un servicio existente")
            print("0. No desea agregar un nuevo servicio")
            value = int(input())
            if value == 1:
                New_Servicio = input("Que servicio desea agregar? ")
                self.Add_Servicio(New_Servicio)
            elif value == 2:
                self.Show_Servicios()
                pos = int(input("Que servicio desea eliminar? "))
                self.Delete_Servicio(pos)
                New_Servicio = input("Que servicio desea agregar? ")
                self.Add_Servicio(New_Servicio)
            elif value == 0:
                salida = False
            else:
                print("Opcion invalida")

    def Add_Servicio(self, New_Servicio):
        self.Servicios.append(New_Servicio)

    def Delete_Servicio(self, pos):
        if 0 <= pos < len(self.Servicios):
            deleted_service = self.Servicios.pop(pos)
            print(f"El servicio {deleted_service} ha sido eliminado")
        else:
            print("La posición especificada no es válida.")

    def Show_Destinos(self):
        print("Los destinos frecuentes del Jet son:")
        for destino in self.Destinos:
            print(destino)

    def SetDestinos(self):
        salida = True
        while salida:
            print("Desea:")
            print("1. Agregar un nuevo destino frecuente.")
            print("2. Remplazar un destino existente")
            print("0. No desea agregar un nuevo destino")
            value = int(input())
            if value == 1:
                New_Destino = input("Que destino desea agregar? ")
                self.Add_Destino(New_Destino)
            elif value == 2:
                self.Show_Destinos()
                pos = int(input("Que destino desea eliminar? "))
                self.Delete_Destino(pos)
                New_Destino = input("Que destino desea agregar? ")
                self.Add_Destino(New_Destino)
            elif value == 0:
                salida = False
            else:
                print("Opcion invalida")

    def Add_Destino(self, New_Destino):
        self.Destinos.append(New_Destino)

    def Delete_Destino(self, pos):
        if 0 <= pos < len(self.Destinos):
            deleted_destination = self.Destinos.pop(pos)
            print(f"El destino {deleted_destination} ha sido eliminado")
        else:
            print("La posición especificada no es válida.")

    def Show_Info_J(self):
        self.Show_Info()
        print(f"Propietario: {self.Propietario}")
        self.Show_Servicios()
        self.Show_Destinos()
