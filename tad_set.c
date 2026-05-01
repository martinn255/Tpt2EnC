#include "tad_set.h"
#include <stdio.h>
#include <stdlib.h>
#include "cadena.h"


Tdata create_str_ast(){
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = STR;
	//n->string = NULL;
	n->string=str_crear();
	return n;
}
	
Tdata create_set(){
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = SET;
	n->data = NULL;
	n->next = NULL;
	return n;
}
	
Tdata create_list(){
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = LIST;
	n->data = NULL;
	n->next = NULL;
	return n;
}
Tdata clone2(Tdata n){
	if(n == NULL) return NULL;
	
	Tdata nuevo = NULL;
	
	if(n->nodeType == STR){
		nuevo = create_str_ast();
		//nuevo->string = load2(n->string);
		//str_desde_string(&n_nuevo,n->string);
		nuevo->string=str_copiar_cad(n->string);
		//printf("\n---------\n");
		//str_imprimir(nuevo->string);
		//printf("\n---------\n");
	}
	
	else if(n->nodeType == SET || n->nodeType == LIST){
		//nuevo = (n->nodeType == SET) ? create_set() : create_list();
		
		Tdata aux = n;
		Tdata head = NULL;
		Tdata tail = NULL;
		
		while(aux != NULL){
			/*Tdata nodo_lista;
			if(aux->nodeType==LIST){
				nodo_lista =create_list();
			}else{
				nodo_lista=create_set();
			}*/
			//Tdata nodo_lista = create_list(); // nodo contenedor
			//Tdata nodo_lista = create_set();//este es el original peroel de arriba es con lista
			Tdata nodo_lista= (Tdata)malloc(sizeof(struct dataType));
			nodo_lista->nodeType =aux->nodeType;
			
			nodo_lista->data = clone2(aux->data);
			nodo_lista->next = NULL;
			
			if(head == NULL){
				head = nodo_lista;
				tail = nodo_lista;
			} else {
				tail->next = nodo_lista;
				tail = nodo_lista;
			}
			
			aux = aux->next;
		}
		
		return head;
	}
	
	return nuevo;
}

Tdata clone(Tdata n){
	if(n == NULL) return NULL;
	
	Tdata nuevo = NULL;
	
	if(n->nodeType == STR){
		nuevo = create_str_ast();
		//nuevo->string = load2(n->string);
	}
	
	else if(n->nodeType == SET || n->nodeType == LIST){
		nuevo = (n->nodeType == SET) ? create_set() : create_list();
		
		Tdata aux = n;
		Tdata head = NULL;
		Tdata tail = NULL;
		
		while(aux != NULL){
			Tdata nodo_lista = create_set();  // nodo contenedor
			
			nodo_lista->data = clone(aux->data);
			nodo_lista->next = NULL;
			
			if(head == NULL){
				head = nodo_lista;
				tail = nodo_lista;
			} else {
				tail->next = nodo_lista;
				tail = nodo_lista;
			}
			
			aux = aux->next;
		}
		
		return head;
	}
	
	return nuevo;
}

void append_set(Tdata *A, Tdata e){
	Tdata nuevo = create_set();
	
	nuevo->data = clone2(e);
	nuevo->next = NULL;
	
	if(*A == NULL){
		*A = nuevo;
	} else {
		Tdata aux = *A;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = nuevo;
	}
}
void append_list(Tdata *list ,Tdata elem){
	Tdata nuevo= create_list();
	
	nuevo->data = clone2(elem);
	nuevo->next=NULL;
	
	if(*list == NULL){
		*list= nuevo;
	}else{
		Tdata aux=*list;
		while(aux->next != NULL){
			aux=aux->next;
		}
		aux->next=nuevo;
	}
}
void printSet(Tdata A){
	if(A == NULL){
		printf("{}");
		return;
	}
	
	printf("{ ");
	
	Tdata aux = A;
	
	while(aux != NULL){
		
		if(aux->data != NULL){
			
			if(aux->data->nodeType == STR){
				//print_string(aux->data->string);
				str_imprimir(aux->data->string);
			}
			
			else if(aux->data->nodeType == SET){
				printSet(aux->data);  
			}
			
			else if(aux->data->nodeType == LIST){
				//printf("[LIST]");
				print_list(aux->data);
			}
			
			if(aux->next != NULL)
				printf(", ");
		}
		
		aux = aux->next;
	}
	
	printf(" }");
}
//Operaciones Sobre set	
	//Insertar una cadena a dicho conjunto(sin duplicados)//verificar bien que hace 
