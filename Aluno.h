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
				//verificar
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

				//funcoes
			void receberDanoNota( int );
			void curarDanoNota( int );
			void bonusNotaAluno( float );

		//exibir
			void printCaracteristicasAluno( ) const;//const

		//métodos static
			static int getNumTotalgeralAlunos ( ) { return totalGeralAlunos;}
			void printTiposCadastrados( );

		//alocacao
		void cadastrarHistALunosIdade( int );
		void alocarHistALunosIdade( int );
		void printHistoricoIdadeAlunos ( ) const;

		

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

			//alocacao de memoria
				//historico de idades dos alunos
			int *histAlunosIdadePtr;
			int tamAlocadoHistoricoAlunosIdade, qtdHistoricoAlunosIdade;
			void printHistAlunosIdade( ) const;
			void alocaHistAlunosIdade( int );	
			
};

#endif