#include <iostream>
#include <string>
#include "Estudante.h"
using std::cout;
using std::string;

// inicio-construtores
Estudante::Estudante( )
:idadeMaxima( 120 ), notaMaxima( 10.0 )
{ //padrao
	//cout << "Inicializando Estudante.\n";
	nome = "joao";
	idade = 0;
	notaFinal = 0;
	numeroChamada = 0000;
};
Estudante::~Estudante( ){ //destrutor
};
Estudante::Estudante( string Anome, int Aidade, float AnotaFinal, int AnumeroChamada )
:idadeMaxima(120), notaMaxima(10.0){ //argumento
	//cout << "contrutor com argumentos\n";
	nome = Anome;
	setIdade( Aidade );
	setNotaFinal( AnotaFinal );
	numeroChamada = AnumeroChamada;
};
Estudante::Estudante( const Estudante &other ):idadeMaxima( other.idadeMaxima ), notaMaxima( other.notaMaxima ){ //copia
	nome = other.nome;
	idade = other.idade;
	notaFinal = other.notaFinal;
	numeroChamada = other.numeroChamada;
};
// fim-construtores

// inicio-set&get
int Estudante::getIdade( ){
	return idade;
};
void Estudante::setIdade( int Aidade ){
	if (Aidade  >= 0 && Aidade <= idadeMaxima){
		idade = Aidade;
	}else{
		idade = 18;
	}
};
int Estudante::getNumeroChamada( ){
	return numeroChamada;
};
void Estudante::setNumeroChamada( int AnumeroChamada ){
	numeroChamada = AnumeroChamada;
};
float Estudante::getNotaFinal( ){
	return notaFinal;
};
void Estudante::setNotaFinal( float AnotaFinal){
	if (AnotaFinal >= 0.0 && AnotaFinal <= notaMaxima){
		notaFinal = AnotaFinal;
	}else{
		notaFinal = 0.0;
	}
};
// fim-set&get

// inicio-metodos-constantes
//esses métodos/atributos so podem ser configurados na inicialização
int Estudante::getNotaMaxima( ) const{
	return notaMaxima;
};
int Estudante::getIdadeMaxima( ) const{
	return idadeMaxima;
};
int Estudante::getNumeroChamada( ) const{
	return numeroChamada;
};
// fim-metodos-constantes

// inicio-exibir
void Estudante::print( ) const{
	cout << "\nNome: " << nome;
	cout << "\nIdade: " << idade;
	cout << "\nNota Final: " << notaFinal;
	cout << "\nNumero Chamada: " << numeroChamada;
};
// fim-exibir