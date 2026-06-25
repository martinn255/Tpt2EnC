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
//Crea los nodos para el delta(q,alf)={q1,q2}
DeltaNodo crear_deltaNodo(char *q,char *simb){
	DeltaNodo nodo;
	nodo = (DeltaNodo) malloc(sizeof(NodoDel));
	nodo->from=crea_str_Enl(q);//modificar para que sea un conjunto no solo un strEnlazado
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
// ej Delta(q,alf)={q1,q2}->dest / el q es igual a donde va osea el from
void agregar_transiciones(AF aut,char *from,char *alf,char *dest){
	//verifico si exite si es verdar le agrego los detinos por ser AFND
	//sino una nueva entrada lo creo y la agrego sus destinos
	
	State q = crea_str_Enl(from);
	//Symbol al = crea_str_Enl(alf);
	DeltaNodo trans = buscar_transicion(aut,q,alf);
	Tdata destino = crea_str_Enl(dest);
	
	if(trans!=NULL){
		//Esto significa que si exite la transicion por lo tanto le agrego el destimmo a dicha transicion 
		append_set(&trans->destinatario,destino);
		//printf("Se agrego el nuevo destino a la transicion");
	}else{
		//agrega al sig nodo la transicion ya que es nueva
		if(pertenece_Q(aut,destino)==1){
			DeltaNodo nuevo = crear_deltaNodo(from, alf);//es el mismo valor que q,al
			
			append_set(&nuevo->destinatario, destino);
			nuevo->sigi = aut->delta;
			aut->delta  = nuevo;
		}else{
			printf("\nNo pertenece al conjunto\n");
		}
	}
	

}
//verifica el q si exixte la transicion
int pertenece_Q(AF aut,Tdata destino){
	AF aux=aut;
	
	if(belongs(aux->Q,destino)==1){
		return 1;
	}
	return 0;
}
//esta solo busca las transiciones nada mas
DeltaNodo buscar_transicion(AF aut,State q,char *alf){
	//idea geberal buscar el delta osea el nodo delta(q,simbolo)
	Symbol al =crea_str_Enl(alf);
	
	DeltaNodo aux = aut->delta;

	while(aux!=NULL){
		if(equals_general(aux->from,q)==0 && equals_general(aux->symbol,al)==0){
			return aux;
		}
		aux=aux->sigi;
	}
	return NULL;
}

void aceptacion_cadena(AF aut, char *w){
	Tdata cadena = crea_str_Enl(w);
	if(cadena == NULL || cadena->string == NULL){
		printf("\nCadena vacia\n");
		
	}else{
		Tdata estados_actuales = NULL;
		append_set(&estados_actuales, aut->qI);
		
		str aux = cadena->string;
		//printf("\nCadena : ");
		//str_imprimir(aux);
		//printf("\n");
		
		while(aux != NULL){
			
			char simb[2] = {
				aux->dato, '\0'
			};
			//char simb=aux->dato;
			//Symbol si=carac_str(simb);
			
			Tdata nuevos_estados = NULL; //estados siguientes
			
			//por cada estado actual busco su transicion
			Tdata e = estados_actuales;
			while(e != NULL){
				
				//DeltaNodo trans = buscar_trans_estados(aut, e->data,si->data);
				DeltaNodo trans =buscar_transicion(aut,e->data,simb);
				
				if(trans != NULL){
					// agrego todos los destinos al nuevo conjunto
					Tdata dest = trans->destinatario;
					//printSet(trans->destinatario);
					while(dest != NULL){
						if(belongs(nuevos_estados, dest->data) != 1){
							append_set(&nuevos_estados, dest->data);//delta 
						}
						dest = dest->next;
					}
				}
				e = e->next;
			}
			
			//if(nuevos_estados == NULL){
				//printf("\nCadena RECHAZADA: no hay transiciones posibles\n");
				//return;
			//}
			
			estados_actuales = nuevos_estados;
			aux = aux->sig;
		}
		// verifico si algún estado actual es de aceptación
		if(pertence_qf(aut,estados_actuales)==1){
			printf("\nCadena ACEPTADA\n");
		}else{
			printf("\nCadena RECHAZADA:ningun estado final es de aceptacion\n");
		}
	}
	
}
//Devuelve 1 si algun estado esta pertenece a F=qf
int pertence_qf(AF aut ,Tdata estados){
	Tdata aux = estados;
	//printSet(estados);
	while(aux!=NULL){
		if(belongs(aut->F, aux->data) == 1){
			return 1;
		}
		aux=aux->next;
	}
	return 0;
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
	printf("Mostrar tranciciones \n");
	DeltaNodo aux = aut->delta;
	while(aux!=NULL){
		printf("delta(");
		str_imprimir(aux->from->string);
		//printSet(aux->symbol);este es para modelar AFND
		printf(",");
		str_imprimir(aux->symbol->string);
		printf(")=");
		printSet(aux->destinatario);
		printf("\n");
		aux=aux->sigi;
	}
	
}
//aqui nesesito cambiar las transiciones ya que se convierten de 
//delta(q,a)={q,q} a una transicion que el q es un conjunto 
//Y hacer uniones de dicos conjuntos
void conv_afnd_afd(AF aut){
	AF nuevo = crear_automata();
	
	State qIinicial = NULL;
	append_set(&nuevo,qIinicial);
	//hago una lista para tener los pendientes a procesar
	State pend=NULL;
	append_list(&pend,qIinicial);
	
	//una lista para agregar conjuntos que ya procese para no repetotir
	State procesado=NULL;
	
	while(pend!=NULL){
		State estado_actual=clone2(pend->data);
		//cabio el estado a procesado para no volver a tocar
		append_list(&procesado,estado_actual);
		
		
		//le doy el valor del simbolo
		Symbol si=nuevo->sigma;
		//while(){
			
		//}
		pend=pend->next;
	}
	
	DeltaNodo aux = aut->delta;
	printf("\nTranciciones a modificar \n");
	while(aux!=NULL){
		printf("delta(");
		str_imprimir(aux->from->string);
		//printSet(aux->symbol);este es para modelar AFND
		printf(",");
		str_imprimir(aux->symbol->string);
		printf(")=");
		printSet(aux->destinatario);
		printf("\n");
		aux=aux->sigi;
	}
}
int perteneceSigma(Tdata sigma, char *w){
	int i = 0;
	Tdata aux=NULL, set=NULL;
	while(w[i] != '\0'){
		char c[2];
		c[0] = w[i];
		c[1] = '\0';
		aux = crea_str_Enl(c);
		append_set(&set, aux);
		//printSet(set);
		i++;
	}
	if(subset(set, sigma)==1){
		return 1;
	} else{
		return -1;
	}
}
/*
char str_a_string(str cadena){  //En cadena.h y cadena.c
	int len = 0;
	str aux = cadena;
		
	// Contar caracteres
	while(aux != NULL){
		len++;
		aux = aux->sig;
	}
	
	// Reservar memoria (+1 para '\0')
	char texto = malloc((len + 1) * sizeof(char));
	if(texto == NULL)
		return NULL;
	
	// Copiar caracteres
	aux = cadena;
	int i = 0;
	while(aux != NULL){
		texto[i] = aux->dato;
		i++;
		aux = aux->sig;
	}
	
	texto[i] = '\0';
	
	return texto;
}
void aceptacion_cadena(AF aut, char *w){
	if(w!=NULL && perteneceSigma(aut->sigma, w)==1){
		Tdata viejoEstadosActuales=NULL;
		Tdata nuevoEstadosActuales=NULL;
		append_set(&nuevoEstadosActuales, aut->qI);
		
		int i=0;
		while(w[i] != '\0'){
			char c[2];
			c[0] = w[i];
			c[1] = '\0';
			viejoEstadosActuales = nuevoEstadosActuales;
			nuevoEstadosActuales = NULL;        //implementar free() para malloc
			while(viejoEstadosActuales!=NULL){
				str estado = viejoEstadosActuales->data->string;
				//if(viejoEstadosActuales->data==NULL) printf("A----- %d", viejoEstadosActuales->nodeType);
				char est = str_a_string(estado);
				//printSet(aut->delta);
				DeltaNodo transicion = buscar_transicion(aut, est, c);
				//printf("\nEstado: %s - Symbolo: %s", est, c);
				if(transicion!=NULL){
					Tdata destinatarios = transicion->destinatario;
					while(destinatarios != NULL){
						append_set(&nuevoEstadosActuales, destinatarios->data);
						destinatarios = destinatarios->next;
					}
				}
				
				viejoEstadosActuales = viejoEstadosActuales->next;
				}
			
			i++;
		}
		//printSet(nuevoEstadosActuales);printSet(aut->F);
		Tdata interseccion = intersection_set(nuevoEstadosActuales, aut->F);
		if(interseccion!=NULL){
			printf("Cadena aceptada");
		}
	}
}*/
	/*DeltaNodo buscar_trans_estados(AF aut,State q,Symbol alf){
	//idea geberal buscar el delta osea el nodo delta(q,simbolo)
	//Symbol al =crea_str_Enl(alf);
	str_imprimir(alf);
	DeltaNodo aux = aut->delta;
	
	while(aux!=NULL){
	if(equals_general(aux->from,q)==0 && equals_general(aux->symbol,alf)==0){
	return aux;
	}
	aux=aux->sigi;
	}
	return NULL;
	}*/
	
	/*Symbol carac_str(char c){
		Symbol carac=create_str_ast();
		str_agregar(&carac,c);
		return carac;
	}*/		
