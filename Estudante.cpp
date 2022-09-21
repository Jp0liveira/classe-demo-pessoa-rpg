#include <iostream>
#include <string>
#include "Estudante.h"
using std::cout;
using std::string;

//instanciação de variaveis statics
int Estudante::numEstudantesMaiores = 0;
const string Estudante::notaAzul[ numNotas ] = {"E","B","R","I"};

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
	// idade = other.idade;
	setIdade(other.idade);
	// notaFinal = other.notaFinal;
	setNotaFinal(other.notaFinal);
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
		if (Aidade >= 18){
			//estudantes maiores de idade (criar metodo para cadastrar alunos)
			numEstudantesMaiores++;
		}
	}else{
		//idade minima
		idade = 3;
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
		//bool
		if (AnotaFinal <= 5){
			comSono = true;
		}
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

//inicio_novos metodos
void Estudante::printNotaAzul( ){
    for( int i = 0; i < numNotas; i++ ){
		// [E, B, R, I]
		if (notaAzul[ i ] == "I"){
			 cout <<"Nota Vermelha: ";
		}else{
			 cout <<"Nota Azul: ";
		}
		cout << notaAzul[ i ] << ' ' << '(' <<&notaAzul[ i ] << ')' << '\n';
	}
}
void Estudante::caracEstudante( const string &Anome ){
    //caracteristicas atribuidas ao aluno
	cout << "\n\tCaracteristicas do Aluno\n";
    if( comSono ){
		cout << Anome << " pode estar stressado!\n";
		if (notaFinal <= 2){
			cout << Anome << " deve estar desconfortavel!\n";
		}
		if (notaFinal == 0.0){
			cout << Anome << " esta em panico!\n";
		}
    }else{
		cout << Anome << " deve ter iniciado o semestre, mo paz!\n";
	}
}
//fim_novos metodos

// inicio-exibir
void Estudante::print( ) const{
	cout << "\nNome: " << nome;
	cout << "\nIdade: " << idade;
	cout << "\nNota Final: " << notaFinal;
	cout << "\nNumero Chamada: " << numeroChamada << "\n";
};
// fim-exibir