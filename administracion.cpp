#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct usuarios{
	char usuario[10];
	char password[10];
	char nomb[60];
	
};

struct veterinario{
	char nomb[60];
	int matricula;
	int dni;
	char telefono[25];
};

void regvet(FILE*vet0,veterinario vet);
void reguser(FILE*user0,usuarios user);

void regvet(FILE*vet0,veterinario vet){
       system("CLS");
       vet0=fopen("veterinario.dat","ab");
       printf("Bienvenido al registro");
       printf("======================");
       printf("Ingrese los datos requeridos.");
       printf("Ingrese el nombre y apellido/s del veterinario: ");
       fflush(stdin);
       gets(vet.nomb);
       printf("Ingrese su matricula: ");
       scanf("%d",&vet.matricula);
       printf("Ingrese su DNI: ");
       scanf("%d",&vet.dni);
       printf("Ingrese su numero de telefono");
       fflush(stdin);
       gets(vet.telefono);
       fwrite(&vet,sizeof(veterinario),1,vet0);
       fclose(vet0);
}

void reguser(FILE*user0,usuarios user){
       int checkm=0,i=0,cnum=0,cmay=0;
       system("CLS");
       user0=fopen("usuarios.dat","ab");
       printf("Bienvenido al registro\n");
       printf("Ingrese su apellido y nombre: \n");
       fflush(stdin);
       gets(user.nomb);
       printf("Ingrese un nombre de usuario: \n");
       fflush(stdin);
       gets(user.usuario);
       do{ 
	   		if(user.usuario[i]=='a' or user.usuario[i]=='b' or user.usuario[i]=='c' or user.usuario[i]=='d' or user.usuario[i]=='e' or user.usuario[i]=='f' or user.usuario[i]=='g' or user.usuario[i]=='h' or user.usuario[i]=='i' or user.usuario[i]=='o' or user.usuario[i]=='j' or user.usuario[i]=='k' or user.usuario[i]=='l' or user.usuario[i]=='m' or user.usuario[i]=='n' or user.usuario[i]=='ñ' or user.usuario[i]=='o' or user.usuario[i]=='p' or user.usuario[i]=='q' or user.usuario[i]=='r' or user.usuario[i]=='s' or user.usuario[i]=='t' or user.usuario[i]=='u' or user.usuario[i]=='v' or user.usuario[i]=='w' or user.usuario[i]=='x' or user.usuario[i]=='y' or user.usuario[i]=='z'){
                     checkm++;}
              i++;
              
              if(checkm==0){
                     printf("ERROR: El primer caracter del nombre de usuario no es una minuscula. Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese un nombre de usuario: \n");
                     fflush(stdin);
                     gets(user.usuario);
                     i=0;
                     checkm=0;
                     cnum=0;
                     cmay=0;}
				
              for(int j=0;j<10;j++){
                     if(user.usuario[j]=='A' or user.usuario[j]=='B' or user.usuario[j]=='C' or user.usuario[j]=='D' or user.usuario[j]=='E' or user.usuario[j]=='F' or user.usuario[j]=='G' or user.usuario[j]=='H' or user.usuario[j]=='I' or user.usuario[j]=='J' or user.usuario[j]=='K' or user.usuario[j]=='L' or user.usuario[j]=='M' or user.usuario[j]=='N' or user.usuario[j]=='Ñ' or user.usuario[j]=='O' or user.usuario[j]=='P' or user.usuario[j]=='Q' or user.usuario[j]=='R' or user.usuario[j]=='S' or user.usuario[j]=='T' or user.usuario[j]=='U' or user.usuario[j]=='V' or user.usuario[j]=='W' or user.usuario[j]=='X' or user.usuario[j]=='Y' or user.usuario[j]=='Z'){
                     cmay++;}}
                     
              
                     
              if(cmay<2){
                     printf("ERROR: La cantidad de caracteres mayusculas necesarios no fue alcanzada. Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese un nombre de usuario: \n");
                     fflush(stdin);
                     gets(user.usuario);
                     i=0;
                     checkm=0;
                     cnum=0;
                     cmay=0;}

				

       } while (strlen(user.usuario)>=6 and strlen(user.usuario)<=10);
}
        
           


main (){
int opcion;
FILE* vets;
FILE* users;
usuarios user;
veterinario vet;

    do {
    	printf("\tMódulo Administración\n");
    	printf("=========================\n");
        printf("1.- Registrar Veterinario\n");
        printf("2.- Registrar Usuario Asistente\n");
        printf("3.- Atenciones por Veterinarios\n");
        printf("4.- Ranking de Veterinarios por Atenciones\n");
        printf("5.- Cerrar la aplicación.\n\n");
        printf("Ingrese una opcion: ");
        scanf("%i",&opcion);
        switch (opcion) {
            case 1:regvet(vets,vet);
                   break;
            case 2:reguser(users,user);
                   break;

        }
    } while (opcion!=5);
    return 0;	
	
}
