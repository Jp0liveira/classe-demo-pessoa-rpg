#include <iostream>
#include "Aluno.cpp" 

int main( ){
	Aluno felipe("Felipe", "bagunceiro", 21, 6.8);
	const Aluno FELIPE("Felipe Oliveira", "estudioso", 20, 9.0);
	const Aluno JOAO(felipe);
	felipe.printCaracteristicasAluno( );
	FELIPE.printCaracteristicasAluno( );
	JOAO.printCaracteristicasAluno( );

	return 0;
};