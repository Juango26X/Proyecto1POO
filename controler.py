from Vista import Vista
from jetPrivado import JetPrivado
from helicoptero import Helicoptero
from avion import Avion
from VehiculosAereos import VehiculosAereos
from torredecontrol import Torre
import streamlit as st
from Vuelo import Vuelo
from pasajero import  Pasajero
from PIL import Image
import json
import requests

class Controller:
    def __init__(self):
        self.view = Vista()
        # self.torre = Torre()
        '''
        if 'torre' not in st.session_state:
            st.session_state['torre'] = self.torre
        '''
        if 'vehiculo' not in st.session_state:
            st.session_state['vehiculo'] = {}
            self.Vehiculos = {}
        else:
            self.Vehiculos = st.session_state['vehiculo']
        if 'Vuelos' not in st.session_state:
            st.session_state['Vuelos'] = {}
            self.Vuelos_Act = {}
        else:
            self.Vuelos_Act = st.session_state['Vuelos']
        if 'Clientes' not in st.session_state:
            st.session_state['Clientes'] = {}
            self.Clientes = {}
        else:
            self.Clientes = st.session_state['Clientes']
        
    
    def add_Vehiculo(self, id, vehiculo):
        self.Vehiculos[id] = vehiculo
        st.session_state['vehiculo']  = self.Vehiculos

    def Add_Vuelo(self, id, Vuelo: Vuelo):
        tmp : VehiculosAereos
        tmp = self.Vehiculos[id]
        
        if True:
            self.Vehiculos[id] = tmp
            st.session_state['vehiculo'] = self.Vehiculos
            id = Vuelo.get_no_identificacion()
            self.Vuelos_Act[id] = Vuelo
            st.session_state['Vuelos'] = self.Vuelos_Act

    
    def Show_Menu(self):
        option = self.view.menu()
        st.session_state['option'] = option
        if option == 'Ver informacion del areopuerto':
            self.Info_Areopuerto()
        elif option == 'Ver estado de las areonaves':
            self.Estado_Areonaves()
        elif option == 'Crear una nueva areaonave':
            self.Crear_Areonave()
        elif option == 'Acceder al modulo de areolinea':
            self.Areolinea()
        elif option == 'Comprar vuelos':
            self.Comprar_Vuelos()
        elif option == 'Acceder como areopuerto':
            self.arepuerto()
        elif option == 'Consulta global':
            self.Consulta()

    def Info_Areopuerto(self):
        st.write("El Aeropuerto Internacional Alfonso Bonilla Aragón, ubicado en Palmira, Valle del Cauca, es el principal aeropuerto que sirve a la ciudad de Cali, Colombia. Conocido también como Aeropuerto de Cali, es uno de los aeródromos más importantes del país. Este moderno aeropuerto cuenta con instalaciones actualizadas y servicios que atienden a pasajeros nacionales e internacionales. Con una infraestructura diseñada para ofrecer comodidad y eficiencia, el Aeropuerto de Cali alberga diversas aerolíneas que conectan la región con destinos nacionales e internacionales. Sus instalaciones incluyen salas de espera cómodas, puntos de información, servicios de migración y aduana, así como locales comerciales y restaurantes que brindan una variedad de opciones para satisfacer las necesidades de los viajeros. Además, el aeropuerto se destaca por sus medidas de seguridad y servicios de transporte terrestre que facilitan la conexión con la ciudad de Cali y otras áreas circundantes. Con una gestión eficiente y una ubicación estratégica, el Aeropuerto Internacional Alfonso Bonilla Aragón desempeña un papel fundamental en la conectividad aérea de la región, ofreciendo a los viajeros una experiencia agradable y funcional.")
        print("Info del areopuerto")
        image_path = r"C:\Users\ASUS\Desktop\proyecto1POO\Proyecto1POO\proyectoAeropuertoPython\08-AEROBONILLA-2.jpg"
        image = Image.open(image_path)
        st.image(image, caption="foto del aeropuerto", use_column_width=True)
        
    def Estado_Areonaves(self):
        self.view.View_Estado_Areonaves(self.Vehiculos)

    
    def Crear_Areonave(self):
        option = self.view.View_Crear_Areonave()
        st.session_state['option'] = option
        
        if option == 'Avion':
            data = self.view.View_Crear_Avion(self.Vehiculos)
            if data:
                print("entro")
                avion = Avion(id=data["id"], tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], altura_max=data["alt_Max"], no_motores=data["no_Motores"], cat=data["cat"])
                self.add_Vehiculo(data["id"], avion)
        elif option == 'Helicoptero':
            data = self.view.View_Crer_Helicoptero(self.Vehiculos)
            if data:
                helicoptero = Helicoptero(id=data["id"], tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], capa_elevacion=data["capa_elevacion"], no_rotores=data["no_Rotores"], uso=data["uso"])
                self.add_Vehiculo(data["id"], helicoptero)
        elif option == 'Jet Privado':
            data = self.view.View_Crear_Jet_Privado(self.Vehiculos)
            if data:
                jet_privado = JetPrivado(id=data["id"], tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], propietario=data["propietario"])
                self.add_Vehiculo(data["id"],jet_privado)
    
    def Areolinea(self):
        option = self.view.View_Areolinea()
        if option == 'Crear un vuelo':
            data = self.view.Crear_Vuelo(self.Vehiculos)
            if data:
                vuelo = Vuelo(no_identificacion=data["no_identificacion"], fecha=data["fecha"], origen=data["origen"], destino=data["destino"], tripu=data["tripulacion"], id=data["id"])
                
                self.Add_Vuelo(data['id'], vuelo)
        elif option == 'Ver vuelos disponibles':
            self.view.Ver_Vuelos_Areolinea(self.Vuelos_Act, True)
        elif option == 'Ver clientes':
            self.view.Ver_Clientes(self.Clientes)
    
    def Comprar_Vuelos(self):
        data = self.view.View_Comprar_Vuelos1(self.Vuelos_Act)
        if data:
            print('Entrooo')
            Vuelos = self.view.Mostrar_Vuelos_Parametros(Origen = data['Origenes'], Destino=data['Destinos'], Fecha=data['Fechas'], Vuelos=self.Vuelos_Act)
            if Vuelos:
                pasajero = self.view.View_Comprar_Vuelos2(Vuelos)
                pasajero_tmp = Pasajero(id=pasajero['id'], nombre=pasajero['nombre'], fechaNacimiento=pasajero['fechaNacimiento'],genero=pasajero['genero'], direccion=pasajero['direccion'], telefono=pasajero['telefono'], correo=pasajero['correo'], nacionalidad=pasajero['Nacionalidad'], noMaletas=pasajero['noMaletas'], infoMedica=pasajero['InfoMedica'])
                self.Clientes[pasajero['id']] = pasajero_tmp
                st.session_state['Clientes'] = self.Clientes
    def arepuerto(self):
        print("Areopuerto")
    
    def Consulta(self):
            def obtener_global(nombre_pais):
                print("Consulta")
                st.write("vamole")
                url = f"https://restcountries.com/v3.1/name/{nombre_pais}?fullText=true"
                response = requests.get(url)
                data = response.json()[0]

                st.write(f"Nombre del país: **{data['name']['common']}**")
                st.write(f"Moneda: **{data['currencies']}**")
                st.write(f"Ciudad capital: **{data['capital'][0]}**")
                st.write(f"Región: **{data['region']}**")
                st.write(f"Población: **{data['population']}**")
                st.image(data['flags']['png'], width=200)


            pais = st.text_input("Ingrese el nombre del país:")
            if pais:
                obtener_global(pais)