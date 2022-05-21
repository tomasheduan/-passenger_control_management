#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPasajero.h"
//FUNCION 2.1 initPassangers
int inicializacionPasajeros(pasajero* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].vacio=1;
			pArray[i].estadoVuelo=0;
		}
	}
	return retorno;	
}
//FUNCION 2.2 addPassangers
int agregarPasajeros(pasajero* pArray, int limite, int id, char nom[], char apellido[], float precio, char codigo[], int tipo, int estado)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		strcpy(pArray[id].nombre,nom);
		strcpy(pArray[id].apellido,apellido);
		pArray[id].precio=precio;
		strcpy(pArray[id].codigoVuelo,codigo);
		pArray[id].tipoPasajero=tipo;
		pArray[id].estadoVuelo=estado;
	}
	return retorno;
}
//FUNCION 2.3 findPassengerById
int buscarPasajeroPorId(pasajero* pArray, int limite, int id)
{
	int retorno = -1;
	int i;
		if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(i==id)
			{
				if(pArray[id].vacio==0)
				{
					printf("\nSe a econtrado al pasajero");
					printf("\nID: %d", id);	
					printf("\nNombre: %s", pArray[id].nombre);
					printf("\nApellido: %s", pArray[id].apellido);
					printf("\nCodigo de Vuelo: %s", pArray[id].codigoVuelo);
					printf("\nEstado de Vuelo: %d", pArray[id].estadoVuelo);
					printf("\nPrecio de Vuelo: %f", pArray[id].precio);	
					retorno = 0;
					return retorno;	
				}
				else
				    {
					printf("\nNo se a econtrado al pasajero");
					return retorno;
				    }
			}
	    }
	}
}
//FUNCION 2.4 removePassanger
int removerPasajero(pasajero* pArray, int limite, int id)
{
		int retorno = -1;
	int i;
		if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
		    if(i==id)
			{
			   printf("\nSe eliminara al pasajero: ");
			   printf("\nID: %d", id);	
			   printf("\nNombre: %s", pArray[id].nombre);
				printf("\nApellido: %s", pArray[id].apellido);
				printf("\nCodigo de Vuelo: %s", pArray[id].codigoVuelo);
				printf("\nEstado de Vuelo: %d", pArray[id].estadoVuelo);
				printf("\nPrecio de Vuelo: %f", pArray[id].precio);	
			   	pArray[id].id=pArray[0].id;
				strcpy(pArray[id].nombre,pArray[0].nombre);
				strcpy(pArray[id].apellido,pArray[0].apellido);
				pArray[id].precio=pArray[0].precio;
				strcpy(pArray[id].codigoVuelo,pArray[0].codigoVuelo);
				pArray[id].tipoPasajero=pArray[0].tipoPasajero;
				pArray[id].estadoVuelo=pArray[0].estadoVuelo;
				pArray[id].vacio=1;
				printf("\n\nPasajero Eliminado ");
			}
		}
	}
	return retorno;
}
//FUNCION 2.5 sortPassanger
int clasificarPasajero(pasajero* pArray, int limite, int ordenamiento)
{
	int retorno = -1;
	int i,j;
	int cont=0;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].vacio==0)
			{
				cont++;
			}
	    }
	    char lista_ap[cont][51];
	    int lista_tipo[cont];
	    char temp[51];
	    int temp2;
	    int k=0;
	    for(i=0;i<limite;i++)
		{
			if(pArray[i].vacio==0)
			{
				strcpy(lista_ap[k],pArray[i].apellido);
				lista_tipo[k]=pArray[i].tipoPasajero;
				k++;
			}
	    }
		for(i=0;i<cont;i++)
		{
			for(j=i;j<cont;j++)
			{
				if(ordenamiento==1)
				{
				if(strcmp(lista_ap[i],lista_ap[j])>0)
				{
					strcpy(temp,lista_ap[i]);
					strcpy(lista_ap[i],lista_ap[j]);
					strcpy(lista_ap[j],temp);
					
					
					temp2 = lista_tipo[i];
					lista_tipo[i]=lista_tipo[j];
					lista_tipo[j]=temp2;
				}
			}
			    if(ordenamiento==2)
				{
				if(strcmp(lista_ap[i],lista_ap[j])<0)
				{
					strcpy(temp,lista_ap[i]);
					strcpy(lista_ap[i],lista_ap[j]);
					strcpy(lista_ap[j],temp);
					
					temp2 = lista_tipo[i];
					lista_tipo[i]=lista_tipo[j];
					lista_tipo[j]=temp2;
				}
			   }
			}
		}
		printf("\n LISTA ORDENADA");
		printf("\n N\tAPELLIDO\t\tTIPO");
	    for(i=0;i<cont;i++)
	    {
	    	printf("\n %d\t%s\t\t\t%d",i+1,lista_ap[i],lista_tipo[i]);
		}
	}
	return 0;
}
//FUNCION 2.6 printPassanger
int listarPasajero(pasajero* pArray,int limite)
{
	int retorno = -1;
	int i;
	char tipo[51];
		if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].vacio==0)
			{
				if(pArray[i].tipoPasajero==1)
				{
					
					strcpy(tipo,"ACTIVO");
				}
				else
				{
					strcpy(tipo,"INACTIVO");
				}
				printf("\n%d-%s-%s-%.2f-%s-%s",pArray[i].id,pArray[i].nombre,pArray[i].apellido,pArray[i].precio,pArray[i].codigoVuelo, tipo);
			}
		}
	}
	return retorno;
}
//FUNCION 2.7 sortPassangerByCode
int clasificarPasajeroporcodigo(pasajero* pArray,int limite, int ordenamiento)
{
	int retorno = -1;
	int i,j;
	int cont=0;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].vacio==0)
			{
				cont++;
			}
	    }
	    char lista_cod[cont][51];
	    int lista_estado[cont];
	    char temp[51];
	    int temp2;
	    int k=0;
	    for(i=0;i<limite;i++)
		{
			if(pArray[i].vacio==0)
			{
				strcpy(lista_cod[k],pArray[i].codigoVuelo);
				lista_estado[k]=pArray[i].estadoVuelo;
				k++;
			}
	    }
		for(i=0;i<cont;i++)
		{
			for(j=i;j<cont;j++)
			{
				if(ordenamiento==1)
				{
				if(strcmp(lista_cod[i],lista_cod[j])>0)
				{
					strcpy(temp,lista_cod[i]);
					strcpy(lista_cod[i],lista_cod[j]);
					strcpy(lista_cod[j],temp);
					
					temp2 = lista_estado[i];
					lista_estado[i]=lista_estado[j];
					lista_estado[j] = temp2;
				}
			}
			    if(ordenamiento==2)
				{
				if(strcmp(lista_cod[i],lista_cod[j])<0)
				{
					strcpy(temp,lista_cod[i]);
					strcpy(lista_cod[i],lista_cod[j]);
					strcpy(lista_cod[j],temp);
					
					temp2 = lista_estado[i];
					lista_estado[i]=lista_estado[j];
					lista_estado[j] = temp2;
				}
			   }
			}
		}
		printf("\n LISTA ORDENADA");
		printf("\n N\tCodigo de Vuelo\t\tTIPO");
		char estado_ai[30];
	    for(i=0;i<cont;i++)
	    {
	    	if(lista_estado[i]==1)
	    	{
	    		strcpy(estado_ai,"ACTIVO");
			}
			else
			{
				strcpy(estado_ai,"INACTIVO");
			}
	    	printf("\n %d\t\t%s\t\t%s",i+1,lista_cod[i],estado_ai);
		}
	}
	return 0;
}
