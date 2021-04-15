#include<stdio.h>

/* Funcion para apilar */
void push(int pile[], int tope) {
	int i;
	for (i = 0; i <= tope; i++) {
		printf("Introduce un entero positivo (no cero)\n");
		scanf("%i", &pile[i]);
		if (i == tope) {
			printf("La pila esta llena\n");
		} else {
			printf("Elemento #%i\n",i+1);
		}
	}
}

/* Funcion para desapilar */
void pop(int pile[], int tope) {
	int i;
	int resultado;
	int op;
	
	for (i = 4; i >= 0; i--) {
		printf("Para desapilar un elemento ingrea 1, para salir cualquier otro numero\n");
		scanf("%i", &op);
		
		if (op == 1){
			if (i <= tope || i == 1) {
				resultado = pile[i];
				printf("Elemento desapilado: %i\n",resultado);
				pile[i] = 0;
		} else {
			
		}	
			
		}else {
			printf(" %i\n",resultado);
			break;
		}

	}
	
}

/* Verifica si la pila está llena */
void pila_llena(int pile[], int tope) {
	int a;
	int i;
	for (i = 0; i <= 4; i+=1) {
		if (pile[i] > 0 && pile[i+1] >0) {
			a = 1;
		} else {
			a = 0;
		}
	}
	if (a==1) {
		printf("La pila esta llena\n");
	} else {
		printf("La pila no esta llena\n");
	}
}

/* Verifica si la pila está vacia */
void pila_vacia(int pile[], int tope) {
	int a;
	int i;
	for (i = 0; i <= 4; i++) {
		if (pile[i] == 0 && pile[i+1] == 0) {
			a = 1;
		} else {
			a = 0;
		}
	}
	if (a == 1) {
		printf("La pila esta vacia\n");
	} else {
		printf("La pila no esta vacia\n");
	}
}

int main() {
	int i;
	int opciones;
	int pile[5];
	int resultado;
	int tope;
	tope = 4;

	printf("Fecha: 06/08/2020\n");

	do {
		printf("\n");
		printf("*************MENU****************\n\n");
		printf("1. Insertar un elemento (push)\n");
		printf("2. Eliminar elemento de pila (pop)\n");
		printf("3. Verificar si la pila esta llena\n");
		printf("4. Verificar si la pila esta vacia\n");
		printf("5. Salir\n\n");
		printf("*************************************\n");
		scanf("%i",&opciones);
		switch (opciones) {
		case 1:
			push(pile,tope);
			printf("[");
			for (i = 0; i<= 4; i++) {
				printf("%i\t",pile[i]);
			}
			printf("]\n");
			break;
		case 2:
			pop(pile,tope);
			printf("[");
			for (i=0;i<=4;i+=1) {
				printf("%i\t",pile[i]);
			}
			printf("]\n");
			break;
		case 3:
			pila_llena(pile,tope);
			break;
		case 4:
			pila_vacia(pile,tope);
			break;
		}
	} while (opciones!=5);
	return 0;
}

