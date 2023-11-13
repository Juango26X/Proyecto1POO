import streamlit as st

from Persona import Persona
class MTripulacion(Persona):
    def __init__(self, id, nombre, fechaNacimiento, genero, direccion, telefono, correo, puesto, exp, horasMax):
        super().__init__(id, nombre, fechaNacimiento, genero, direccion, telefono, correo)
        self.Puesto = puesto
        self.Exp = exp
        self.HorasMax = horasMax

    def ShowInfoM(self):
        st.write("La información del miembro de la tripulación es:")
        self.ShowInfo()
        st.write(f"Puesto: {self.Puesto}")
        st.write(f"Experiencia: {self.Exp} años")
        st.write(f"Horas Máximas: {self.HorasMax} horas")

