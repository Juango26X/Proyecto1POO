from Vuelo import Vuelo  # Importar la clase Vuelo
from Horas import Horas  # Importar la clase Horas

class Puerta:
    def __init__(self, id, ubicacion, disponibilidad):
        self.Id = id
        self.Ubicacion = ubicacion
        self.Disponibilidad = disponibilidad
        self.Hora_Embarque = Horas(0, 0)  # Inicializar Hora_Embarque con valores predeterminados
        self.act = None
        self.Asignado = False
        self.historial = []

    def getId(self):
        return self.Id

    def setId(self, newId):
        self.Id = newId

    def getUbicacion(self):
        return self.Ubicacion

    def setUbicacion(self, newUbicacion):
        self.Ubicacion = newUbicacion

    def getDisponibilidad(self):
        return self.Disponibilidad

    def setDisponibilidad(self, newDisponibilidad):
        self.Disponibilidad = newDisponibilidad

    def getHora_Embarque(self):
        return self.Hora_Embarque

    def setHoraDeEmbarque(self, hora):
        self.Hora_Embarque = hora

    def getHistorial(self):
        tam = len(self.historial)
        Info = 0
        vuelo_Sel = 0
        if tam != 0:
            if tam > 1:
                print("Los vuelos que han sido asignados a esta puerta son:")
                for i in range(tam):
                    print(f"{i + 1}. {self.historial[i].getNo_Identificacion()}.")
                print("Desea conocer más información de alguno de los vuelos?\n1. Si.\n2. No.")
                Info = int(input())
                if Info == 1:
                    print("Sobre qué vuelo desea recibir información? (Indique el número del índice)")
                    vuelo_Sel = int(input())
                    if 1 <= vuelo_Sel <= tam:
                        self.historial[vuelo_Sel - 1].Show_Info(True)
                elif Info == 2:
                    print("Entendido")
                else:
                    print("Valor indefinido")
            else:
                print(f"El único vuelo que ha sido asignado a esta puerta es el vuelo: {self.historial[0].getNo_Identificacion()}")
                print("Desea conocer más información?\n1. Si.\n2. No.")
                Info = int(input())
                if Info == 1:
                    self.historial[0].Show_Info(True)
                elif Info == 2:
                    print("Entendido")
                else:
                    print("Valor indefinido")
        else:
            print("No se ha asignado ningún vuelo a esta puerta")

    def addVuelo(self, newVuelo):
        print("El vuelo ha sido asignado")
        self.act = newVuelo
        self.historial.append(newVuelo)

    def setV_Asignado(self, Valor):
        self.Asignado = Valor

    def getV_Asignado(self):
        return self.Asignado

    def getVuelo(self):
        return self.act

    def setVuelo(self, newVuelo):
        self.act = newVuelo
        self.setV_Asignado(True)

    def Clear_Vuelo(self):
        self.Hora_Embarque.SetHora(0, 0)
        self.act = None
        self.Asignado = False

    def Show_Info(self):
        print(f"ID: {self.Id}")
        print(f"Ubicacion: {self.Ubicacion}")
        print(f"Disponibilidad: {self.Disponibilidad}")
        if self.act is not None and self.Asignado:
            print("Hora de Embarque:", end=" ")
            self.Hora_Embarque.Show_Hora()
            print("\nVuelo Asignado:")
            self.act.Show_Info(False)
        else:
            print("No hay vuelo asignado.")
        if self.historial:
            print("Historial de Vuelos:\n")
            for vuelo in self.historial:
                vuelo.Show_Info(False)
        else:
            print("No hay historial de vuelos.")

