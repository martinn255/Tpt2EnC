#include "tad_set.h"
#include "cadena.h"
#include <stdio.h>

//Solo es para darles un nombre distinto de Tdata
typedef Tdata State;
typedef Tdata Symbol;


//Entrada funcional 
/*typedef struct{
	State from;//estado
	Symbol symbol;//simbolo 
	Tdata destinatario;//a donde va osea a los conjuntos ej,q1,q2 es un set
}DeltaEntry;*/
typedef struct NodoD{
	State from;
	Symbol symbol;
	Tdata destinatario;
	struct NodoD *sigi;
}NodoDel;
typedef NodoDel *DeltaNodo;

//AUTOMATA

typedef struct{
	Tdata Q;//conjunto no vacio de estados 
	Tdata sigma;//Conjunto no vacio de simbolos o alfabeto
	//DeltaEntry* delta;// ej delta(q0,a)={q1} es la transicion 
	//int deltaCount;//cuenta las transixiones No me convence las tranciciones con i 
	DeltaNodo delta;
	State qI;//estado inicial
	Tdata F;//Conjunto de estados de aceptacion
}Automata;
typedef Automata *AF;

DeltaNodo crear_deltaNodo(char *,char *);
AF crear_automata();

State crea_str_Enl(char *);
void agregar_estado(AF ,char *);
void agregar_simbolo(AF ,char *);
void agregar_Einicial(AF ,char*);
void agregar_Efinal(AF ,char *);

void agregar_transiciones(AF ,char *q,char *simb,char *dest);
void mostar_automata(AF);
//DeltaNodo buscar_transicion(AF , State,Symbol);
void aceptacion(AF,char*);

DeltaNodo buscar_transicion(AF,State,char*);
//void aceptacion_cadena(AF,char *);
int perteneceSigma(Tdata,char*);
int pertence_qf(AF,Tdata);
int pertenece_Q(AF,Tdata);
