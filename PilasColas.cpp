#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
/*Comentario
Elaborado por:Fernando Lopez Mejia, Leyder Londoño*/

struct Nodo_pila{
	int dato_pila;
	Nodo_pila *posicion_siguiente_pila;
};

struct Nodo_cola{
	int dato_cola;
	Nodo_cola *siguiente_cola;
};

Nodo_pila *pila = NULL;
Nodo_cola *frente = NULL;
Nodo_cola *fin = NULL;

void insertar_pila(Nodo_pila *&pila, int dato);
void borrar_pila(Nodo_pila *&pila);
void mostrar_datos_pila(Nodo_pila *&pila);
void opciones_pila(Nodo_pila *&pila);

void insertar_cola(Nodo_cola *&frente, Nodo_cola *&fin, int dato);
bool colaVacia(Nodo_cola *frente);
void eliminar_cola(Nodo_cola *&frente, Nodo_cola *&fin, int &dato);
void mostrar_datos(Nodo_cola *&frente, Nodo_cola *&fin, int dato);
void opciones_cola(Nodo_cola *&frente, Nodo_cola *&fin);
void Menu();

int main(){
	Menu();
	return 0;
}


void insertar_cola(Nodo_cola *&frente, Nodo_cola *&fin, int dato){
	Nodo_cola *nuevo_nodo_cola = new Nodo_cola();
	nuevo_nodo_cola-> dato_cola = dato;
	nuevo_nodo_cola->siguiente_cola = NULL;
	if(colaVacia(frente)){
		frente = nuevo_nodo_cola;
	}else{
		fin->siguiente_cola = nuevo_nodo_cola;
	}
	fin=nuevo_nodo_cola;
	printf("\n\t\tEl dato [%d] se agrego correctamente a la Cola\n",dato);
}

bool colaVacia(Nodo_cola *frente){
	return (frente==NULL)?true : false;
}

void eliminar_cola(Nodo_cola *&frente, Nodo_cola *&fin, int &dato){
	
	if(frente == NULL){
		printf("\n\t\tCola vacia\n");
		opciones_cola(frente,fin);
	}
	
	dato=frente->dato_cola;
	Nodo_cola *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->siguiente_cola;
	}
	delete aux;
	printf("\n\t\tEl dato [%d] se elimino correctamente de la Cola\n",dato);
}


void mostrar_datos(Nodo_cola *&frente, Nodo_cola *&fin, int dato){
	
	Nodo_cola *aux = fin;
	
	if(fin == NULL){
		printf("\n\n\t\tLa cola esta vacia\n");
	}
	
	aux = frente;
	
	while(aux != NULL){
		printf("\n\t\t[%d] ",aux->dato_cola);
		aux=aux->siguiente_cola;
	}
	printf("\n");
}

void opciones_cola(Nodo_cola *&frente, Nodo_cola *&fin){
	int opc=0;
	int dato=0;
	system("cls");
	while(opc != 3){
		
		printf("\n|------------------------------------------------------|");
		printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
		printf("\n|                     DE LA  COLA                      |");
		printf("\n|-------------------------|----------------------------|");
		printf("\n|                         |                            |");
		printf("\n| 1. INSERTAR DATO        | 2. VER DATO                |");
		printf("\n|                         |                            |");
		printf("\n| 3.ELIMINAR DATO         | 4. ANTERIOR                |");
		printf("\n|                         |                            |");
		printf("\n|-------------------------|----------------------------|");
		printf("\n|------------------------------------------------------|");
		
		printf("\nOpcion :");
		scanf("%i",&opc);
		
		switch(opc){
			
		case 1: 
			printf("\n\t\tIngrese un numero\n\t\t");
			scanf("%d",&dato);
			insertar_cola(frente,fin,dato);
			printf("\n\t\t");
			system("pause");
			system("cls");
			break;
			
		case 2:
			printf("\n\t\tMostrar los datos\n");
			mostrar_datos(frente,fin,dato);
			printf("\n\t\t");
			system("pause");
			opciones_cola(frente,fin);
			break;
			
		case 3: 
			printf("\n\t\tEliminando datos de la pila\n\t\t");
			eliminar_cola(frente,fin,dato);
			printf("\n\t\t");
			system("pause");
			system("cls");
			break;
			
		case 4: printf("\n Volviendo al Menu Principal \n");
		Menu();
		break;
		
		default: printf("\n\t\tHa introducido un dato invalido\n");
		printf("\n\t\t");
		system("pause");
		opciones_cola(frente,fin);
		break;
		}		
	}
}		

