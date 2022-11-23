#pragma once
#include <string>
using std::string;
using std::ostream;

class Pessoa{
 	friend ostream &operator<<( ostream &, const Pessoa & ); // sobrecarga do operador <<
	public:
		// construtores
		Pessoa( );
		Pessoa( int, string, string, int, int, int);
		Pessoa( const Pessoa & );
		~Pessoa( );

		// set & get
		void setIdadePessoa( int );
		void setNomePessoa( string );
		void setTipoPessoa( string );

		int getIdadePessoa( ) { return idadePessoa; }
		int getDiaNascimento( ) { return dia; }
		int getMesNascimento( ) { return mes; }	
		int getAnoNascimento( ) { return ano; }
		string getNomePessoa( ){ return nomePessoa; }
		string getTipoPessoa( ) { return tipoPessoa; }

		//data
		void setDataNascimento( int, int, int );
		int verificaDia( int );

		// exibir  
		void printCaracteristicaPessoa( ) const;
		void printTiposCadastradosPessoa( );
		
	private:
		// atributos
		int idadePessoa;
		string nomePessoa, tipoPessoa;

		// dataNascimento
		int dia = 01, mes = 01, ano = 2000;
		// const
		const int IDADEMAXIMA;
		const int IDADEMINIMA;
		const int SIZENOME;

		// static
		static const int PESSOAS = 2;
		static const string TIPOS[ PESSOAS ];

};