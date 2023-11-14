#from datetime import date
#import streamlit as st
from mTripulacion import MTripulacion  

class Vuelo:
    def __init__(self, no_identificacion, fecha, origen, destino, tripu, id):
        self.no_identificacion = no_identificacion
        self.fecha_programada = fecha
        self.origen = origen
        self.destino = destino
        self.tripulacion = tripu
        self.nave = id

    def get_nave(self):
        return self.nave
    
    def set_nave(self, id):
        self.nave = id

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

    def get_Tripulacion(self):
        return self.tripulacion
    
    def show_info(self):
        print('AAAAA', type(self.tripulacion))
        print('Esta entrando ', len(self.tripulacion))
        return {
            'no_identificacion': self.no_identificacion,
            'fecha_programada' : self.fecha_programada,
            'origen' : self.origen,
            'destino' : self.destino,
            'Tripulacion' : self.tripulacion
        }
    '''
        st.write(f"Número de vuelo: {self.no_identificacion}")
        st.write('Fecha actual: ', self.fecha_programada)
        st.write(f"Origen: {self.origen}")
        st.write(f"Destino: {self.destino}")
        
        if self.tripulacion:
            st.header('Informacion de un miembro de la tripulacion:')
            for tripulante in self.tripulacion:
                tripulante.ShowInfoM()
        '''