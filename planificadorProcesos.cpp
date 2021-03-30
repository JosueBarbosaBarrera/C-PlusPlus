#include <iostream>
#include <conio.h>

using namespace std;

int a, b, i, j, k=0, opc, aux, aux1, cont, cont2, cont3;
char aux2;
int arrayServicio[10], arrayLlegada[10];
char alfa[10]={'A','B','C','D','E','F','G','H','I','J'}; // Soporta 10 procesos

//---------------------------------------- FUNCIONES -----------------------------------------//

void capturarDatos(){  // Controla la captura de datos que el usuario desea ingresar
	for(i=0; i<a; i++){ // pedir datos 
		cout << "\n\tDigita la llegada del proceso " << alfa[i] << ": "; //Nombra e imprime a las columnasrepectivas A B C d ... repectivas 
		cin>>arrayLlegada[i]; //introduce el valor de la llegada del proceso dentro del subindide del arreglo
		
		cout << "\n\tCuanto tiempo de servicio que requiere el proceso " << alfa[i] << ": ";
		cin>>arrayServicio[i]; //introduce el valor del servicio del proceso en el subindide indicado
	}
	for(i=0; i<a; i++){
		cout << "los valores son: \n" << arrayLlegada[i] << arrayServicio[i] << endl; // validacion de captura correcta
	}
}

void ordenamiento(){  // Metodo para ordenamiento de Llegadas
	for(j=0; j<a-1; j++){ // Se encarga de repitir las comparacion de los indices las mismamas veces que el numero de procesos
		for(i=0; i<a-1; i++){   // comapar indices as mismamas veces que el numero de procesos
			if (arrayLlegada[i] > arrayLlegada[i+1]){ // validacion de numeros si indice 1 es menor que indice 2 se recorre
			
				aux = arrayLlegada[i]; // Comparacion entre indices, el menor se recorre una posicion
				arrayLlegada[i] = arrayLlegada[i+1];
				arrayLlegada[i+1] = aux;
				
				aux1 = arrayServicio[i]; // modo espejo para los Servicios, cambian posicion con sus respectivas llegadas
				arrayServicio[i] = arrayServicio[i+1];
				arrayServicio[i+1] = aux1;
				
				aux2 = alfa[i]; // modo espejo para las letras: Proceso A,B,C,D, etc...
				alfa[i] = alfa[i+1];
				alfa[i+1] = aux2;
			}
			else{
				cout << "No hubo cambios en el valor: " << i << endl; // datos de salida
			}
		}
	}

	cout << "\nEl ordenamiento de llegadas quedo asi: " << endl;
	for(i=0; i<a; i++){ // verificador de de salida corrector :  datos de llegadas
		cout << "\n " << arrayLlegada[i] << endl;
	}
	cout << "\n";
}

void calcularTabla(){  // Calcular tabla FCFS
	// Proceso   Llegada   Servicio   Inicio   Fin   Espera   Retorno
	i=0;
	
	cout << "   " << alfa[i] << "\t      " << arrayLlegada[i] << "        " << arrayServicio[i] << "          " <<  arrayLlegada[i]/*inicio*/ << "      " << (arrayLlegada[i]+arrayServicio[i])/*fin*/ << "       " << arrayLlegada[i-1] /*espera*/ << "      "  << arrayServicio[i] /*retorno*/ << endl; // pibote
	
	cont = arrayLlegada[i] + arrayServicio[i];
	
	for(i=1; i<a; i++){ // Calculo de tabla e imprecion de tabla
	
	cont2 = cont + arrayServicio[i]; //contador #2 manipula el fin 
	
	cout << "   " << alfa[i] << "\t      " << arrayLlegada[i] << "        " << arrayServicio[i] << "          " << cont /*n*/ << "      " << cont2 /*fin*/<< "      " << cont - arrayLlegada[i] /*espera*/ << "     " << cont2 - arrayLlegada[i] /*retorno*/ << endl;
	
	cont = cont + arrayServicio[i]; // contador #1 manipula el inicio de cada proceso

	}
}

void imprimirTabla(){  // Imprecion de grafica. Ejemplo de imprecion: AABBCCAADDEECDDD
	cout << "\n\n +++ Forma Grafica +++ \n\n";
	cont3 = arrayServicio[k];
	for(i=0;i<a;i++){
		for(j=0;j<arrayServicio[i];j++){
			cout << " " << alfa[i];
		}
	}
}

void calcularSPN(){
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			if(arrayLlegada[i]==arrayLlegada[i+1]){
				if(arrayServicio[i]>arrayServicio[i+1]){ //entra el metodo burbuja al cumplirse esta condicion
			
				aux = arrayLlegada[i]; // Comparacion entre indices, el menor se recorre una posicion
				arrayLlegada[i] = arrayLlegada[i+1];
				arrayLlegada[i+1] = aux;
				
				aux1 = arrayServicio[i]; // modo espejo para los Servicios, cambian posicion con sus respectivas llegadas
				arrayServicio[i] = arrayServicio[i+1];
				arrayServicio[i+1] = aux1;
				
				aux2 = alfa[i]; // modo espejo para las letras: Proceso A,B,C,D, etc...
				alfa[i] = alfa[i+1];
				alfa[i+1] = aux2;
				}
				else {
					cout << "noting \n";
				}
			}
		}
	}
}

//-------------------------------------- FUNCION PRINCIPAL --------------------------------------//

int main(){
	inicio:
	system("cls");
	cout << "\nBienvenido al adminitrador de Tecnicas de Planificacion de Procesos" << "\n\nA continuacion te presentamos nuestro Menu: " << endl;
	cout << "\n\t1.- Primera llegada, primer servicio (FCFS) \n\n\t2.- SPN (Short process next) \n\n\t3.- Por Ronda (Round Robin) \n\nElige una Opcion: ";
	cin >> opc;
	switch(opc) {
		case 1: system("cls");
			cout << "\t+++ Primera llegada, primer servicio (FCFS) +++\n\nDigita el numero de procesos a calcular: ";
			cin>>a;
			capturarDatos();
			ordenamiento();
			cout << "\n\t  +++ Impresion de datos +++  \n\n" << endl;
			cout << "Proceso   Llegada   Servicio   Inicio   Fin   Espera   Retorno" << endl;
			calcularTabla(); // calcular FCFS
			imprimirTabla();
			getch();
			goto inicio; //Vuelve al menu desde esta etiqueta
			break;
		case 2: system("cls");
			cout << "\t++SPN (Short process next)++ " "\n\nDigita el numero de procesos a calcular: ";
			cin>>a;
			capturarDatos();
			ordenamiento();
			calcularSPN(); // funcion de validacion y todenamientos de llegadas y servicios
			cout << "\n\t  +++ Impresion de datos +++  \n\n" << endl;
			cout << "Proceso   Llegada   Servicio   Inicio   Fin   Espera   Retorno" << endl;
			calcularTabla(); // calcular SPN
			imprimirTabla();
			getch();
			goto inicio;
			break;
		case 3: system("cls");
			cout << "\t++Por Ronda (Round Robin)++";
			cout << "\n\n....... Aun en construccion, lamentamos los inconvenientes" << endl;
		
			getch();
			goto inicio;
			break;
		default :
			cout << "Error: Digita una opcion valida del Menu" << endl;
			break;
	}
	getch();
	return 0 ;
}
