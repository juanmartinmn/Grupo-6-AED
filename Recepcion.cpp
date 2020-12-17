#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Veterinaria.h"
#include <windows.h>
#include <time.h>

const int TAMANO = 60;
typedef char nombreArchi[20];

void RegMasc(FILE *archi)
{
    int datos = 0;
    float anios;

    archi = fopen("Mascotas.dat", "r+b");
    mascota reg;

    system("cls");
    printf("Registrar Mascota\n=================\n\n0.-Volver al menu principal\n\nNombre mascota: ");
    _flushall();
    gets(reg.nombre);

    if (strcmp(reg.nombre, "0") == 0)
    {
        return;
    }

    system("cls");
    datos = 1;
    InfoMascotaActual(reg, datos);

    printf("\nDireccion: ");
    _flushall();
    gets(reg.direcc);

    system("cls");
    datos = 2;
    InfoMascotaActual(reg, datos);

    printf("\nDNI duenio: ");
    scanf("%d", &reg.DNI_DUENIO);

    system("cls");
    datos = 3;
    InfoMascotaActual(reg, datos);

    printf("\nLocalidad: ");
    _flushall();
    gets(reg.localidad);

    system("cls");
    datos = 4;
    InfoMascotaActual(reg, datos);

    printf("\nFecha nacimiento");

    printf("\n\tDia: ");
    scanf("%d", &reg.fec.dia);

    printf("\tMes: ");
    scanf("%d", &reg.fec.mes);

    printf("\tAnio: ");
    scanf("%d", &reg.fec.anio);

    time_t t = time(NULL);

    struct tm tm = *localtime(&t);

    anios = (float)(((tm.tm_year + 1900) * 365) + ((tm.tm_mon + 1) * 30) + (tm.tm_mday) - ((reg.fec.anio) * 365) - ((reg.fec.mes) * 30) - (reg.fec.dia)) / 365;

    reg.edad = anios;

    system("cls");
    datos = 5;
    InfoMascotaActual(reg, datos);

    printf("\nPeso mascota: ");
    scanf("%f", &reg.peso);

    system("cls");
    datos = 6;
    InfoMascotaActual(reg, datos);

    printf("\nNro de telefono: ");
    _flushall();
    gets(reg.numeroTel);

    system("cls");
    datos = 7;
    InfoMascotaActual(reg, datos);

    fseek(archi, 0, SEEK_END);
    fwrite(&reg, sizeof(reg), 1, archi);

    fclose(archi);
    printf("\n\nMascota registrada");
    getch();
}

void ListarAnimales(FILE *archi)
{
    int contadorAnimales = 0;

    archi = fopen("Mascotas.dat", "r+b");

    mascota reg;

    rewind(archi);

    fread(&reg, sizeof(reg), 1, archi);

    while (!feof(archi))
    {
        if (!feof(archi))
        {
            printf("Mascota: %s\n",reg.nombre);
            printf("Direccion: %s", reg.direcc);
            printf("\nDNI Due%co: %d",164,reg.DNI_DUENIO);
            printf("\nLocalidad: %s\n",reg.localidad);
            printf("Fecha de nacimiento: %d/%d/%d\n",reg.fec.dia, reg.fec.mes, reg.fec.anio);
            int auxiliar = reg.edad;
            float auxiliar2 = (reg.edad - auxiliar) * 12;
            printf("Edad: %d a%cos y %d meses",(int)reg.edad,164,(int)auxiliar2);
            printf("\nPeso: %.2f kg", reg.peso);
            printf("\nTelefono: %s", reg.numeroTel);
            contadorAnimales++;
        }

        fread(&reg, sizeof(reg), 1, archi);
    }

    if (contadorAnimales == 0)
    {
        printf("\tNo hay mascotas registradas");
    }

    fclose(archi);
    getch();
}

