
#include <iostream>
#include <iomanip>
#include <array>
#include <stdio.h>
#include <ctime>
using namespace std;


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

// Realiza la busqueda binaria
template < typename T, size_t size >
int binarySearch( const array< T, size > &items, const T& key)
{
	int low = 0; // Indice Bajo
	int high = items.size() - 1; // Indice Alto
	int middle = ( low + high + 1 ) / 2; // Elemento central
	int location = -1; // -1 si no es encontrado

	do // loop para buscar elemento
	{
	
		// si el elemento esta en el centro
		if ( key == items[ middle ] )
			location = middle; 
		else if ( key < items[ middle ] ) // mitad es alta
			high = middle - 1; // elimina la mitad alta
		else // mitad es bajo
			low = middle + 1; // elimina la mitad baja
			
		middle = ( low + high + 1 ) / 2; // recalculo de la mitad
	} while ( ( low <= high ) && ( location == -1 ) );
		
	return location; // devuelve la ubicacion buscada
	
} 



int main()
{
	
	//Definicion de Variables y Arreglos
	
	
	const unsigned int N=20;
	array< int, N > bombas = {30,16,12,45,8,31,21,15,16,41,33,11,81,23,12,36,10,32,23,55}; 
	
	// Imprime los Valores del arreglo
	cout << "Los Valores Iniciales del Arreglo son:" <<endl;	
	print(bombas);
	
	//Ordena el arreglo
	cout << "Ordena de Mayor a Menor" <<endl;
	Menor(bombas);
	
	// Imprime los Valores del arreglo Ordenado
	cout << "Los Valores Ordenados del Arreglo son:" <<endl;	
	print(bombas);
	
	// Entrada del usuario
	cout << "Porfavor Introduzca Valor Buscado (-1 to quit): ";
	int searchKey; 
	cin >> searchKey;
	cout << endl;
	
	// Introduce un valor a buscar , -1 para Salir
	while ( searchKey != -1 )
	{
		// Busqueda binaria para hallar el valor buscado
		int position = binarySearch( bombas, searchKey );
		
		// -1 se entrega si no encuentra el valor
		if ( position == -1 )
			cout << "El Entero " << searchKey << " no fue encontrado.\n";
		else
			cout << "El entero " << searchKey
			<< " fue encontrado en " << position << ".\n";
			
		// Entrada del usuario
		cout << "Porfavor Introduzca Valor Buscado (-1 to quit): ";
		cin >> searchKey; 
		cout << endl;
	}
	
	return 0;
} 
