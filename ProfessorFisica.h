#pragma once
#include "ProfessorEnsinoMedio.h"
#include "PrepararAula.h"

class ProfessorFisica: public ProfessorEnsinoMedio{
    public: 
        ProfessorFisica( );// construtor padrao
        ProfessorFisica( int, string, int, int, int, float = 0.0 );// construtor com iformaçoes básicas
        ProfessorFisica( int, int, int, int );// preparar metodologia 
        ProfessorFisica( const ProfessorFisica & );
        ~ProfessorFisica( );

        //polimorfismo
        void metodoAvaliativo( );// diferente para um professor de fisica do ensino medio
        void relatorioDesempenho( Aluno );//relatorio diferente para um professor de fisica do ensino medio
        void prepararAula( );// dicas de aulas

        void setSalario( float );
        
        // para um professor substituto, por exemplo :)
        virtual void temaParaAula( );
        virtual void materiaisApoio( );

        float getBonificacao( );// bonus de salario para um professor do ensino medio de fisica + 15%

        // novas metodos da classe
        void setNumProvaSubstitutiva( int );
        void setNumTrabalhosGrupo( int );
        int getNumProvaSubstitutiva( ){ return this->numProvaSubstitutiva; }
        int getNumTrabalhosGrupo( ){ return this->numTrabalhosGrupo; }

    private:
        PrepararAula metodologia;

        float salario;
        int numProvaSubstitutiva, numTrabalhosGrupo;

        const static string PROFESSORFISICA;
        const static int NUMMAXIMOTEMAS = 10;
        const static int NUMMAXIMOMATERIAIS = 20;



};
