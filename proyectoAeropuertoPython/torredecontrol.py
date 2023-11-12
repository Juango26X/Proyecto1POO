import streamlit as st
from VehiculosAereos import VehiculosAereos
from jetPrivado import JetPrivado
from helicoptero import Helicoptero
from avion import Avion

class Torre:
    def __init__(self):
        if 'vehiculo' not in st.session_state:
            st.session_state['vehiculo'] = []
            self.Vehiculos = []
        else:
            self.Vehiculos = st.session_state['vehiculo']
    
    def add_Vehiculo(self, vehiculo):
        self.Vehiculos.append(vehiculo)
        st.session_state['vehiculo']  = self.Vehiculos

    def get_All(self):
        print(len(self.Vehiculos))
        return self.Vehiculos