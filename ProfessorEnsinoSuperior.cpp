#include <iostream>
#include "ProfessorEnsinoSuperior.h"

using std::cout;

/*
prototipo:
    especializacao - História
    area de atuacao - História da América Latina, História do Brasil e História das Ideias Políticas
    instituicao - Universidade Federal do Rio Grande do Sul
    experiencia profissional - 10 anos de experiência em ensino superior.
    salario - mais de 10,000;
*/

// inicio - construtores
ProfessorEnsinoSuperior::ProfessorEnsinoSuperior( ): SALARIOMINIMO( 8000 ), NUMMAXIMOINFORMACOES( 20 ) {
    this->especializacao = "historia";
    this->areaAtuacao = "historia da america latina, historia do brasil e historia das ideias politicas";
    this->instituicao = "universidade federal do rio grande do sul";
    this->setSalario( 8000 );
};

ProfessorEnsinoSuperior::ProfessorEnsinoSuperior( int idade, string nome, int diaNascimentoProfessor, int mesNascimentoProfessor, int anoNascimentoProfessor ): Professor( idade, nome, diaNascimentoProfessor, mesNascimentoProfessor, anoNascimentoProfessor ), SALARIOMINIMO( 8000 ), NUMMAXIMOINFORMACOES( 20 )  { };

ProfessorEnsinoSuperior::ProfessorEnsinoSuperior( string especializacao,  string areaAtuacao, string instituicao, int salario ): SALARIOMINIMO( 8000 ), NUMMAXIMOINFORMACOES( 20 ) {
    this->especializacao = especializacao;
    this->areaAtuacao = areaAtuacao;
    this->instituicao = instituicao;
    this->setSalario( salario );
};

ProfessorEnsinoSuperior::ProfessorEnsinoSuperior( const ProfessorEnsinoSuperior&  otherProfessorEnsinoSuperior ): Professor(  otherProfessorEnsinoSuperior ), SALARIOMINIMO(  otherProfessorEnsinoSuperior.SALARIOMINIMO ), NUMMAXIMOINFORMACOES( otherProfessorEnsinoSuperior.NUMMAXIMOINFORMACOES ) {    
    this->especializacao = otherProfessorEnsinoSuperior.especializacao;
    this->areaAtuacao = otherProfessorEnsinoSuperior.areaAtuacao;
    this->instituicao = otherProfessorEnsinoSuperior.instituicao;
    this->salario = otherProfessorEnsinoSuperior.salario;
}

ProfessorEnsinoSuperior::~ProfessorEnsinoSuperior( ){ };

 // fim - construtores

 // inicio - set
 void ProfessorEnsinoSuperior::setSalario( float salario ){
    if ( salario >= SALARIOMINIMO ){// não possue salario maximo :)
        this->salario = salario;
        return;
    }
    this->salario = SALARIOMINIMO;
 };
 // fim - set

// inicio - bonificacao 
float ProfessorEnsinoSuperior::getBonificacao( ){
    return this->salario * 0.25;
};
// fim - bonificacao 


// inicio - polimorfismo 
void ProfessorEnsinoSuperior::planoDeAulas( const string &planoAssuntos ){
    if  ( this->planoAssuntos.size( ) < NUMMAXIMOINFORMACOES ){
        this->planoAssuntos.push_back( new string( planoAssuntos ) );        
        return;
    }else{
        cout << "Nao e possivel cadastrar " << planoAssuntos << '.' << " numero maximo de informacoes.\n";
    }
};

void ProfessorEnsinoSuperior::curriculoProfessor( const string &curriculoLattes ){
    if  ( this->curriculoLattes.size( ) < NUMMAXIMOINFORMACOES ){
        this->curriculoLattes.push_back( new string( curriculoLattes ) );        
        return;
    }else{
        cout << "Nao e possivel cadastrar " << curriculoLattes << '.' << " numero maximo de informacoes.\n";
    }
};

void ProfessorEnsinoSuperior::participacaoComites( const string &comites ){
    if  ( this->comites.size( ) < NUMMAXIMOINFORMACOES ){
        this->comites.push_back( new string( comites ) );        
        return;
    }else{
        cout << "Nao e possivel cadastrar " << comites << '.' << " numero maximo de informacoes.\n";
    }
};

void ProfessorEnsinoSuperior::printPlanejamento( ){
    cout << "\n-------------- PLANO DE AULAS --------------\n";
    for( int i = 0; i < this->planoAssuntos.size( ); i++ ){
        cout << planoAssuntos[ i ] << " |\t" << *planoAssuntos[ i ] << "\n";
    }
    cout << "---------------------------------------\n";
    cout << "\n-------------- CURRICULO --------------\n";
    for( int i = 0; i < this->curriculoLattes.size( ); i++ ){
        cout << curriculoLattes[ i ] << " |\t" << *curriculoLattes[ i ] << "\n";
    }
    cout << "---------------------------------------\n";
    cout << "\n-------------- PART. COMITES --------------\n";
    for( int i = 0; i < this->comites.size( ); i++ ){
        cout << comites[ i ] << " |\t" << *comites[ i ] << "\n";
    }
    cout << "---------------------------------------\n";
};

void ProfessorEnsinoSuperior::metodoAvaliativo( ){
    ProfessorEnsinoSuperior::printPlanejamento( );// :)
};

// fim - polimorfismo 

//  inicio - sobrecarga de operadores
// em processo...
//  fim - sobrecarga de operadores
