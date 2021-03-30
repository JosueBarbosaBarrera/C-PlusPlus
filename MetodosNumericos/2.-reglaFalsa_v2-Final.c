#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

float fx(float x){
	return pow(x,3) + (4 * pow(x,2)) - 10;
}

void iteracion(){ // Evaluar por iteraciones + error relativo
	int i=0, iter;
	float a, b, c, error= 0.0, c0 = 0.0;
	
	printf("Dame el numero de iteraciones:\n"); // pedimos el numero de iteraciones a realizar
	scanf("%i",&iter);
	printf("Ingrese el intervalo inicial [a, b]\n"); // ingreso de datos por el usuario
	scanf("%f %f",&a,&b);
	
	if(fx(a) * fx(b) > 0){ // validar si se puede aplicar el metodo
		printf("\nNo se puede aplicar el metodo de la biseccion\n");
		printf("%f y %f son del mismo signo\n",a ,b);
	}else{
		printf("\n     a\t\tb       c      f(a)       f(b)       f(c)     Error Relativo\n");
		for(i;i<iter;i++){ // calculo de iteraciones
			c0 = c;
			c = b - ((fx(b) * (a - b)) / (fx(a) - fx(b))); // valor de C
			error=(c-c0)/c;
		if(i==0){
			error=0; // valor inicial del error
		}
			printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,c,fx(a),fx(b),fx(c),error);
			if(fx(c) * fx(a) > 0){
				a = c; // valor de f(c) asignado a -> a
			}else if(fx(c) * fx(b) > 0){
				b = c; // f(c) asignado a -> b
			}
		}
	}
	system("pause");
	system("cls");
}

void funcion(){ // validar por funcion
	float a, b, c, tolerancia;
	
	printf("Dame la Tolerancia:\n");
	scanf("%f",&tolerancia);
	printf("Ingrese el intervalo inicial [a, b]\n");
	scanf("%f %f",&a,&b);
	// c = b-
	if(fx(a) * fx(b) > 0){ // valiar si se puede aplicar el metodo de biseccion
		printf("\nNo se puede aplicar el metodo de la biseccion\n");
		printf("f ( %f ) y f ( %f ) son del mismo signo\n\n",a ,b);
		system("pause");
	}else{ // si se puedeaplicar la biseccion y se hace esto
		printf("\n    a\t\tb      c      f(a)      f(b)      f(c)\n");
		do{
			c = b - ((fx(b) * (a - b)) / (fx(a) - fx(b))); // valor de C
			printf("%f  %f  %f  %f  %f  %f\n",a,b,c,fx(a),fx(b),fx(c));
			if(fabs(fx(c)) <= tolerancia){ // hasta que se cumpla esto, el while sera 0
				printf("\n\nPara una tolerancia de %f \nla biseccion encontrada es: %f\n\n",tolerancia,fx(c)); // Vemos si cumple o no cumple
				printf("valor absoluto de f(c): %f\n\n",fabs(fx(c)));
				system("pause");
				break; // y termina si se cumple
			}else{ // si no , sigue siendo abs(F(x) mayor que tolerancia. 
				if(fx(a) * fx(c) > 0){ //que cambio de variable para evaluar el renglon siguiente
					a = c; // valor de f(c) asignado a -> a
				}else if(fx(b) * fx(c) > 0){
					b = c; // f(c) asignado a -> b
				}
			}
		}while(fabs(fx(c)) > tolerancia); // si, se cumple el if, sale del do()while  :)
	}
}

void error(){ // validar por Error
	
	int i=0;
	float a, b, c, errorDigitado, error = 0.0, z = 0.0, c0 = 0.0;
	
	printf("Digita el error Relativo a encontrar:\n");
	scanf("%f",&errorDigitado); //0.0001
	printf("Ingrese el intervalo inicial [a, b]\n");
	scanf("%f %f",&a,&b);
	
	if(fx(a) * fx(b) > 0){ // valiar si se puede aplicar el metodo de biseccion
		printf("\nNo se puede aplicar el metodo de la biseccion\n");
		printf("f ( %f ) y f ( %f ) son del mismo signo\n\n",a ,b);
		system("pause");
	}else{ // si se puede aplicar la biseccion y se hace esto
		
		printf("\n    a\t\tb      c      f(a)       f(b)       f(c)     Error Relativo\n");
		do{
			c0 = c;
			c = b - ((fx(b) * (a - b)) / (fx(a) - fx(b))); // valor de C
			
			if(i == 0){
				z = 1;
				error = 0.0;
			}else{
				error = (c-c0)/c;
				z = fabs(error);
			}
			
			printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,c,fx(a),fx(b),fx(c),z);
			
			if(z <= errorDigitado){ // hasta que se cumpla esto, el while sera 0
				printf("\n\nTu error a sido encontrado : %f \ny es igual a la biseccion : %f\n\n",errorDigitado, fx(c)); // Vemos si cumple o no cumple
				system("pause");
				break;
			}else{
				if(fx(a) * fx(c) > 0){ //que cambio de variable
					a = c; // valor de f(c) asignado a -> a
				}else if(fx(b) * fx(c) > 0){
					b = c; // f(c) asignado a -> b
				}
			}
			i++;
		}while(errorDigitado < z);
		system("pause");
	}
}

int main(){
	int opc;
	
	do{
		printf("\t..:: Metodo de Regla Falsa ::..\n\n");
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
