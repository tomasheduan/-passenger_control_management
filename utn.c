#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPasajero.h"
#include "utn.h"

void mostrarMenu()
{
	
	
		printf("\n--> MENU <-- ");
		printf("\nAGREGAR\t\t - (1)");
		printf("\nMODIFICAR\t - (2)");
		printf("\nBAJA\t\t - (3)");
		printf("\nINFORMAR\t - (4)");
}
int pasajeroVacio(pasajero* pArray)
{
	pArray[0].id = 0;
	strcpy(pArray[0].nombre,"");
	strcpy(pArray[0].apellido,"");
	pArray[0].precio=0;
	strcpy(pArray[0].codigoVuelo,"");
	pArray[0].tipoPasajero=0;
	pArray[0].estadoVuelo=0;
	pArray[0].vacio=1;
	return 0;
}
void datoModificar()
{
		printf("\n--> DATOS <-- ");
		printf("\nNOMBRE\t\t - (1)");
		printf("\nAPELLIDO\t - (2)");
		printf("\nPRECIO\t\t - (3)");
		printf("\nTIPO DE PAS.\t - (4)");
		printf("\nCOD. DE VUELO\t - (5)");
		printf("\nIngrese el DATO que desea modificar: ");
}
void modificarDatoaccion(pasajero* pArray, int id, int dato)
{
	if(dato==1)
	{
	    pedirNombre(pArray, id);
	}
	if(dato==2)
	{
	    pedirApellido(pArray, id);
	}
	if(dato==3)
	{
		pedirPrecio(pArray, id);
	}
	if(dato==4)
	{
		pedirTipo(pArray,id);
	}
	if(dato==5)
	{
		pedirCodigo(pArray,id);
	}
}
void listaPreciopasajes(pasajero* pArray, int limite)
{
	
	int i;
	float acumulador=0;
	float cont = 0;
	float promedio;
	int contador_supera=0;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].vacio==0)
			{
				cont++;
				acumulador = acumulador+pArray[i].precio;
			}
		}
		promedio = acumulador/cont;
		printf("\nTotal de los precios\t%.2f",acumulador);
		printf("\nPromedio de los precios\t%.2f",promedio);
		for(i=0;i<limite;i++)
		{
			if(pArray[i].vacio==0)
			{
				if(pArray[i].precio>=promedio)
				{
					contador_supera++;
				}
			}
		}
		printf("\nTotal de pasajeros que superan el promedio: \t%d", contador_supera);
		printf("\n\n");
		system("pause");
	}
}
void pedirNombre(pasajero* pArray, int id)
{
	do
    	{
    		printf("\nIngrese nombre del pasajero: ");
    		fflush(stdin);
    		gets(pArray[id].nombre);
    		system("cls");	
    		if(strlen(pArray[id].nombre)==0)
    	{
    			printf("\nNo debe dejar espacios vacios.\n");
    			printf("\n");
				system("pause");
				system("cls");
		}
		} while(validarChar(pArray[id].nombre)||strlen(pArray[id].nombre)==0);
}
void pedirApellido(pasajero* pArray, int id)
{
	do
    	{
    		printf("\nIngrese Apellido del pasajero: ");
    		fflush(stdin);
    		gets(pArray[id].apellido);
    		system("cls");	
    		if(strlen(pArray[id].apellido)==0)
    	{
    			printf("\nNo debe dejar espacios vacios.\n");
    			printf("\n");
				system("pause");
				system("cls");
		}
		} while(validarChar(pArray[id].apellido)||strlen(pArray[id].apellido)==0);
}
void pedirPrecio(pasajero* pArray, int id)
{
	int opc_precio = 0;
	do
	{
	printf("\nIngrese precio del vuelo: ");
    		printf("\n$1.000,00  -> (1)");
    		printf("\n$2.000,00  -> (2)");
    		printf("\n$3.000,00  -> (3)");
    		printf("\n$4.000,00  -> (4)");
    		printf("\n$5.000,00  -> (5)");
    		printf("\nOPCION: ");
    		fflush(stdin);
    		scanf("%d", &opc_precio);
    		system("cls");	
    		if(opc_precio<1||opc_precio>5)
    		{
    			printf("\nError. Vuelva a ingresar.");
    			printf("\n");
				system("pause");
				system("cls");		
			}
    		pArray[id].precio = (float)(opc_precio * 1000);
    	    }while(opc_precio<1||opc_precio>5);
}
void pedirTipo(pasajero* pArray, int id)
{
	do
    {
    printf("\nIngrese tipo de pasajero: ");
    printf("\nTIPO 1 - (1): ");
    printf("\nTIPO 2 - (2): ");
    printf("\nTIPO 3 - (3): ");
    printf("\nTIPO: ");
    fflush(stdin);
    scanf(" %d", &pArray[id].tipoPasajero);
    system("cls");	
    if(pArray[id].tipoPasajero<1||pArray[id].tipoPasajero>3)
    {
    printf("\nError. Vuelva a ingresar.");
    printf("\n");
	system("pause");
	system("cls");	
	pArray[id].tipoPasajero = 0;
	}
    } while(pArray[id].tipoPasajero<1||pArray[id].tipoPasajero>3);
}
void pedirCodigo(pasajero* pArray,int id)
{
	do
    {
    printf("\nIngrese codigo de vuelo (CARACTERES): ");
    fflush(stdin);
    gets(pArray[id].codigoVuelo);
    system("cls");	
    if(strlen(pArray[id].codigoVuelo)==0)
    {
    	printf("\nNo debe dejar espacios vacios.\n");
    	printf("\n");
		system("pause");
		system("cls");
	}
    } while(validarChar(pArray[id].codigoVuelo)||strlen(pArray[id].codigoVuelo)==0);
}
void pedirEstado(pasajero* pArray,int id)
{
	do
    {
    printf("\nIngrese estado de Vuelo: ");
    printf("\nACTIVO - (1): ");
    printf("\nINACTIVO - (0): ");
    printf("\nEstado: ");
	fflush(stdin);	
    scanf(" %d", &pArray[id].estadoVuelo);
    system("cls");	
    if(pArray[id].estadoVuelo<0||pArray[id].estadoVuelo>1)
    {
	printf("\nError. Vuelva a ingresar");	
    printf("\n");
	system("pause");
	system("cls");	
	pArray[id].estadoVuelo = 2;  
	}
    } while(pArray[id].estadoVuelo<0||pArray[id].estadoVuelo>1); 
}
int validarChar(char string[])
{
	int retorno = 0;
	for (int i = 0; i < strlen(string); i++)
    {
        if(isdigit(string[i]) ) 
		{
            printf("\nIngrese caracteres validos.\n");
            retorno = 1;
            return retorno;
            break;
        }
    }
    return retorno;
}