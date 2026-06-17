#include "tad_set.h"
#include "cadena.h"
#include <stdio.h>

typedef Tdata State;
typedef Tdata Symbol;


//Entrada funcional 
typedef struct{
	State from;//estado
	Symbol symbol;//simbolo 
	Tdata destinatario;//a donde va osea a los conjuntos ej,q1,q2
}DeltaEntry;

//AUTOMATA

typedef struct{
	Tdata Q;//conjunto no vacio de estados 
	Tdata sigma;//Conjunto no vacio de simbolos o alfabeto
	DeltaEntry* delta;// ej delta(q0,a)={q1} es la transicion 
	int deltaCount;
	State qI;//estado inicial
	Tdata F;//Conjunto de estados de aceptacion
}Automata;
typedef Automata *AF;

Automata* crear_automata();
//void agregar_estado();
//void agregar_simbolo();
