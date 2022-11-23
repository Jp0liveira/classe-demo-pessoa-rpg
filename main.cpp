#include <iostream>
#include "AllClasses.h"
using std::cout;

int main( ) {
	Estudioso estudioso( 21, "Ferreira C. Oliveira", 28, 06, 2000, 9.5, 2021006895 );
	Bagunceiro bagunceiro( 15, "Thiago J. Pereira", 28, 06, 2008, 7.5, 2022007823 );
	
	// materiais do semestre
	bagunceiro.materialSemestreBagunceiro( );

	// sobrecarga de operadores 
	bagunceiro = "Mochila: nikeFashion";
	bagunceiro == estudioso;
	bagunceiro != bagunceiro;
	cout << bagunceiro;

	// caracteristicas do bagunceiro
	bagunceiro.printListaMateriais( );
	bagunceiro.printCaracteristicasBagunceiro( bagunceiro );
	!bagunceiro;
	bagunceiro.printListaMateriais( );
	
	// habilidades
	bagunceiro.printHabilidades( );
	cout << "\n--------- SIST. BATALHA ---------"; // sim, poderia fazer um metodo pra isso.
	cout << "\nEscudo: ";
	while ( bagunceiro.getVidaSemestre( ) >= 50  ){
		bagunceiro.receberDanoNota( );
		// escudo recebe + 10 de dano
		// vida recebe o danoNota / 2 == + 5 de dano;
		cout << bagunceiro.getEscudoNota( ) << " ";
		if ( bagunceiro.getEscudoNota( ) == 0 ){ // escudo quebra e começa a usar a vida
			cout << "\nVida: " << bagunceiro.getVidaSemestre( ) << " Escudo: ";
		}	
	};
	cout << "\n---------------------------------\n";
	bagunceiro.printHabilidades( );
	
	bagunceiro.curarDanoNota( 20 );// curando o escudo >= 10
	bagunceiro.curarDanoNota( 5 );// curando a vida <= 10 

	bagunceiro.printHabilidades( );

	bagunceiro.printCaracteristicasBagunceiro( bagunceiro );
	
	return 0;

};