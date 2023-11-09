class VehiculosAereos:
    def __init__(self, tipo, marca, modelo, num_asientos, velo_max, autonomia, agno, estado):
        self.Tipo = tipo
        self.Marca = marca
        self.Modelo = modelo
        self.Asientos = {i: False for i in range(1, num_asientos + 1)}
        self.Num_asientos = num_asientos
        self.Velo_Max = velo_max
        self.Autonomia = autonomia
        self.Agno = agno
        self.Estado = estad
        self.Vuelos_Act = []

    def Get_Tipo(self):
        return self.Tipo

    def getMarca(self):
        return self.Marca

    def getModelo(self):
        return self.Modelo

    def getCapacidad_Pasajeros(self):
        return len(self.Asientos)

    def getVelo_Max(self):
        return self.Velo_Max

    def getAutonomia(self):
        return self.Autonomia

    def getAgno(self):
        return self.Agno

    def getEstado(self):
        return self.Estado

    def Show_Asientos_D(self):
        print("Estos son los asientos que se encuentran disponibles:")
        for i, disponible in self.Asientos.items():
            if not disponible:
                print(f"El asiento {i}")

    def Asignar_Pasajero(self, pos):
        intentos = 0
        salida = False
        while intentos < 2 and pos in self.Asientos and not salida:
            if not self.Asientos[pos]:
                print(f"Usted ha sido asignado al asiento: {pos}")
                self.Asientos[pos] = True
                salida = True
            else:
                print("Ese asiento no se encuentra disponible")
                print("Estos son los asientos disponibles:")
                self.Show_Asientos_D()
                print("Por favor inténtelo nuevamente")
                intentos += 1
                pos = int(input())
        if intentos == 2 or pos not in self.Asientos:
            print("Los asientos que intentó reservar no se encuentran disponibles, por favor inténtelo nuevamente o en otro vuelo.")

    def Vaciar_Vuelo(self):
        self.Asientos = {i: False for i in range(1, self.Num_asientos + 1)}

    def addVuelo_T(self, Valor):
        if len(self.Vuelos_Act) != 3:
            self.Vuelos_Act.append(Valor)
        else:
            print("El avión se encuentra totalmente asignado")
        if len(self.Vuelos_Act) == 3:
            self.Estado = "Totalmente Asignado"

    def GetVuelo_T(self, pos):
        return self.Vuelos_Act[pos] if 0 <= pos < len(self.Vuelos_Act) else None

    def Get_No_Vuelos(self):
        return len(self.Vuelos_Act)

    def showVuelos(self, Trupi):
        if self.Vuelos_Act:
            if len(self.Vuelos_Act) > 1:
                print("Vuelos disponibles:")
                for vuelo in self.Vuelos_Act:
                    vuelo.Show_Info(Trupi)
            else:
                print("Vuelo disponible:")
                self.Vuelos_Act[0].Show_Info(Trupi)
        else:
            print("No hay vuelos disponibles")

    def elimViuelo(self, pos):
        if 0 <= pos < len(self.Vuelos_Act):
            self.Vuelos_Act.pop(pos)
        else:
            print("La posición especificada no es válida.")
        if len(self.Vuelos_Act) < 4:
            self.Estado = "Servicio"

    def Show_Info(self):
        print("Marca:", self.Marca)
        print("Modelo:", self.Modelo)
        print("Numero de Asientos:", self.Num_asientos)
        print("Velocidad Maxima:", self.Velo_Max)
        print("Autonomia:", self.Autonomia)
        print("Agno de Fabricacion:", self.Agno)
        print("Estado:", self.Estado)

    def Verificar_Vuelo(self, Id):
        if self.Vuelos_Act:
            for vuelo in self.Vuelos_Act:
                if vuelo.getNo_Identificacion() == Id:
                    return True
        return False

    def Verificar_Fecha(self, fecha):
        for vuelo in self.Vuelos_Act:
            if vuelo.getFecha() == fecha:
                vuelo.Show_Info(False)
                return True
        return False

    def Verificar_Destino(self, Destino):
        for vuelo in self.Vuelos_Act:
            if vuelo.getDestino() == Destino:
                vuelo.Show_Info(False)
                return True
        return False