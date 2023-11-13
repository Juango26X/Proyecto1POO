import streamlit as st
import Vuelo as Vuelo

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
        self.Estado = estado
        if 'Vuelos' not in st.session_state:
            st.session_state['Vuelos'] = {}
            self.Vuelos_Act = {}
        else:
            self.tripulacion = st.session_state['Vuelos']

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
            id = Valor.get_no_identificacion()
            self.Vuelos_Act[id] = Valor
            st.session_state['Vuelos'] = self.Vuelos_Act
        else:
            st.write("::warning:: La areonave esta totalmente asignada")
        if len(self.Vuelos_Act) == 3:
            self.Estado = "Totalmente Asignado"

    def GetVuelo_T(self, pos):
        return self.Vuelos_Act[pos] if 0 <= pos < len(self.Vuelos_Act) else None

    def Get_No_Vuelos(self):
        return len(self.Vuelos_Act)

    def showVuelos(self):
        if self.Vuelos_Act:
            if len(self.Vuelos_Act) > 1:
                st.header('Estos son los vuelos asociados al avion', self.marca)
                ids = self.Vuelos_Act.keys()
                for i in ids:
                    self.Vuelos_Act[i].show_info()
            else:
                st.header('Estos es el vuelo asociado al avion', self.marca)
                ids = self.Vuelos_Act.keys()
                for i in ids:
                    self.Vuelos_Act[i].show_info()
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
        st.header('Esta es la informacion de la areonave:')
        st.write("Marca:", self.Marca)
        st.write("Modelo:", self.Modelo)
        st.write("Numero de Asientos:", self.Num_asientos)
        st.write("Velocidad Maxima:", self.Velo_Max)
        st.write("Autonomia:", self.Autonomia)
        st.write("Agno de Fabricacion:", self.Agno)
        st.write("Estado:", self.Estado)



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