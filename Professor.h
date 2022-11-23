#pragma once
#include <string>
#include "Pessoa.h"
#include "Aluno.h"

using std::string;

class Professor: public Pessoa{
    public:
        // construtores
        Professor( );
        Professor( int, string, int, int, int );
        Professor( const Professor & );
        ~Professor( );

        // exibir 
        void exibirConceito( Aluno );

    private:
        // static
        const static string NOMECLASSPROFESSOR; 
};