#pragma once
#include "Pessoa.h"
#include "Aluno.h"
#include "Habilidades.h"
#include "Materiais.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

class Estudioso: public Pessoa, public Aluno, public Habilidades, public Materiais{
	public:
		Estudioso( );
		~Estudioso( );
		void printCaracteristicaEstudioso( Estudioso ) const;
		void materialSemestreEstudioso( );

	private:
		static const int ESTUDIOSOIDADE;
		static const int DIANASCIMENTO;
		static const int MESNASCIMENTO;
		static const int ANONASCIMENTO;

		static const string ESTUDIOSONOME;
		static const string TIPOESTUDIOSO;

		static const float NOTAESTUDIOSO;
		static const int 	MATRICULAESTUDIOSO;

		static const float ESCUDOESTUDIOSO;
		static const float DANONOTAESTUDIOSO;
		static const float VIDASEMESTREESTUDIOSO;

   	Materiais numMateriaisEstudioso;// struct
	
};