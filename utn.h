#ifndef _UTN
#define _UTN
//#include "arrayPasajero.c"
//FUNCION agreagada
int pasajeroVacio(pasajero*);
void mostrarMenu();
int validarChar(char[]);
void ingresarPasajero(pasajero*, int, int);
void datoModificar();
void modificarDatoaccion(pasajero*, int, int);
void listaPreciopasajes(pasajero*, int);

void pedirNombre(pasajero*, int);
void pedirApellido(pasajero*, int);
void pedirPrecio(pasajero*, int);
void pedirTipo(pasajero*,int);
void pedirCodigo(pasajero*,int);
void pedirEstado(pasajero*,int);
#endif