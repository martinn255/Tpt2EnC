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
		nuevo->string=str_copiar_cad(n->string);
		//str_imprimir(nuevo->string);
		//printf("\n---------\n");
	}
	
	else if(n->nodeType == SET || n->nodeType == LIST){
		//nuevo = (n->nodeType == SET) ? create_set() : create_list();
		
		Tdata aux = n;
		Tdata head = NULL;
		Tdata tail = NULL;
		
		while(aux != NULL){
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

/*Tdata clone(Tdata n){
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
}*/

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
	
	if(belongs(*A,elem)!=1){
		append_set(A,elem);
		printf("\nIngreso");
	}else{
		printf("\nEl elemento ya esta en el conjunto");
	}
}
//buscar zi pertenece la Cadena o conjunto(list O set) a dicha (LIST,SET)
int belongs(Tdata A, Tdata elem){
	if(A==NULL || elem ==NULL)return -1; //si el lugar donde busco o el elemento que busco no es null
	Tdata aux=A;
	while(aux!=NULL){
		if(aux->data != NULL && equals_general(aux->data,elem)==0){
			//printf("\n entro \n");
			return 1;//si encontro el eleemnto en (LIST,SET) o (si una cadena es igual a otra) 
		}
		aux=aux->next;
	}
	//printf("\nNO lo encontro en el conjunto O lista vacia\n");
	return -1;
}
//eliminar elem del conjunto (esto entiendo yo)
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
	
}
//Concateno 2 listas l1 y l2 
Tdata concat(Tdata l1, Tdata l2){
	if(l1->nodeType!=LIST || l2->nodeType!=LIST) return NULL;
	Tdata res=copy_list(l1);
	Tdata aux=l2;
	while(aux!=NULL){
		append_list(&res,aux->data);
		aux=aux->next;
	}
	return res;
}
//Busca el eleemnto y te da la posicion por ser en lista 
int search(Tdata list, Tdata elem){
	Tdata aux=NULL;
	int pos=0;
	if(list ==NULL || elem==NULL || list->nodeType!=LIST)return -1;
	aux=list;
	while(aux!=NULL){
		if(aux->data!=NULL && equals_general(aux->data,elem)==0){//si es 0 lo encontro en la lista
			return pos;//retorno pos
		}
		aux=aux->next;
		pos++;
	}
	return -1;
}
//Operaciones Algrebraicas
//Une A y B sin repetidos
Tdata union_set(Tdata A, Tdata B){
	Tdata resu=NULL;
	//Copio todo A
	Tdata aux=A;
	while(aux!=NULL){
		append_set(&resu,aux->data);
		aux=aux->next;
	}
	//Copio lo de B 
	aux=B;
	while(aux!=NULL){
		if(belongs(resu,aux->data)!=1){//busco en resu si no esta agrego 
			append_set(&resu,aux->data);
		}
		aux=aux->next;	
	}
	return resu;
}
//Los elementos que estan en A y en B solamente
Tdata intersection_set(Tdata A, Tdata B){
	Tdata res=NULL;
	Tdata aux=A;
	while(aux!=NULL){
		//if(belongs(B,aux->data)==1){//si esta en B agrego
			//append_set(&res,aux->data);
		//}
		aux=aux->next;
	}
	return res;
}
//Los elelemntos de A que no estan en B 
Tdata difference_set(Tdata A, Tdata B){
	Tdata res=NULL;
	Tdata aux=A;
	while(aux!=NULL){
		if(belongs(B,aux->data)!=1){//que no este en B
			append_set(&res,aux->data);
		}
		aux=aux->next;
	}
	return res;
	
}
//Si A es subconjunto de B(Si todo elemento de A pertenece a B)
int subset(Tdata A, Tdata B){
	Tdata aux=A;
	while(aux!=NULL){
		if(belongs(B,aux->data)!=1){//Si no esta salgo no es subconjunto
			return -1;
		}
		aux=aux->next;
	}
	return 1;
}
//Compara cuakquier par de Tdata sea(STR,SET,LIST),sin importar el tipo
//devuelve 0 si son iguales y -1 distintos
//Esto es recursivo asi no tengo que repetir instrucciones en equal list y set
int equals_general(Tdata A, Tdata B){
	if(A==NULL && B==NULL) return 0; //Ambos vacios:iguales
	if(A==NULL||B==NULL)return -1; //Alguno vacio y el otro no
	
	if(A->nodeType!=B->nodeType) return -1;//si no Son del mismo tipo :diferentes
	//Muy importante el anterior ya que sino no puedo hacer el switch de abajo
	switch(A->nodeType){
		case STR:
			return str_compara(A->string,B->string);
		case LIST:
			return equals_list(A, B);
		case SET:
			return equals_set(A, B);
		default:
			return -1;
	}
	
}
int equals_list(Tdata A, Tdata B){
	while(A!=NULL && B!=NULL){//hasta terminar las listas
		if( A->data==NULL || B->data==NULL ) return -1;//Si alguna list tiene un dato null son dif
		if(equals_general(A->data,B->data)!=0)return -1;//si en la lista hay sublistas o set o cadenas hace recursion
		A=A->next;
		B=B->next;
	}
	if(A==NULL && B==NULL){//Si las dos son vacias es porque son iguales
		return 0;//son iguales las listas
	}else{
		return -1;//Si no son las 2 null son dif
	}
}
//En equal_set tuve muchas complicaciones ya que al ser conjuntos el orden no importa
// por lo tanto basta encontrar cada elemento a esta en b y cada ele de b en a
//osea tengo que encontrar a con una busqueda secuencial sin un orden como la lista 
//tengo que usar el belong 	
int equals_set(Tdata A, Tdata B){
	Tdata aux=A;//Si los ele de a estan en B
	while(aux!=NULL){
		if(belongs(B,aux->data)!=1){
			return -1;
		}
		aux=aux->next;
	}
	aux=B;//Si los ele de b estan en A
	while(aux!=NULL){
		if(belongs(A,aux->data)!=1){
			return -1;
		}
		aux=aux->next;
	}
	return 0;  // 0 si son iguales ya que no retorno antes
}		
	
Tdata prod_cartesiano(Tdata A,Tdata B){
	Tdata prod=NULL,nuevo;
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
