
#include <iostream>
#include <iomanip>
#include <array>
#include <stdio.h>
#include <ctime>
using namespace std;

// Ordena en forma Ascendente
template < typename T, size_t size >
void Menor( array< T, size > &items )
{	// loop de elementos
	for ( size_t i = 0; i < items.size() - 1; ++i )
	{
		size_t indexOfSmallest = i; // Almacena el valor mas pequeno
		
		// Encuentra el item mas pequeno
		for ( size_t index = i + 1; index < items.size(); ++index )
			if ( items[ index ] < items[ indexOfSmallest ] )
				indexOfSmallest = index;
		
		// Cambia la posicion de los elementos.
		T hold = items[ i ];
		items[ i ] = items[ indexOfSmallest ];
		items[ indexOfSmallest ] = hold;
	} 
}

// Ordena en forma descendente
template < typename T, size_t size >
void Mayor( array< T, size > &items )
{	// loop de los elementos
	for ( size_t i = 0; i < items.size() - 1; ++i )
	{
		size_t indexOfGreater = i; // Guarda el Valor mas Grande
		
		// Encuentra el item mas Grande
		for ( size_t index = i + 1; index < items.size(); ++index )
			if ( items[ index ] > items[ indexOfGreater ] )
				indexOfGreater = index;
		
		// swap the elements at positions i and indexOfSmallest
		T hold = items[ i ];
		items[ i ] = items[ indexOfGreater ];
		items[ indexOfGreater ] = hold;
	} 
}

//Imprime los elementos del arreglo
template < typename T, size_t size >
void print( array< T, size > &items )
{

	cout << "Element" << setw( 13 ) << "Value" << endl;
	//loop para el barrido del arreglo
	for ( size_t j = 0; j < items.size(); ++j )
		cout << setw( 7 ) << j << setw( 13 ) << items[ j ] << endl;
	
	cout << endl;
}


int main()
{
	
	//Definicion de Variables y Arreglos
	
	srand( static_cast<unsigned int>( time( 0 ) ) );
	const unsigned int N=25;
	array< double, N > n; 
	
	// Inicializacion de arreglo a 0
	for ( size_t i = 0; i < n.size(); ++i )
		n[ i ] = 0; // set element at location i to 0
	
	
	// Imprime los Valores del arreglo
	cout << "Los Valores Iniciales del Arreglo son:" <<endl;	
	print(n);
		
	// Asignacion de Valores de Bsf aleatorios
	for ( size_t i = 0; i < n.size(); ++i )
		n[ i ] = 100 + rand() % 10000; 
		
	// Imprime los Valores del arreglo
	cout << "Los Valores de Sueldos del Arreglo son:" <<endl;
	print(n);
		
	// Selecciona el Tipo de Orden
	int orden=0;
	cout << "Desea ordenar de Mayor-menor (1) o de menor-Mayor(2):" <<endl;
	cin >> orden;
	
	if (orden ==1){
		cout << "Ordena de Mayor a Menor" <<endl;
		Mayor(n);
		
		// Imprime los Valores del arreglo
		cout << "Los Valores Ordenados del Arreglo son:" <<endl;	
		print(n);
		}
	else{
		cout << "Ordena de menor a Mayor" <<endl;
		Menor(n);
		
		// Imprime los Valores del arreglo
		cout << "Los Valores Ordenados del Arreglo son:" <<endl;	
		print(n);
		}
		
	return 0;
		
		
} 
