#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using std::string;
using std::cout;

class Aluno{
	public:
		//construtores
		Aluno( );
		Aluno( string , string, int = 18, float = 0.0);//parametro default
		Aluno( const Aluno & );
		~Aluno( );

		//set e get
		void setNomeAluno( string );
		string getNomeAluno( );

		void setTipoAluno( string );
		string getTipoAluno( );

		void setIdadeAluno( int );
		int getIdadeAluno( );

		bool setEscudoNotaAtual( int );
		int getEscudoNotaAtual( );

		void setVidaAlunoSemestre( float );
		float getVidaAlunoSemestre( );

		void setNotaFinalAluno( float );
		float getNotaFinalAluno( );

		void receberDanoNota( int );
		void curarDanoNota( int );

	//exibir
		void printCaracteristicasAluno( ) const;//const

	//métodos static
		static int getNumTotalgeralAlunos ( ) { return totalGeralAlunos;}
		void printTiposCadastrados( );

	

	private:
		//atributos
		int idadeAluno, escudoNotaAtual;

		float vidaAlunoSemestre, notaFinalAluno;

		string nomeAluno, tipoAluno;

		bool fadigaAlunoNota = false;	

		const int IDADEALUNOMAXIMO;
		const int ESCUDONOTAMAXIMO;
		const int VIDAALUNOSEMESTREMAXIMO;
		const float NOTAFINALMAXIMO;

		//atributos static
		
		static int totalGeralAlunos;
		static const int NUMTIPOSCADASTRADOS = 7;
		static const string TIPOS[ NUMTIPOSCADASTRADOS ];

};

#endif