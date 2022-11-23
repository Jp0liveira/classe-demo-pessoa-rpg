#include <iostream>
#include "Bagunceiro.h"

using std::ctime;
using std::cout;

// inicio - static
int Bagunceiro::numBagunceiros = 0;

const int Bagunceiro::BAGUNCEIROIDADE = 00;
const int Bagunceiro::DIANASCIMENTO = 01;
const int Bagunceiro::MESNASCIMENTO = 01;
const int Bagunceiro::ANONASCIMENTO = 2000;
const string Bagunceiro::BAGUNCEIRONOME = "Default";

const float Bagunceiro::NOTABAGUNCEIRO = 6.5;
const int Bagunceiro::MATRICULABAGUNCEIRO = 0000000000;

 // aluo Bagunceiro por padrão já nasce com essas caracteristicas
const float Bagunceiro::ESCUDOBAGUNCEIRO = 80.0;
const float Bagunceiro::DANONOTABAGUNCEIRO = 10.0 ;
const float Bagunceiro::VIDASEMESTREBAGUNCEIRO = 100.0;
// fim - static

// inicio - construtores
Bagunceiro::Bagunceiro( ): Aluno( BAGUNCEIROIDADE, BAGUNCEIRONOME, DIANASCIMENTO, MESNASCIMENTO, ANONASCIMENTO, NOTABAGUNCEIRO, MATRICULABAGUNCEIRO ), Habilidades( ESCUDOBAGUNCEIRO, DANONOTABAGUNCEIRO, VIDASEMESTREBAGUNCEIRO ) {
     numBagunceiros++ ;
};
// implementar: se a nota for menor que 7, ele não é um aluno Bagunceiro, ou esta com algum problema;

Bagunceiro::Bagunceiro( int idadeBagunceiro, string nomeBagunceiro, int diaNascimentoBagunceiro, int mesNascimentoBagunceiro, int anoNascimentoBagunceiro, double notaFinalBagunceiro, int matriculaBagunceiro ): Aluno( idadeBagunceiro, nomeBagunceiro, diaNascimentoBagunceiro, mesNascimentoBagunceiro, anoNascimentoBagunceiro, notaFinalBagunceiro, matriculaBagunceiro ), Habilidades( ESCUDOBAGUNCEIRO, DANONOTABAGUNCEIRO, VIDASEMESTREBAGUNCEIRO ) {
     numBagunceiros++ ;
};
Bagunceiro::~Bagunceiro( ){ 
    for( auto i = 0; i < materiaisBagunceiro.materiais.size( ); i++){
        materiaisBagunceiro.materiais.pop_back();
        delete materiaisBagunceiro.materiais[i];
    }
    numBagunceiros--;
};
Bagunceiro::Bagunceiro( const Bagunceiro& other ): Aluno( static_cast< Aluno > ( other )) , Habilidades (static_cast< Habilidades > ( other )) { 
     numBagunceiros++;
};
// fim - construtores

// inicio - exibir
void Bagunceiro::printCaracteristicasBagunceiro( Bagunceiro nomeClass ) const {
    cout << "\n--------- CARAC. BAGUNCEIRO ---------";
    cout << "\nNome Bagunceiro\t|\t" << nomeClass.getNomePessoa( ) << "\n";
    cout << "Tipo Bagunceiro\t|\t" << nomeClass.getTipoPessoa( )  << "\n";
    cout << "Numº Matricula\t|\t" << nomeClass.getMatriculaAluno( )  << "\n";
    cout << "Idade Bagunceiro|\t" << nomeClass.getIdadePessoa( ) << "\n";
    cout << "Data Nascimento\t|\t" << nomeClass.getDiaNascimento( ) << "/" << nomeClass.getMesNascimento( ) << "/" << nomeClass.getAnoNascimento( ) << "\n";
    cout << "Nota Final\t\t|\t" << nomeClass.getNotaFinalAluno( )  << "\n";
    cout << "Escudo Nota\t\t|\t" << nomeClass.getEscudoNota( )  << "\n";
    cout << "Dano Nota\t\t|\t" << nomeClass.getDanoNota( )  << "\n";
    cout << "Vida Semestre\t|\t" << nomeClass.getVidaSemestre( ) << "\n";
    cout << "-----------------------------------\n";
};

