#include <iostream>
#include "Aluno.h"
#include "Habilidades.h"
using std::cout;

//static  
const string Aluno::NOTAS[ CONCEITOS ]= { "E", "B", "R", "I" }; 
const string Aluno::NOMECLASS = "aluno";

// inicio - construtores
Aluno::Aluno( ): NOTAMAXALUNO( 10.0 ), NOTAMINALUNO( 0.0 ), Pessoa( ){
	notaFinalAluno = NOTAMINALUNO;
	matriculaAluno = 000;
};

Aluno::Aluno( int idadeAluno, string nomeAluno, int diaNascimento, int mesNascimento, int anoNascimento, float notaFinalAluno,  int matriculaAluno ): NOTAMAXALUNO( 10.0 ), NOTAMINALUNO( 0.0 ), Pessoa( idadeAluno, nomeAluno, NOMECLASS, diaNascimento, mesNascimento, anoNascimento){
	this->setNotaFinalAluno( notaFinalAluno );
	this->setMatriculaAluno( matriculaAluno );
};

Aluno::Aluno( const Aluno& other): NOTAMAXALUNO( other.NOTAMAXALUNO ), NOTAMINALUNO( other.NOTAMINALUNO ){
	this -> matriculaAluno = other.matriculaAluno;
	this -> notaFinalAluno = other.notaFinalAluno;
};

Aluno::~Aluno(){ };
// fim - construtores

// inicio - set
void Aluno::setNotaFinalAluno( float AnotaFinalAluno ){
	if ( AnotaFinalAluno >= NOTAMINALUNO && AnotaFinalAluno <= NOTAMAXALUNO ){
		notaFinalAluno = AnotaFinalAluno;
		return;
	}
	else{
		cout << "\n[ERRO!] nota inválida\n";
		printNotasCadastrados( );
	}
	notaFinalAluno = NOTAMINALUNO;
};

void Aluno::setMatriculaAluno( int AmatriculaAluno ){
	matriculaAluno = AmatriculaAluno;
};
// fim - set

// inicio - exibir
void Aluno::printCaracteristicaAluno( ) const{
	cout << "\n-------- CARAC. PESSOA --------";
	cout << "\nNota final Aluno: " << notaFinalAluno << "\n";
	cout << "Matricula Aluno: " << matriculaAluno << "\n";
	cout << "--------------------------------\n";
};

void Aluno::printNotasCadastrados( ){
	cout << "\n-------- NOTAS CADASTRADAS -------\n";
	for (int i = 0; i < CONCEITOS; i++){
		cout << "Nota Cadastrada: " << NOTAS[i] << " (" << &NOTAS[i] << ")\n";
	}
	cout << "------------------------------------\n";
};
// fim - exibir