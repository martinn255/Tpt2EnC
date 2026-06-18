#ifndef TAD_SET_H
#define TAD_SET_H

#include "cadena.h"

#define STR 1
#define SET 2
#define LIST 3

struct dataType{
	int nodeType;   /* STR, SET, LIST */
	union{
		str string;
		struct{
			struct dataType* data;
			struct dataType* next;
		};
	};
};

typedef struct dataType* Tdata;

Tdata create_str_ast();
Tdata create_list();
Tdata create_set();

void append_set(Tdata*,Tdata);
void printSet(Tdata);


//Operaciones sobre SET
void insert_set(Tdata* set, Tdata elem); 	//(sin duplicados)
int belongs(Tdata set, Tdata elem);		//buscar o pertenece//listo
void remove_set(Tdata* set, Tdata elem); //eliminar
	
//#Operaciones algebraicas
Tdata union_set(Tdata A, Tdata B);//
Tdata intersection_set(Tdata A, Tdata B);//
Tdata difference_set(Tdata A, Tdata B);//
int subset(Tdata A, Tdata B);//sub conjunto
int equals_set(Tdata A, Tdata B); // compara dos conjuntos
int equals_general(Tdata,Tdata);


	//Operaciones sobre Listas
void append_list(Tdata* list, Tdata elem);				//listo
int length(Tdata list);									//listo
Tdata copy_list(Tdata list); //(copia profunda)			//probar
Tdata concat(Tdata l1, Tdata l2);
int search(Tdata list, Tdata elem);

int equals_list(Tdata,Tdata);

void print_list(Tdata);
//Para ambos o algo parecido
Tdata prod_cartesiano(Tdata,Tdata);


#endif
