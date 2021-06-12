#include <stdio.h>
#include <stdlib.h>

#include "Librerias/Interfaz/interfaz.h"
#include "Librerias/TDA_Mapa/hashmap.h"
#include "Librerias/personajes.h"
#include "Librerias/logros.h"

void menuDesbloqueo(HashMap * mapaPersonajes,HashMap *mapaLogros)
{
	int opcion;
	char nombrePersonaje[20];
	int idBuscar;
	do
	{
		mostrarMenuDesbloqueo();
		scanf("%i", &opcion);
		printf(cls);
		if(opcion == 0) return;

		switch (opcion)
		{
		case 1:
			mostrarNombres();
			printf("\nIngrese el nombre del personaje: ");
			getchar();
			scanf("%19[^\n]s", nombrePersonaje);
			convertirMayuscula(nombrePersonaje);			
			desbloquearPersonajes(mapaPersonajes, nombrePersonaje);
			esperarEnter();
			break;
		
		case 2:
			mostrarNombres();
			printf("\nIngrese el nombre del personaje: ");
			getchar();
			scanf("%19[^\n]s", nombrePersonaje);
			convertirMayuscula(nombrePersonaje);
			avanceMarcasLogros(mapaPersonajes, nombrePersonaje);			
			esperarEnter();
			break;

		case 3:
			break;

		case 4:
			printf("Ingrese el ID del logro a desbloquear: ");
			scanf("%d",&idBuscar);
			desbloquearLogro(mapaLogros, idBuscar);
			esperarEnter();
			break;

		case 5:
			break;

		default:
			printf(red"\nLa opcion ingresada no existe\n"reset);
			break;
		}
		printf(cls);
	}while(opcion != 0);
}

int main()
{
	int opcion;
	int idBuscar;
	HashMap * mapaPersonajes = createMap(10);
	HashMap * mapaLogros = createMap(576);
	importarArchivoPersonajes(mapaPersonajes);
	importarArchivoLogros(mapaLogros);
	
	do
	{
		mostrarMenuOpciones();
		scanf("%i", &opcion);
		printf(cls);
		if(opcion == 0) break;

		switch (opcion)
		{
			case 1:
				menuDesbloqueo(mapaPersonajes,mapaLogros);
				break;

			case 2:
				guardarInfoPersonajes(mapaPersonajes);
				break;

			case 3:
				
				break;

			case 4:
				printf("Ingrese el ID del logro a buscar: ");
				scanf("%d",&idBuscar);
				buscarLogroEspecifico(mapaLogros, idBuscar);
				esperarEnter();
				break;
			
			case 5:
				
				break;

			case 6:
				mostrarPersonajes(mapaPersonajes);
				esperarEnter();
				break;

			case 7:
				
				break;

			case 8:
				mostrarLogros(mapaLogros);
				esperarEnter();
				break;

			case 9:
				
				break;

			default:
				printf(red"\nLa opcion ingresada no existe\n"reset);
				break;
		}
		printf(cls);
	}while(opcion != 0);
	printf("\nFin del Programa\n\n");

	free(mapaPersonajes);
	free(mapaLogros);

	return 0;
}