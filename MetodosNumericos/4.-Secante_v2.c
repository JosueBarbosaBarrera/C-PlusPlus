#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

float fx(float x){
	return atan(x) - (2 * x) + 1;
}

void iteracion(){ // Evaluar por iteraciones + error relativo
	int i=0, iter;
	float a,b, x=0.0, error=0.0, x0;
	
	printf("Dame el numero de iteraciones:\n");
	scanf("%i",&iter);
	printf("Ingrese el intervalo inicial [a] [b]\n");
	scanf("%f %f",&a,&b);
	
	printf("\n    X\t    f(x)     error\n");
	printf("%f  %f  %f\n",a,fx(a),error);
	printf("%f  %f  %f\n",b,fx(b),error);
	for(i;i<iter;i++){ // calculo de iteraciones
		x = a - ((fx(a)*(b - a)) / (fx(b) - fx(a))); // nueva X
		error = b-x/b;    // X actual - X anterior / X
		printf("%f  %f  %f\n",x,fx(x),fabs(error));
		
		a=b;
		b=x;
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
	float c, x = 0.0, errorDigitado, error = 0.0, z = 0.0, x0 = 0.0;
	
	printf("Digita el error Relativo a encontrar:\n");
	scanf("%f",&errorDigitado); //0.0001
	printf("Ingrese el intervalo inicial [a, b]\n");
	scanf("%f",&c);
	
	printf("\n    c\t\tgx(x)     fx(x)    Error Relativo\n");
	do{
		x0 = x;
		
		if(i == 0){
			z = 1;
			error = 0.0;
		}else{
			error = (x-x0)/x;
			z = fabs(error);
		}
		
		//printf("%f  %f  %f  %f\n",c,gx(c),fx(c),error);
		
		if(z <= errorDigitado){ // hasta que se cumpla esto, el while sera 0
			//printf("\n\nTu error a sido encontrado : %f \nen el valor : %f\n\n",errorDigitado, gx(c)); 
			system("pause");
			break;
		}
		
		//c = gx(c);
		
		i++;
	}while(errorDigitado < z);
	system("pause");
}

int main(){
	int opc;
	
	do{
		printf("\t..:: Metodo de la Secante ::..\n\n");
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