// ------- PILA ------

void insertar_pila(	Nodo_pila *&pila, int dato){
	Nodo_pila *nuevo_nodo_pila = new Nodo_pila();
	nuevo_nodo_pila->dato_pila = dato;
	nuevo_nodo_pila->posicion_siguiente_pila = pila;
	pila=nuevo_nodo_pila;
	printf("\n\t\tEL dato [%d] se agrego correctamente a la pila\n",dato);
}

void borrar_pila(Nodo_pila *&pila){
	if(pila != NULL){
		Nodo_pila *aux = pila;
		pila=aux->posicion_siguiente_pila;
		printf("\n\t\tSe ha borrado el dato [%d]\n",aux->dato_pila);
		delete aux;
	}
}

void mostrar_datos_pila(Nodo_pila *&pila){
	Nodo_pila *nuevo_nodo_pila = pila;
	if(pila == NULL){
		printf("\n\t\tLa pila esta vacia\n");
	}else{
		if(nuevo_nodo_pila != NULL){
			while(nuevo_nodo_pila != NULL){
				printf("\n\t\t[%d]",nuevo_nodo_pila->dato_pila);
				nuevo_nodo_pila = nuevo_nodo_pila->posicion_siguiente_pila;
			}
		}else{
			printf("\n\t\t[%d]",nuevo_nodo_pila->dato_pila);
		}
		printf("\n");
	}
}

void opciones_pila(Nodo_pila *&pila){
	int opc=0;
	int dato=0;
	system("cls");
	while(opc != 3){
		
		printf("\n|------------------------------------------------------|");
		printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
		printf("\n|                     DE LA PILA                       |");
		printf("\n|-------------------------|----------------------------|");
		printf("\n|                         |                            |");
		printf("\n| 1. INSERTAR DATO        | 2. VER DATO                |");
		printf("\n|                         |                            |");
		printf("\n| 3.ELIMINAR DATO         | 4. ANTERIOR                |");
		printf("\n|                         |                            |");
		printf("\n|-------------------------|----------------------------|");
		printf("\n|------------------------------------------------------|");
		
		printf("\nOPCION:");
		scanf("%i",&opc);
		
		switch(opc){
			
		case 1: printf("\n\t\tIngrese un numero:\n\t\t");
		scanf("%d",&dato);
		insertar_pila(pila,dato);
		printf("\n\t\t");
		system("pause");
		system("cls");
		break;
		
		case 2:	printf("\n\t\tMostrar los datos:\n");
		mostrar_datos_pila(pila);
		printf("\n\t\t");
		system("pause");
		opciones_pila(pila);
		break;	
		
		case 3: printf("\n\t\tEliminando datos de la pila:\n\n");
		borrar_pila(pila);
		printf("\n\t\t");
		system("pause");
		system("cls");
		break;
		
		case 4:	printf("\n Volviendo al Menu Principal \n");
		Menu();	
		break;
		
		default: printf("\n\t\tHa introducido un dato invalido\n");
		printf("\n\t\t");
		system("pause");
		opciones_pila(pila);
		break;
		}		
	}
}

void Menu(){
	
	int opc =0;
	system("cls");
	
	printf("\n|------------------------------------------------------|");
	printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
	printf("\n|-------------------------|----------------------------|");
	printf("\n|                         |                            |");
	printf("\n| 1. PILA                 | 3. FINALIZAR               |");
	printf("\n|                         |                            |");
	printf("\n| 2. COLA                 |                            |"); 
	printf("\n|-------------------------|----------------------------|");
	printf("\n|------------------------------------------------------|");
	
	printf("\nOPCION:");
	scanf("\n%i",&opc);
	
	switch(opc){
	case 1: opciones_pila(pila);
	break;
	
	case 2: opciones_cola(frente,fin);
	break;
	
	case 3: printf("\n\t\tHASTA LA VISTA BABY\n");
	exit(-1);//para que me saque por completo del programa.
	break;
	
	default: printf("\n\t\tHa ingresado un dato invalido\n");
	printf("\n\t\t");
	system("pause");
	
	break;
	}
}

