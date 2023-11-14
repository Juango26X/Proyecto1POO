import streamlit as st
from Vuelo import Vuelo
from VehiculosAereos import VehiculosAereos
class Torre:
    def __init__(self):
        if 'vehiculo' not in st.session_state:
            st.session_state['vehiculo'] = {}
            self.Vehiculos = {}
        else:
            self.Vehiculos = st.session_state['vehiculo']
        if 'Vuelos' not in st.session_state:
            st.session_state['Vuelos'] = {}
            self.Vuelos_Act = {}
        else:
            self.Vuelos_Act = st.session_state['Vuelos']
        
    
    def add_Vehiculo(self, id, vehiculo: VehiculosAereos):
        self.Vehiculos[id] = vehiculo
        st.session_state['vehiculo']  = self.Vehiculos

    def Add_Vuelo(self, id, Vuelo: Vuelo):
        tmp = self.Vehiculos[id]
        tmp.addVuelo_T()
        id = Vuelo.get_no_identificacion()
        self.Vuelos_Act[id] = Vuelo
        st.session_state['Vuelos'] = self.Vuelos_Act

    def Get_Vuelos(self):
        return self.Vuelos_Act

    def get_All(self):
        return self.Vehiculos
    