#ifndef _ARRAYPASAJERO
#define _ARRAYPASAJERO
//#include "utn.c"
typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int vacio; //isEmpty
	
}pasajero;
//FUNCION 2.1 initPassangers
int inicializacionPasajeros(pasajero*, int);
//FUNCION 2.2 addPassangers
int agregarPasajeros(pasajero*, int, int, char[], char[], float, char[], int, int);
//FUNCION 2.3 findPassengerById
int buscarPasajeroPorId(pasajero*, int, int);
//FUNCION 2.4 removePassanger
int removerPasajero(pasajero*, int, int);
//FUNCION 2.5 sortPassanger
int clasificarPasajero(pasajero*, int, int);
//FUNCION 2.6 listPassanger
int listarPasajero(pasajero*, int);
//FUNCION 2.7 sortPassangerByCode
int clasificarPasajeroporcodigo(pasajero*, int, int);
#endif
