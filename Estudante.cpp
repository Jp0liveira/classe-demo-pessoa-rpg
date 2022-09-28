#include <iostream>
#include <string>
#include "Estudante.h"
using std::cout;
using std::string;

//instanciação de variaveis statics
int Estudante::numEstudantesMaiores = 0;
<<<<<<< Updated upstream
const string Estudante::NOTAZUL[ NUMERONOTAS ] = {"E","B","R","I"};
=======
const string Estudante::notaAzul[ numNotas ] = {"E","B","R","I"};
const string Estudante::estadoEstudante[4] =  {"Sono", "Cansado", "Ansioso", "no trabalho"};
>>>>>>> Stashed changes

// inicio-construtores
Estudante::Estudante( )
:IDADEMAXIMA( 120 ), NOTAMAXIMA( 10.0 )
{ //padrao
	//cout << "Inicializando Estudante.\n";
	nome = "joao";
	idade = 0;
	notaFinal = 0;
	numeroChamada = 0000;
};
Estudante::~Estudante( ){ //destrutor
	numEstudantesMaiores--;
};
Estudante::Estudante( string Anome, int Aidade, float AnotaFinal, int AnumeroChamada )
:IDADEMAXIMA( 120 ), NOTAMAXIMA( 10.0 ){ //argumento
	//cout << "contrutor com argumentos\n";
	nome = Anome;
	setIdade( Aidade );
	setNotaFinal( AnotaFinal );
	numeroChamada = AnumeroChamada;
};
<<<<<<< Updated upstream
Estudante::Estudante( const Estudante &other ):IDADEMAXIMA( other.IDADEMAXIMA), NOTAMAXIMA( other.NOTAMAXIMA ){ //copia
	nome = other.nome;
=======
Estudante::Estudante( const Estudante &other ):idadeMaxima( other.idadeMaxima ), notaMaxima( other.notaMaxima ){ //copia
	this-> nome = other.nome;
>>>>>>> Stashed changes
	// idade = other.idade;
	this-> setIdade(other.idade);
	// notaFinal = other.notaFinal;
	this-> setNotaFinal(other.notaFinal);
	this-> numeroChamada = other.numeroChamada;
};
// fim-construtores

// inicio-set&get
int Estudante::getIdade( ){
	return idade;
};
void Estudante::setIdade( int Aidade ){
<<<<<<< Updated upstream
	if (Aidade  >= 0 && Aidade <= IDADEMAXIMA){
		idade = Aidade;
=======
	if (Aidade  >= 0 && Aidade <= idadeMaxima){
		this-> idade = Aidade;
>>>>>>> Stashed changes
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
	this-> numeroChamada = AnumeroChamada;
};
float Estudante::getNotaFinal( ){
	return notaFinal;
};
void Estudante::setNotaFinal( float AnotaFinal){
<<<<<<< Updated upstream
	if (AnotaFinal >= 0.0 && AnotaFinal <= NOTAMAXIMA){
		notaFinal = AnotaFinal;
=======
	if (AnotaFinal >= 0.0 && AnotaFinal <= notaMaxima){
		this-> notaFinal = AnotaFinal;
>>>>>>> Stashed changes
		//bool
		if (AnotaFinal <= 5){
			this-> comSono = true;
			return;
		}
	}else{
		this-> notaFinal = 0.0;
	}
};

// fim-set&get

// inicio-metodos-constantes
//esses métodos/atributos so podem ser configurados na inicialização
int Estudante::getNotaMaxima( ) const{
	return NOTAMAXIMA;
};
int Estudante::getIdadeMaxima( ) const{
	return IDADEMAXIMA;
};
int Estudante::getNumeroChamada( ) const{
	return numeroChamada;
};
// fim-metodos-constantes

//inicio_novos metodos
void Estudante::printNotaAzul( ){
    for( int i = 0; i < NUMERONOTAS; i++ ){
		// [E, B, R, I]
		if (NOTAZUL[ i ] == "I"){
			 cout <<"Nota Vermelha: ";
		}else{
			 cout <<"Nota Azul: ";
		}
		cout << NOTAZUL[ i ] << ' ' << '(' <<&NOTAZUL[ i ] << ')' << '\n';
	}
}
void Estudante::caracEstudante( const string &Anome ){
    //caracteristicas atribuidas ao aluno
	cout << "\n\tCaracteristicas do Estudante\n";
    if( comSono ){
		cout << Anome << " pode estar stressado!\n";
		if (notaFinal <= 2.0){
			cout << Anome << " deve estar desconfortavel!\n";
		}
		if (notaFinal == 0.0){
			cout << Anome << " esta em panico!\n";
		}
    }else{
		cout << Anome << " deve ter iniciado o semestre, mo paz!\n";
	}
}

void Estudante::caracNotaFinal( ){
	while ( comSono ){
		notaFinal++;
		cout << "\nEstudante precisa estudar!\n";
		if (notaFinal == 5){
			break;
		}
	}
}; 

void Estudante::printEstadoEstudante( ){
	cout << "\n\tO estudante pode estar: \n";
   for( int i = 0; i < sizeof(estadoEstudante) / sizeof(estadoEstudante[0]); i++ ){
		cout << estadoEstudante[ i ] << '\n';
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