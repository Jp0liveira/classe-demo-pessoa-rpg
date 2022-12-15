#pragma once
#include "Professor.h"

class ProfessorEnsinoMedio: public Professor{
    public:
        ProfessorEnsinoMedio( );
        ProfessorEnsinoMedio(  int, string, int, int, int, float = 0.0, string = "professor" );
        
        // preparar aula
        //tema,  materiaisapoio, aulasInterativas, numProvas, numTrabalhos 
        ProfessorEnsinoMedio( string, string, bool, int, int );

        ProfessorEnsinoMedio( const ProfessorEnsinoMedio& );
        virtual ~ProfessorEnsinoMedio( );
        
        //polimorfismo
        virtual void metodoAvaliativo( );
        virtual void relatorioDesempenho( Aluno );
        virtual void prepararAula( );

        virtual void setSalario( float = 0.0 );

        //set
        void setTipoProfessor( string );
        void setNumProvas( int );
        void setNumTrabalhos( int );

        //get
        string getTema( ){ return this->tema; }
        string getMateriaisApoio( ){ return this->materiaisApoio; }
        string getTipoProfessor( ){ return this->tipoProfessor; }
        bool getAulasInterativas( ){ return this->aulasInterativas; }
        int getNumProvas( ){ return this->numProvas; }
        int getNumTrabalhos( ){ return this->numTrabalhos; }
        float getSalario( ){ return this->salario; }
        
        virtual float getBonificacao( );// bonus de salario para um professor do ensino medio + 10%
    
    private:
        string tema, materiaisApoio, tipoProfessor;
        bool aulasInterativas;
        int numProvas, numTrabalhos;
        float salario;

        const static int PROFESSORES = 2;// professor de fisica e professor de matematica
        const static string PROFESSOR[ PROFESSORES ];

        const int NUMMAXIMOPROVAS;
        const int NUMMAXIMOTRABALHOS;
};



