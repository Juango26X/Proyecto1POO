from Vista import Vista
from jetPrivado import JetPrivado
from helicoptero import Helicoptero
from avion import Avion
from torredecontrol import Torre
import streamlit as st
from Vuelo import Vuelo
from PIL import Image
import requests
class Controller:
    def __init__(self):
        self.view = Vista()
        self.torre = Torre()
        if 'torre' not in st.session_state:
            st.session_state['torre'] = self.torre

    
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
        elif option == 'Ver vuelos':
            self.Ver_Vuelos()
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
        tmp = self.torre.get_All()
        self.view.View_Estado_Areonaves(tmp)

    
    def Crear_Areonave(self):
        option = self.view.View_Crear_Areonave()
        st.session_state['option'] = option
        
        if option == 'Avion':
            tmp = self.torre.get_All()
            data = self.view.View_Crear_Avion(tmp)
            if data:
                print("entro")
                avion = Avion(tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], altura_max=data["alt_Max"], no_motores=data["no_Motores"], cat=data["cat"])
                self.torre.add_Vehiculo(data["modelo"], avion)
        elif option == 'Helicoptero':
            tmp = self.torre.get_All()
            data = self.view.View_Crer_Helicoptero(tmp)
            if data:
                helicoptero = Helicoptero(tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], capa_elevacion=data["capa_elevacion"], no_rotores=data["no_Rotores"], uso=data["uso"])
                self.torre.add_Vehiculo(data["modelo"], helicoptero)
        elif option == 'Jet Privado':
            tmp = self.torre.get_All()
            data = self.view.View_Crear_Jet_Privado(tmp)
            if data:
                jet_privado = JetPrivado(tipo=data["tipo"], marca=data["marca"], modelo=data["modelo"], num_asientos=data["num_asientos"], velo_max=data["velo_Max"], autonomia=data["agno"], agno=data["agno"], estado=data["estado"], propietario=data["propietario"])
                self.torre.add_Vehiculo(data["modelo"],jet_privado)
    
    def Areolinea(self):
        option = self.view.View_Areolinea()
        if option == 'Crear un vuelo':
            data = self.view.Crear_Vuelo(self.torre.get_All())
            if data:
                vuelo = Vuelo(no_identificacion=data["no_identificacion"], fecha=data["fecha"], origen=data["origen"], destino=data["destino"], tripu=data["tripulacion"])
                self.torre.Add_Vuelo(data['id'], vuelo)
        elif option == 'Ver vuelos disponibles':
            self.view.Ver_Vuelos_Areolinea(self.torre.get_All())
        #elif option == 'Eliminar vuelo':

    
    def Ver_Vuelos(self):
        print("Vuelos")
    
    def arepuerto(self):
        print("Areopuerto")
    
    def Consulta(self):
        print("Consulta")
        st.write("vamole")
        def obtener_info_pais(nombre_pais):
            url = f"https://restcountries.com/v3.1/name/{nombre_pais}"
            response = requests.get(url)

            if response.status_code == 200:
                datos_pais = response.json()[0]
                return datos_pais
            else:
                st.error(f"Error al obtener información del país {nombre_pais}")
                return None

    def mostrar_info_pais(datos_pais):
        if datos_pais:
            st.write(f"Nombre del país: {datos_pais['name']['common']}")
            st.write(f"Moneda: {datos_pais['currencies'].get('primary')}")
            st.write(f"Ciudad Capital: {datos_pais['capital'][0]}")
            st.write(f"Región: {datos_pais['region']}")
            st.write(f"Población: {datos_pais['population']}")
            st.image(datos_pais['flags']['png'], caption="Bandera del país", use_column_width=True)
        else:
            st.warning("No se pudo obtener información del país.")

    # Interfaz de usuario con Streamlit
    st.title("Información del País")

    # Input para que el usuario ingrese el nombre del país
    nombre_pais = st.text_input("Ingrese el nombre del país:")
    if st.button("Obtener Información"):
        datos_pais = obtener_info_pais(nombre_pais)
        mostrar_info_pais(datos_pais)