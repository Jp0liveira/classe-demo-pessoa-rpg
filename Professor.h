#pragma once
#include <string>
#include "Pessoa.h"
#include "Aluno.h"

// classe abstrata

using std::string;

class Professor: public Pessoa{
    public:
        // construtores
        Professor( );
        Professor( int, string, int, int, int );
        Professor( const Professor & );
       
        //polimorfismo
        virtual ~Professor( );
        virtual void relatorioDesempenho( Aluno );
        virtual float getBonificacao( ) = 0;
        
    private:
        // static
        const static string NOMECLASSPROFESSOR; 

         //polimorfismo
        virtual void metodoAvaliativo( ) = 0;  
};