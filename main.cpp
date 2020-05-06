#include <iostream>
#include <string.h>

const int nElementos = 16; //numero de elementos totales de la lista del enunciado

using namespace std;

void llenarLista(int lista[nElementos]); //llena manualmente la lista por defecto del enunciado
void imprimirLista(int lista[nElementos], char titulo[50]); //imprime la lista
void ordenarShell(int lista[nElementos]); //metodo de ordenamiento shell

int main(int argc, char** argv) {
	int lista[nElementos]; //define la lista por defecto del enunciado
	char titulo[50]; //variable para imprimir el titulo de la lista

	llenarLista(lista); // se llama al metodo que llena la lista de forma manual	
	strcpy(titulo, "Lista de entrada: "); // asigna el nombre de la primera lista a mostrar: lista inicial
	imprimirLista(lista, titulo); //imprime la lista inicial
	ordenarShell(lista);	 // llama al metodo de ordenamiento shell
	strcpy(titulo, "\n\nLista Ordenada de forma descendente: ");// asigna el nombre de la segunda lista a mostrar: lista ordenada
	imprimirLista(lista, titulo); //imprime lista ordenada

	cout << endl;
	system("pause");
}

void llenarLista(int lista[nElementos]){ //Funci�n que llena la lista de forma manual, con los valores dados en el enunciado
	lista[0] = 13;
	lista[1] = 14;
	lista[2] = 94;
	lista[3] = 33;
	lista[4] = 82;
	lista[5] = 25;
	lista[6] = 59;
	lista[7] = 94;
	lista[8] = 65;
	lista[9] = 23;
	lista[10] = 45;
	lista[11] = 27;
	lista[12] = 73;
	lista[13] = 25;
	lista[14] = 39;
	lista[15] = 10;
}


void imprimirLista(int lista[nElementos], char titulo[50]){ //Imprime el titulo y los valores de la lista
	cout << titulo << endl << "\t";
	for(int i = 0; i < nElementos; i ++){ //Recorre todos los elementos de la lista
		if(i == nElementos - 1){ // si es el ultimo elemento no imprime la , luego del valor
			cout << lista[i];
		}else{ // si no es el ultimo elemento imprime la , luego del valor correspondiente en la lista
			cout << lista[i] << ", ";
		}
	}
}

void ordenarShell(int lista[nElementos]){ //Funcion de ordenamiento Shell, ordena una lista de forma descendente, este metodo funciona con la divisi�n de sus elementos en subgrupos
	int ngrupos, iteraciones, actual, posicion_eq; //define las variables a usar: cantidad de grupos a dividir, maximo de elementos a ordenar, elemento actual y la posici�n equivalente o de comparaci�n en el proceso de ordenar
	
	ngrupos = nElementos/2; //Formula del metodo para definir la cantidad grupos: tama�o_lista/2
	iteraciones = nElementos; //decimos que el total de elementos a ordenar o iterar es la misma cantidad de elementos de la lista
	
	while(ngrupos > 0){ //Mientras la cantidad de subgrupos a ordenar sea mayor a 0
		for(int i = ngrupos; i < iteraciones; i++){ //Se recorre la parte superior de la lista
			actual = lista[i]; //se hace un respaldo del elemento actual de la lista
			posicion_eq = i - ngrupos; //buscamos la posici�n equivalente/espejo con la que vamos a comparar: posicion actual - la cantidad de grupos
			
			while(posicion_eq >= 0 && actual > lista[posicion_eq]){ //mientas el indice/posicion a buscar a en la lista sea mayor a 0 y el valor actual sea mayor al valor en lo posici�n equivalente que estamos consultando
				lista[posicion_eq + ngrupos] = lista[posicion_eq]; //actualizamos el valor actual con el valor de la posici�n equivalente, asi llevamos los valores menores al final de la lista
				posicion_eq = posicion_eq - ngrupos; //recalculamos la posici�n a comparar, que ser� la equivalente actual - la cantidad de grupos
			}
			lista[posicion_eq + ngrupos] = actual; //se actualiza la lista en la posici�n equivalente con el valor actual, en el caso de que no ingrese al while, el valor de esta posici�n ser� la posici�n actual
		}
		
		ngrupos = ngrupos/2; //volvemos a subdividir los grupos
	}	
}
