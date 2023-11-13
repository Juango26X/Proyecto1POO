import streamlit as st
class Persona:
    def __init__(self, id, nombre, fecha_nacimiento, genero, direccion, telefono, correo):
        self.Tipo = "Persona"  
        self.Id = id
        self.Nombre = nombre
        self.Fecha_Nacimiento = fecha_nacimiento
        self.Genero = genero
        self.Direccion = direccion
        self.Telefono = telefono
        self.Correo = correo

    def ShowInfo(self):
        st.write("Tipo:", self.Tipo)
        st.write("ID:", self.Id)
        st.write("Nombre:", self.Nombre)
        st.write("Fecha de Nacimiento:", self.Fecha_Nacimiento)
        st.write("Género:", self.Genero)
        st.write("Dirección:", self.Direccion)
        st.write("Teléfono:", self.Telefono)
        st.write("Correo:", self.Correo)