void Bagunceiro::materialSemestreBagunceiro( ) {
        materiaisBagunceiro.numMateriais = NUMMAXMATERIAIS;
        string materiaisEscolares[] = {
            "garrafinha: Tupperware",
            "lancheira: CK PRESENTES",
            "sombrinha: XIAOMI",
            "caneta: Pilot Frixion Ball",
            "caderno: Tilibra Happy"
         };
         for (int i = 0; i < sizeof( materiaisEscolares ) / sizeof( string ); i++){
            materiaisBagunceiro.cadastrarMateriais( materiaisEscolares[ i ]);
         }
         materiaisBagunceiro.printListaMateriais( );
};

// reescrita da função
void Bagunceiro::printListaMateriais( ){
    materiaisBagunceiro.Materiais::printListaMateriais( );
};
// inicio - exibir

// inicio - sobrecarga de operadores 
    // adiciona mais um material escolar 
Bagunceiro& Bagunceiro::operator=( const string novoMaterialEscolar ){
    if ( materiaisBagunceiro.materiais.size( ) < NUMMAXMATERIAIS ){
        materiaisBagunceiro.materiais.push_back( new string ( novoMaterialEscolar ));
        // incrementar o numero de materiais globais static ;
    } else {
        cout << "\nBagunceiro: [ " << getNomePessoa( ) << "] já  possui os materiais escolares necessarios\n";
    }
    return *this;
};

    // Compara se o nome ou idade são iguais
bool Bagunceiro::operator==( Pessoa aluno ){
    bool caracteristicasComuns = Bagunceiro::getNomePessoa( ) == aluno.getNomePessoa( ) || Bagunceiro::getIdadePessoa( ) == aluno.getIdadePessoa( );
    if ( caracteristicasComuns ){
        cout << Bagunceiro::getNomePessoa( ) << " e " << aluno.getNomePessoa( ) << " POSSUEM: \n Nome ou Idade iguais.\n";
        cout << "";
        return true;
    }
    cout << Bagunceiro::getNomePessoa( ) << " e " << aluno.getNomePessoa( ) << " NÃO POSSUEM: \n Nome ou Idade iguais.\n";
    return false;
};

    // verifica se a idade é igual ao ano de nascimento 
bool Bagunceiro::operator!=( Pessoa bagunceiro ){
    int calculoIdade = materiaisBagunceiro.calcularAnoAtual( bagunceiro.getAnoNascimento( ) );
    if ( calculoIdade == Bagunceiro::getIdadePessoa( ) ){
        cout << "A idade é igual ao ano de nascimento\n";
        return true;
    }else{
       cout << "A idade é diferente do ano de nascimento\n";
        return false;
    }
};

    // exclue todos os materiais do aluno :(
Bagunceiro& Bagunceiro::operator!( ){
    cout << "\nExcluindo todos os materiais do aluno..." << "\n";
    while ( materiaisBagunceiro.materiais.begin( ) != materiaisBagunceiro.materiais.end( ) ){
      materiaisBagunceiro.materiais.pop_back( );   
    }
    return *this;
};

    // exibe todas as caracteristicas da "pessoa"
ostream &operator<<( ostream &COUT, const Bagunceiro &bagunceiro ){
    COUT << static_cast< Aluno >( bagunceiro );
    COUT << "Escudo Bagunceiro: "<< bagunceiro.ESCUDOBAGUNCEIRO << "\n";
    COUT << "Dano Bagunceiro: "<< bagunceiro.DANONOTABAGUNCEIRO << "\n";
    COUT << "Vida Semestre: " << bagunceiro.VIDASEMESTREBAGUNCEIRO << "\n";
    return COUT; 
};
// fim - sobrecarga de operadores 
