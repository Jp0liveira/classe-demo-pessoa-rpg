#include "Aluno.cpp"
#include "Aluno.h"

int main( ){
	
	Aluno joao("joao", "bagunceiro", 21, 7.0);
	Aluno *joaoPtr = &joao;
	joaoPtr->printHistoricoIdadeAlunos( );

	return 0;
};