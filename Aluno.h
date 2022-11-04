#pragma once
#include "Pessoa.h"
#include "Habilidades.h"

class Aluno: public Pessoa{
	public:
		Aluno( );
		Aluno( int , string , int , int , int , float , int );
		Aluno( const Aluno & );
		~Aluno( );

		void setNotaFinalAluno( float );
		void setMatriculaAluno( int );

		float getNotaFinalAluno( ){ return notaFinalAluno; }
		int getMatriculaAluno( ){ return matriculaAluno; }

		void printCaracteristicaAluno( ) const;
		void printNotasCadastrados( );

	private:
		float notaFinalAluno;
		int matriculaAluno;

		const float NOTAMAXALUNO;
		const float NOTAMINALUNO;

		static const int CONCEITOS = 4;
		static const string NOTAS[ CONCEITOS ];

		static const string NOMECLASS;	

};
