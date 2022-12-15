#pragma once
#include "Professor.h"

#include <vector>

using std::vector;

class ProfessorEnsinoSuperior: public Professor{

    public:
        ProfessorEnsinoSuperior( );
        ProfessorEnsinoSuperior( string, string, string, int );
        ProfessorEnsinoSuperior( int, string, int, int, int );
        ProfessorEnsinoSuperior( const ProfessorEnsinoSuperior& );

        virtual ~ProfessorEnsinoSuperior( );

        //polimorfismo 
            // entrar em contato com a universidade para mais informacoes
        virtual void planoDeAulas( const string& );
        virtual void curriculoProfessor( const string& );
        virtual void participacaoComites( const string& );

        virtual void printPlanejamento( );
        virtual void metodoAvaliativo( );

        virtual void setSalario( float = 0.0 );

        
        virtual float getBonificacao( );// bonus de salario para um professor do ensino superior + 25%

    private:
        string especializacao, areaAtuacao, instituicao;
        float salario;

        vector < string *> planoAssuntos;
        vector < string *> curriculoLattes;
        vector < string *> comites;

        const int SALARIOMINIMO;
        const int NUMMAXIMOINFORMACOES;

};



