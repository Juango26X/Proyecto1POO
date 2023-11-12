import streamlit as st
import pandas as pd
import numpy as np
from helicoptero import Helicoptero
# from Vuelo import Vuelo
from fecha import Fecha
from avion import Avion
from mTripulacion import MTripulacion
from Horas import Horas
from pasajero import Pasajero
from Persona import Persona
# from torredecontrol import TorreDeControl
from VehiculosAereos import VehiculosAereos
from jetPrivado import JetPrivado
# from puerta import Puerta
# from Vista import Vista
from controler import Controller


def main():
    if st.checkbox('Show dataframe'):
        chart_data = pd.DataFrame(
            np.random.randn(20, 3),
            columns=['a', 'b', 'c'])

    chart_data
    controler = Controller()
    controler.Show_Menu()

main()


