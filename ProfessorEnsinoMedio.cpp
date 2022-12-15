#include <iostream>
#include "ProfessorEnsinoMedio.h"
using std::cout;

// static's
const string ProfessorEnsinoMedio::PROFESSOR[ PROFESSORES ] = { "professor de fisica", "professor de matematica" };

// inicio - construtores
ProfessorEnsinoMedio::ProfessorEnsinoMedio( ): NUMMAXIMOPROVAS( 4 ), NUMMAXIMOTRABALHOS( 5 ){
    this->tema = "default";
    this->materiaisApoio = "default";
    this->aulasInterativas = true;
    this->salario = 100;
    this->setNumProvas( 1 );
    this->setNumTrabalhos( 1 );
 };

ProfessorEnsinoMedio::ProfessorEnsinoMedio( int idadeProfessor, string nomeProfessor, int diaNascimentoProfessor, int mesNascimenoProfessor, int anoNascimentoProfessor, float salario, string  tipoProfessor ): Professor( idadeProfessor,  nomeProfessor, diaNascimentoProfessor, mesNascimenoProfessor, anoNascimentoProfessor ), NUMMAXIMOPROVAS( 4 ), NUMMAXIMOTRABALHOS( 5 ){
    this->setSalario( salario );
    this->setTipoProfessor( tipoProfessor );
    this->setNumProvas( 1 );
    this->setNumTrabalhos( 1 );
};

//tema, materiaisapoio, aulasInterativas, numProvas, numTrabalhos 
ProfessorEnsinoMedio::ProfessorEnsinoMedio( string tema, string materiaisApoio, bool aulasInterativas, int numProvas, int numTrabalhos ): NUMMAXIMOPROVAS( 4 ), NUMMAXIMOTRABALHOS( 5 ){// preparar aula
    this->tema = tema;
    this->materiaisApoio = materiaisApoio;
    this->aulasInterativas = aulasInterativas;
    this->setNumProvas( numProvas );
    this->setNumTrabalhos( numTrabalhos );
};

ProfessorEnsinoMedio::ProfessorEnsinoMedio( const ProfessorEnsinoMedio &otherProfessor ):Professor( otherProfessor ), NUMMAXIMOPROVAS( otherProfessor.NUMMAXIMOPROVAS ), NUMMAXIMOTRABALHOS( otherProfessor.NUMMAXIMOTRABALHOS ){ 
    this->tema = otherProfessor.tema;
    this->materiaisApoio = otherProfessor.materiaisApoio;
    this->aulasInterativas = otherProfessor.aulasInterativas;
    this->numProvas = otherProfessor.numProvas;
    this->numTrabalhos = otherProfessor.numTrabalhos;
    this->salario = otherProfessor.salario;
    this->tipoProfessor = otherProfessor.tipoProfessor;
};

ProfessorEnsinoMedio::~ProfessorEnsinoMedio( ){ };

// fim - construtores

// inicio - set
void ProfessorEnsinoMedio::setNumProvas( int numProvas ){
    if ( numProvas > 0 && numProvas <= NUMMAXIMOPROVAS ){
        this-> numProvas = numProvas;
        return;
    }
    this-> numProvas = NUMMAXIMOPROVAS;   
};

void ProfessorEnsinoMedio::setNumTrabalhos( int numTrabalhos ){
    if ( numTrabalhos > 0 && numTrabalhos <= NUMMAXIMOTRABALHOS ){
        this-> numTrabalhos =  numTrabalhos;
        return;
    }
    this-> numTrabalhos = NUMMAXIMOTRABALHOS;
};

void ProfessorEnsinoMedio::setSalario( float salario ){
    if ( salario > 0 ){
        this->salario = salario;
        return;
    }
    this->salario = 0.0;
};

void ProfessorEnsinoMedio::setTipoProfessor( string tipoProfessor ){
    for ( int i = 0; i < PROFESSORES; i++ ){
        if ( tipoProfessor == PROFESSOR[ i ] ){
            this->tipoProfessor = tipoProfessor;
            return;
        }	
        this->tipoProfessor = PROFESSOR[ i ];
    } 
};

// fim - set

// inicio - polimorfismo 
void ProfessorEnsinoMedio::metodoAvaliativo( ){
   cout << "\n--------------- MET. AVALIATIVO---------------";
   cout <<"\n\t\tPROVAS\t\t\t|\t\t\tTRABALHOS\n";
   cout << getNumProvas( ) << " PROVAS AVALIATIVAS\t|\t " << getNumTrabalhos( ) << " TRABALHOS INDIVIDUAIS\n"; 
   cout << "1 PROVA SUBSTITUITIVA \t|\t 2 TRABALHOS EM GRUPO\n";   
   cout << "-----------------------------------------------------\n";
};

void ProfessorEnsinoMedio::relatorioDesempenho( Aluno aluno ){
    ProfessorEnsinoMedio::metodoAvaliativo( );
    Professor::relatorioDesempenho( aluno );
};

void ProfessorEnsinoMedio::prepararAula( ){
     cout << "\nDICAS PARA ELABORACAO DE AULAS:";
     cout << "\n*Tema escolhido: " << getTema( ) << "; O tema deve ser relevante para os alunos e deve abordar assuntos que eles possam relacionar.\n";
     cout << "*Material de Apoio escolhido: " << getMateriaisApoio( ) << "; Obtenha material de apoio apropriado para o tema da aula, como livros, vídeos, folhetos, etc.\n";
     cout << "*As aulas serão interativas: " << getAulasInterativas( ) << "; Crie atividades interativas para ajudar os alunos a entender o conteúdo da aula. Estas atividades podem incluir perguntas e respostas, jogos, discussões em grupo, etc.\n";
     cout <<"*Planeje uma Avaliacao: " << getNumProvas( ) << " Provas Avaliativas e " << getNumTrabalhos( ) << " Trabalhos Avaliativos; Prepare uma avaliação para avaliar os conhecimentos dos alunos ao final da aula.\n";
};

float ProfessorEnsinoMedio::getBonificacao( ){// bonus de salario para um professor do ensino medio + 10%

    return this->salario*0.1;
};
// fim - polimorfismo 

//  inicio - sobrecarga de operadores


