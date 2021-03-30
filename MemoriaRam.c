/*
	//Programa de simulacion de la gestion de precesos en la memoria Ram
	
	//                Hecho en Mexico por 
	//     ANTROPHIA DESING TECNOLOGY S. DE R.L.
	//  Para INSTITUTO TECNOLOGICO SUPERIOR DE ZAPOPAN
	//   Guadalajara, Jalisco a 25 de Octubre 2018

	//	  Copyright Oficial 2018 All rights reserved. 
	//By: Josue Barbosa Barrera & Cecilia Alejandra Muriedas Ortiz
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

int main() {
	int opcion;
	
	inicio:
	printf("\n\t+++ SIMULACION DE MEMORIA RAM +++\n\n\tMENU :\n\n\t1.- PARTICION FIJA\n\t2.- PARTICION FIJA DE DIFERENTES TAMANIOS\n\t3.- PARTICION DINAMICA\n" );
	scanf("%i",&opcion);
	
	switch(opcion){
		case 1: particionFija();
			fflush(stdin);
			system("cls");
			goto inicio;
			break;
		case 2: particionPorTamanos();
			fflush(stdin);
			system("cls");
			goto inicio;
			break;
    	case 3: particion_dinamica();  // en construccion
			printf("Actualmente el contruccion  ......... ");
			getch();
			system("cls");
			goto inicio;
		break;
	}
	return 0;
}


void particionFija(){
	int mem,particion,opcion=0;
	int numero1=0,numero=0,tamano=0;
	char procesos[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	printf("\n\tCuanta memoria vas a almacenar? ");
	scanf("%i",&mem);
	printf("\n\tDe cuanto sera cada particion? ");
	scanf("%i",&particion);
	while(mem%particion!=0){
		printf("\n\tError 001: Particion no valida\n\tRecuerda que debe ser divisible con la memoria");
    	printf("\n\tIntentalo nuevamente");
    	printf("\n\tDe cuanto sera cada particion?");
		scanf("%i",&particion);
	}
	system("cls");
	printf("\nCreaste una memoria Ram de capacidad %i con %i particiones de tamano %i cada una\n\n",mem,mem/particion,particion);
	
	int i,j; // declaracion de variables dependientes de datos introducidos por el usuario
	int x=mem/particion;
	char memoria[x][particion];  //matriz [x=mem/particion(4)] [tamano de particion(8)]
 	printf("\nTu Memoria Ram: ");
	for(i=0;i<x;i++){
		printf("[");
    	for(j=0;j<particion;j++){ // control de vectoresde la matriz
    		memoria[i][j] =' '; // imprecion de espacion en blanco
    		printf("%c",memoria[i][j]);
    	}
    	printf("] ");
	}
	printf("\n\n");
	
	while (opcion!=3) {
    printf("\n\tQue quieres hacer con la memoria?\n\n\t1.-> Almacenar un proceso\n\t2.-> Borrar un proceso\n\t3.-> Volver al Menu Principal "); 
	scanf("%i",&opcion);
    switch(opcion){
		case 1: // 1.- Almacenar un proceso
			segundo:
    		printf("\n\tDe que tamano es el proceso a almacenar? ");
    		scanf("%i",&tamano);
    		if(tamano<=particion){
    			printf("\nTu Memoria Ram: ");
    			for(i=0;i<x;i++){ //0 0<4 0++    x = mem(32)/tama�o de particion(8) = 4 
    				printf("[");
        			for(j=0;j<particion;j++){ // debe de imprimir procesos a b c d etc....
						//0; 0<8; 0++     particion = tama�o de particion
        				if(i==(numero1) && j<tamano || memoria[i][j]==procesos[i]){ // si I = 0, y J menor q 3 o memoria[0][0] = espacio
            				//numero1=0 Y j<3    ejemplo tama�o = 3
            				memoria[i][j] = procesos[i];
							printf("%c",memoria[i][j]);
          				}else{ 
          					memoria[i][j] = ' '; // debe de imprimir espacion
          					printf("%c",memoria[i][j]);
        				}
        			}
    				printf("] ");
      			}
      		}else{
      			printf("\n\tError 010: proceso no valido\n\tRecuerda que debe ser menor o igual al tamano que elejiste particionar");
    			printf("\n\tIntentalo nuevamente\n");
    			goto segundo;
			}
      		printf("\n\n");
			tamano=0;
    		numero1++;
    		break;
    	case 2: // Borrar Particion de Memoria
    		printf("\n\tQue particion quieres borrar? ");
    		scanf("%i",&numero);
    		numero1=numero-1; // para que borre la particion digitada por el usuario sin depender del 0
    		printf("\nTu Memoria Ram: ");
    		for (i=0;i<x;i++){ // control de particiones 1, 2 3 , 4 etc....
    			printf("[");
    			for (j=0;j<particion;j++){ // control de contenidos de filas (sub indice de la fila 0,1,2,3,4 etc...)
        			if(i==(numero-1)){
        				memoria[i][j] =' '; // imprecion de un espacio en b�anco
        				printf("%c",memoria[i][j]);
					}else{
        				printf("%c",memoria[i][j]);
        			}
        		}
        		printf("] ");
      		}
      		printf("\n\n");
    		break;
    	case 3: // Salir y volver al menu principal
    		break;
    	default: //default
    		printf("\n\tError 011: Elige una opcion valida\n\n");
    	}// fin del switch
	} // fin de while
}// fin de la funcion


void particionPorTamanos(){
	int proceso=0, opc=0, i=0, j=0, k=0, particiones=0, totalP=0, idParticion=0, memoria=0;
 	int arrayAlmacen[1000]; // vector para almacenamiento de procesos
 	char procesos[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 	bool espacio=1; // validacion de espacio libre
 	
 	printf("\n\tCuanta memoria vas a almacenar ? ");
 	scanf("%i",&memoria);
 	printf("\n\tEl tamano de tu memoria Ram es: %i",memoria);
 	while (i<memoria&&espacio==1)
 	{
 		printf("\n\tDigita el tamano asignado a la particion # %i :",i);
 		scanf("%i",&particiones);
 		idParticion+=particiones;

 		if(idParticion<=memoria){
 			printf("\n\tValidacion de espacio en memoria.......\n\tEl espacio disponible es: %i ",memoria-idParticion);
 			arrayAlmacen[i]=particiones;
 			totalP++;
 			i++;
 			if(idParticion==memoria){
 				espacio=0;
			}
 		}else{
 			idParticion-=particiones;
 			printf("\n\tEl espacio disponible es: %i ",memoria-idParticion);
 			printf("\n\tError 011: No hay suficiente espacio en la memoria, para este proceso ");
		 }
	}
	
	system("cls");
	printf("\n\n");
	printf("Tu Memoria Ram ");
	for(i=0; i<totalP; i++){
		printf("[");
		for(j=0; j<arrayAlmacen[i];j++){
			printf(" ");
		}
		printf("] ");
	}
	printf("\n\n");
	
	int arrayValido[1000];
	int manejador[1000];
	for(i=0; i<totalP; i++){ //validar total de las particiones
		manejador[i]=0;
		arrayValido[i]=0;
	}

	int aux=0;
	for(i=0; i<totalP; i++){
		arrayValido[i]=arrayAlmacen[i];
	}
	
	for(i=0; i<totalP; i++){ // metodo burbuja
		for(j=i+1; j<totalP; j++){
			if(arrayValido[i]>arrayValido[j]){
				aux=arrayValido[i];
				arrayValido[i]=arrayValido[j];
				arrayValido[j]=aux;
			}
		}
	}

	do{
	printf("\n\tQue quieres hacer con la memoria? \n");
	printf("\n\t1.-> Almacenar un proceso ");
	printf("\n\t2.-> Borrar un proceso ");
	printf("\n\t3.-> Volver al Menu Principal \n");
	scanf("%i",&opc);
	if(opc==1){
		printf("\n\tDe que tamano es el proceso a almacenar ? ");
		scanf("%i",&proceso);
		bool validacion=1;
		int z=0, j=0; 
		for(i=0; i<totalP&&validacion==1;i++){
			if(proceso<=arrayValido[i]){
				for(j=0; j<totalP;j++){
					if(arrayValido[i]==arrayAlmacen[j]&&validacion==1){
						z=j;
						if(manejador[z]==0&&validacion==1){
							manejador[z] = proceso;
							validacion=0;
						}
					}
				}
			}
		}

		if(validacion==1){
			printf("\n\tError 101: Falta espacio en la memoria Ram, intenta de nuevo");
		}
		printf("\n\n");
		printf("Tu Memoria Ram ");
		for(i=0; i<totalP; i++){ // imprime las particiones  en tama�os seleccionados
			printf("[");
			if(manejador[i]==0){ // mnejadore de particiones
				for(j=0; j<arrayAlmacen[i];j++){
					printf(" ");
				}
			}else{
				for(k=0; k<arrayAlmacen[i];k++){
					if(k<manejador[i]){
						printf("%c",procesos[i]);
					}else{
						printf(" ");
					}
				}
			}
			printf("] ");
		}
	}  // fin de 1ra condicion If
	
	printf("\n");
	if(opc==2){
		int borrar=0; //EliminarProceso=borrar
		printf("\n\tDigita el numero de proceso que desea borrar: ");
		scanf("%i",&borrar);
		if(borrar<=totalP){
			manejador[borrar-1] = 0; // ejem:  1 , 2 , 3 , 4  ... etc
		}
		printf("\n\n");
		printf("Tu Memoria Ram ");
		for(i=0; i<totalP; i++){ // vuelve  imprimir las particiones
			printf("[");
			if(manejador[i]==0){ //vuele aponer en blanco la partciones seleccionada
				for(j=0; j<arrayAlmacen[i];j++){
					printf(" ");
				}
			}else{
				for(k=0; k<arrayAlmacen[i];k++){
					if(k<manejador[i]){
						printf("%c",procesos[i]);
					}else{
						printf(" ");
					}
				}
			}
			printf("] ");
		}
	}  // fin segunda condicion if
	printf("\n");
	if(opc==3){
		break;
	} // fin del 3era condicion if
	}while(opc==1||opc==2); // fin de Do while
} // fin de la funcion

void particion_dinamica(){}
