from Vista import Vista
from jetPrivado import JetPrivado
from helicoptero import Helicoptero
from avion import Avion
from torredecontrol import Torre
import streamlit as st
from Vuelo import Vuelo

class Controller:
    def __init__(self):
        self.view = Vista()
        self.torre = Torre()
        if 'torre' not in st.session_state:
            st.session_state['torre'] = self.torre

    
    def Show_Menu(self):
        option = self.view.menu()
        st.session_state['option'] = option
        if option == 'Ver informacion del areopuerto':
            self.Info_Areopuerto()
        elif option == 'Ver estado de las areonaves':
            self.Estado_Areonaves()
        elif option == 'Crear una nueva areaonave':
            self.Crear_Areonave()
        elif option == 'Acceder al modulo de areolinea':
            self.Areolinea()
        elif option == 'Ver vuelos':
            self.Ver_Vuelos()
        elif option == 'Acceder como areopuerto':
            self.arepuerto()
        elif option == 'Consulta global':
            self.Consulta()

    def Info_Areopuerto(self):
        
        print("Info del areopuerto")
        
    def Estado_Areonaves(self):
        tmp = self.torre.get_All()
        self.view.View_Estado_Areonaves(tmp)

    
    def Crear_Areonave(self):
        option = self.view.View_Crear_Areonave()
        st.session_state['option'] = option
        
        if option == 'Avion':
            data = self.view.View_Crear_Avion()
            if data:
                print("entro")
                avion = Avion(tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], altura_max=data["alt_Max"], no_motores=data["no_Motores"], cat=data["cat"])
                self.torre.add_Vehiculo(data["modelo"], avion)
        elif option == 'Helicoptero':
            data = self.view.View_Crer_Helicoptero()
            if data:
                helicoptero = Helicoptero(tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], capa_elevacion=data["capa_elevacion"], no_rotores=data["no_Rotores"], uso=data["uso"])
                self.torre.add_Vehiculo(data["modelo"], helicoptero)
        elif option == 'Jet Privado':
            data = self.view.View_Crear_Jet_Privado()
            if data:
                jet_privado = JetPrivado(tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], propietario=data["propietario"])
                self.torre.add_Vehiculo(data["modelo"],jet_privado)
    
    def Areolinea(self):
        option = self.view.View_Areolinea()
        if option == 'Crear un vuelo':
            data = self.view.Crear_Vuelo(self.torre.get_All())
            if data:
                vuelo = Vuelo(no_identificacion=data["no_identificacion"], fecha=data["fecha"], origen=data["origen"], destino=data["destino"], tripu=data["tripulacion"])
                self.torre.Add_Vuelo(data['id'], vuelo)
        elif option == 'Ver vuelos disponibles':
            self.view.Ver_Vuelos_Areolinea(self.torre.get_All())
        #elif option == 'Eliminar vuelo':

    
    def Ver_Vuelos(self):
        print("Vuelos")
    
    def arepuerto(self):
        print("Areopuerto")
    
    def Consulta(self):
        print("Consulta")