void RegistrarTurno(FILE *archi, FILE *archi2, FILE *archi3)
{
    archi = fopen("Turnos.dat", "r+b");
    archi2 = fopen("Veterinarios.dat", "r+b");
    archi3 = fopen("Mascotas.dat", "r+b");

    int datos = 0;
    mascota masc;
    turnos reg;
    veterinario regi;

    int dni = 0, situacion[2];
    bool matCorrecta, dniValido = false;

    system("cls");

    printf("\t\tRegistrar Turno\n=================\n\n0.-Volver al menu principal\n");

    do
    {
        matCorrecta = true;
        printf("\nMatricula del Veterinario que lo atendera: ");
        scanf("%d", &reg.matriculaVet);

        if (reg.matriculaVet == 0)
        {
            return;
        }

        CheckMatricula(reg.matriculaVet, situacion);

        if (situacion[0] == 0)
        {
            printf("\n\ERROR: Matricula no registrada");
            matCorrecta = false;
            getch();

            system("cls");
            InfoTurnoActual(reg, datos);
        }

    } while (!matCorrecta);

    system("cls");
    datos = 1;
    InfoTurnoActual(reg, datos);

    printf("\nTurno\nDia: ");
    scanf("%d", &reg.fec.dia);
    printf("Mes: ");
    scanf("%d", &reg.fec.mes);
    printf("A%co: ",164);
    scanf("%d", &reg.fec.anio);

    system("cls");
    datos = 2;
    InfoTurnoActual(reg, datos);

    do
    {
        printf("\n\nDNI Due%co: ",164);
        scanf("%d", &dni);
        rewind(archi3);

        fread(&masc, sizeof(mascota), 1, archi3);

        while (!feof(archi3))
        {
            if (masc.DNI_DUENIO == dni)
            {
                dniValido = true;
                break;
            }

            fread(&masc, sizeof(mascota), 1, archi3);
        }

        if (dniValido)
        {
            continue;
        }

        printf("\n\tError: DNI invalido");
        getch();

        system("cls");
        InfoTurnoActual(reg, datos);
    } while (!dniValido);

    reg.DNIduenio = dni;

    system("cls");
    datos = 3;
    InfoTurnoActual(reg, datos);

    reg.borrado = false;

    strcpy(reg.atencion, "No atendido");

    fseek(archi, 0, SEEK_END);
    fwrite(&reg, sizeof(reg), 1, archi);

    fclose(archi);
    fclose(archi2);
    fclose(archi3);

    printf("\nTurno a%cadido",164);
    getch();
}

