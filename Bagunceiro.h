
#pragma once
#include "Materiais.h"
#include "Aluno.h"
#include "Habilidades.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

class Bagunceiro: public Aluno, public Habilidades{
	friend ostream &operator<<( ostream &, const Bagunceiro & ); // sobrecarga do operador <<
	public:
		// construtores
		Bagunceiro( );
		Bagunceiro( int, string, int, int, int, double, int );
		~Bagunceiro( );
		Bagunceiro( const Bagunceiro & );

		// exibir 
		void printCaracteristicasBagunceiro( Bagunceiro ) const;
		void materialSemestreBagunceiro( );
		void printListaMateriais( );
		
		// set & get
		static int getNumBagunceiros( ){ return  numBagunceiros; }

		// sobrecarga de operadores 
		Bagunceiro& operator=( const string );
		Bagunceiro& operator!( );
		bool operator==( Pessoa );
		bool operator!=( Pessoa );

	private:
		// atributos 
		static const int BAGUNCEIROIDADE;
		static const int DIANASCIMENTO;
		static const int MESNASCIMENTO;
		static const int ANONASCIMENTO;

		static const string BAGUNCEIRONOME;

		static const float NOTABAGUNCEIRO;
		static const int MATRICULABAGUNCEIRO;

		// atributos padrão
		static const float ESCUDOBAGUNCEIRO;
		static const float DANONOTABAGUNCEIRO;
		static const float VIDASEMESTREBAGUNCEIRO;
		
		// struct
		const static int NUMMAXMATERIAIS = 8;
   		Materiais materiaisBagunceiro;

		// static 
		static int numBagunceiros;
};