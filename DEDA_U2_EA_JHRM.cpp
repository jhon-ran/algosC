#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//funci�n de ordenamiento por burbuja
void burbuja (int lista[]){
	int i, j, aux, iter = 0;
	for (i=1;i<20;i++){
		for (j=0;j<20-1;j++){
			if (lista[j] > lista[j+1])
			{
				aux = lista[j];
				lista[j]=lista[j+1];
				lista[j+1]=aux;
			}
			iter = iter + 1;
		}	
	}

	for(i=0;i<20;i++)
    	printf("%i, ",lista[i]);
    	printf("Iteraciones: %i\n", iter);
}

//funci�n de ordenamiento por inserci�n
void insercion (int lista[]){
	int i, j, k, iter = 0;
	for (i=1; i<20; i++) { 
        j=i; 
        while (j>=0 && lista[j]<lista[j-1]) { 
            k=lista[j]; 
            lista[j]=lista[j-1]; 
            lista[j-1]=k;
            j--; 
            }
			iter = iter + 1;
    }
	for(i=0;i<20;i++)
    	printf("%i, ",lista[i]);
		printf("Iteraciones: %i\n", iter); 
}

//funci�n de ordenamiento por selecci�n
void seleccion(int lista[]){
	int i, j, aux, min, iter = 0;
	for (i = 0; i < 20 - 1; i++){
        int min = i;
        for (int j = i + 1; j < 20; j++){
            if (lista[j] < lista[min])
                {
                min = j;
                }
        }
        if (i != min) 
            {
            aux= lista[i];
            lista[i] = lista[min];
            lista[min] = aux;
            }
        iter = iter + 1;
       }
       	for(i=0;i<20;i++)
    		printf("%i, ",lista[i]);
    		printf("Iteraciones: %i\n", iter);
}

//funci�n de ordenamiento por Quicksort
void quicksort(int lista[], int izq, int der){
	int i, j, pivote, aux, iter;
	if(izq < der){
		pivote = izq;
		i = izq;
		j = der;
		while(i<j){
			while(lista[i] <= lista[pivote] && i < der)
				i++;
			while(lista[j] > lista[pivote])
				j--;
			if(i<j){
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	aux = lista[pivote];
	lista[pivote] = lista[j];
	lista[j] = aux;
	quicksort(lista, izq, j-1);
	quicksort(lista, j+1, der);
	}
}

//Funcion b�squeda
void busqueda (int lista[]){
	printf ("Se busca el num 50 en la lista\n\n");
	int num = 28, inmediato = 10, superior;
	int i, j = 0; 
	
	superior = num + inmediato;
	
	for(i = 0; i < 20; i++)
	
	{
		if ( num == lista[i])
		{
      		printf("%i se encuentra en la posicion %i de la lista\n", num, i);
      		j = j+1;
      	}
   		else if ( superior == lista[i] &&  num == lista[i]){
	        printf("No se encontro el numero %i, ni un numero inmediato superior\n", num, i);
	        j = j+1;
		}
		else 
			printf("No se encontro el numero %i, ni un numero inmediato superior\n", num, i);
			j = j+1;
			break;
	
	}
	printf("Despues de %i pasadas", j);
}


int main()
{

printf("Fecha:  05/08/2020\n\n");

//int lista[10] = {23,5,13,11,7,14,17,19,12,16};
int lista[20] = {0};
int i, op;


for (int i = 0; i < 20 ;i++) {
    lista[i] = (rand() % 100)+1;
}


printf("Valores de lista desordenada: \n");
for (i=0;i<20;i++)
   printf("%i, ",lista[i]);
   

do{
	printf("\n\nMENU\n\n");
	printf("Elija una opcion:\n");
	printf("1. Odenar con metodo burbuja\n");
	printf("2. Odenar con metodo por insercion\n");
	printf("3. Ordenar con metodo por seleccion\n");
	printf("4. Ordenar por Quicksort\n");
	printf("5. Busqueda secuencial\n");
	printf("6. Salir\n");
	
	scanf("%i", &op);
	switch(op){

		case 1:
			printf("\n\nValores ordenados con el metodo burbuja: \n\n");
			burbuja(lista);
			break;
		case 2:
			printf("\n\nValores ordenados con el metodo por insercion: \n\n");
			insercion(lista);
			break;
		case 3:
			printf("\n\nValores ordenados con el metodo por seleccion: \n\n");
			seleccion(lista);
			break;
		case 4:
			printf("\n\nValores ordenados por Quicksort: \n\n");
			quicksort(lista,0,20-1);
			for(i=0;i<20;i++)
    			printf("%i, ",lista[i]);
			break;
		case 5:
			printf("\n\nBusqueda secuencial: \n\n");
			busqueda(lista);
			break;
		case 6:
			printf("Programa finalizado");
			break;
		default: printf("Opcion no valida"); 
	}
	}while(op != 6);


system("pause");
}
