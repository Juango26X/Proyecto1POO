import streamlit as st
from Vuelo import Vuelo
class Torre:
    def __init__(self):
        if 'vehiculo' not in st.session_state:
            st.session_state['vehiculo'] = {}
            self.Vehiculos = {}
        else:
            self.Vehiculos = st.session_state['vehiculo']
    
    def add_Vehiculo(self, id, vehiculo):
        self.Vehiculos[id] = vehiculo
        st.session_state['vehiculo']  = self.Vehiculos

    def Add_Vuelo(self, id, Vuelo):
        if self.Vehiculos[id]:
            print("nas;dasd")
            self.Vehiculos[id].addVuelo_T(Vuelo)
            st.session_state['vehiculo'] = self.Vehiculos

    def get_All(self):
        return self.Vehiculos