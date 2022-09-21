#include <iostream>
#include "Estudante.cpp"
#include "Estudante.h"

int main( ) {
	Estudante estudante1( "Felipe", 21 , 3.0, 55);//argumentos

	cout << "\n\tDado estudante";
	estudante1.print( );

	cout << "\n\tNotas Cadastradas\n";
	estudante1.printNotaAzul( );//const static

	cout << "\nEstudantes maiores de idade: ";
	cout << estudante1.getNumEstudantesMaiores( ) << " \n";//static

	estudante1.caracEstudante("Felipe");//const string 
};