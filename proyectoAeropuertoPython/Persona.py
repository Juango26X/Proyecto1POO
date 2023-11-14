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
        return{
            'Tipo': self.Tipo,
            'ID': self.Id,
            'Nombre': self.Nombre,
            'Fecha de Nacimiento': self.Fecha_Nacimiento,
            'Género': self.Genero,
            'Dirección': self.Direccion,
            'Teléfono': self.Telefono,
            'Correo': self.Correo
        }
        


