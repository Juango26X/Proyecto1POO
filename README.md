# Manual de Usuario - Aeropuerto Alfonso Bonilla Aragón

## Introducción
Bienvenido al programa de gestión del Aeropuerto Alfonso Bonilla Aragón. Este programa le permite realizar diferentes acciones según su rol: pasajero, aerolínea o propietario de Jet Privado. A continuación, se describen las opciones disponibles y cómo utilizar
las.

## Link UML
https://drive.google.com/file/d/17RGN31BPJfZTFYyH7jMJKWJ6S7dZkHzm/view?usp=sharing
## ¿Como Compilar?

# Requisitos Previos
- Asegúrate de tener un compilador C++ (como g++) instalado en tu sistema.
- Tener un archivo Makefile configurado para compilar el programa(opcional).

## Pasos

### 1. Abre la Línea de Comandos (CMD):
- En Windows, presiona `Win + R`, escribe `cmd` y presiona Enter.
- En sistemas Unix (Linux o macOS), abre una terminal.

### 2. Navega al Directorio del Proyecto:
Utiliza el comando `cd` para cambiar al directorio donde se encuentra tu proyecto del aeropuerto, incluido el archivo Makefile.

Ejecuta el comando make para compilar el programa utilizando el archivo Makefile.
El Makefile especificará las reglas de compilación y enlazado necesarias para compilar el programa de manera eficiente. Asegúrate de que el Makefile esté correctamente configurado.

Una vez que el programa se compile con éxito, puedes ejecutarlo con el siguiente comando:
./nombre_del_programa

## Menú Principal
Al iniciar el programa, se le presentará un menú principal con varias opciones. Para seleccionar una opción, ingrese el número correspondiente y presione Enter.


1. **Ingresar como pasajero:** Si es un pasajero, seleccione esta opción para realizar acciones relacionadas con la reserva de vuelos y su información personal.

2. **Ingresar como aerolínea:** Si representa a una aerolínea, seleccione esta opción para administrar vuelos y aeronaves.

3. **Consultar información de vuelos:** Consulte información sobre los vuelos disponibles en el aeropuerto.

4. **Ingresar como propietario de Jet Privado:** (Opción no implementada en el código proporcionado).

0. **Salir:** Salga del programa.

## Módulo de Pasajero
Si selecciona "Ingresar como pasajero", se le presentará un submenú con las siguientes opciones:

1. **Registrar pasajero:** Registre sus datos personales, como ID, nombre, fecha de nacimiento, género, dirección, teléfono, correo, nacionalidad, número de maletas e información médica.

2. **Ver todos los vuelos:** Vea una lista de todos los vuelos disponibles en el aeropuerto.

3. **Ver los vuelos por filtro de fecha:** Consulte los vuelos disponibles para una fecha específica.

4. **Ver todos los vuelos por filtro de destino:** Vea los vuelos disponibles hacia un destino específico.

0. **Salir:** Regrese al menú principal.

### Registrar Pasajero
Para registrar sus datos como pasajero, seleccione la opción "Registrar pasajero" e ingrese la información solicitada, como ID, nombre, etc. Una vez registrado, sus datos se almacenarán en el sistema.

### Ver Todos los Vuelos
Esta opción le mostrará una lista de todos los vuelos disponibles en el aeropuerto. Puede optar por comprar boletos para alguno de estos vuelos si lo desea.

### Ver Vuelos por Filtro de Fecha
Ingrese una fecha (día, mes y año) y el sistema mostrará los vuelos disponibles para esa fecha específica.

### Ver Vuelos por Filtro de Destino
Ingrese un destino y el sistema mostrará los vuelos disponibles hacia ese destino.

## Módulo de Aerolínea
Si selecciona "Ingresar como aerolínea", se le presentará un submenú con las siguientes opciones:

1. **Ver todas las aeronaves disponibles:** Muestra la lista de todas las aeronaves registradas en el aeropuerto.

2. **Crear un vuelo y asignarlo a una aeronave:** Registre un nuevo vuelo y asígnele una aeronave disponible.

3. **Ver todos los vuelos:** Consulte la lista de todos los vuelos registrados en el aeropuerto.

4. **Eliminar un vuelo:** Elimine un vuelo registrado en el sistema.

0. **Salir:** Regrese al menú principal.

### Ver Todas las Aeronaves Disponibles
Esta opción muestra la lista de todas las aeronaves registradas en el aeropuerto.

### Crear un Vuelo y Asignarlo a una Aeronave
Seleccione esta opción para registrar un nuevo vuelo. Deberá ingresar detalles como el número de identificación de la aeronave, la fecha de salida, el origen y el destino. Puede elegir entre registrar un vuelo para un avión o un helicóptero.

### Ver Todos los Vuelos
Esta opción muestra una lista de todos los vuelos registrados en el aeropuerto.

### Eliminar un Vuelo
Seleccione esta opción para eliminar un vuelo registrado en el sistema. Ingrese los detalles del vuelo que desea eliminar.

## Consultar Información de Vuelos
Seleccione esta opción para ver información sobre los vuelos disponibles en el aeropuerto. Puede ver todos los vuelos o filtrarlos por fecha o destino.

## Salir
Siempre puede seleccionar la opción "Salir" para cerrar el programa.

Este es un resumen de cómo utilizar el programa del Aeropuerto Alfonso Bonilla Aragón. Siga las instrucciones según su rol y las acciones que desee realizar. ¡Disfrute su experiencia en el aeropuerto!
