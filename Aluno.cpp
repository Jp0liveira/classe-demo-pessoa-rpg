#include <iostream>
#include "Aluno.h"

using std::cout;

//static  
const string Aluno::NOTAS[ CONCEITOS ]= { "E", "B", "R", "I" }; 
const string Aluno::NOMECLASSALUNO = "aluno";

// inicio - construtores
Aluno::Aluno( ): NOTAMAXALUNO( 10.0 ), NOTAMINALUNO( 0.0 ), Pessoa( ){
	
	notaFinalAluno = NOTAMINALUNO;
	matriculaAluno = 000;
};

Aluno::Aluno( int idadeAluno, string nomeAluno, int diaNascimento, int mesNascimento, int anoNascimento, float notaFinalAluno,  int matriculaAluno ): NOTAMAXALUNO( 10.0 ), NOTAMINALUNO( 0.0 ), Pessoa( idadeAluno, nomeAluno, NOMECLASSALUNO, diaNascimento, mesNascimento, anoNascimento ){
	this->setNotaFinalAluno( notaFinalAluno );
	this->setMatriculaAluno( matriculaAluno );
};

Aluno::Aluno( const Aluno& other): NOTAMAXALUNO( other.NOTAMAXALUNO ), NOTAMINALUNO( other.NOTAMINALUNO ), Pessoa( static_cast< Pessoa > ( other ) ) {
	this -> matriculaAluno = other.matriculaAluno;
	this -> notaFinalAluno = other.notaFinalAluno;
};

Aluno::~Aluno( ){ };
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
	cout << "\n-------- CARAC. ALUNO --------";
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

// incio - sobrecarga de operadores
	// exibe todas as caracteristicas da "pessoa"
ostream &operator<<( ostream &COUT, const Aluno &aluno ){
	COUT << static_cast< Pessoa > ( aluno );
	COUT << "Nota final Aluno: " << aluno.notaFinalAluno << "\n";
	COUT << "N° de matricula: " << aluno.matriculaAluno << "\n";
    return COUT;
};
// fim - sobrecarga de operadores