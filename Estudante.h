#ifndef ESTUDANTE_H
#define ESTUDANTE_H
using std::string;

class Estudante{
	public:
		//construtores
		Estudante( );
		Estudante( string, int, float, int= 000 );
		~Estudante( );
		Estudante( const Estudante& );

		//get|set
		int getIdade( ); 
		int getNumeroChamada( );
		void setNumeroChamada( int );
		float getNotaFinal( );

		//static
		static int getNumEstudantesMaiores( ) { return numEstudantesMaiores;};
		static void printNotaAzul( );

		//const get | set
		int getNotaMaxima( ) const;
		int getIdadeMaxima( ) const;
		int getNumeroChamada( ) const;

		//const string
		void caracEstudante( const string & );

		//exibir
		void print( ) const;
		
	private:
		//atributos
		int idade, numeroChamada;	
		float notaFinal;

		string nome, mensagem;//string		
		bool comSono = false;//boll
		static int numEstudantesMaiores;//static
		static const int numNotas = 4;//const static
		static const string notaAzul[ numNotas ];//const string

		const float notaMaxima;
		const int idadeMaxima;

		void setIdade( int );
		void setNotaFinal( float );
};
/*
caracteristicas a serem implementadas 
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