void ListarTurno(FILE *archi, FILE *archi2, FILE *archi3)
{
    turnos reg;
    veterinario regi;
    mascota masc;

    int mat = 0;
    int situ[2], i = 1, mes = 0, anio = 0;
    bool matEncontrada = false;
    bool matValida = false;

    do
    {
        matValida = true;
        system("cls");
        printf("Listado de Turnos\n==================\n\n0.-Volver al menu principal\n\nMatricula veterinario: ");
        scanf("%d", &mat);

        if (mat == 0)
        {
            return;
        }

        CheckMatricula(mat, situ);
        if (situ[0] == 0)
        {
            printf("\nERROR: matricula invalida");
            getch();
            matValida = false;
        }
    } while (!matValida);

    archi3 = fopen("Mascotas.dat", "r+b");
    archi2 = fopen("Veterinarios.dat", "r+b");
    archi = fopen("Turnos.dat", "r+b");

    system("cls");

    fread(&regi, sizeof(veterinario), 1, archi2);

    while (!feof(archi2))
    {
        if (mat == regi.matricula)
        {
            matEncontrada = true;
            break;
        }

        fread(&regi, sizeof(veterinario), 1, archi2);
    }

    do
    {
        printf("Listado de Turnos\n==================\n\nVeterinario:\n");
        printf("Nombre: %s\n", regi.nomyApe);
        printf("DNI: %d\n", regi.DNI);
        printf("\n\nMes: ");
        scanf("%d", &mes);
        printf("\nA%co: ",164);
        scanf("%d", &anio);

        if ((mes < 1 or mes > 12) or (anio > 2021 or anio < 2019))
        {
            printf("\nERROR: Fecha invalida");
            getch();
        }

        system("cls");
    } while (mes < 1 or mes > 12);

    printf("Listado de Turnos\n==================\n\n");
    printf("Nombre: %s\n", regi.nomyApe);
    printf("DNI: %d\n", regi.DNI);

    printf("\nTurnos en el mes de ");

    switch (mes)
    {
    case 1:
        printf("enero");
        break;
    case 2:
        printf("febrero");
        break;
    case 3:
        printf("marzo");
        break;
    case 4:
        printf("abril");
        break;
    case 5:
        printf("mayo");
        break;
    case 6:
        printf("junio");
        break;
    case 7:
        printf("julio");
        break;
    case 8:
        printf("agosto");
        break;
    case 9:
        printf("septiembre");
        break;
    case 10:
        printf("octubre");
        break;
    case 11:
        printf("noviembre");
        break;
    case 12:
        printf("diciembre");
        break;
    }

    printf(" del a%co %d\n",164,anio);

    fread(&reg, sizeof(turnos), 1, archi);

    if (matEncontrada)
    {
        while (!feof(archi))
        {
            if (!feof(archi) and reg.matriculaVet == mat and reg.fec.mes == mes and reg.fec.anio == anio)
            {
                printf("\nTurno %d\n", i);
                printf("=======\n");

                fread(&masc, sizeof(mascota), 1, archi3);

                while (!feof(archi3))
                {
                    if (reg.DNIduenio == masc.DNI_DUENIO)
                    {
                        printf("Mascota: %s", masc.nombre);
                        break;
                    }

                    fread(&masc, sizeof(mascota), 1, archi3);
                }

                printf("\nFecha: %d/%d/%d", reg.fec.dia, reg.fec.mes, reg.fec.anio);
                printf("\nDNI: %d", reg.DNIduenio);
                printf("\nDetalles: ");
                puts(reg.atencion);
                printf("Estado: ");

                if (reg.borrado == true)
                {
                    printf("Atendido");
                }
                else
                {
                    printf("Pendiente");
                }

                i++;
            }

            fread(&reg, sizeof(turnos), 1, archi);
        }

        if (i == 1)
        {
            printf("\nNo se encontraron turnos");
        }
    }
    else
    {
        printf("\nNo hay turnos registrados");
    }

    getch();

    fclose(archi);
    fclose(archi2);
    fclose(archi3);
}

main()
{
	system("COLOR 8B");
    FILE *archivo, *archivo2, *archivo3;
    int opcion, idx = 0, idxTurnos = 0, caso = 0, salirPrograma;

    nombreArchi archivoMascotas = "Mascotas.dat", archivoTurnos = "Turnos.dat", archivoVeterinarios = "Veterinarios.dat";

    CrearArch(archivo, archivoMascotas);
    CrearArch(archivo2, archivoTurnos);
    CrearArch(archivo3, archivoVeterinarios);

    do
    {
        system("cls");

        printf("Modulo de Asistente\n===================\n\n1.-Registrar mascota\n2.-Listar mascotas\n3.-Registrar turno\n4.-Listado de atenciones por veterinario y fecha\n\n5.-Volver al menu principal\n\nIngrese una opcion -->  ");
        scanf("%d", &caso);

        switch (caso)
        {

        case 1:
            system("cls");
            RegMasc(archivo);
            break;

        case 2:
            system("cls");
            printf("\t\tListar Mascotas\n\t\t===============\n\n");
            ListarAnimales(archivo);
            break;

        case 3:
            system("cls");
            RegistrarTurno(archivo2, archivo3, archivo);
            break;

        case 4:
            system("cls");
            ListarTurno(archivo2, archivo3, archivo);
            break;
        case 5:break;
        }

    } while (caso != 5);
}








