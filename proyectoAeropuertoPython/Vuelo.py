import streamlit as st
from datetime import date
from mTripulacion import MTripulacion  

class Vuelo:
    def __init__(self, no_identificacion, fecha, origen, destino, tripu):
        self.no_identificacion = no_identificacion
        self.fecha_programada = fecha
        self.origen = origen
        self.destino = destino
        if 'tripulacion' not in st.session_state:
            st.session_state['tripulacion'] = tripu
            self.tripulacion = tripu
        else:
            self.tripulacion = st.session_state['tripulacion']

    def get_no_identificacion(self):
        return self.no_identificacion

    def set_no_identificacion(self, new_id):
        self.no_identificacion = new_id

    def get_fecha(self):
        return self.fecha_programada

    def set_fecha(self, new_fecha):
        self.fecha_programada = new_fecha

    def get_origen(self):
        return self.origen

    def set_origen(self, new_origen):
        self.origen = new_origen

    def get_destino(self):
        return self.destino

    def set_destino(self, new_destino):
        self.destino = new_destino

    def add_Tripulacion(self, miemrbro):
        self.tripulacion.append(miemrbro)
        st.session_state['tripulacion'] = self.tripulacion

    def get_Tripulacion(self):
        return self.tripulacion


    def show_info(self):
        st.write("Número de Identificación:", self.no_identificacion)
        st.write("Fecha Programada:", f"{self.fecha_programada.get_dia()}/{self.fecha_programada.get_mes()}/{self.fecha_programada.get_agno()}")
        st.write("Origen:", self.origen)
        st.write("Destino:", self.destino)
        if self.tripulacion:
            st.header('Informacion de un miembro de la tripulacion:')
            for tripulante in self.tripulacion:
                tripulante.ShowInfoM()