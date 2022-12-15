#include <iostream>
#include "ProfessorFisica.h"

using std::cout;

const string ProfessorFisica::PROFESSORFISICA = "professor de fisica";

// inicio - construtores
ProfessorFisica::ProfessorFisica( ): ProfessorEnsinoMedio( ){ 
    this->setNumProvaSubstitutiva( 0 );
    this->setNumTrabalhosGrupo( 0 );
};

ProfessorFisica::ProfessorFisica( int idadeProfessor, string nomeProfessor, int diaNascimentoProfessor, int mesNascimenoProfessor, int anoNascimentoProfessor, float salario ): ProfessorEnsinoMedio( idadeProfessor,  nomeProfessor, diaNascimentoProfessor, mesNascimenoProfessor, anoNascimentoProfessor, salario, PROFESSORFISICA ){ 
};

// preparar aula
ProfessorFisica::ProfessorFisica( int numProvas, int numTrabalhos, int numProvaSubstitutiva, int numTrabalhosGrupo ){
    ProfessorEnsinoMedio::setNumProvas( numProvas );
    ProfessorEnsinoMedio::setNumTrabalhos( numTrabalhos );
    this->setNumProvaSubstitutiva( numProvaSubstitutiva );
    this->setNumTrabalhosGrupo( numTrabalhosGrupo );
};

ProfessorFisica::ProfessorFisica( const ProfessorFisica &otherProfessorFisica ): ProfessorEnsinoMedio( otherProfessorFisica ){ };

ProfessorFisica::~ProfessorFisica( ){ };

// fim - construtores

// inicio - polimorfismo 
    // inicio - set
void ProfessorFisica::setSalario( float salario ){// bonuns salario muda
    if ( salario > 0 ){
        this->salario = salario;
        this->salario += ProfessorFisica::getBonificacao( );
    }
};

void ProfessorFisica::setNumProvaSubstitutiva( int numProvaSubstitutiva ){
    if (  numProvaSubstitutiva > 0  && numProvaSubstitutiva < ProfessorEnsinoMedio::getNumProvas( ) ){// meio que utiliza o set da classe "ProfessorEnsinoMedio" :)
        this->numProvaSubstitutiva = numProvaSubstitutiva;
        return;
    }
     this->numProvaSubstitutiva = 0;
};

void ProfessorFisica::setNumTrabalhosGrupo( int numTrabalhosGrupo ){
    if ( numTrabalhosGrupo > 0  && numTrabalhosGrupo <= ProfessorEnsinoMedio::getNumTrabalhos( ) + 1 ){// meio que utiliza o set da classe "ProfessorEnsinoMedio" :)
        this->numTrabalhosGrupo = numTrabalhosGrupo;
        return;
    }
     this->numTrabalhosGrupo = 0;
}
    // fim - set

void ProfessorFisica::metodoAvaliativo( ){
   cout << "\n--------------- MET. AVALIATIVO---------------";
   cout <<"\n\t\tPROVAS\t\t\t|\t\t\tTRABALHOS\n";
   cout << ProfessorEnsinoMedio::getNumProvas( ) << " PROVAS AVALIATIVAS\t|\t " << ProfessorEnsinoMedio::getNumTrabalhos( ) << " TRABALHOS INDIVIDUAIS\n"; 
   cout << ProfessorFisica::getNumProvaSubstitutiva( ) << " PROVA SUBSTITUITIVA \t|\t " << ProfessorFisica::getNumTrabalhosGrupo( ) << " TRABALHOS EM GRUPO\n";   
   cout << "-----------------------------------------------------\n";
};

void ProfessorFisica::relatorioDesempenho( Aluno aluno ){
    ProfessorFisica::metodoAvaliativo( );
    Professor::relatorioDesempenho( aluno );
};

// struct "PrepararAula.h"
void ProfessorFisica::temaParaAula( ){
    metodologia.numMaximoTemas = NUMMAXIMOTEMAS;
    string temasCorpoDocente[ ] = {
        "1: Energia e mecânica clássica",
        "2: Cinemática, dinâmica e gravidade",
        "3: Ondas e óptica",
        "4: Eletromagnetismo",
        "5: Termodinâmica",
        "6: Fisica Nuclear",
        "7: Dinâmica e movimento",
        "8: Termodinâmica"
        };
    for (int i = 0; i < sizeof( temasCorpoDocente ) / sizeof( string ); i++){
        metodologia.cadastrarTemasAula( temasCorpoDocente[ i ] );
    }
    metodologia.printTemasAula( );
};

void ProfessorFisica::materiaisApoio( ){
    metodologia.numMaximoMateriais = NUMMAXIMOMATERIAIS;
    string materiaisCorpoDocente[ ] = {
        "Livro: Fundamentos de Física, Halliday e Resnick",
        "Livro: Física para Cientistas e Engenheiros, Tipler e Mosca",
        "Livro: Física Moderna, Serway",

        "Online: Khan Academy",
        "Online: Tutorials Point",
        "Online: Physics Classroom ",

        "Simulacao: PhET Interactive Simulations",
        "Simulacao: Virtual Lab",
        "Simulacao: Easy Java Simulations ",
        "Simulacao: Visual Quantum Mechanics",
        
        "Filme: O Universo de Stephen Hawking",
        "Filme: Cosmos: Uma Odisseia no Tempo",
        "Filme: Partículas Elementares",
        "Filme: O Big Bang Theory"
    };
    for (int i = 0; i < sizeof( materiaisCorpoDocente ) / sizeof( string ); i++){
        metodologia.cadastrarMateriaisAula( materiaisCorpoDocente[ i ] );
    }
    metodologia.printMateriaisAula( );
};

void ProfessorFisica::prepararAula( ){
    cout << "\nDICAS PARA ELABORACAO DE AULAS:";
    ProfessorFisica::temaParaAula( );
    ProfessorFisica::materiaisApoio( );
};

float ProfessorFisica::getBonificacao( ){// bonus de salario para um professor do ensino medio + 15%
    return ProfessorEnsinoMedio::getSalario( )*0.15;
};
// fim - polimorfismo 

