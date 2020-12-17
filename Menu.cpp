#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Veterinaria.h"
#include <windows.h>


main()
{
	system("COLOR 8B");
    char Usuario[10], Clave[10];
    int opcion, matricula;
    bool admin, veterinario, asistente;

    do
    {
        system("cls");
        printf("Bienvenido al sistema\n=====================\n\n1.-Inicio de sesion: Administrador\n2.-Inicio de sesion: Veterinario\n3.-Inicio de sesion: Asistente\n\n4.-Salir del programa\n\nIngrese una opcion -->  ");
		scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            system("cls");
            printf("Inicio de sesion: Administrador\n===============================\n\n0.-Volver al menu principal\n\nUsuario: ");
            _flushall();
            gets(Usuario);
			if (strcmp(Usuario, "0") == 0)
            {
                break;
            }
            
            printf("\nContrase%ca: ",164);
            _flushall();
            gets(Clave);

            if (LogUser(Usuario, Clave, 1))
            {
                printf("\nSesion iniciada correctamente.\n\n Redireccionando al programa.");
                admin = true;
                getch();
                system("Administracion.exe");
            }
            else
            {
                printf("\nERROR: usuario o contrase%ca incorrecto/s o inexistente/s.",164);
            }

            getch();

            break;
        case 2:
            system("cls");
            printf("Inicio de sesion: Veterinario \n=============================\n\n0.-Volver al menu principal\n\nMatricula: ");
            scanf("%d", &matricula);

            if (matricula == 0)
            {
                break;
            }
            printf("\nContrase%ca: ",164);
            _flushall();
            gets(Clave);

            if (LogVet(matricula, Clave))
            {
                printf("\nSesion iniciada correctamente.\n\n Redireccionando al programa.");
                veterinario = true;
                getch();
                system("Consultorio.exe");
            }
            else
            {
                printf("\nERROR: matricula o contrase%ca incorrecto/s o inexistente/s.",164);
            }

            getch();

            break;
        case 3:
            system("cls");
            printf("Inicio de sesion: Asistente\n============================\n\n0.-Volver al menu principal\n\nUsuario: ");
            _flushall();
            gets(Usuario);

            if (strcmp(Usuario, "0") == 0)
            {
                break;
            }

            printf("\nContrase%ca: ",164);
            _flushall();
            gets(Clave);

            if (LogUser(Usuario, Clave, 3))
            {
                printf("\nSesion iniciada correctamente.\n\n Redireccionando al programa.");
                asistente = true;

                getch();
                system("Recepcion.exe");
            }
            else
            {
                printf("\nERROR: matricula o contrase%ca incorrecto/s o inexistente/s.",164);
            }

            getch();

            break;
        case 4:break;
        }

    } while (opcion != 4);
}
