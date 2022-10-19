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
		string getNomePessoa( ) { return nomePessoa; }
		string getTipoPessoa( ) { return tipoPessoa; }


		//data
		void setDataNascimento( int, int, int );
		int verificaDia( int );
		
		// sobrecarga de operadores
		// Ps: não entendi muito bem como implementar na minha classe, ainda estou estudando isso :)
		/* 
 		operator=(int);
		operator!( );
		bool operator==(const Pessoa &); 
  	bool operator!=(const Pessoa &); 
		*/

		// exibir  
		void printCaracteristicaPessoa( ) const;
		void printTiposCadastradosPessoa( );

	private:
		// atributos
		int idadePessoa;
		string nomePessoa, tipoPessoa;
		// dataNascimento
		int dia = 28, mes = 06, ano = 2001;
		// const
		const int IDADEMAXIMA;
		const int IDADEMINIMA;
		const int SIZENOME;

		// static
		static const int PESSOAS = 1;
		static const string TIPOS[ PESSOAS ];

};