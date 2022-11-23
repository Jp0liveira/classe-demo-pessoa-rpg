#pragma once
#include "Pessoa.h"

class Aluno: public Pessoa{
	friend ostream &operator<<( ostream &, const Aluno & ); // sobrecarga do operador <<
	public:
		// construtores
		Aluno( );
		Aluno( int , string , int , int , int , float , int );
		Aluno( const Aluno & );
		~Aluno( );

		// set & get
		void setNotaFinalAluno( float );
		void setMatriculaAluno( int );

		float getNotaFinalAluno( ){ return notaFinalAluno; }
		int getMatriculaAluno( ){ return matriculaAluno; }

		// exibir  
		void printCaracteristicaAluno( ) const;
		void printNotasCadastrados( );

		// static
		static const int CONCEITOS = 4;
		static const string NOTAS[ CONCEITOS ];

	private:
		// atributos
		float notaFinalAluno;
		int matriculaAluno;

		// const
		const float NOTAMAXALUNO;
		const float NOTAMINALUNO;

		// static
		static const string NOMECLASSALUNO;	

};
