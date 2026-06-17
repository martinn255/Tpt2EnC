#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef char* str;

str load2(str);
void print_string(str);

*/

///*
typedef struct Nodo{
	char dato;
	struct Nodo *sig;
}TR_Nodo;
typedef TR_Nodo *str;

str str_crear();
void str_agregar(str *, char);
void str_desde_string(str *, char *);
void str_eliminar_vocales(str *);
void str_imprimir(str);
void str_destruir(str *);
str str_copiar_cad(str);
str str_concat(str,str);
int str_compara(str,str);//*/
#endif
