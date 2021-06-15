#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TDA_Mapa/hashmap.h"
#include "Interfaz/interfaz.h"
#include "Estructuras/structs.h"


tipoItem * copiarInformacionItems(char * lineaLeida)
{
	tipoItem * aux = malloc (sizeof(tipoItem));
	char * fragmento;
	
	//ID
	fragmento = strtok(lineaLeida, ";");
	aux->ID = strtol(fragmento, NULL, 10);
	
	//Encontrado
	fragmento = strtok(NULL, ";");
	aux->encontrado = strtol(fragmento, NULL, 10);
	
	//Nombre
	fragmento = strtok(NULL, ";");
	strcpy(aux->nombre, fragmento);
	
	//Efecto
	fragmento = strtok(NULL, ";");
	strcpy(aux->efecto, fragmento);
	return aux;
}

void importarArchivoItems(HashMap * mapaItems)
{
	FILE * archivo = fopen("items.txt", "r");
	if(archivo == NULL) return;

	char lineaLeida[310];
	fgets(lineaLeida, 309, archivo);
	while(fgets(lineaLeida, 309, archivo))
	{
		tipoItem * nuevoItem = copiarInformacionItems(lineaLeida);
		insertMap(mapaItems, nuevoItem->nombre, nuevoItem);
	}

	fclose(archivo);
}

void mostrarTodosItems(HashMap * mapaItems)
{
	for(int i = 1; i < 553; i++)
	{
		tipoItem * aux = firstMap(mapaItems);
		while(aux != NULL)
		{
			if(aux->ID == i)
			{
				printf("%s ", aux->nombre);
				if(aux->encontrado == 0) printf(red"No encontrado\n"reset);
				else printf(green"Encontrado\n", reset);
			}
			aux = nextMap(mapaItems);
		}
	}
}