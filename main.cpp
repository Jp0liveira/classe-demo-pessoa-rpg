#include <iostream>
#include "Aluno.cpp" 

int main( ){
	Aluno joao("Joao", "estudioso", 21, 3.5);
	Aluno *joaoPtr;
	joaoPtr =  new Aluno("Felipe", "timido", 19, 7.5);
	joaoPtr->printCaracteristicasAluno( );
	joaoPtr = new Aluno;
	joaoPtr->printCaracteristicasAluno( );
	joaoPtr = &joao;
	joaoPtr->printCaracteristicasAluno( );

	return 0;
};