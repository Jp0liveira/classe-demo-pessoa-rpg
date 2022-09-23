#include <iostream>
#include "Estudante.cpp"
#include "Estudante.h"

int main( ) {
	Estudante estudante1( "Felipe", 21 , 3.0, 55 );//argumentos
	const Estudante ESTUDANTE2( "Thiago", 19, 7.0, 23 );
	// const Estudante ESTUDANTE3( ESTUDANTE2 );

	const int numEstudantes = 2;
	const string estudantes[  numEstudantes ] = { estudante1.getNomeEstudante(), ESTUDANTE2.getNomeEstudante() };
	

	cout << "\n\tDado estudante";
	estudante1.print( );

	cout << "\n\tNotas Cadastradas\n";
	estudante1.printNotaAzul( );//const static

	estudante1.caracEstudante("Felipe");//const string 

	cout << "\n---------------------------------\n";
	cout << "\n\tDado estudante";
	ESTUDANTE2.print( );

	cout << "\n\tNotas Cadastradas\n";
	ESTUDANTE2.printNotaAzul( );//const static
	
	// ESTUDANTE2.caracEstudante("Thiago");//const string 

	cout << "\nImprimindo Estudantes:\n";
	for (int i = 0; i < numEstudantes; i++) {
		cout << estudantes[ i ] << "\n";
	}

	cout << "\nEstudantes maiores de idade: ";
	cout << ESTUDANTE2.getNumEstudantesMaiores( ) << " \n";//static

	cout << "\n\n";
};