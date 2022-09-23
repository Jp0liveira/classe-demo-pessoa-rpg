#ifndef ESTUDANTE_H
#define ESTUDANTE_H
using std::string;

class Estudante{
	public:
		// construtores
		Estudante( );
		Estudante( string, int, float, int= 000 );
		~Estudante( );
		Estudante( const Estudante& );

		// get|set
		int getIdade( ); 
		int getNumeroChamada( );
		void setNumeroChamada( int );
		float getNotaFinal( );

		// static
		static int getNumEstudantesMaiores( ) { return numEstudantesMaiores;};
		static void printNotaAzul( );

		// const get | set
		int getNotaMaxima( ) const;
		int getIdadeMaxima( ) const;
		int getNumeroChamada( ) const;
		string getNomeEstudante() const { return nome; };

		// const string
		void caracEstudante( const string & );

		// exibir
		void print( ) const;
		
	private:
		// atributos
		int idade;	
		int numeroChamada;	
		float notaFinal;

		string nome;
		string mensagem; // string	
		bool comSono; // boll
		static int numEstudantesMaiores; // static
		static const int NUMERONOTAS = 4; // const static numNotas 
		static const string NOTAZUL[ NUMERONOTAS ]; // const string  notaAzul

		const float NOTAMAXIMA; // 	notaMaxima
		const int IDADEMAXIMA; // idadeMaxima 

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