#include<stdio.h>

// Declaraciones adelantadas de las funciones


/* Funcion para apilar */
void push(int col[], int tope) {
	int i;
	for (i = 0; i <= 4; i++) {
		printf("Introduce un entero positivo (no cero)\n");
		scanf("%i", &col[i]);
		if (i == tope) {
			printf("La cola esta llena\n");
		} else {
			printf("Elemento #%i\n",i+1);
		}
	}
}

/* Funcion para eliminar elementos de la cola */
void pop(int col[], int tope) {
	int i;
	int resultado;
	int op;
	
	for (i = 0; i <= 4; i += 1) {
		printf("Para desapilar un elemento ingrea 1, para salir cualquier otro numero\n");
		scanf("%i", &op);
		
		if (op == 1){
			if (i <= tope) {
				resultado = col[i];
				printf("Elemento eliminado de la cola: %i\n",resultado);
				col[i] = 0;
			} else {
			}
		}else {
			printf(" %i\n",resultado);
			break;
			}
	}
}

/* Verifica si la pila está llena */
void cola_llena(int col[], int tope) {
	int a;
	int i;
	for (i = 0; i <= 4; i+=1) {
		if (col[i] > 0 && col[i+1] > 0) {
			a = 1;
		} else {
			a = 0;
		}
	}
	if (a == 1) {
		printf("La cola esta llena\n");
	} else {
		printf("La cola no esta llena\n");
	}
}

/* Verifica si la cola está vacia */
void cola_vacia(int col[], int tope) {
	int a;
	int i;
	for (i = 0; i <= 4; i+=1) {
		if (col[i] == 0 && col[i+1] == 0) {
			a = 1;
		} else {
			a = 0;
		}
	}
	if (a==1) {
		printf("La cola esta vacia\n");
	} else {
		printf("La cola no esta vacia\n");
	}
}

int main() {
	int col[5];
	int i;
	int opciones;
	int resultado;
	int tope;
	tope = 4;

	printf("Fecha: 06/08/2020\n");
	do {
		printf("\n");
		printf("*************MENU***************\n\n");
		printf("1. Insertar un elemento (push)\n");
		printf("2. Eliminar elemento de cola (pop)\n");
		printf("3. Verificar si la cola esta llena\n");
		printf("4. Verificar si la cola esta vacia\n");
		printf("5. Salir\n\n");
		printf("*************************************\n");
		scanf("%i",&opciones);
		switch (opciones) {
		case 1:
			push(col,tope);
			printf("[");
			for (i = 0; i <= 4; i += 1) {
				printf("%i\t",col[i]);
			}
			printf("]\n");
			break;
		case 2:
			pop(col,tope);
			printf("[");
			for (i=0;i<=4;i+=1) {
				printf("%i\t",col[i]);
			}
			printf("]\n");
			break;
		case 3:
			cola_llena(col,tope);
			break;
		case 4:
			cola_vacia(col,tope);
			break;
		}
	} while (opciones!=5);
	return 0;
}

