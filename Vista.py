import streamlit as st
import pandas as pd
from datetime import date
from mTripulacion import MTripulacion
from Vuelo import Vuelo
from VehiculosAereos import VehiculosAereos
class Vista:
    def __init__(self):
        st.title("Menu principal")

    def menu(self):
        st.header("Menú de opciones")
        option = st.selectbox('Seleccione la operación que quiere realizar:', ['Ver informacion del areopuerto', 'Ver estado de las areonaves', 'Crear una nueva areaonave', 'Acceder al modulo de areolinea', 'Comprar vuelos', 'Acceder como areopuerto', 'Consulta global'])
        return option
        
    
    def View_Info_Areopuerto(self):
        print("Info del areopuerto")
        
        
    def View_Estado_Areonaves(self, aeronaves):
        if aeronaves:
            st.header("Módulo de visualización de areonaves")
            ids = aeronaves.keys()
            for i in ids:
                # Luego, puedes obtener los atributos usando los métodos de la clase
                vehiculo = aeronaves[i]
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
                st.write("    ---          ")
        else:
            st.info("No hay areonaves hasta el momento", icon="ℹ️")
        
    def View_Crear_Areonave(self):
        st.write('Bienvenido al modulo para adicionar una areonave a la base de datos del areopuerto')
        option = st.selectbox('Que tipo de areonave desea crear?', ['Avion', 'Helicoptero', 'Jet Privado'])
        return option
               
    def View_Crear_Avion(self, aeronaves):
        st.header("Crear un avion")
        id = st.text_input("Ingrese el identificador del avion")
        tipo = "Avion"
        marca = st.text_input("Ingrese la marca del avion")
        modelo = st.text_input("Ingrese el modelo del avion")
        num_asientos = st.number_input("Ingrese el numero de asientos", step = 1)
        velo_Max = st.number_input("Ingrese la velocidad maxima del avion", step = 1)
        agno = st.number_input("Ingrese el agno de fabricacion", step = 1)
        estado = st.selectbox("Seleccione el estado del avion", ["Disponible","En vuelo","puerta de embarque", "En pista de despegue", "Totalmente asignada", "Mantenimiento",])
        ids = aeronaves.keys()
        for i in ids:
            if aeronaves[i].getEstado() == "En pista de despegue":
                    aeronaves[i].modificarEstado("En vuelo")
        alt_Max = st.number_input("Ingrese la altura maxima del avion", step = 1)
        no_Motores = st.number_input("Ingrese el numero de motores del avion", step = 1)
        cat = st.selectbox("Seleccione la categoria del avion", ["Comercial", "Carga"])
        Agregar = st.button("Agregar la areonave", type="primary")
        if Agregar:
            return {
                "id" : id,
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
    
    def View_Crer_Helicoptero(self, aeronaves):
        st.header("Crear un helicoptero")
        id = st.text_input("Ingrese el identificador del helicoptero")
        tipo = "Helicoptero"
        marca = st.text_input("Ingrese la marca del helicóptero")
        modelo = st.text_input("Ingrese el modelo del helicóptero")
        num_asientos = st.number_input("Ingrese el numero de asientos", step = 1)
        velo_Max = st.number_input("Ingrese la velocidad maxima del helicóptero", step = 1)
        agno = st.number_input("Ingrese el agno de fabricacion", step = 1)
        estado = st.selectbox("Seleccione el estado del avion", ["Disponible","En vuelo","puerta de embarque", "En pista de despegue", "Totalmente asignada", "Mantenimiento",])
        ids = aeronaves.keys()
        for i in ids:
            if aeronaves[i].getEstado() == "En pista de despegue":
                    aeronaves[i].modificarEstado("En vuelo")
        capa_elevacion = st.number_input("Ingrese la capa de elevacion del helicóptero", step = 1)
        no_Rotores = st.number_input("Ingrese el numero de rotores del helicóptero", step = 1)
        uso = st.selectbox("Seleccione el uso del helicóptero", ["rescate", "turismo", "transporte", "Otros"])
        Agregar = st.button("Agregar la areonave", type="primary")
        if Agregar:
            return {
                "id" : id,
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
        
    def View_Crear_Jet_Privado(self, aeronaves):
        st.header("Crear jet privado")
        id = st.text_input("Ingrese el identificador del Jet")
        tipo = "Jet_Privado"
        marca = st.text_input("Ingrese la marca del jet privado")
        modelo = st.text_input("Ingrese el modelo del jet privado")
        num_asientos = st.number_input("Ingrese el numero de asientos", step = 1)
        velo_Max = st.number_input("Ingrese la velocidad maxima del jet privado", step = 1)
        agno = st.number_input("Ingrese el agno de fabricacion", step = 1)
        estado = st.selectbox("Seleccione el estado del avion", ["Disponible","En vuelo","puerta de embarque", "En pista de despegue", "Totalmente asignada", "Mantenimiento",])
        ids = aeronaves.keys()
        for i in ids:
            if aeronaves[i].getEstado() == "En pista de despegue":
                    aeronaves[i].modificarEstado("En vuelo")
        propietario = st.text_input("Ingrese el nombre del propietario del Jet")
        Agregar = st.button("Agregar la areonave", type="primary")
        if Agregar:
            return {
                "id" : id,
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
        acciones = ['Ver vuelos disponibles','Crear un vuelo', 'Ver clientes']
        df = pd.DataFrame({
            'Acciones': acciones})
        option = st.selectbox(
            'Seleccione una opción',
            df['Acciones'])
        return option

    
    def Crear_Vuelo(self, lista: dict[str, VehiculosAereos]):
        st.header('Informacion de vuelo')
        if 'Tripulacion' not in st.session_state:
            st.session_state['Tripulacion'] = []
            self.tripulacion = []
        else:
            self.tripulacion = st.session_state['Tripulacion']

        no_identificacion = st.number_input("Indique el numero de identificacion del vuelo", step = 1)
        fecha = st.date_input("Seleccione la fecha del vuelo")
        origen = st.text_input("Cual es la ciudad de origen?")
        destino = st.text_input("Cual es la ciudad de destino?")
        st.header('Informacion de los miembros de tripulacion')
        st.write('Para agregar el nuevo miembro de la tripulacion debe oprimir el boton "Agregar miembro"')
        id = st.number_input("Indique el id del miembro de la tripulación", step = 1)
        nombre = st.text_input('Indique el nombre del miembro de la tripulación')
        fechaNacimiento = st.date_input('Indique la fecha de nacimiento del miembro de la tripulación')
        genero = st.radio("Cual es el genero del miembro de la tripulación",["***Hombre***", "***Mujer***", "***No binario***"], index=None)
        direccion = st.text_input('Indique la direccion del miembro de la tripulación')
        telefono = st.number_input('Indique el numero de telefono del miembro de la tripulación', step = 1)
        correo = st.text_input('Indique el correo del miembro de la tripulación')
        puesto = st.text_input('Indique el puesto del miembro de la tripulación')
        exp = st.number_input('Idique la experiencia del miembrode la tripulación', step = 1)
        horasMax = st.number_input('Indique las horas maximas del miembro de la tripulacion', step = 1)
        Agregar1 = st.button("Agregar miembro", type="primary")
        if Agregar1:
            Tripulante = MTripulacion(id, nombre, fechaNacimiento, genero, direccion, telefono, correo, puesto, exp, horasMax)
            self.tripulacion.append(Tripulante)
            st.session_state['Tripulacion'] = self.tripulacion
        st.header('Debe seleccionar la areonave a la que se le va a asignar el vuelo')
        ids = lista.keys()
        df2 = pd.DataFrame({'first column': ids})
        option2 = st.selectbox('A que areonave le gustaria agregar el vuelo? (Seleccione para ver mas informacion)', df2['first column'])
        lista[option2]
        Agregar2 = st.button("Agregar el vuelo", type="primary")
        if Agregar2:
            print("Esta entrando ", len(self.tripulacion))
            return {
                "no_identificacion" : no_identificacion,
                "fecha" : fecha,
                "origen" : origen,
                "destino" : destino,
                "tripulacion" : self.tripulacion,
                "id" : option2
            }

    def Ver_Vuelos_Areolinea(self, lista, Usuario):
        if lista:
            #st.header('Estos son los vuelos disponibles en el areopuerto')
            Vuelos = lista.values()
            tripulacion = False
            if Usuario:
                tripulacion = st.toggle("Desea ver la tripulacion los vuelos vuelo?")
            else:
                st.write("Al final de la pagina podra seleccionar el vuelo que desea comprar")
            for i in Vuelos:
                id = i.get_no_identificacion()
                st.header('Este es el vuelo disponible:')
                data = i.show_info()
                if data:
                    st.write("Número de vuelo: ", data['no_identificacion'])
                    st.write('Fecha actual: ', data['fecha_programada'])
                    st.write("Origen: ", data['origen'])
                    st.write("Destino: ", data['destino'])
                    if tripulacion:
                        tmp = data['Tripulacion']
                        for b in tmp:
                            tripulante = b.ShowInfoM()
                            Info = tripulante['info']
                            st.header("La información del miembro de la tripulación es:")
                            st.write("Tipo: ", Info['Tipo'])
                            st.write("ID: ", Info['ID'])
                            st.write("Nombre: ", Info['Nombre'])
                            st.write("Fecha de Nacimiento: ", Info['Fecha de Nacimiento'])
                            st.write("Género: ", Info['Género'])
                            st.write("Dirección: ", Info['Dirección'])
                            st.write("Teléfono: ", Info['Teléfono'])
                            st.write("Correo: ", Info['Correo'])
                            st.write("Puesto: ", tripulante['Puesto'])
                            st.write(f"Experiencia: {tripulante['Exp']} años")
                            st.write(f"Horas Máximas: {tripulante['HorasMax']} horas")
        else:
            st.warning('Aun no hay vuelos')

    def Ver_Clientes(self, clientes):
        usuarios = clientes.values()
        for i in usuarios:
            data = i.ShowInfoP()
            Info = data['info']
            st.header("La información del pasajero es:")
            st.write("Tipo: ", Info['Tipo'])
            st.write("ID: ", Info['ID'])
            st.write("Nombre: ", Info['Nombre'])
            st.write("Fecha de Nacimiento: ", Info['Fecha de Nacimiento'])
            st.write("Género: ", Info['Género'])
            st.write("Dirección: ", Info['Dirección'])
            st.write("Teléfono: ", Info['Teléfono'])
            st.write("Correo: ", Info['Correo'])
            st.write("Nacionalidad: ", data['Nacionalidad'])
            st.write("La informacion medica del pasajero es: ", data['Informacion Médica'])

    def View_Comprar_Vuelos1(self, vuelos):
        if 'Fechas' not in st.session_state:
            st.session_state['Fechas'] = []
            self.Fechas = []
        else:
            self.Fechas = []

        if 'Origen' not in st.session_state:
            st.session_state['Origen'] = []
            self.Origen = []
        else:
            self.Origen = []

        if 'Destino' not in st.session_state:
            st.session_state['Destino'] = []
            self.Destino = []
        else:
            self.Destino = []

        
        if 'Fechas1' not in st.session_state:
            st.session_state['Fechas1'] = []
            self.Fechas1 = []
        else:
            self.Fechas1 = []

        if 'Origen1' not in st.session_state:
            st.session_state['Origen1'] = []
            self.Origen1 = []
        else:
            self.Origen1 = []

        if 'Destino1' not in st.session_state:
            st.session_state['Destino1'] = []
            self.Destino1 = []
        else:
            self.Destino1 = []
        Tmp = vuelos.values()
        for i in Tmp:
            fecha_tmp = i.get_fecha()
            self.Fechas.append(fecha_tmp)
            st.session_state['Fechas'] = self.Fechas
            Origen_tmp = i.get_origen()
            self.Origen.append(Origen_tmp)
            st.session_state['Origen'] = self.Origen
            Destino_tmp = i.get_destino()
            self.Destino.append(Destino_tmp)
            st.session_state['Destino'] = self.Destino
        
        self.Origen1 = st.multiselect('Seleccione las ciudades de origen en las que desea buscar un vuelo', self.Origen)
        st.session_state['Origen1'] = self.Origen1

        self.Destino1 = st.multiselect('Seleccione las ciudades de destino en las que desea buscar un vuelo', self.Destino)
        st.session_state['Fechas1'] = self.Destino1
        
        self.Fechas1 = st.multiselect('Seleccione las Fechas en las que desea buscar un vuelo', self.Fechas)
        st.session_state['Fechas1'] = self.Fechas1

        
        return {
            'Fechas' : self.Fechas1,
            'Origenes' : self.Origen1,
            'Destinos' : self.Destino1
        }
        
        

        

        
        
        Fechas = vuelos
        option = st.selectbox('Seleccione el numero de vuelo que desea comprar', Ids)
        tmp = vuelos[option]
        st.header("Porfavor ingrese la siguiente informacion personal para proceder con la compra: ")

    def View_Comprar_Vuelos2(self, Vuelos):
        ids = Vuelos.keys()
        option = st.selectbox('Seleccione el numero de vuelo que desea comprar:', ids)
        st.header('Porfavor indique la siguiente informacion personal para proceder con la compra:')
        id = st.number_input("Indique el id del pasajero", step=1)
        nombre = st.text_input('Indique el nombre del pasajero')
        fechaNacimiento = st.date_input('Indique la fecha de nacimiento del pasajero')
        genero = st.radio("Cual es el genero del pasajero", ["***Hombre***", "***Mujer***", "***No binario***"], index=None)
        direccion = st.text_input('Indique la direccion del pasajero')
        telefono = st.number_input('Indique el numero de telefono del pasajero', step=1)
        correo = st.text_input('Indique el correo del pasajero')
        Nacionalidad = st.text_input('Indique la nacionalidad del pasajero')
        noMaletas = st.number_input('Indique el numero de maletas del pasajero', step = 1)
        InfoMedica = st.text_input('Indique la informacion medica del pasajero')
        Agregar2 = st.button("Comprar el tiquete", type="primary")
        if Agregar2:
            st.write('El tiquete se ha comprado con exito')
            return{
                'No_Vuelo' : option,
                'id': id,
                'nombre': nombre,
                'fechaNacimiento': fechaNacimiento,
                'genero': genero,
                'direccion': direccion,
                'telefono': telefono,
                'correo': correo,
                'Nacionalidad': Nacionalidad,
                'noMaletas': noMaletas,
                'InfoMedica': InfoMedica
            }
        

    def Mostrar_Vuelos_Parametros(self, Origen, Destino, Fecha, Vuelos):
        if 'Aceptados' not in st.session_state:
            st.session_state['Aceptados'] = {}
            self.Aceptados = {}
        else:
            self.Aceptados = {}
        
        tmp = Vuelos.values()
        for i in tmp:
            Origen_tmp = i.get_origen()
            Destino_tmp = i.get_destino()
            fecha_tmp = i.get_fecha()
            for b in Origen:
                if Origen_tmp == b:
                    id = i.get_no_identificacion()
                    self.Aceptados[id] = i
                    st.session_state['Aceptados'] = self.Aceptados
            for c in Destino:
                if Destino_tmp == c:
                    id = i.get_no_identificacion()
                    self.Aceptados[id] = i
                    st.session_state['Aceptados'] = self.Aceptados
            for d in Fecha:
                if fecha_tmp == d:
                    id = i.get_no_identificacion()
                    self.Aceptados[id] = i
                    st.session_state['Aceptados'] = self.Aceptados
        self.Ver_Vuelos_Areolinea(self.Aceptados, False)
        return self.Aceptados
                
            
    def View_arepuerto(self):
        print("Areopuerto")
    
    def View_View_Consulta(self):
        print("Consulta")