import streamlit as st
import pandas as pd
from VehiculosAereos import VehiculosAereos
from jetPrivado import JetPrivado
from helicoptero import Helicoptero
from avion import Avion

class Vista:
    def __init__(self):
        st.title("Menu principal")

    def menu(self):
        st.header("Menú de opciones")
        option = st.selectbox('Seleccione la operación que quiere realizar:', ['Ver informacion del areopuerto', 'Ver estado de las areonaves', 'Crear una nueva areaonave', 'Acceder al modulo de areolinea', 'Ver vuelos', 'Acceder como areopuerto', 'Consulta global'])
        return option
        
    
    def View_Info_Areopuerto(self):
        print("Info del areopuerto")
        
        
    def View_Estado_Areonaves(self, aeronaves):
        if aeronaves:
            avion = 0
            helicop = 0
            jet = 0
            st.header("Módulo de visualización de areonaves")
            for vehiculo in aeronaves:
                # Luego, puedes obtener los atributos usando los métodos de la clase
                tipo = vehiculo.Get_Tipo()
                marca = vehiculo.getMarca()
                modelo = vehiculo.getModelo()
                capacidad_pasajeros = vehiculo.getCapacidad_Pasajeros()
                velocidad_maxima = vehiculo.getVelo_Max()
                autonomia = vehiculo.getAutonomia()
                agno_fabricacion = vehiculo.getAgno()
                estado = vehiculo.getEstado()

                # Imprime los atributos usando st.write
                st.write(f"Tipo: {tipo}")
                st.write(f"Marca: {marca}")
                st.write(f"Modelo: {modelo}")
                st.write(f"Capacidad de Pasajeros: {capacidad_pasajeros}")
                st.write(f"Velocidad Máxima: {velocidad_maxima}")
                st.write(f"Autonomía: {autonomia}")
                st.write(f"Año de Fabricación: {agno_fabricacion}")
                st.write(f"Estado: {estado}")
                if tipo == 'Avion':
                    alt_Max = vehiculo.get_Altura_Max()
                    no_Motores = vehiculo.get_No_Motores()
                    cat = vehiculo.get_categoria()
                    st.write(f"La altura maxima del avion es {alt_Max}")
                    st.write(f"El avion tiene {no_Motores} motores")
                    st.write(f"La categoria del avion es: {cat}\n\n")
                elif tipo == 'Helicoptero':
                    capa_elevacion = vehiculo.getCapa_Elevacion()
                    no_Rotores = vehiculo.getNo_Rotores()
                    uso = vehiculo.get_Uso()
                    st.write(f"La capa de elevacion del helicoptero es {capa_elevacion}")
                    st.write(f"El helicoptero tiene {no_Rotores} rotores")
                    st.write(f"El uso del helicoptero es: {uso}\n\n")
                elif tipo == 'Helicoptero':
                    propietario = vehiculo.GetPropietario()
                    st.write(f"El propietario del Jet es {propietario}")
        else:
            st.info("No hay areonaves hasta el momento", icon="ℹ️")
        
    def View_Crear_Areonave(self):
        st.write('Bienvenido al modulo para adicionar una areonave a la base de datos del areopuerto')
        option = st.selectbox('Que tipo de areonave desea crear?', ['Avion', 'Helicoptero', 'Jet Privado'])
        return option
               
    def View_Crear_Avion(self):
        st.header("Crear un avion")
        tipo = "Avion"
        marca = st.text_input("Ingrese la marca del avion")
        modelo = st.text_input("Ingrese el modelo del avion")
        num_asientos = st.number_input("Ingrese el numero de asientos", step = 1)
        velo_Max = st.number_input("Ingrese la velocidad maxima del avion", step = 1)
        agno = st.number_input("Ingrese el agno de fabricacion", step = 1)
        estado = st.selectbox("Seleccione el estado del avion", ["En servicio", "Totalmente asignada", "Mantenimiento"])
        alt_Max = st.number_input("Ingrese la altura maxima del avion", step = 1)
        no_Motores = st.number_input("Ingrese el numero de motores del avion", step = 1)
        cat = st.selectbox("Seleccione la categoria del avion", ["Comercial", "Carga"])
        Agregar = st.button("Agregar la areonave", type="primary")
        if Agregar:
            return {
                "tipo": tipo,
                "marca": marca,
                "modelo": modelo,
                "num_asientos": num_asientos,
                "velo_Max": velo_Max,
                "agno": agno,
                "estado": estado,
                "alt_Max": alt_Max,
                "no_Motores": no_Motores,
                "cat": cat
            }
    
    def View_Crer_Helicoptero(self):
        st.header("Crear un helicoptero")
        tipo = "Helicoptero"
        marca = st.text_input("Ingrese la marca del helicóptero")
        modelo = st.text_input("Ingrese el modelo del helicóptero")
        num_asientos = st.number_input("Ingrese el numero de asientos", step = 1)
        velo_Max = st.number_input("Ingrese la velocidad maxima del helicóptero", step = 1)
        agno = st.number_input("Ingrese el agno de fabricacion", step = 1)
        estado = st.selectbox("Seleccione el estado del helicóptero", ["En servicio", "Totalmente asignada", "Mantenimiento"])
        capa_elevacion = st.number_input("Ingrese la capa de elevacion del helicóptero", step = 1)
        no_Rotores = st.number_input("Ingrese el numero de rotores del helicóptero", step = 1)
        uso = st.selectbox("Seleccione el uso del helicóptero", ["rescate", "turismo", "transporte", "Otros"])
        Agregar = st.button("Agregar la areonave", type="primary")
        if Agregar:
            return {
                "tipo": tipo,
                "marca": marca,
                "modelo": modelo,
                "num_asientos": num_asientos,
                "velo_Max": velo_Max,
                "agno": agno,
                "estado": estado,
                "capa_elevacion": capa_elevacion,
                "no_Rotores": no_Rotores,
                "uso": uso
            }
        
    def View_Crear_Jet_Privado(self):
        st.header("Crear jet privado")
        tipo = "Jet_Privado"
        marca = st.text_input("Ingrese la marca del jet privado")
        modelo = st.text_input("Ingrese el modelo del jet privado")
        num_asientos = st.number_input("Ingrese el numero de asientos", step = 1)
        velo_Max = st.number_input("Ingrese la velocidad maxima del jet privado", step = 1)
        agno = st.number_input("Ingrese el agno de fabricacion", step = 1)
        estado = st.selectbox("Seleccione el estado del jet privado", ["En servicio", "Totalmente asignada", "Mantenimiento"])
        propietario = st.text_input("Ingrese el nombre del propietario del Jet")
        Agregar = st.button("Agregar la areonave", type="primary")
        if Agregar:
            return {
                "tipo": tipo,
                "marca": marca,
                "modelo": modelo,
                "num_asientos": num_asientos,
                "velo_Max": velo_Max,
                "agno": agno,
                "estado": estado,
                "propietario": propietario
            }

    def View_Areolinea(self):
        print("Areolinea")
    
    def View_Ver_Vuelos(self):
        print("Vuelos")
    
    def View_arepuerto(self):
        print("Areopuerto")
    
    def View_View_Consulta(self):
        print("Consulta")