#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPasajero.h"
#include "utn.h"
#define CANTIDAD 2000

int main()
{
	
    //DECLARACION de array de estructura "pasajero" con nombre "lista" de cantidad= CANTIDAD
	pasajero lista[CANTIDAD];
	//FUNCION *AGREGADA* PASAJERO NULO
	pasajeroVacio(lista);
    //FUNCION 2.1 initPassangers
	inicializacionPasajeros(lista, CANTIDAD);
	//VARIABLES
    
	int menu_opcion=0;
	int dato_modificar=1;
	int tipo_informar;
	int contador = 1;
	int id;
	int orden;
	int menu_completo_habilitado = 0;
	int repetir = 1;
    do //BUCLE DE TODO EL PROGRAMA
	{ 
    do //BUCLE PARA MENU
    {
    do //BUCLE PARA SELECCION DE 1ERA OPCION
    {
	mostrarMenu(); //SE MUESTRA EL MENU
	printf("\n\nINGRESE OPCION: ");
	fflush(stdin);
	scanf(" %d", &menu_opcion);
	system("cls");	
	if(menu_opcion==1)
	{
		menu_completo_habilitado=1;
	}
	if(menu_opcion!=1 && menu_completo_habilitado==0)
	{
		printf("\nPrimero debe Agregar");
    }
    }while(menu_completo_habilitado==0);
	if(menu_opcion<1||menu_opcion>4)
    {
    	printf("\nError. Vuelva a ingresar.");
    	printf("\n");
		system("pause");
		system("cls");		
	}
	} while(menu_opcion<1||menu_opcion>4);
		
    switch(menu_opcion)
    {
    	case 1:
    		{
    		id = contador;
    		contador++;
    		lista[id].id = id;
    		pedirNombre(lista, id);
			pedirApellido(lista, id);
    	    pedirPrecio(lista,id);
    	    pedirTipo(lista, id);
    	    pedirCodigo(lista, id);
    	    pedirEstado(lista,id);
    		lista[id].vacio=0;
    		//FUNCION 2.2 addPassangers
	        agregarPasajeros(lista, CANTIDAD,id,lista[id].nombre,lista[id].apellido, lista[id].precio,lista[id].codigoVuelo,lista[id].tipoPasajero,lista[id].estadoVuelo);
    	    }
			break;
    	case 2:
    		{
    		printf("\nLista de pasajeros completa:\n ");
    		//FUNCION 2.6 listPassanger
			listarPasajero(lista,CANTIDAD);
			do
			{
    		printf("\nIngrese el ID del pasajero que desea buscar: ");
    		fflush(stdin);
    		scanf(" %d", &id);
    		//FUNCION 2.3 findPassengerById
    	    } while(buscarPasajeroPorId(lista, CANTIDAD, id));
    		do
    		{
    		datoModificar();
    		fflush(stdin);
    		scanf(" %d",&dato_modificar);
    		system("cls");
    		modificarDatoaccion(lista, id, dato_modificar);
    		if(dato_modificar>5 || dato_modificar<1)
    		{
    			printf("\nError. Vuelva a ingresar.");
                printf("\n");
	            system("pause");
                system("cls");	
			}
    	    } while(dato_modificar>5 || dato_modificar<1);
    	    }
    		break;
    	case 3:
    		{
    		printf("\nLista de pasajeros completa: ");
    		printf("\nID\t\tNOMBRE\t\tAPELLIDO\tPRECIO\tCODIGO DE VUELO\tTIPO DE PASAJERO");
    		listarPasajero(lista,CANTIDAD);
    		printf("\nIngrese el ID del pasajero que desea eliminar: ");
    		scanf(" %d", &id);
    		//FUNCION 2.4 removePassanger
    		removerPasajero(lista, CANTIDAD,id);
    	    }
    		break;
    	case 4:
    		{
    		do
    		{
    		printf("\nIngrese que tipo de Informacion desea: ");
    		printf("\nLista por Apellidos - (1)");
    		printf("\nPrecio de pasajes- (2)");
    		printf("\nLista por Codigo de Vuelo - (3)");
    		printf("\nOpcion: ");
    		fflush(stdin);
    		scanf(" %d", &tipo_informar);
    		system("cls");
    		if(tipo_informar>3 || tipo_informar<1)
    		{
    			printf("\nError. Vuelva a ingresar.");
                printf("\n");
	            system("pause");
                system("cls");	
			}
    	    }while(tipo_informar>3 || tipo_informar<1);
    		if(tipo_informar==1)
			{
				do
				{
				printf("\nIngrese como desea ordenar alfabeticamente los apellidos: ");
    			printf("\n1: A->Z");
    			printf("\n2: Z->A");
    			printf("\nOPCION: ");
    			fflush(stdin);
    			scanf(" %d", &orden);
    			if(orden>2 || orden<1)
    			{
    				printf("\nError. Vuelva a ingresar.");
                    printf("\n");
	                system("pause");
                    system("cls");	
				}
    		    }while(orden>2 || orden<1);
    			//FUNCION 2.5 sortPassanger
    			clasificarPasajero(lista, CANTIDAD, orden);
			}
			if(tipo_informar==2)
			{
				listaPreciopasajes(lista,CANTIDAD);
			}
			if(tipo_informar==3)
			{
				do
				{
				printf("\nIngrese como desea ordenar alfabeticamente los Codigos de Vuelo: ");
    			printf("\n1: A->Z");
    			printf("\n2: Z->A");
    			printf("\nOPCION: ");
    			fflush(stdin);
    			scanf(" %d", &orden);
    			if(orden>2 || orden<1)
    			{
    				printf("\nError. Vuelva a ingresar.");
                    printf("\n");
	                system("pause");
                    system("cls");	
				}
    		    }while(orden>2 || orden<1);
				//FUNCION 2.7 sortPassangerByCode
			clasificarPasajeroporcodigo(lista, CANTIDAD, orden);
			}
		    }
    		break;
    		default:
    		break;
	}
}while(repetir==1);
} 