#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

//Nodo
struct nodo {
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

//Se inicializa vacia
struct nodo *raiz = NULL;

void insertar(int x)
{
    struct nodo *nuevo;
    //En C o C++ puede lanzar error esta l�nea 
    //De ser el caso substituir por nuevo = malloc(sizeof(struct nodo));
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo -> dato = x;
    nuevo -> izq = NULL;
    nuevo -> der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        struct nodo *anterior, *recorrido;
        anterior = NULL;
        recorrido = raiz;
        while (recorrido != NULL)
        {
            anterior = recorrido;
            if (x < recorrido -> dato)
                recorrido = recorrido ->izq;
            else
                recorrido = recorrido -> der;
        }
        if (x < anterior -> dato)
            anterior->izq = nuevo;
        else
            anterior -> der = nuevo;
    }
}

//imprimir in-orden
void inorden(struct nodo *recorrido)
{
    if (recorrido != NULL)
    {
        inorden(recorrido -> izq);
        printf("%i ",recorrido -> dato);
        inorden(recorrido -> der);
    }
}


//imprimir pre-orden
void preorden(struct nodo *recorrido)
{
    if (recorrido != NULL)
    {
        printf("%i ",recorrido -> dato);
        preorden(recorrido -> izq);
        preorden(recorrido -> der);
    }
}


//imprimir post-orden
void postorden(struct nodo *recorrido)
{
    if (recorrido != NULL)
    {
        postorden(recorrido -> izq);
        postorden(recorrido -> der);
        printf("%i ",recorrido -> dato);
    }
}

//borrar nodo
void borrar(struct nodo *recorrido)
{
    if (recorrido != NULL)
    {
        borrar(recorrido -> izq);
        borrar(recorrido -> der);
        free(recorrido);
    }
}



int main (){

	printf("Fecha: 26/08/2020\n\n");
	printf("Debes de llenar el arbol binario tal como se muestra: \n\n");
	
	//variable para menu
	int op;
	
	printf("      	     (14)\n");
	printf("           /       \\ \n");
	printf("   	 (4)     (15)\n");
	printf("         /  \\    \n");
	printf("        (3) (9) \n");
	printf("            /  \n");
	printf("          (7) \n\n");
	

    do{
		printf("\n\nMENU\n\n");
		printf("Elija una opcion:\n");
		printf("1. Introducir valores en arbol\n");
		printf("2. Imprimir en in-orden\n");
		printf("3. Imprimir en pre-orden\n");
		printf("4. Imprimir en post-orden\n");
		printf("5. Borrar nodo\n");
		printf("6. Salir\n");
		
		scanf("%i", &op);
		switch(op){
			
			case 1:
				//Variables para cada nodo
				int root, izq1, der1, izq2, der2, izq3;
				//Raiz
				printf("\n\nIntroduce el #14 en raiz \n\n");
				scanf("%i", &root);
				insertar(root);
				//1er nivel
				printf("\n\nIntroduce el #4 en nodo izquierdo 1er nivel \n\n");
				scanf("%i", &izq1);
				insertar(izq1);
				printf("\n\nIntroduce el #15 en nodo derecho 1er nivel \n\n");
				scanf("%i", &der1);
				insertar(der1);
				//2do nivel
				printf("\n\nIntroduce el #3 en nodo izquierdo 2ndo nivel \n\n");
				scanf("%i", &izq2);
				insertar(izq2);
				printf("\n\nIntroduce el #9 en nodo derecho 2ndo nivel \n\n");
				scanf("%i", &der2);
				insertar(der2);
				//3er nivel
				printf("\n\nIntroduce el #7 en nodo izquierdo 3er nivel \n\n");
				scanf("%i", &izq3);
				insertar(izq3);		
				break;
			case 2:
				printf("In-orden: ");
	    		inorden(raiz);
	    		printf("\n\n");
	    		printf("*********************************************\n\n");
				break;
			case 3:
				printf("Pre-orden: ");
	    		preorden(raiz);
	    		printf("\n\n");
	    		printf("*********************************************\n\n");
				break;
			case 4:
				printf("Post-orden: ");
	    		postorden(raiz);
	    		printf("\n\n");
	    		printf("*********************************************\n\n");
				break;
			case 5:
				printf("\n\nBorrado \n\n");
				borrar(raiz);
				break;
			case 6:
				printf("Programa finalizado");
				break;
			default: printf("Opcion no valida"); 
		}
	}while(op != 6);
    
    getch();
    return 0;
	
}
