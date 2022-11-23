#pragma once
#include "Materiais.h"
#include "Aluno.h"
#include "Habilidades.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

class Estudioso: public Aluno, public Habilidades{
	friend ostream &operator<<( ostream &, const Estudioso & ); // sobrecarga do operador <<
	public:
		// construtores
		Estudioso( );
		Estudioso( int, string, int, int, int, double, int );
		~Estudioso( );
		Estudioso( const Estudioso & );

		// exibir 
		void printCaracteristicaEstudioso( Estudioso ) const;
		void materialSemestreEstudioso( );
		void printListaMateriais( );
		
		// set & get
		static int getNumEstudiosos( ){ return  numEstudiosos; }

		// sobrecarga de operadores 
		Estudioso& operator=( const string );
		Estudioso& operator!( );
		bool operator==( Pessoa );
		bool operator!=( Pessoa );

	private:
		// atributos 
		static const int ESTUDIOSOIDADE;
		static const int DIANASCIMENTO;
		static const int MESNASCIMENTO;
		static const int ANONASCIMENTO;

		static const string ESTUDIOSONOME;

		static const float NOTAESTUDIOSO;
		static const int MATRICULAESTUDIOSO;

		// atributos padrão
		static const float ESCUDOESTUDIOSO;
		static const float DANONOTAESTUDIOSO;
		static const float VIDASEMESTREESTUDIOSO;
		
		// struct
		const static int NUMMAXMATERIAIS = 10;
   		Materiais materiaisEstudioso;

		static int numEstudiosos;
};