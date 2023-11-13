import streamlit as st
import pandas as pd
from datetime import date
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
    df = pd.DataFrame({
        'first column': [1, 2, 3, 4],
        'second column': [10, 20, 30, 40]
        })

    option = st.selectbox(
        'Which number do you like best?',
        df['first column'])

    'You selected: ', option

    date = st.date_input("Pick a date")
    controler = Controller()
    controler.Show_Menu()

main()


