#include <stdlib.h>
#include <stdio.h>
#include "cadena.h"
#include "tad_set.h"
#include "automata.h"

int main(){
	
	AF A=crear_automata();
	//Lo mas parecido a los automatas de pyton la entrada
	agregar_estado(A,"q0");
	agregar_estado(A,"q1");
	agregar_estado(A,"q2");
	
	agregar_simbolo(A,"a");
	agregar_simbolo(A,"b");
	
	agregar_Einicial(A,"q0");
	agregar_Efinal(A,"q2");
	
	mostar_automata(A);
	//prueba_set();
	//prueba_cad();
	//printf("\n");
	
	
	return 0;
}
void prueba_set(){
	
	///*
	Tdata A= NULL;
	Tdata B = NULL;
	
	Tdata li = NULL; //tipo lista
	Tdata li2 = NULL;
	
	//Conjuntos
	
	//A = {"hola", "mundo"} 
	Tdata s1= create_str_ast();
	str_desde_string(&(s1->string),"Hola");//Esta es la forma de agrgar una cadena
	Tdata s2= create_str_ast();				//ya que es Tdata con mas cosas aparte de string
	str_desde_string(&(s2->string),"Mundo");//Corregir este s->string 
	
	//concatenacion de cadena
	//str conc=str_concat(s2,s1);
	//str_imprimir(conc);
	//printf("\n");
	//Mostar s1
	//str_imprimir(s1);
	//printf("\n");
	
	append_set(&A, s1);
	//printf("A = ");
	//printSet(A);
	append_set(&A, s2);
	//printf("A = ");
	//printSet(A);//*/
	
	//B = {"palabra", {A}} 
	Tdata s3 = create_str_ast();
	str_desde_string(&(s3->string),"palabra");
	//s3->string = load2("palabra"); es lo mismo que arriba
	
	append_set(&B, s3);
	append_set(&B, A);   
	
	printf("A = ");
	printSet(A);
	
	printf("\n");
	printf("\nComparacion:");
	int comp = equals_general(A,B);
	printf("%d",comp);
	
	
	printf("\nB = ");
	printSet(B);
	
	//Listas
	append_list(&li, s1);  
	append_list(&li,s2);
	
	append_list(&li2,s2);
	append_list(&li2,s1);
	append_list(&li2,s3);
	
	printf("\n Lista1= ");
	//printSet(li);
	print_list(li);
	
	//intentemos no mesclar listas y conjuntos por ahora
	printf("\n");
	printf("\n lista li con conjunto A :");
	append_list(&li,A);
	print_list(li);
	
	//Revisar error en mostrar una lista me sale como conjunto en mostSet o copi
	//printf("\n Conjunto A con listas li:");
	//append_set(&A,li);
	//printSet(A);
	
	printf("\n");
	printf("\n Lista2= ");
	print_list(li2);
	
	printf("\n");
	
	printf("\nTamanio de la lista1: ");
	int tam1=length(li);
	printf("%d ",tam1);
	printf("\nTamanio de la lista2: ");
	int tam2=length(li2);
	printf("%d ",tam2);
	
	
	int valor = str_compara(s1,s2);
	printf("\ncompara cadenas:");
	printf("%d",valor);
	
	printf("\n el S3=");
	str_imprimir(s3->string);
	int bus=belongs(B,s3);
	printf("\nPertenece al conjunto:");
	printf("%d",bus);
	
	//Pregunta (Yo lo que hice fue ingregar si no habia un elemento repetido aun conjunto )
	printf("\n");
	insert_set(&A,s2);
	printf("\nA=");
	printSet(A);
	printf("\nB=");
	printSet(B);
	
	
	printf("\n");
	printf("\nUnion 1:");
	Tdata U1=union_set(A,B);
	printSet(U1);
	
	printf("\nIntersecion 1:");
	Tdata I1=intersection_set(A,B);
	printSet(I1);
	
	printf("\nDiferencia 1:");
	Tdata D1=difference_set(A,B);
	printSet(D1);
	
	printf("\nSubSet 1:");
	int subconj = subset(A,U1);//si lo pruebo al reves ya no es subconj
	printf("%d",subconj);
	
	printf("\nCopia de Lista:");
	Tdata copi=copy_list(li2);
	print_list(copi);
	
	printf("\nConcatenacion de Lista:");
	Tdata concl = concat(li,li2);
	print_list(concl);
	
	printf("\nProducto cartesiano 1:");
	Tdata Pr= prod_cartesiano(A,B);
	printSet(Pr);
	
}
void prueba_cad(){
	
	/*
	str cad1;
	cad1=str_crear();
	str_desde_string(&cad1, "Hola");
	str_imprimir(cad1);
	str_agregar(&cad1, ' ');str_agregar(&cad1, '2');
	printf("\n---\n");
	str_eliminar_vocales(&cad1);
	str_imprimir(cad1);
	printf("\n---\n");
	str_destruir(&cad1);
	str_imprimir(cad1);*/
	
	//*/
}
	
