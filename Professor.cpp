#include <iostream>
#include "Professor.h"

using std::cout;

// static
const string Professor::NOMECLASSPROFESSOR = "professor";

// inicio - construtores
Professor::Professor( ){ };

Professor::Professor( int idadeProfessor, string nomeProfessor, int diaNascimentoProfessor, int mesNascimenoProfessor, int anoNascimentoProfessor ): Pessoa( idadeProfessor, nomeProfessor, NOMECLASSPROFESSOR, diaNascimentoProfessor, mesNascimenoProfessor, anoNascimentoProfessor ){ };

Professor::Professor( const Professor& other): Pessoa( static_cast< Pessoa >( other ) ){ };

Professor::~Professor( ){ };
// fim - construtores

// inicio - exibir
void Professor::relatorioDesempenho( Aluno tipoAluno ){
    cout << "\n-------- CONCEITO. ALUNO --------";
    cout << "\nConceito atribuido ao aluno: ";
    float notaFinalProfessor = tipoAluno.getNotaFinalAluno( );
    if ( notaFinalProfessor > 8.0 ){
      cout << tipoAluno.NOTAS[ 0 ];
    }else if( notaFinalProfessor >= 7 ){
      cout << tipoAluno.NOTAS[ 1 ];
    }else if( notaFinalProfessor >= 5){
      cout << tipoAluno.NOTAS[ 2 ];
    }else{
      cout << tipoAluno.NOTAS[ 3 ];
    }
    cout << "\n--------------------------------\n";
};
// fim - exibir

