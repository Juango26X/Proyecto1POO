PROGRAM := aeropuertoApp.exe
COMP := g++
FLAGS := -o
compilar:
	$(COMP) Avion.cpp Avion.h Fecha.cpp Fecha.h Helicoptero.h Helicoptero.cpp Horas.h Horas.cpp Jet_Privado.h Jet_Privado.cpp M_Tripulacion.cpp M_Tripulacion.h Pasajero.h Pasajero.cpp Persona.h Persona.cpp Puerta.h Puerta.cpp Torre_Control.cpp Torre_Control.h Vehiculos_Aereos.h Vehiculos_Aereos.cpp Vuelo.h Vuelo.cpp main.cpp $(FLAGS) $(PROGRAM)