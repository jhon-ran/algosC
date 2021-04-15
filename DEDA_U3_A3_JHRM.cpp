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


int main (){

	printf("Fecha: 24/08/2020\n\n");
	printf("Retomando el arbol binario de la actividad se sustituyen las letras y operadores por numeros como se muestra: \n\n");
	
	printf("      	      (50)\n");
	printf("           /       \\ \n");
	printf("   	 (25)     (70)\n");
	printf("     /  \\        /       \\ \n");
	printf("  (12) (40)     (60)       (80)\n");
	printf("                /  \\        / \\ \n");
	printf("              (55) (68)  (75) (90)\n\n");
	
	
	//Raiz
	insertar(50);
	//1er nivel
    insertar(25);
    insertar(70);
    //2do nivel
    insertar(12);
    insertar(40);
    insertar(60);
    insertar(80);
    //3er nivel
    insertar(55);
    insertar(68);
    insertar(75);
    insertar(90);
    
    
    printf("In-orden: ");
    inorden(raiz);
    printf("\n\n");
    printf("*********************************************\n\n");
    
    printf("Pre-orden: ");
    preorden(raiz);
    printf("\n\n");
    printf("*********************************************\n\n");

    printf("Post-orden: ");
    postorden(raiz);
    printf("\n\n");
    printf("*********************************************\n\n");

    getch();
    return 0;
	
}
