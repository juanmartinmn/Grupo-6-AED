#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Veterinaria.h"
#include <windows.h>

typedef char nombreArchi[20];


void MostrarTurnos(FILE *arch, FILE *arch2, FILE *arch3)
{
	turnos reg;
	veterinario regi;
	mascota masc;

	int mat = 0;
	int situ[2], i = 1;
	bool matEncontrada = false;
	bool matValida = false;

	do
	{
		matValida = true;
		system("cls");
		printf("Listado de Turnos\n==================\n\n0.-Volver al menu principal\n\n\nMatricula veterinario: ");
		scanf("%d", &mat);

		if (mat == 0)
		{
			break;
		}

		CheckMatricula(mat, situ);
		if (situ[0] == 0)
		{
			printf("\n\ERROR: matricula inexistente en el sistema");
			getch();
			matValida = false;
		}
	} while (!matValida);

	if (mat != 0)
	{
		arch3 = fopen("Mascotas.dat", "r+b");
		arch2 = fopen("Veterinarios.dat", "r+b");
		arch = fopen("Turnos.dat", "r+b");

		system("cls");

		fread(&regi, sizeof(veterinario), 1, arch2);

		while (!feof(arch2))
		{
			if (mat == regi.matricula)
			{
				matEncontrada = true;
				break;
			}

			fread(&regi, sizeof(veterinario), 1, arch2);
		}

		printf("\n\tVeterinario:\n");
		printf("\%20s: %s\n", "Nombre", regi.nomyApe);
		printf("\%20s: %d\n", "DNI", regi.DNI);

		printf("\nTurnos:\n");

		fread(&reg, sizeof(turnos), 1, arch);

		if (matEncontrada)
		{
			while (!feof(arch))
			{
				if (!feof(arch) and reg.matriculaVet == mat and !reg.borrado)
				{
					printf("\nTurno %d\n\n", i);

					fread(&masc, sizeof(mascota), 1, arch3);

					while (!feof(arch3))
					{
						if (reg.DNIduenio == masc.DNI_DUENIO and !reg.borrado)
						{
							printf("\nNombre: %s",masc.nombre);
							printf("\nDireccion: %s", masc.direcc);
							printf("\nDNI Due%co: %d",164,masc.DNI_DUENIO);
							printf("\nLocalidad: %s", masc.localidad);
							int auxiliar = masc.edad;
							float auxiliar2 = (masc.edad - auxiliar) * 12;
							printf("\nEdad: %d a%cos, %d meses",(int)masc.edad,164,(int)auxiliar2);
							printf("\nPeso: %.2f kg", masc.peso);
							break;
						}

						fread(&masc, sizeof(mascota), 1, arch3);
					}

					printf("\nFecha: %d/%d/%d",reg.fec.dia, reg.fec.mes, reg.fec.anio);

					i++;
				}

				fread(&reg, sizeof(turnos), 1, arch);
			}

			if (i == 1)
			{
				printf("\n\tNo hay turnos");
			}
		}

		getch();

		fclose(arch);
		fclose(arch2);
		fclose(arch3);
	}
}

void evolucionMascota(FILE *archivo, FILE *archivo2)
{
	system("cls");
	char apeynom[60], aux[380];
	int opc = 0, datos = 0;
	bool nombreValido = false;
	bool turnoPendiente = false;

	printf("Registrar Evolucion de Mascota\n==============================\n");

	archivo = fopen("Mascotas.dat", "r+b");
	archivo2 = fopen("Turnos.dat", "r+b");

	turnos reg;
	mascota regi;

	do
	{
		printf("\n0.-Volver al menu principal\n\n Ingrese el Nombre de la mascota: ");
		_flushall();
		gets(apeynom);

		if (strcmp(apeynom, "0") == 0)
		{
			return;
		}

		fread(&regi, sizeof(regi), 1, archivo);

		while (!feof(archivo))
		{
			if ((strcmp(regi.nombre, apeynom) == 0))
			{
				fread(&reg, sizeof(reg), 1, archivo2);

				while (!feof(archivo2))
				{
					if ((reg.DNIduenio == regi.DNI_DUENIO) and (reg.borrado == false) and (strcmp(regi.nombre, apeynom) == 0))
					{
						turnoPendiente = true;
						fseek(archivo2, (long)-sizeof(turnos), SEEK_CUR);
						break;
					}

					fread(&reg, sizeof(reg), 1, archivo2);
				}

				nombreValido = true;
				break;
			}

			fread(&regi, sizeof(regi), 1, archivo);
		}

		if (!nombreValido)
		{
			printf("\nERROR: Nombre no encontrado en el sistema");
			getch();

			system("cls");
			InfoEvolucionActual(reg, regi, datos);
		}

	} while (!nombreValido);

	system("cls");
	datos = 1;
	InfoEvolucionActual(reg, regi, datos);

	if (turnoPendiente)
	{
		printf("\nInforme: ");
		_flushall();
		gets(aux);

		strcpy(reg.atencion, aux);

		system("cls");
		datos = 2;
		InfoEvolucionActual(reg, regi, datos);

		reg.borrado = true;

		fwrite(&reg, sizeof(reg), 1, archivo2);

		printf("\nRegistro completado con exito");
	}
	else
	{
		printf("\n Sin turnos pendientes");
	}

	fclose(archivo);
	fclose(archivo2);

	getch();
}

main()
{
	system("COLOR 8B");
	FILE *archivo, *archivo2, *archivo3;
	int caso = 0, opc = 0, salirPrograma = 0;

	archivo = fopen("Mascotas.dat", "r+b");
	archivo2 = fopen("Turnos.dat", "r+b");
	archivo3 = fopen("Veterinarios.dat", "r+b");

	do
	{
		system("cls");

		printf("Modulo Veterinario\n==================\n\n1.-Visualizar lista de espera de turnos (informe)\n2.-Registrar evolucion mascota\n\n3.-Volver al menu principal\n\nIngrese una opcion --> ");
		scanf("%d", &caso);

		switch (caso)
		{
		case 1:
			MostrarTurnos(archivo2, archivo3, archivo);
			break;
		case 2:
			evolucionMascota(archivo, archivo2);
			break;
		case 3:break;
		}

	} while (caso != 3);

	fclose(archivo);
	fclose(archivo2);
	fclose(archivo3);
}




