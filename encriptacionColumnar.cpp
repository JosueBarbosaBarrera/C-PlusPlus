#include <iostream>
#include <cstring>
#include <cctype>
#include <conio.h>

using namespace std;

int main(){
	
	bool statusClave = 0;
	
	char mensaje[100], clave[50], matrizMensaje[50][50], arrayAux[50];
	char *p, *q;
	
	int i=0, j=0, k=0, cont=0 , min=0, aux=0;
	int tamanoMensaje = 0, tamanoClave = 0, tamanoMensajeSinEspacios = 0, tamanoClaveSinEspacios = 0;
	int filas = 0;
	
	char ubicacion[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
///////////////////////////// INICIO /////////////////////////////////////
	cout << "Captura tu Mensaje" << endl; // captura del mensaje
	p = gets(mensaje);
	
	if (p) { // esta validacion funciona :)
		cout << "El texto escrito es: " << mensaje << endl;
	}else{
		cout << "No se ha guardado nada" << endl;
	}
		
	cout << "Tu mensaje capturado es: " << mensaje << endl;
	
	tamanoMensaje = strlen(mensaje); // Tama�o del arreglo
	cout << "Y su tamano es: " << tamanoMensaje << endl;
	
	char *mensajeSinEspacios = new char[tamanoMensaje]; // se crea el Arreglo dinamico
	
	for(i=0;i<tamanoMensaje;i++){ // Quitar espacios del mensaje con este bucle
		if(mensaje[i] != ' '){
			mensajeSinEspacios[j] = mensaje[i] ; // asignacion de caracteres al nuevo Arreglo sin espacios.
			j++;
		}else{
			cont++;
		}
	}
	
	tamanoMensajeSinEspacios = strlen(mensajeSinEspacios);
	cout << "El mensaje sin espacio es: " << mensajeSinEspacios << endl;
	cout << "Su tamano es: " << tamanoMensajeSinEspacios << endl;
	cout << "Y se Borraron: " << cont << " espacios" << endl; // solo como apoyo de validacion.
	
	do{ // Capturar clave
		statusClave = 0;
		cout << "Captura la Clave " << endl;
		gets(clave);
		q = strlwr(clave); // volver a minusculas en caso de que el usuario alla usado mayusculas 
		
		cout << "aver: " << clave << endl;
		
		if (q) {
			cout << "La clave es: " << clave << endl;
		}else{
			cout << "No se ha guardado nada" << endl;
		}
		
		tamanoClave = strlen(clave); // Tama�o de la clave normal
		cout << "Y su tamano es: " << tamanoClave << endl;
	
		char *claveSinEspacios = new char[tamanoClave]; // lo manda una arreglo dinamico, esta variable solo esta activa dentro de este while :(
		
		j=0;
		for(i=0;i<tamanoClave;i++){ // Quitar espacios de la clave no permitidos
			if(clave[i] != ' '){
				claveSinEspacios[j] = clave[i] ; // asignacion de caracteres a la clave sin espacios
				j++;
			}else{
				cont++; // contador de espacios eliminados
			}
		}
		
		tamanoClaveSinEspacios = strlen(claveSinEspacios);
		
		if(tamanoClaveSinEspacios < tamanoMensajeSinEspacios){ // verificar que sea una clave valida, osea, que no sea mayor al mensaje a encriptar
			cout << "Tu clave sin espacios es: " << claveSinEspacios << endl;
			cout << "Y el tamano de clave sin espacios es: " << tamanoClaveSinEspacios << endl; 
			statusClave = 1;
			/*cout << "Deseas usar esta clave: Y/N : "; // preguntar si esta satisfecho.....
			getline(1, c, '\n'); // algo asi
			
			if(c == 'y' || c == 'Y'){
				claveAceptada = 1;
				cout << "OK la clave a usar es: " << claveSinEspacios << endl;
				cout << "valor de c: " << c << endl;
			}else{
				cout << "captura invalida" << endl;
			}*/
		}else{
			cout << "\n\tError 001: \nLa clave es mayor que tu mensaje, vuelve a intentar\n" << endl;
			// do while regresa todo
		}
	}while(statusClave == 0);
	
	///// asignacion de numeros de columnas y filas que tendra la matriz
	if(tamanoMensajeSinEspacios%tamanoClaveSinEspacios == 0){
		/* numero de filas dado por "tamanodelmensaje entre tamanodelaclave" 
		con la condicion de que si residuo es diferente de 0 agregue una fila extra*/
		filas = tamanoMensajeSinEspacios/tamanoClaveSinEspacios;
	}else{
		filas = (tamanoMensajeSinEspacios/tamanoClaveSinEspacios) + 1;
	}
	
	cout << "numero de columnas sera = " << tamanoClaveSinEspacios << endl;
	cout << "numero de filas sera = " << filas << endl;
	
	// Acomodar el mensaje en una matriz
	
	for(j=0;j<filas;j++){ // control de filas
		for(i=0;i<tamanoClaveSinEspacios;i++){ // numero de columnas dado por el tamano de la clave
			matrizMensaje[i][j] = mensajeSinEspacios[k];
			cout << matrizMensaje[i][j]; // esto imprime la matriz
			k++;
		}
		cout << endl;
	}
	
	// asignacion variable entera dependiendo posicion en la que se encuentre dentro del arreeglo "ubicacion"
	int posicionesClave[tamanoClaveSinEspacios];
	
	cout << "[";
	for(i=0;i<tamanoClaveSinEspacios;i++){
		for(j=0;j<26;j++){
			if(q[i] == ubicacion[j]){ // posicionaiento de ubicacion en el alfabeto
				// cout << "La letra " << q[i] << " esta en la posicion # " << j+1 << endl;
				posicionesClave[i] = j+1;
				cout << " " << posicionesClave[i];	
			}
		}
	}
	cout << " ]" << endl;
	
	
	////////////// TRABAJANDO ///////////// A PARTIR DE AQUI....
	
	//char vectorAuxiliar[filas];
	
	// Hasta aqui ya funciona jeje
	
	for(i=0;i<tamanoClaveSinEspacios;i++){ // Ordenamiento por seleccion
		min = i; // min empieza siendo 0
		for(j=i+1;j<tamanoClaveSinEspacios;j++){ // control y recorrido del arreglo
			
			if(posicionesClave[j] < posicionesClave[min]){
				
				for(k=0;k<filas;k++){ // Copiar el contenido de la "matriz mensaje" a la que contendra el mensaje encriptado osea a la "matriz encriptada"
						arrayAux[k] = matrizMensaje[i][k];
						/*cout << "valor de k: " << k << endl;
						cout << "valor de min: " << min << endl;
						cout << "valor de j: " << j << endl;*/
						matrizMensaje[i][k] = matrizMensaje[j][k];
						matrizMensaje[j][k] = arrayAux[k];
				}
				min = j; // esto maneja posiciones con su valor, situa la posicion menor
			}
		}
		// hacer el intercambnio de letras en arreglo, depende del alfabeto
		aux = posicionesClave[i]; // asigna nuevo valor a "aux"
		posicionesClave[i] = posicionesClave[min];
		posicionesClave[min] = aux;
	}
	
	
	cout << "[";
	for(i=0;i<tamanoClaveSinEspacios;i++){ // Imprecion de valores ordenados de "ubicacion", solo para comprobar
		cout << posicionesClave[i] << " ";
	}
	cout << " ]" << endl;
	
	
	cout << "Mensaje encriptado [";
	for(i=0;i<tamanoClaveSinEspacios;i++){ // Imprecion matriz encriptada en forma lineal
		for(j=0;j<filas;j++){
			cout << matrizMensaje[i][j]; // aqui estaba el error, que weyyyyy !!!!!
		}
	}
	cout << "]" << endl;
	return 0;
}