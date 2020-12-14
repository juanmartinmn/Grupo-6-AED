#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct fecha{
	int dia;
	int mes;
	int anio;
};

struct veterinario{
	char apenom[60];
	int matricula;
	int cond;
	char especialidad[60];
	int dia[6];
	char password[10]; 
	float monto;
	float pago;
};

struct mascota{
	char apenom[60];
	char domicilio[60];
	int dni;
	char localidad[60];
	fecha fn;
	float altura;
	float peso;
	char obrasocial[10];
	int nda[10];
};


struct obrasoc{
	char nombre[60];
	float importe;
};

struct turnos{
	int mat;
	fecha fec;
	int dni;
	obrasoc o;
};
main(){
	
	int op, i, matm;
	char pass[10], aux[40];
	bool band;
	FILE *vet, *user, *os, *mas, *tur;
	veterinario m; turnos t; obrasoc o; mascota p;
	
	printf("Modulo Consultorio Veterinario\n==========================\n1-Iniciar sesion \n2-Visualizar lista de espera de pacientes \n3-Registrar evolucion de los pacientes\n\n4-Salir del programa\nDigite su opcion: ");
	scanf("%d",&op);
	

	
	while(op!=1&&op!=4)
	{
		printf("Para realizar esta accion debe Iniciar sesion.");
		scanf("%d",&op);
	}
	
	while(op!=4)
	{
		if(op==1)
		{
			
			vet=fopen("Vetenarios.dat","r+b");
			system("cls");
			printf("Ha seleccionado la opcion 'Iniciar sesion', por favor ingrese sus datos a continuacion: ");
			printf("\nIngrese su matricula: ");
			scanf("%d",&matm);
			fread(&m,sizeof(veterinario),1,vet);
			band=false;
			while(band==false)
			{
				while(!feof(vet))
				{
					if(matm==m.matricula)
					{
						band=true;
						fread(&m,sizeof(veterinario),1,vet);
					}
					else
					{
						fread(&m,sizeof(veterinario),1,vet);
					}
				
				}
				if(band==false)
				{
					printf("\nMatricula incorrecta, por favor intente ingresarla de nuevo: ");
					scanf("%d",&matm);
				}
				
			}
			printf("\nMatricula aceptada, ingrese su contraseña: ");
			_flushall();
			gets(pass);
			rewind(vet);
			fread(&m,sizeof(veterinario),1,vet);
			band=false;
			while(band==false)
			{
				while(!feof(vet))
				{
					if(strcmp(pass,m.password)==0)
					{
						band=true;
						fread(&m,sizeof(veterinario),1,vet);
					}
					else
					{
						fread(&m,sizeof(veterinario),1,vet);
					}
				}
				if(band==false)
				{
					printf("\nContraseña incorrecta, por favor intente de nuevo: ");
					_flushall();
					gets(pass);
				}
			}
			
			printf("\nContraseña aceptada\nInicio de sesion con exito!");
			fclose(vet);
			system("pause");
			system("cls");
			printf("Ingrese su proxima operacion: \n\n2-Visualizar lista de espera de pacientes \n3-Registrar evolucion de los pacientes\n\n4-Salir del programa");
			scanf("%d",&op);
			
		}
		else{
			if(op==2)
			{
				tur=fopen("turnos.dat","r+b");
				vet=fopen("Veterinarios.dat","r+b");
				i=0;

				
				system("cls");
				printf("Ha seleccionado la opcion 'Visualizar lista de espera de pacientes', la lista se mostrara a continuacion: ");
				
				fread(&m,sizeof(veterinario),1,vet);
				fread(&t,sizeof(turnos),1,tur);
				printf("\nLista de espera: \n");
				while(!feof(vet)||!feof(tur)){
					if(m.matricula==t.mat){
						printf("\nTurno %d:",i+1);
						printf("\nFecha:");
						printf("\n\nDia: %d",t.fec.dia);
						printf("\nMes: %d",t.fec.mes);
						printf("\nA%co: %d",164,t.fec.anio);
						printf("\nDNI del dueño: %d", t.dni);
						printf("\nObra social: \n");
						printf("\nNombre: %s",o.nombre);
						printf("\nImporte: %f", o.importe);
						
						fread(&m,sizeof(veterinario),1,vet);
						fread(&t,sizeof(turnos),1,tur);
					}
					else{
						fread(&m,sizeof(veterinario),1,vet);
						fread(&t,sizeof(turnos),1,tur);
					}
				}
				
				fclose(vet);
				fclose(tur);
				system("pause");
				system("cls");
				printf("Ingrese su proxima operacion: \n\n2-Visualizar lista de espera de pacientes \n3-Registrar evolucion de los pacientes\n\n4-Salir del programa");
				scanf("%d",&op);
			}
			else{
				if(op==3){
					
				}
				else{
					
				}
			}
		}
	}
}

