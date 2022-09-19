#ifndef ESTUDANTE_H
#define ESTUDANTE_H
using std::string;

class Estudante{
	public:
		Estudante( ); //construtor padrao
		Estudante( string, int, float, int= 000 ); //construtor com argumentos
		~Estudante( ); //destrutor
		Estudante( const Estudante& ); //construtor de copia
		//get para idade (retorna) | set para idade (modifica)
		int getIdade( ); 
		int getNumeroChamada( );
		void setNumeroChamada( int );
		float getNotaFinal( );
		int getNotaMaxima( ) const; //1-método constante
		int getIdadeMaxima( ) const; //2-método constante
		int getNumeroChamada( ) const; //3-método constante
		//exibir
		void print( ) const;
	private:
		//atributos
		string nome;
		int idade, numeroChamada;	
		float notaFinal;
		const float notaMaxima;
		const int idadeMaxima;
		//set's
		void setIdade( int );
		void setNotaFinal( float );
};
/*
caracteristicas a serem implementadas 
	estressado;(0-100)
	comSono;(verdadeiro ou falso)
		panic;
		ansioso;
		Estágio;
		trabalha;
		iludido;
	semestre;
		zen
		sem sono
		semana antes de prova
	notaFinal;(0-10)
*/

#endif