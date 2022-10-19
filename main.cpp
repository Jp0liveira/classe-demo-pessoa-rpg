#include <iostream>
#include "classes.h"
using std::cout;

int main() {
	Estudioso thiago;
	thiago.printCaracteristicaEstudioso( thiago );
	for ( int i = 0; i < 3; i++){
 	thiago.receberDanoNota( );// + 25 de  dano
	};
	thiago.printCaracteristicaEstudioso( thiago );
	for ( int i = 0; i < 7; i++){
 	thiago.curarDanoNota( );// + 10 de cura
	};
 	thiago.receberDanoNota( );
	thiago.printCaracteristicaEstudioso( thiago );
	thiago.materialSemestreEstudioso( );
	return 0;
}