void insert_set(Tdata* A, Tdata elem){
	
	Tdata aux=*A;
	if(belongs(aux,elem)!=1){
		append_set(&aux,elem);
		printf("\nIngreso");
	}else{
		printf("\nEl str esta en el conjunto no puedo agregarlo");
	}
}
//buscar o pertenece la Cadena a dicho conjunto 
int belongs(Tdata A, Tdata elem){
	if(A!=NULL){
		Tdata aux=A;
		while(aux!=NULL){
			if(str_compara(aux->data->string,elem->string)==0){
				return 1;
			}
			aux=aux->next;
		}
	}
	//printf("\nNO lo encontro en el conjunto O lista vacia\n");
	return -1;
}
//eliminar cadena del conjunto (esto entiendo yo)
void remove_set(Tdata* set, Tdata elem){
	
}


//Operaciones sobre listas	
void print_list(Tdata list){
	if(list == NULL){
		printf("[]");
		return;
	} 
	printf("[");
	Tdata aux=list;
	
	while(aux != NULL){
		
		if(aux->data != NULL){
			
			list_datos(aux->data);
			
		}
		if(aux->next != NULL)
		   printf(", ");
		
		aux = aux->next;
	}
	printf(" ]");
}
void list_datos(Tdata lis){
	if(lis == NULL) return;
	
	if(lis->nodeType == STR){
		//print_string(lis->string);
		str_imprimir(lis->string);
	}
	else if(lis->nodeType == SET){
		printSet(lis);
	}
	else if(lis->nodeType == LIST){
		print_list(lis);
	}
}
int length(Tdata list){
	int tam=0;
	Tdata aux;
	if(list->nodeType != LIST){
		printf("Error : Tdata no es tipo lista \n");
		return -1;
	}
	aux=list;
	tam++;
	while(aux->next!=NULL){
		aux=aux->next;
		tam++;
		//printf("entro");
	}
	return tam;
}
Tdata copy_list(Tdata list){//(copia profunda)
	//Tdata aux=NULL;
	if(list!=NULL && list->nodeType==LIST){
		return clone2(list);
	}else{
		return NULL;
	}
	
	/*Tdata nuevo;
	Tdata copy;
	if(list==NULL){
		return NULL;
	}
	nuevo=NULL;
	copy=NULL;
	if(list->nodeType==STR){
		nuevo->string=str_copiar_cad(list->string);
	}
	if(list->nodeType==LIST){
		copy=copy_list(list->data);
	}
	nuevo=create_list();
	nuevo->data=copy;
	nuevo->next=copy_list(list->next);
	/*if(list->nodeType == STR){//si es str
		nuevo->string=str_copiar_cad(list->string);
	}else{//sie es lista o conjunto
		if(list->nodeType == SET){
			nuevo=create_set();
			nuevo->data=copy_list(list->data);
			nuevo->next=copy_list(list->next);
		}else{
			nuevo=create_list();
			nuevo->data=copy_list(list->data);
			nuevo->next=copy_list(list->next);
		}
	}*/
	
	//retorna la copia
	//return nuevo;
}
Tdata concat(Tdata l1, Tdata l2){
	
}
int search(Tdata list, Tdata elem){
	Tdata aux=NULL;
	if(list==NULL){
		return -1;
	}
	
}
//Operaciones Algrebraicas	
Tdata union_set(Tdata A, Tdata B){
	Tdata res=NULL;
	//Copio todo A
	Tdata aux=A;
	while(aux!=NULL){
		append_set(&res,aux->data);
		aux=aux->next;
	}
	//Copio lo de B
	//aux=B;
	//while(aux!=NULL){
		//if(aux==NULL)
		//aux=aux->next	
	//}
	return res;
}
Tdata intersection_set(Tdata A, Tdata B){
	Tdata res=NULL;
	Tdata aux=A;
	while(aux!=NULL){
		aux=aux->next;
	}
	return res;
}
Tdata difference_set(Tdata A, Tdata B){
	Tdata res=NULL;
	Tdata aux=A;
	while(aux!=NULL){
		aux=aux->next;
	}
	return res;
	
}
Tdata subset(Tdata A, Tdata B){
	
}
int equals_set(Tdata A, Tdata B){
	if(A==B) return 1;
	
}
Tdata prod_cartesiano(Tdata A,Tdata B){
	Tdata prod=NULL,nuevo;
	prod=create_set();
	Tdata auxA=A;
	Tdata auxB=B;
	
	while(auxA!=NULL){
		auxB=B;
		while(auxB!=NULL){
			nuevo=NULL;
			append_list(&nuevo,auxA->data);
			
			append_list(&nuevo,auxB->data);
			
			append_set(&prod,nuevo);
			auxB=auxB->next;
		}
		auxA=auxA->next;
	}
	return prod;
	
}
