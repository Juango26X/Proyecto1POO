import streamlit as st

from Persona import Persona
class MTripulacion(Persona):
    def __init__(self, id, nombre, fechaNacimiento, genero, direccion, telefono, correo, puesto, exp, horasMax):
        super().__init__(id, nombre, fechaNacimiento, genero, direccion, telefono, correo)
        self.Puesto = puesto
        self.Exp = exp
        self.HorasMax = horasMax

    def ShowInfoM(self):
        data = self.ShowInfo()
        return{
            'info' : data,
            'Puesto' : self.Puesto,
            'Exp' : self.Exp,
            'HorasMax' : self.HorasMax
        }
        

