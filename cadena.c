#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadena.h"

///*
str crearNodoCad(char c){
	str nvo;
	nvo =(str) malloc(sizeof(TR_Nodo));
	nvo->dato = c;
	nvo->sig = NULL;
	return nvo;
}
str str_crear(){
	return NULL;
}
void str_agregar(str *cadena, char c){
	str aux = *cadena;
	if(aux == NULL){
		(*cadena) = crearNodoCad(c);
	} else {
		while( aux->sig != NULL ){
			aux =  aux->sig;
		}
		aux->sig = crearNodoCad(c);
	}
}
void str_desde_string(str *cadena, char* texto){
	while (*texto != '\0') {
		str_agregar(cadena, *texto);
		texto++;
	}
}
void str_eliminar_vocales(str *cadena){
	if( *cadena!=NULL ){
		str aux = *cadena, ant = NULL;
		
		do{ 
			if(aux->dato == 'a' || aux->dato == 'e' || aux->dato == 'i' || aux->dato == 'o' || aux->dato == 'u'){
				
				if( ant==NULL ){
					(*cadena) = aux->sig;
					aux->sig = NULL;
					free(aux);
					aux = *cadena;
				} else {
					ant->sig = aux->sig;
					aux->sig = NULL;
					free(aux);
					aux = ant->sig;
				}
				
			}
			else{
				ant = aux;
				aux = aux->sig;
			}
		} while(aux != NULL);
		
	}
}
void str_imprimir(str cadena){
	if(cadena != NULL){
		while( cadena != NULL ){
			printf("%c", cadena->dato);
			cadena = cadena->sig;
		}
	} else {
		printf("\nCadena vacia\n");
	}
}
void str_destruir(str *cadena){

	str act,prox;
	act=(*cadena);
	
	if(act!=NULL){
		
		while(act!=NULL){
			//printf("\nentro");
			prox=act->sig;
			free(act);
			act=prox;
		}
		//printf("3333");
		(*cadena)=NULL;
		printf("\nCadena destruida completamente");
	}else{
		printf("Cadena Vacia no se puede destruir");
	}
}
str str_copiar_cad(str orig){
	str aux=orig;
	char c;
	str nuevo=str_crear();
	if(orig==NULL){
		return NULL;
	}else{
		//str head=NULL;
		//str tail=NULL;
		//str nuevo=str_crear();
		while(aux!=NULL){
			
			c=aux->dato;
			//printf("\nmost:%c",c);
			str_agregar(&nuevo,c);
			aux=aux->sig;
		}
	}
	
	return nuevo;
}
int str_compara(str cad1,str cad2){
	
	if(cad1==NULL || cad2==NULL){ //verifico que las cadenas no esten vacias
		return -1;
	}else{
		str aux1=cad1;
		str aux2=cad2;
		while(aux1!=NULL && aux2!=NULL){
			if(aux1->dato!=aux2->dato){
				return -1;
			}
			aux1=aux1->sig;
			aux2=aux2->sig;
		}
		if(aux1==NULL && aux2==NULL) return 0;
	}
	
	return -1;
}
str str_concat(str cad1 , str cad2){
	str nuevo = str_copiar_cad(cad1);//Copio la primera cadena
	str aux = cad2;
	while(aux!=NULL){
		str_agregar(&nuevo,aux->dato);//le paso la cad1 y el char de cad2
		aux=aux->sig;
	}
	return nuevo;
	
}


