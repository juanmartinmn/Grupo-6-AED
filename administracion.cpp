#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct fecha{
	int dia;
	int mes;
	int anio;
};

struct usuario{
	char usuario[60];
	char password[60];
	char apenom[60];		
	int cp;
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


struct obrasoc
{
	char nombre[60];
	float importe;
};

main()
{
	int op, i, mat, may=0;
	float comisionm;
	char umay[30];
	veterinario m;
	usuario u;
	obrasoc o;
	mascota p;
	bool correct, band;
	FILE *vet, *user, *os, *mas;
	 
	printf("Modulo Administraci%cn\n=====================\n\n1.-Registrar Veterinario\n2.-Registrar Usuario Asistente\n3.-Atenciones por Veterinarios\n4.-Ranking de Veterinarios por Atenciones\n\n5.-Cerrar la aplicacion\n\nIngrese una opcion: ",162,162,162,162);
	scanf("%d",&op);

	while(op!=6){
		if(op==1)
		{
			system("cls");
			vet=fopen("veterinarios.dat","a+b");
			printf("Opcion: 'Registrar veterinario', ingrese los datos solicitados.\n",162);
			printf("Ingrese su apellido y nombre: ");
			_flushall();
			gets(m.apenom);
			printf("Ingrese su especialidad: ");
			_flushall();
			gets(m.especialidad);
			m.cond=0;
			printf("Ingrese de la siguiente forma los dias de actividad\n");
			printf("(Tiene que digitar un numero de 6 digitos que represente la semana de lunes a sabado, y en donde haya trabajado ponga un 1 y donde no un 0):\n");
			for(i=0;i<6;i++)
			{
				if(i==0)
				{
					printf("Lunes: ");
					scanf("%d",&m.dia[i]);
					if(m.dia[i]==1)
					{
						m.cond++;
					}
				}
				else{
					if(i==1)
					{
						printf("Martes: ");
						scanf("%d",&m.dia[i]);
						if(m.dia[i]==1)
						{
							m.cond++;
						}
					}
					else{
						if(i==2)
						{
							printf("Miercoles: ");
							scanf("%d",&m.dia[i]);
							if(m.dia[i]==1)
							{
								m.cond++;
							}
						}
						else{
							if(i==3)
							{
								printf("Jueves: ");
								scanf("%d",&m.dia[i]);
								if(m.dia[i]==1)
								{
									m.cond++;
								}
							}
							else{
								if(i==4)
								{
									printf("Viernes: ");
									scanf("%d",&m.dia[i]);
									if(m.dia[i]==1)
									{
										m.cond++;
									}
								}
								else{
									if(i==5)
									{
										printf("Sabado: ");
										scanf("%d",&m.dia[i]);
										if(m.dia[i]==1)
										{
											m.cond++;
										}
									}
								}
							}
						}
					}
				}
			}
			printf("\nIngrese su numero de matricula: ");
			scanf("%d",&m.matricula);
			printf("\nIngrese la contrase%ca para el veterinario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contrase%ca: ",164,164);
			_flushall();
			gets(m.password);
			correct=false;
			while(correct==false){
		
				if(strstr(m.password,"Q")==NULL &&strstr(m.password,"W")==NULL && strstr(m.password,"E")==NULL && strstr(m.password,"R")==NULL && strstr(m.password,"T")==NULL && strstr(m.password,"Y")==NULL && strstr(m.password,"U")==NULL && strstr(m.password,"I")==NULL && strstr(m.password,"O")==NULL && strstr(m.password,"P")==NULL && strstr(m.password,"A")==NULL && strstr(m.password,"S")==NULL && strstr(m.password,"D")==NULL && strstr(m.password,"F")==NULL && strstr(m.password,"G")==NULL && strstr(m.password,"H")==NULL && strstr(m.password,"J")==NULL && strstr(m.password,"K")==NULL && strstr(m.password,"L")==NULL && strstr(m.password,"Ñ")==NULL && strstr(m.password,"Z")==NULL && strstr(m.password,"X")==NULL && strstr(m.password,"C")==NULL && strstr(m.password,"V")==NULL && strstr(m.password,"B")==NULL && strstr(m.password,"N")==NULL && strstr(m.password,"M")==NULL)
				{
					printf("La contrase%ca no posee mayuscula, ingrese de nuevo la contrase%ca: ",164,164);
					_flushall;
					gets(m.password);
				}
				else
				{
					if(strstr(m.password,"q")==NULL &&strstr(m.password,"w")==NULL && strstr(m.password,"e")==NULL && strstr(m.password,"r")==NULL && strstr(m.password,"t")==NULL && strstr(m.password,"y")==NULL && strstr(m.password,"u")==NULL && strstr(m.password,"i")==NULL && strstr(m.password,"o")==NULL && strstr(m.password,"p")==NULL && strstr(m.password,"a")==NULL && strstr(m.password,"s")==NULL && strstr(m.password,"d")==NULL && strstr(m.password,"f")==NULL && strstr(m.password,"g")==NULL && strstr(m.password,"h")==NULL && strstr(m.password,"j")==NULL && strstr(m.password,"k")==NULL && strstr(m.password,"l")==NULL && strstr(m.password,"ñ")==NULL && strstr(m.password,"z")==NULL && strstr(m.password,"x")==NULL && strstr(m.password,"c")==NULL && strstr(m.password,"v")==NULL && strstr(m.password,"b")==NULL && strstr(m.password,"n")==NULL && strstr(m.password,"m")==NULL)
					{
						printf("La contrase%ca no posee minuscula, ingrese de nuevo la contrase%ca: ",164,164);
						_flushall;
						gets(m.password);
					}
					else
					{
						if(strstr(m.password,"0")==NULL && strstr(m.password,"1")==NULL && strstr(m.password,"2")==NULL && strstr(m.password,"3")==NULL && strstr(m.password,"4")==NULL && strstr(m.password,"5")==NULL && strstr(m.password,"6")==NULL && strstr(m.password,"7")==NULL && strstr(m.password,"8")==NULL && strstr(m.password,"9")==NULL)
						{
							printf("La contrase%ca no posee numeros, ingrese de nuevo la contrase%ca: ",164,164);
							_flushall;
							gets(m.password);
						}
						else
						{
							if(strstr(m.password,",")!=NULL && strstr(m.password,".")!=NULL && strstr(m.password,"-")!=NULL && strstr(m.password,"á")!=NULL && strstr(m.password,"é")!=NULL && strstr(m.password,"í")!=NULL && strstr(m.password,"ó")!=NULL && strstr(m.password,"ú")!=NULL && strstr(m.password,",")!=NULL && strstr(m.password,"Á")!=NULL && strstr(m.password,"É")!=NULL && strstr(m.password,"Í")!=NULL && strstr(m.password,"Ó")!=NULL && strstr(m.password,"Ú")!=NULL)
							{
								printf("La contrase%ca posee signos de puntuacion, ingrese de nuevo la contrase%ca: ",164,164);
								_flushall;
								gets(m.password);
							}
							else
							{
								if(strlen(m.password)<6)
								{
									printf("La contrase%ca es muy corta, ingrese de nuevo la contrase%ca: ",164,164);
									_flushall;
									gets(m.password);
								}
								else
								{
									if(strlen(m.password)>32)
									{
										printf("La contrase%ca es muy larga, ingrese de nuevo la contrase%ca: ",164,164);
										_flushall;
										gets(m.password);
									}
									else
									{
										for(i=0;i<strlen(m.password);i++)
										{
											if((m.password[i+2]==m.password[i+1]+1) && (m.password[i+1]==m.password[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese de nuevo la contrase%ca: ",164);
												_flushall();
												gets(m.password);
											}
											else
											{
												correct=true;
											}
										}								
										if(correct==true)
										{
											printf("\ncontrase%ca aceptada\n",164);
											
										}
									}
								}
							}
						}
					}
				}
			}
			
			fwrite(&m,sizeof(veterinario),1,vet);
			system("pause");
			system("cls");
			printf("Ingrese una nueva operaci%cn: ",162);
			printf("\n1-Registrar veterinario\n2-Registrar usuario recepci%cn\n3-Registrar obras sociales y montos\n4-Liquidaci%cn de veterinarios\n5-Empleados con mayor registros\n\n6-Salir del programa\n\n Digite su proxima opci%cn: ",162,162,162);
			scanf("%d",&op);
		
		}
		else
		{
			if(op==2)
			{
				system("cls");
				int cm=0, cn=0;
				bool b1, b2 , b3, b4, b5;
				char aux[20];
				user=fopen("Usuarios.dat","a+b");
				printf("\nHa seleccionado 'Registrar Usuario Recepcion', por favor ingrese los datos que se solicitan a continuacion: \n\n");
				printf("Nombre de usuario \n(Tiene que comenzar con una letra minuscula, tener al menos 2 mayusculas, y no mas de 3 digitos): ");
				_flushall();
				gets(aux);
				b1=false; b2=false; b3=false; b4=false; b5=false;
				/*
				b1==Sea unico para cada usuario*
				b2==Comenzar con una letra minuscula*
				b3==Tener al menos 2 letras mayusculas*
				b4==Tener como maximo 3 digitos*
				b5==Cantidad de caracteres*
				
				*/
		    	while(b1==false && b2==false && b3==false && b4==false && b5==false){
					rewind(user);
    				fread(&u,sizeof(usuario),1,user);
					while(!feof(user)){
						if(strcmp(aux,u.usuario)){
							printf("\nEste nombre de usuario ya existe, por favor digite otro: ");
							gets(aux);
							b1=false;	
						}
						else{
							b1=true;
						}
					}
							
							
					if(aux[0]=='q' ||	aux[0]=='w' || aux[0]=='e' || aux[0]=='r' || aux[0]=='t' || aux[0]=='y' || aux[0]=='u' || aux[0]=='i' || aux[0]=='o' || aux[0]=='p' || aux[0]=='a' || aux[0]=='s' || aux[0]=='d' || aux[0]=='f' || aux[0]=='g' || aux[0]=='h' || aux[0]=='j' || aux[0]=='k' || aux[0]=='l' || aux[0]=='ñ' || aux[0]=='z' || aux[0]=='x' || aux[0]=='c' || aux[0]=='v' || aux[0]=='b' || aux[0]=='n' || aux[0]=='m'){
						b2=true;
					}
					else{
						b2=false;
						printf("El nombre no comienza con minuscula, por favor digite otro: ");
						gets(aux);
					}
																													
					for(i=0;i<20;i++){
						if(aux[i]=='A'||aux[i]=='B'||aux[i]=='C'||aux[i]=='D'||aux[i]=='E'||aux[i]=='F'||aux[i]=='G'||aux[i]=='H'||aux[i]=='I'||aux[i]=='J'||aux[i]=='K'||aux[i]=='L'||aux[i]=='M'||aux[i]=='N'||aux[i]=='O'||aux[i]=='P'||aux[i]=='Q'||aux[i]=='R'||aux[i]=='S'||aux[i]=='T'||aux[i]=='U'||aux[i]=='V'||aux[i]=='W'||aux[i]=='X'||aux[i]=='Y'||aux[i]=='Z'){
							cm++;
						}
					}
					if(cm<2){
						printf("\nNo posee 2 mayusculas o mas, por favor digite otro:  ");
						gets(aux);
						b3=false;
					}
					else{
						b3=true;
					}
					for(i=0;i<20;i++){
						if(aux[i]=='1'){
							cn++;
						}
						else{
							if(aux[i]=='2'){
								cn++;
							}
							else{
								if(aux[i]=='3'){
									cn++;
								}
								else{
									if(aux[i]=='4'){
										cn++;	
						   			}
						   			else{
						   				if(aux[i]=='5'){
						   					cn++;
									    }
									    else{
									    	if(aux[i]=='6'){
									    		cn++;
											}
											else{
												if(aux[i]=='7'){
													cn++;
												}
												else{
													if(aux[i]=='8'){
														cn++;
													}
													else{
														if(aux[i]=='9'){
															cn++;
														}
														else{
															if(aux[i]=='0'){
																cn++;
															}
														}
													}
												}
											}
										}
								    }
								}
							}
						}
					}
					
					if(cn>3){
						printf("\nEl maximo de numeros permitidos es 3, por favor digite otro: ",cn);
						gets(aux);
						b4=false;
					}
					else{
						b4=true;
					}
					if(strlen(aux)>10 || strlen(aux)<6){
						printf("\nEl tamaño del nombre no es valido, por favor digite otro: ",164);
						gets(aux);
						b5=false;
					}
					else{
						b5=true;
					}				
				} 
				
				printf("\nIngrese la contrase%ca para el usuario, debera cumplir con los siguientes requerimientos: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contrase%ca: ",164,164);
				_flushall();
				gets(u.password);
				correct=false;
				
				while(correct==false){
				if(strstr(u.password,"Q")==NULL && strstr(u.password,"W")==NULL && strstr(u.password,"E")==NULL && strstr(u.password,"R")==NULL && strstr(u.password,"T")==NULL && strstr(u.password,"Y")==NULL && strstr(u.password,"U")==NULL && strstr(u.password,"I")==NULL && strstr(u.password,"O")==NULL && strstr(u.password,"P")==NULL && strstr(u.password,"A")==NULL && strstr(u.password,"S")==NULL && strstr(u.password,"D")==NULL && strstr(u.password,"F")==NULL && strstr(u.password,"G")==NULL && strstr(u.password,"H")==NULL && strstr(u.password,"J")==NULL && strstr(u.password,"K")==NULL && strstr(u.password,"L")==NULL && strstr(u.password,"Ñ")==NULL && strstr(u.password,"Z")==NULL && strstr(u.password,"X")==NULL && strstr(u.password,"C")==NULL && strstr(u.password,"V")==NULL && strstr(u.password,"B")==NULL && strstr(u.password,"N")==NULL && strstr(u.password,"M")==NULL)
				{
					printf("ERROR: La contrase%ca no contiene mayusculas, pruebe otra contrase%ca.",164,164);
					_flushall;
					gets(u.password);
				}
				else
				{
					if(strstr(u.password,"q")==NULL && strstr(u.password,"w")==NULL && strstr(u.password,"e")==NULL && strstr(u.password,"r")==NULL && strstr(u.password,"t")==NULL && strstr(u.password,"y")==NULL && strstr(u.password,"u")==NULL && strstr(u.password,"i")==NULL && strstr(u.password,"o")==NULL && strstr(u.password,"p")==NULL && strstr(u.password,"a")==NULL && strstr(u.password,"s")==NULL && strstr(u.password,"d")==NULL && strstr(u.password,"f")==NULL && strstr(u.password,"g")==NULL && strstr(u.password,"h")==NULL && strstr(u.password,"j")==NULL && strstr(u.password,"k")==NULL && strstr(u.password,"l")==NULL && strstr(u.password,"ñ")==NULL && strstr(u.password,"z")==NULL && strstr(u.password,"x")==NULL && strstr(u.password,"c")==NULL && strstr(u.password,"v")==NULL && strstr(u.password,"b")==NULL && strstr(u.password,"n")==NULL && strstr(u.password,"m")==NULL)
					{
						printf("ERROR: La contrase%ca no contiene minusculas, pruebe otra contrase%ca.",164,164);
						_flushall;
						gets(u.password);
					}
					else
					{
						if(strstr(u.password,"0")==NULL && strstr(u.password,"1")==NULL && strstr(u.password,"2")==NULL && strstr(u.password,"3")==NULL && strstr(u.password,"4")==NULL && strstr(u.password,"5")==NULL && strstr(u.password,"6")==NULL && strstr(u.password,"7")==NULL && strstr(u.password,"8")==NULL && strstr(u.password,"9")==NULL)
						{
							printf("ERROR: La contrase%ca no contiene numeros, pruebe otra contrase%ca.",164,164);
							_flushall;
							gets(u.password);
						}
						else
						{
							if(strstr(u.password,",")!=NULL && strstr(u.password,".")!=NULL && strstr(u.password,"-")!=NULL && strstr(u.password,"á")!=NULL && strstr(u.password,"é")!=NULL && strstr(u.password,"í")!=NULL && strstr(u.password,"ó")!=NULL && strstr(u.password,"ú")!=NULL && strstr(u.password,",")!=NULL && strstr(u.password,"Á")!=NULL && strstr(u.password,"É")!=NULL && strstr(u.password,"Í")!=NULL && strstr(u.password,"Ó")!=NULL && strstr(u.password,"Ú")!=NULL)
							{
								printf("ERROR: La contrase%ca contiene signos de puntuacion, pruebe otra contrase%ca.",164,164);
								_flushall;
								gets(u.password);
							}
							else
							{
								if(strlen(u.password)<6)
								{
									printf("ERROR: La contrase%ca es muy corta, debe tener entre 6 y 32 caracteres, pruebe otra contrase%ca.",164,164);
									_flushall;
									gets(u.password);
								}
								else
								{
									if(strlen(u.password)>32)
									{
										printf("ERROR: La contrase%ca es muy larga, debe tener entre 6 y 32 caracteres, pruebe otra contrase%ca.",164,164);
										_flushall;
										gets(u.password);
									}
									else
									{
										for(i=0;i<strlen(u.password);i++)
										{
											if((u.password[i+2]==u.password[i+1]+1) && (u.password[i+1]==u.password[i]+1))
											{
												printf("ERROR: No ingrese numeros ni letras consecutivos, ingrese de nuevo la contrase%ca: ",164);
												_flushall();
												gets(u.password);
											}
											else
											{
												correct=true;
											}
										}								
										if(correct==true)
										{
											printf("La contrase%ca cumple con lo requerido. contrase%ca aceptada",164);
											
										}
									}
								}
							}
						}
					}
				}
			}
				
			strcpy(u.usuario,aux);
			fwrite(&u,sizeof(usuario),1,user);
			printf("\nEl usuario recepcion fue guardado correctamente");
			system("pause");
			system("cls");
			printf("Ingrese una nueva operaci%cn: ",162);
			printf("\n1-Registrar veterinario\n2-Registrar usuario recepci%cn\n3-Registrar obras sociales y montos\n4-Liquidaci%cn de veterinarios\n5-Empleados con mayor registros\n\n6-Salir del programa\n\n Digite su proxima opci%cn: ",162,162,162);			scanf("%d",&op);
				
			}
			else
			{
				if(op==3){
					system("cls");
					os=fopen("ObraSocial.dat","a+b");
					printf("Ha seleccionado la opcion 'Registrar obras sociales y montos', ingrese la informacion de la obre social: ");
					printf("\nIngrese el nombre: ");
					_flushall();
					gets(o.nombre);
					printf("Ingrese su importe por atencion: ");
					scanf("%f",&o.importe);
					fwrite(&o,sizeof(obrasoc),1,os);
					system("pause");
					system("cls");
					printf("Ingrese una nueva operaci%cn: ",162);
					printf("\n1-Registrar veterinario\n2-Registrar usuario recepci%cn\n3-Registrar obras sociales y montos\n4-Liquidaci%cn de veterinarios\n5-Empleados con mayor registros\n\n6-Salir del programa\n\n Digite su proxima opci%cn: ",162,162,162);					scanf("%d",&op);
					
				}
				else
				{
					if(op==4)
					{
						system("cls");
						printf("Ha ingresado la opcion 'Liquidacion de veterinarios'");
						rewind(os);
						rewind(vet);
						mas=fopen("Mascotas.dat","r+b");
						printf("\nIngrese la matricula del veterinario para realizar su liquidacion: ");
						scanf("%d",&mat);
						fread(&m,sizeof(veterinario),1,vet);
						band=false;
						while(!feof(vet))
						{
							if(mat==m.matricula)
							{
								if(strstr(p.obrasocial,"NO")!=NULL)
								{
									m.pago=o.importe*m.cond;
								}
								else
								{
									printf("\nIngrese el monto de atencion por dia del veterinario: ");
									scanf("%f",&m.monto);
									m.pago=m.monto*m.cond;
								}
								band=true;
								fread(&m,sizeof(veterinario),1,vet);
							}
							else
							{
								fread(&m,sizeof(veterinario),1,vet);
							}
						}
						fclose(mas);
						system("pause");
						system("cls");
						printf("Ingrese una nueva operaci%cn: ",162);
						printf("\n1-Registrar veterinario\n2-Registrar usuario recepci%cn\n3-Registrar obras sociales y montos\n4-Liquidaci%cn de veterinarios\n5-Empleados con mayor registros\n\n6-Salir del programa\n\n Digite su proxima opci%cn: ",162,162,162);						scanf("%d",&op);
					}
					else{
						if(op==5){
						system("cls");
						printf("Empleado con Mayor Registros: ");
						rewind(user);
						
						fread(&u,sizeof(usuario),1,user);
						while(!feof(user)){
							if(u.cp>may){
								may=u.cp;
								strcpy(u.apenom,umay);
							}
							fread(&u,sizeof(usuario),1,user);
						}
						
						printf("El usuario que registro mas pacientes es: %s con %d pacientes\n", umay, may);
						
						
						
						printf("Ingrese una nueva operaci%cn: ",162);
						printf("\n1-Registrar veterinario\n2-Registrar usuario recepci%cn\n3-Registrar obras sociales y montos\n4-Liquidaci%cn de veterinarios\n5-Empleados con mayor registros\n\n6-Salir del programa\n\n Digite su proxima opci%cn: ",162,162,162);
						}
						else{
							if(op==6){
								printf("\nGracias por utilizar nuestro programa, Hasta luego.\n");
								getch();
							}
						}
					}
				}
			}
		}
	
	
	
	}
}
