#include <iostream>
#include "Pessoa.h"
using std::cout;

//static's
const string Pessoa::TIPOS[ PESSOAS ] = {"aluno"};

// inicio - construtores
Pessoa::Pessoa( ): IDADEMAXIMA( 120 ), IDADEMINIMA( 3 ), SIZENOME( 70 ){
	idadePessoa = 0;
	nomePessoa = "default";
	tipoPessoa = "default";
	setDataNascimento( dia, mes, ano );
};

Pessoa::Pessoa( int AidadePessoa, string AnomePessoa, string AtipoPessoa, int Adia, int Ames, int Aano): IDADEMAXIMA( 120 ), IDADEMINIMA( 3 ), SIZENOME( 70 ){
	setIdadePessoa( AidadePessoa );
	setNomePessoa( AnomePessoa );
	setTipoPessoa( AtipoPessoa );
	setDataNascimento( Adia, Ames, Aano );
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

//inicio - set
void Pessoa::setIdadePessoa( int AidadePessoa ){
	if (AidadePessoa >= IDADEMINIMA && AidadePessoa <= IDADEMAXIMA){
		idadePessoa = AidadePessoa;
		return;
	}
	idadePessoa = IDADEMINIMA;
};

void Pessoa::setNomePessoa( string AnomePessoa ){
	if ( AnomePessoa.length( ) <= SIZENOME ){
		nomePessoa = AnomePessoa;
		return;
	}
	nomePessoa = "default";
};

void Pessoa::setTipoPessoa( string AtipoPessoa ){
	for ( int i = 0; i < PESSOAS; i++ ){// pessoas cadastradas
		if ( AtipoPessoa == TIPOS[ i ] ){
			tipoPessoa = AtipoPessoa;
			return;
		}	
		tipoPessoa = TIPOS[ i ];
	}
};
//fim - set

// inicio - Data
void Pessoa::setDataNascimento( int d, int m, int a){
	if ( m > 0 && m <= 12 ){
		mes = m;
	}	
	if ( a < 0 ){
		ano = 1900;
	}else{
		ano = a;
	}
	dia = verificaDia( d );
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
ostream &operator<<(ostream &COUT, const Pessoa &pessoa){
    COUT << "\nInformacoes sobre este Treinador:\n";
    COUT << "Nome da Pessoa: " << pessoa.nomePessoa << "\n";
    COUT << "Idade Pessoa: " << pessoa.idadePessoa << "\n";
    COUT << "Tipo de pessoa: " << pessoa.tipoPessoa;
    return COUT;
};

// Pessoa::operator=( int NovaidadePessoa) {
// 	int verificar = 2022 - ano;  
//     if (verificar == NovaidadePessoa ){
//         this -> idadePessoa = idadePessoa;
// 				this -> ano = ano;
//     } else {
//       cout << "\nidade difente do ano de nascimento, nova idade: " << "\n";
//     }
// };
// não terminei direito 
// Pessoa::operator!( ){ 
// }


// Pessoa::operator==(const Pessoa &outro) {
  
// }

// bool Pessoa::operator!=(const Pessoa &outro) {
// }

// fim -sobrecarga de operadores 

// inicio - exibir
void Pessoa::printCaracteristicaPessoa( ) const {
	cout << "\n-------- CARAC. PESSOA --------";
	cout << "\nIdade da Pessoa: " << idadePessoa << "\n";
	cout << "Data de Nascimento: " << dia << "/" << mes << "/" << ano << "\n";
	cout << "Nome da Pessoa: " << nomePessoa << "\n";
	cout << "Tipo da Pessoa: " << tipoPessoa << "\n";
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