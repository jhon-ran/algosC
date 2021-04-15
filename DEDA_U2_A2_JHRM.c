#include <stdio.h>

int main()
{

printf("Fecha:  04/08/2020\n\n");

int lista[10] = {23,5,13,11,7,14,17,19,12,16};
int aux=0, aux2 = 0;
int i,j, t;

printf("Valores de lista desordenada: \n");

for (i=0;i<10;i++)
   printf("%i\t",lista[i]);

// se evalua -5 para que pare el ordenamiento en la 4ta pasada
for (i=1;i<5;i++){
	
	for (j=0;j<10-1;j++){
		if (lista[j] > lista[j+1])
		{
			aux = lista[j];
			lista[j]=lista[j+1];
			lista[j+1]=aux;
		}
	}
}

printf("\n\nResultado despues de 4 pasadas con el metodo burbuja: \n\n");

for(i=0;i<10;i++)
    printf("%i\t",lista[i]);
    
//Método por inserción
int lista2[10] = {23,5,13,11,7,14,17,19,12,16};

int k;
// se evalua -5 para que pare el ordenamiento en la 4ta pasada
    for (i=1; i<5; i++) { 
        j=i; 
            while (j>=0 && lista2[j]<lista2[j-1]) { 
                k=lista2[j]; 
                lista2[j]=lista2[j-1]; 
                lista2[j-1]=k;
                j--; 
            } 
    } 
    printf("\n\nResultado despues de 4 pasadas con el metodo por insercion: \n\n"); 
    for(i=0;i<10;i++)
    printf("%i\t",lista2[i]);


return 0;
}
