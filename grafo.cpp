#include "grafo.h"

//Icializa el Grafo a Vacio en su vertice null
void Grafo::Inicializa(){

	h=NULL;
}

//Determina si esta el grafo vacio o no
bool Grafo::Vacio(){

	if (h==NULL)
		return true;
	else return false;

}

//Determina el Tamano de Grafo
int Grafo::Tamano(){
	
	int cont=0;
	Vertice *aux;
	aux=h;
	
	while (aux != NULL){
		//Mientras se recorre el Grafo se cuenta los vertices
		cont++;
		aux = aux -> sig;	
	
	}

	return cont;
}

//Obtiene la posicion de memoria del vertice buscado
Vertice *Grafo::GetVertice(string nombre){

	Vertice *aux;
	aux=h;
	
	while(aux != NULL){
	
		if(aux->nombre == nombre)
			return aux;
			
		aux = aux -> sig;
		
	}
	
	return NULL;
}


//Inserta la arista del grafo
void Grafo::InsertaArista(Vertice *origen, Vertice *destino, int peso){

	Arista *nueva = new Arista;
	nueva->peso=peso;
	nueva->sig=NULL;
	nueva->ady=NULL;
	
	Arista *aux;
	aux = origen->ady;
	
	if(aux == NULL){
		origen->ady= nueva;
		nueva->ady= destino;
	}
	else{
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		
		aux->sig = nueva;
		nueva->ady = destino;
	}
}

//Inserta el vertice del grafo
void Grafo::InsertaVertice(string nombre){

	Vertice *nuevo=new Vertice;
	nuevo->nombre = nombre;
	nuevo->sig=NULL;
	nuevo->ady=NULL;
	
	if (Vacio())
		h=nuevo;
	else {
		Vertice *aux;
		aux=h;
		
		while(aux->sig != NULL){
		
			aux = aux->sig;
		
		}
		
		aux->sig = nuevo;
	}
}

//Imprime las adyacencias de los vertices
void Grafo::ListaAdyacencia(){

	Vertice *VertAux;
	Arista *ArisAux;
	
	VertAux=h;
	
	while (VertAux != NULL){
	
		cout << VertAux->nombre << "->" ;
		
		ArisAux = VertAux->ady;
		
		while(ArisAux != NULL){
		
			cout << "(" <<ArisAux->peso <<")"<< ArisAux->ady->nombre <<"->" ;
			
			ArisAux=ArisAux->sig;
				
		}
	
		VertAux = VertAux->sig;
		cout << endl;
	}
}

//anula todo el vertice
void Grafo::Anular(){

	Vertice *aux;
	
	while(h != NULL){
	
		aux=h;
		h= h->sig;
		delete(aux);
	
	}	
}

//Elimina las aristas del grafo
void Grafo::EliminarArista(Vertice *origen, Vertice *destino){

	int band=0;
	
	Arista *actual, *anterior;
	
	actual= origen->ady;
	
	if (actual == NULL)
		cout << "El vertice no tiene Aristas" << endl;
	else 
		if( actual->ady == destino ){
	
			origen->ady = actual->sig;
			delete(actual);
	
		}
		else{
			
			while(actual != NULL){
			
				if(actual->ady == destino){
				
					band=1;
					anterior->sig = actual->sig;
					delete(actual);
					break;
				}
			
				anterior=actual;
				actual=actual->sig;
			}
			
			if(band == 0){
			
				cout << "Estos dos vertices no estanconectados" << endl;
			
			}	
		}
}

//Elimina los vertices del grafo
void Grafo::EliminarVertice(Vertice *vert){

	Vertice *actual, *anterior;
	Arista *aux;
	
	actual=h;
	
	while(actual != NULL){
	
		aux=actual->ady;
		
		while(aux != NULL){
			
			if(aux->ady == vert){
				
				EliminarArista(actual,aux->ady);
				break;
			}
			
			aux=aux->sig;
		}
	
		actual=actual->sig;
	}
	
	actual = h;
	
	if(h == vert){
	
		h=h->sig;
		delete(actual);
	}
	else{
	
		while(actual != vert){
		
			anterior=actual;
			actual=actual->sig;
		}
		
		anterior->sig = actual->sig;
		delete(actual);		
	}	
}

//Realiza 
void Grafo::RecorridoAnchura(Vertice *origen){

	int band,band2;
	Vertice *actual;
	queue<Vertice*> cola;
	list <Vertice*> lista;
	list <Vertice*>::iterator i;
	
	cola.push(origen);
	
	while(!cola.empty()){
		
		band=0;
		actual=cola.front();
		cola.pop();
		
		for(i=lista.begin(); i != lista.end(); i++){
		
			if(*i == actual)
				band=1;
				
		}
		
		if(band==0){
		
			cout<< actual->nombre << ", ";
			lista.push_back(actual);
			
			Arista *aux;
			aux=actual->ady;
			
			while(aux != NULL){
			
				band2=0;
				for(i=lista.begin(); i != lista.end(); i++){
					
					if(aux->ady == *i)
						band2=1;			
				}
				
				if(band2==0){			
				cola.push(aux->ady);
				}
			
			aux=aux->sig;

			}
		}
	}
}




