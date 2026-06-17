#include "automata.h"
#include "tad_set.h"
#include <stdio.h>

AF crear_automata(){
	AF aut;
	aut = (AF) malloc(sizeof(Automata));
	aut->Q = NULL;
	aut->sigma=NULL;
	aut->qI=NULL;
	aut->F=NULL;
	//aut->delta=
	return aut;
}
