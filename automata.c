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
//Crea los nodos para el delta
DeltaNodo crear_deltaNodo(char *q,char *simb){
	DeltaNodo nodo;
	nodo = (DeltaNodo) malloc(sizeof(NodoDel));
	nodo->from=crea_str_Enl(q);
	nodo->symbol=crea_str_Enl(simb);
	nodo->destinatario=NULL;
	nodo->sigi=NULL;
	return nodo;
}
	
//Crea un str desde una cadena c osea le puedo pasar q0,q1,a,b,qx0 asi Ya la tengo pero esta me retorna el String como Tdata
State crea_str_Enl(char *nombre){
	Tdata sr=create_str_ast();
	str_desde_string(&(sr->string),nombre);//verificar sr->string
	return sr;
}

void agregar_estado(AF aut,char *nom){
	append_set(&aut->Q,crea_str_Enl(nom));
}
void agregar_simbolo(AF aut,char *simb){
	append_set(&aut->sigma,crea_str_Enl(simb));
}
void agregar_Einicial(AF aut,char *q){
	aut->qI=crea_str_Enl(q);
}
void agregar_Efinal(AF aut,char *Eacepta){
	append_set(&aut->F,crea_str_Enl(Eacepta));
}
void agregar_transiciones(){
	//buscar el Nodo
	//verifico si exite si es verdar le agrego los detinos por ser AFND
	//sino una nueva entrada lo creo y la agrego sus destinos
}
DeltaNodo buscar_nodo(){
	//idea geberal buscar el delta osea el nodo delta(q,simbolo)
}
void mostar_automata(AF aut){
	printf("\nQ =");
	printSet(aut->Q);
	printf("\nSigma =");
	printSet(aut->sigma);
	printf("\nq0 =");
	str_imprimir(aut->qI->string);
	printf("\nF =");
	printSet(aut->F);
	printf("\n");
	
	//Falta el imprimir el delta osea las transiciones 
}
	//Faltaria para modificar los estados o las transiciones 
