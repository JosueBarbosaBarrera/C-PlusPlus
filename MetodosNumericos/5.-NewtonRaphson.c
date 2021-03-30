#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

float fx(float x){
	return exp(-x) - log(x);
}

float fxd(float x){ //funcion derivada de X
	return -exp(-x) - (1/x);
}

void iteracion(){ // Evaluar por iteraciones + error relativo
	int i=0, iter;
	float x, xn, z=0.0, error=0.0, z0 = 0.0;
	
	printf("Dame el numero de iteraciones:\n");
	scanf("%i",&iter);
	printf("Ingrese el intervalo inicial [x]\n");
	scanf("%f",&x); //esto captura el valor de X

	printf("\n    X\t    f(x)        f´(x)     X++     Error Relativo\n");  // la variable "c" actua como X en este caso.
	for(i;i<iter;i++){  //calculo de iteraciones
		z0 = z;
		z = x; // valor de x es lo que me de xn
		
		error=(z-z0)/z;  // X actual - X anterio / X
		
		if(i==0){ //primer error siempre es = 0
			error=0;
		}
		
		xn = x - (fx(x)/fxd(x)); // funcion para encontar la Xn++
		printf("%f  %f  %f  %f  %f\n",x,fx(x),fxd(x),xn,error);
		x = xn; //se asigna la nueva x a x jeje
	}
		
	system("pause");
	system("cls");
}

void funcion(){ // por funcion no se puede evaluar
	printf("\tno se puede evaluar por funcion\n\tjajajajaja\n");
	system("pause");
}

void error(){ // validar por Error
	
	int i=0;
	float x, xn, z = 0.0, errorDigitado, error = 0.0, y = 0.0, z0 = 0.0;
	
	printf("Digita el error Relativo a encontrar:\n");
	scanf("%f",&errorDigitado); //0.0001
	printf("Ingrese el intervalo inicial [x]\n");
	scanf("%f",&x);
	
	printf("\n    X\t    f(x)        f´(x)     X++     Error Relativo\n");
	do{
		z0 = z;
		z = x;  // valor de x
		
		if(i == 0){
			y = 1;
			error = 0.0;
		}else{
			error = (z-z0)/z;
			y = fabs(error);
		}
		
		xn = x - (fx(x)/fxd(x));
		
		printf("%f  %f  %f  %f  %f\n",x,fx(x),fxd(x),xn,error);
		
		if(y <= errorDigitado){ // hasta que se cumpla esto, el while sera 0
			printf("\n\nTu error a sido encontrado : %f \nen el valor : %f\n\n",errorDigitado, x);
			system("pause");
			break;
		}
		
		x = xn;
		
		i++;
	}while(errorDigitado < y);
	system("pause");
}

int main(){
	int opc;
	
	do{
		printf("\t..:: Metodo de Newton Raphson ::..\n\n");
		printf("Por favor selecciona un metodo del Menu.\n\n");
		printf("1.- Evaluar por Funcion\n2.- Evaluar por Iteracion\n3.- Evaluar por Error\n4.- Salir del Programa\n\n");
		printf("Tu eleccion: ");
		scanf("%i",&opc);
		system("cls");
		switch(opc){
			case 1: // por funcion
				funcion();
				system("cls");
				break;
			case 2: // por iteracion
				iteracion();
				system("cls");
				break;
			case 3: // por error
				error();
				system("cls");
				break;
			case 4: //salir
				break;
			default:
				printf("\nOpcion no valida\n\n");
				system("pause");
				system("cls");
			break;
		}
	}while(opc != 4);
	
	system("pause");
	return 0;
}
