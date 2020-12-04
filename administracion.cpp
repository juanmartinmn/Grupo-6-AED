#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


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
	int checkm=0,i=0,cnum=-1,cmay=0,checkmin=0,checkmay=0,checknum=0;
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
                     cnum=-1;
                     cmay=0;}
				
              for(int j=0;j<10;j++){
                     if(user.usuario[j]=='A' or user.usuario[j]=='B' or user.usuario[j]=='C' or user.usuario[j]=='D' or user.usuario[j]=='E' or user.usuario[j]=='F' or user.usuario[j]=='G' or user.usuario[j]=='H' or user.usuario[j]=='I' or user.usuario[j]=='J' or user.usuario[j]=='K' or user.usuario[j]=='L' or user.usuario[j]=='M' or user.usuario[j]=='N' or user.usuario[j]=='Ñ' or user.usuario[j]=='O' or user.usuario[j]=='P' or user.usuario[j]=='Q' or user.usuario[j]=='R' or user.usuario[j]=='S' or user.usuario[j]=='T' or user.usuario[j]=='U' or user.usuario[j]=='V' or user.usuario[j]=='W' or user.usuario[j]=='X' or user.usuario[j]=='Y' or user.usuario[j]=='Z'){
                     cmay++;}}
                     
              if(user.usuario[i]=='0' or user.usuario[i]=='1' or user.usuario[i]=='2' or user.usuario[i]=='3' or user.usuario[i]=='4' or user.usuario[i]=='5' or user.usuario[i]=='6' or user.usuario[i]=='7' or user.usuario[i]=='8' or user.usuario[i]=='9'){
                     cnum++;
              }
                     
              if(cmay<2){
                     printf("ERROR: La cantidad de caracteres mayusculas necesarios no fue alcanzada. Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese un nombre de usuario: \n");
                     fflush(stdin);
                     gets(user.usuario);
                     i=0;
                     checkm=0;
                     cnum=-1;
                     cmay=0;}
                     
              if(cnum>5){
              	printf("ERROR: La cantidad de digitos fue excedida. Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese un nombre de usuario: \n");
                     fflush(stdin);
                     gets(user.usuario);
                     i=0;
                     checkm=0;
                     cnum=-1;
                     cmay=0;
              }

				

       } while (strlen(user.usuario)>=6 and strlen(user.usuario)<=10);
       printf("Ingrese una contraseña: \n");
       fflush(stdin);
       gets(user.password);
       do{
              for(i=0;i<32;i++){
                     if(user.password[i]=='a' or user.password[i]=='b' or user.password[i]=='c' or user.password[i]=='d' or user.password[i]=='e' or user.password[i]=='f' or user.password[i]=='g' or user.password[i]=='h' or user.password[i]=='i' or user.password[i]=='j' or user.password[i]=='k' or user.password[i]=='l' or user.password[i]=='m' or user.password[i]=='n' or user.password[i]=='ñ' or user.password[i]=='o' or user.password[i]=='p' or user.password[i]=='q' or user.password[i]=='r' or user.password[i]=='s' or user.password[i]=='t' or user.password[i]=='u' or user.password[i]=='v' or user.password[i]=='w' or user.password[i]=='x' or user.password[i]=='y' or user.password[i]=='z'){
                     checkmin++;}

                     if(user.password[i]=='A' or user.password[i]=='B' or user.password[i]=='C' or user.password[i]=='D' or user.password[i]=='E' or user.password[i]=='F' or user.password[i]=='G' or user.password[i]=='H' or user.password[i]=='I' or user.password[i]=='J' or user.password[i]=='K' or user.password[i]=='L' or user.password[i]=='M' or user.password[i]=='N' or user.password[i]=='Ñ' or user.password[i]=='O' or user.password[i]=='P' or user.password[i]=='Q' or user.password[i]=='R' or user.password[i]=='S' or user.password[i]=='T' or user.password[i]=='U' or user.password[i]=='V' or user.password[i]=='W' or user.password[i]=='X' or user.password[i]=='Y' or user.password[i]=='Z'){
                     checkmay++;}

                     if(user.password[i]=='0' or user.password[i]=='1' or user.password[i]=='2' or user.password[i]=='3' or user.password[i]=='4' or user.password[i]=='5' or user.password[i]=='6' or user.password[i]=='7' or user.password[i]=='8' or user.password[i]=='9'){
                     checknum++;}
              }

              if(checkmin==0 or checkmay==0 or checknum==0){
                     printf("ERROR: La contraseña no cumple con los parametros requeridos (No incluye mayuscula y/o minuscula y/o numero). Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese una contraseña: \n");
                     fflush(stdin);
                     gets(user.password);
                     
                     checkmin=0;
                     checkmay=0;
                     checknum=0;
              }

              if (user.password[i]=='á' or user.password[i]=='é' or user.password[i]=='í' or user.password[i]=='ó' or user.password[i]=='ú' or user.password[i]==' ' or user.password[i]=='.' or user.password[i]==',' or user.password[i]=='!' or user.password[i]=='¡' or user.password[i]=='¿' or user.password[i]=='?' or user.password[i]=='+' or user.password[i]=='-' or user.password[i]=='/' or user.password[i]==':' or user.password[i]=='*' or user.password[i]=='|' or user.password[i]=='^' or user.password[i]=='{' or user.password[i]=='}' or user.password[i]=='(' or user.password[i]==')' or user.password[i]=='[' or user.password[i]==']')
              {
                     printf("ERROR: La contraseña no debe incluir caracteres especiales. Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese una contraseña: \n");
                     fflush(stdin);
                     gets(user.password);
                     i=0;
                     checkmin=0;
                     checkmay=0;
                     checknum=0;
              }

              if(user.password[i]=='ab' or user.password[i]=='bc' or user.password[i]=='cd' or user.password[i]=='de' or user.password[i]=='ef' or user.password[i]=='fg' or user.password[i]=='gh' or user.password[i]=='hi' or user.password[i]=='ij' or user.password[i]=='jk' or user.password[i]=='kl' or user.password[i]=='lm' or user.password[i]=='mn' or user.password[i]=='no' or user.password[i]=='op' or user.password[i]=='pq' or user.password[i]=='qr' or user.password[i]=='rs' or user.password[i]=='st' or user.password[i]=='tu' or user.password[i]=='uv' or user.password[i]=='vw' or user.password[i]=='wx' or user.password[i]=='xy' or user.password[i]=='yz' or user.password[i]=='za' or user.password[i]=='AB' or user.password[i]=='BC' or user.password[i]=='CD' or user.password[i]=='DE' or user.password[i]=='EF' or user.password[i]=='FG' or user.password[i]=='GH' or user.password[i]=='HI' or user.password[i]=='IJ' or user.password[i]=='JK' or user.password[i]=='KL' or user.password[i]=='LM' or user.password[i]=='MN' or user.password[i]=='NO' or user.password[i]=='OP' or user.password[i]=='PQ' or user.password[i]=='QR' or user.password[i]=='RS' or user.password[i]=='ST' or user.password[i]=='TU' or user.password[i]=='UV' or user.password[i]=='VW' or user.password[i]=='WX' or user.password[i]=='XY' or user.password[i]=='YZ' or user.password[i]=='ZA'){
               printf("ERROR: La contraseña no debe incluir 2 letras consecutivas . Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese una contraseña: \n");
                     fflush(stdin);
                     gets(user.password);
                     i=0;
                     checkmin=0;
                     checkmay=0;
                     checknum=0;      
              }

              if(user.password[i]=='012' or user.password[i]=='123' or user.password[i]=='234' or user.password[i]=='345' or user.password[i]=='456' or user.password[i]=='567' or user.password[i]=='678' or user.password[i]=='789' or user.password[i]=='890'){
               printf("ERROR: La contraseña no debe incluir 3 numeros consecutivos . Intente de nuevo.\n");
                     system("pause");
                     system("CLS");
                     printf("Ingrese una contraseña: \n");
                     fflush(stdin);
                     gets(user.password);
                     i=0;
                     checkmin=0;
                     checkmay=0;
                     checknum=0;      
              }
              
              i++;



              

       } while (strlen(user.password)>=6 and strlen(user.password)<=32);

       fwrite(&user,sizeof(usuarios),1,user0);
       fclose(user0);
       
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

