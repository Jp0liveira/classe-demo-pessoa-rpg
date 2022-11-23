#include <iostream>
#include "Pessoa.h"
using std::cout;

//static's
const string Pessoa::TIPOS[ PESSOAS ] = {"aluno", "professor"};

// inicio - construtores
Pessoa::Pessoa( ): IDADEMAXIMA( 120 ), IDADEMINIMA( 3 ), SIZENOME( 70 ){
	this -> idadePessoa = 0;
	this -> nomePessoa = "default";
	this -> tipoPessoa = "default";
	this -> setDataNascimento( dia, mes, ano );
};

Pessoa::Pessoa( int AidadePessoa, string AnomePessoa, string AtipoPessoa, int Adia, int Ames, int Aano): IDADEMAXIMA( 120 ), IDADEMINIMA( 3 ), SIZENOME( 70 ){
	this -> setIdadePessoa( AidadePessoa );
	this -> setNomePessoa( AnomePessoa );
	this -> setTipoPessoa( AtipoPessoa );
	this -> setDataNascimento( Adia, Ames, Aano );
};

Pessoa::Pessoa( const Pessoa& other): IDADEMAXIMA( other.IDADEMAXIMA ), IDADEMINIMA( other.IDADEMINIMA ), SIZENOME( other.SIZENOME ){
	this -> idadePessoa = other.idadePessoa;
	this -> nomePessoa = other.nomePessoa;
	this -> tipoPessoa = other.tipoPessoa;
	this -> dia = other.dia;
	this -> mes = other.mes;
	this -> ano = other.ano;
};

Pessoa::~Pessoa( ){ };
// fim - construtores

// inicio - set
void Pessoa::setIdadePessoa( int AidadePessoa ){
	if ( AidadePessoa >= IDADEMINIMA && AidadePessoa <= IDADEMAXIMA ){
		this -> idadePessoa = AidadePessoa;
		return;
	}
	this -> idadePessoa = IDADEMINIMA;
};

void Pessoa::setNomePessoa( string AnomePessoa ){
	if ( AnomePessoa.length( ) <= SIZENOME ){
		this -> nomePessoa = AnomePessoa;
		return;
	}
	this -> nomePessoa = "default";
};

void Pessoa::setTipoPessoa( string AtipoPessoa ){
	for ( int i = 0; i < PESSOAS; i++ ){// pessoas cadastradas
		if ( AtipoPessoa == TIPOS[ i ] ){
			this -> tipoPessoa = AtipoPessoa;
			return;
		}	
		this -> tipoPessoa = TIPOS[ i ];
	}
};
// fim - set

// inicio - Data
void Pessoa::setDataNascimento( int d, int m, int a){
	if ( m > 0 && m <= 12 ){
		this -> mes = m;
	}	
	if ( a < 0 ){
		this -> ano = 1900;
	}else{
		this -> ano = a;
	}
	this -> dia = verificaDia( d );
};
int Pessoa::verificaDia( int diaTeste) {
	  static const int diasPorMes[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	  if ( diaTeste > 0 && diaTeste <= diasPorMes[ mes ] ){
				return diaTeste;
			}
		
	  if ( mes == 2 && diaTeste == 29 && ( ano % 400 == 0 || ( ano % 4 == 0 && ano % 100 != 0 ) ) ){
			return diaTeste;
		}
	  cout << "Dia invalido (" << diaTeste << ") configurado para 1.\n";
	  return 1; 
};
// fim - Data

//inicio - sobrecarga de operadores
ostream &operator<<( ostream &COUT, const Pessoa &pessoa ){
    COUT << "\n----------- INF. GERAIS -----------\n";
    COUT << "Nome da Pessoa: " << pessoa.nomePessoa << "\n";
    COUT << "Idade Pessoa: " << pessoa.idadePessoa << "\n";
    COUT << "Tipo de pessoa: " << pessoa.tipoPessoa << "\n";
	COUT << "Data de nascimento: " << pessoa.dia << "/" << pessoa.mes << "/" << pessoa.ano << "\n"; 
    return COUT;
};
// fim -sobrecarga de operadores 

// inicio - exibir
void Pessoa::printCaracteristicaPessoa( ) const {
	cout << "\n-------- CARAC. PESSOA --------";
	cout << "\nIdade da Pessoa: " << this -> idadePessoa << "\n";
	cout << "Data de Nascimento: " << this -> dia << "/" << this -> mes << "/" << this -> ano << "\n";
	cout << "Nome da Pessoa: " << this -> nomePessoa << "\n";
	cout << "Tipo da Pessoa: " << this -> tipoPessoa << "\n";
	cout << "--------------------------------\n";
};

void Pessoa::printTiposCadastradosPessoa( ){
	cout << "\n-------- PESSOAS CADASTRADAS -------\n";
	for (int i = 0; i < PESSOAS; i++){
		cout << "Pessoa Cadastrada: " << TIPOS[i] << " (" << &TIPOS[i] << ")\n";
	}
	cout << "------------------------------------\n";
};
// fim - exibir