#include "automata.h"
#include "tad_set.h"
#include <stdio.h>
//Hice cambios en la extructura intente hacer la propuesta4
//pero le agregrege que sea como lista enlazada sin isar el indice del 4 
//seria como una combinacion del 4 y lista enlazada de deltaENtry
AF crear_automata(){
	AF aut;
	aut = (AF) malloc(sizeof(Automata));
	aut->Q = NULL;
	aut->sigma=NULL;
	aut->qI=NULL;
	aut->F=NULL;
	//aut->deltaCount=0;//Verificar esto 
	//aut->delta= malloc(sizeof(DeltaEntry));
	aut->delta=NULL;
	return aut;
}
DeltaNodo crear_deltaNodo(char *es,char *sym){
	DeltaNodo nodo;
	nodo = (DeltaNodo) malloc(sizeof(NodoDel));
	nodo->from=str_liEnlaz(es);
	nodo->symbol=str_liEnlaz(sym);
	nodo->destinatario=NULL;
	nodo->sigi=NULL;
}
	
//Crea un str desde una cadena c osea le puedo pasar q0,q1,a,b,qx0 asi Ya la tengo pero esta me retorna el String como Tdata
State str_liEnlaz(char *nombre){
	Tdata sr=create_str_ast();
	str_desde_string(&sr,nombre);//verificar sr->string
	return sr;
}
void agregar_estado(){
	
}
void agregar_simbolo(){
	
}
void agregar_Einicial(){
	
}
void agregar_Efinal(){
	
}
void agregar_transiciones(){
	
}
