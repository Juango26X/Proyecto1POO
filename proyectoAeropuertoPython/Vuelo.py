from fecha import fecha  
from mTripulacion import mTripulacion  

class Vuelo:
    def __init__(self, no_identificacion, fecha, origen, destino, tripulacion):
        self.no_identificacion = no_identificacion
        self.fecha_programada = fecha
        self.origen = origen
        self.destino = destino
        self.tripulacion = tripulacion

    def get_no_identificacion(self):
        return self.no_identificacion

    def set_no_identificacion(self, new_id):
        self.no_identificacion = new_id

    def get_fecha(self):
        return self.fecha_programada

    def set_fecha(self, new_fecha):
        self.fecha_programada = new_fecha

    def get_origen(self):
        return self.origen

    def set_origen(self, new_origen):
        self.origen = new_origen

    def get_destino(self):
        return self.destino

    def set_destino(self, new_destino):
        self.destino = new_destino

    def show_info(self, tripu):
        print("Número de Identificación:", self.no_identificacion)
        print("Fecha Programada:", f"{self.fecha_programada.get_dia()}/{self.fecha_programada.get_mes()}/{self.fecha_programada.get_agno()}")
        print("Origen:", self.origen)
        print("Destino:", self.destino)
        if tripu:
            if self.tripulacion:
                for tripulante in self.tripulacion:
                    tripulante.show_info_m()