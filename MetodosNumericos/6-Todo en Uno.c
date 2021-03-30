#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main(){
	int opc;
	
	do{
		printf("\t..:: TODO EN UNO ::..\n\n");
		printf("Por favor selecciona un metodo del Menu.\n\n");
		printf("1.- Biseccion\n2.- Regla Falsa\n3.- Punto Fijo\n4.- Secante\n5.- Newton Raphson\n\n6.- Salir\n\n");
		printf("Tu eleccion: ");
		scanf("%i",&opc);
		system("cls");
		switch(opc){
			case 1: //
				system("1.-Biseccion_v2-Final.exe");
				break;
			case 2: // 
				system("2.-reglaFalsa_v2-Final.exe");
				break;
			case 3: //
				system("3.-puntoFijo_v2-Final.exe");
				break;
			case 4: //
				system("4.-Secante_v2.exe");
				break;
			case 5: //
				system("5.-NewtonRaphson.exe");
				break;
			case 6: //salir
				break;
			default:
				printf("\nOpcion no valida\n\n");
				system("pause");
				system("cls");
			break;
		}
	}while(opc != 6);
	
	system("pause");
	return 0;
}
