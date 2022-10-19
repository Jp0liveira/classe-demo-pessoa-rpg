#include <iostream>
#include "Estudioso.h"
using std::cout;

const int Estudioso::ESTUDIOSOIDADE = 21;
const int Estudioso::DIANASCIMENTO = 28;
const int Estudioso::MESNASCIMENTO = 06;
const int Estudioso::ANONASCIMENTO = 2001;
const string Estudioso::ESTUDIOSONOME = "Thiago O. Silva";
const string Estudioso::TIPOESTUDIOSO = "aluno";

const float Estudioso::NOTAESTUDIOSO = 10.0;
const int Estudioso::MATRICULAESTUDIOSO = 2021094524;

const float Estudioso::ESCUDOESTUDIOSO = 50.0;
const float Estudioso::DANONOTAESTUDIOSO = 25.0 ;
const float Estudioso::VIDASEMESTREESTUDIOSO = 100.0;


Estudioso::Estudioso( ): Pessoa( ESTUDIOSOIDADE, ESTUDIOSONOME, TIPOESTUDIOSO, DIANASCIMENTO, MESNASCIMENTO, ANONASCIMENTO ), Aluno( NOTAESTUDIOSO, MATRICULAESTUDIOSO ), Habilidades( ESCUDOESTUDIOSO, DANONOTAESTUDIOSO, VIDASEMESTREESTUDIOSO ) { };

Estudioso::~Estudioso( ){ };

void Estudioso::printCaracteristicaEstudioso( Estudioso nomeClass ) const{
	cout << "\n--------- CARAC. ESTUDIOSO ---------";
	cout << "\nNome Estudioso\t|\t" << nomeClass.getNomePessoa( ) << "\n";
	cout << "Tipo Estudioso\t|\t" << nomeClass.getTipoPessoa( )  << "\n";
	cout << "Numº Matricula\t|\t" << nomeClass.getMatriculaAluno( )  << "\n";
	cout << "Idade Estudioso\t|\t" << nomeClass.getIdadePessoa( ) << "\n";
	cout << "Data Nascimento\t|\t" << nomeClass.getDiaNascimento( ) << "/" << nomeClass.getMesNascimento( ) << "/" << nomeClass.getAnoNascimento( ) << "\n";
	cout << "Nota Final\t\t|\t" << nomeClass.getNotaFinalAluno( )  << "\n";
	cout << "Escudo Nota\t\t|\t" << nomeClass.getEscudoNota( )  << "\n";
	cout << "Dano Nota\t\t|\t" << nomeClass.getDanoNota( )  << "\n";
	cout << "Vida Semestre\t|\t" << nomeClass.getVidaSemestre( ) << "\n";
	cout << "-----------------------------------\n";
};

void Estudioso::materialSemestreEstudioso( ) {
	numMateriaisEstudioso.numeroMateriais = 8;
  vector < string * > materialEstudioso; 
	materialEstudioso.push_back( new string( "garrafinha: Tupperware") );
	materialEstudioso.push_back( new string( "lancheira: CK PRESENTES") );
	materialEstudioso.push_back( new string( "sombrinha: XIAOMI") );
	materialEstudioso.push_back( new string( "caneta: Pilot Frixion Ball") );
	materialEstudioso.push_back( new string( "caderno: Tilibra Happy") );
	for ( int i = 0; i < materialEstudioso.size( ); i++){
			numMateriaisEstudioso.cadastrarMateriais( *materialEstudioso[i] );
	}
	numMateriaisEstudioso.printListaMateriais( );
};

