#include <iostream>
#include "Estudioso.h"

using std::ctime;
using std::cout;

// inicio - static

int Estudioso::numEstudiosos = 0;
const int Estudioso::ESTUDIOSOIDADE = 00;
const int Estudioso::DIANASCIMENTO = 01;
const int Estudioso::MESNASCIMENTO = 01;
const int Estudioso::ANONASCIMENTO = 2000;
const string Estudioso::ESTUDIOSONOME = "Default";

const float Estudioso::NOTAESTUDIOSO = 10.0;
const int Estudioso::MATRICULAESTUDIOSO = 0000000000;
 
 // aluo Estudioso por padrão já nasce com essas caracteristicas
const float Estudioso::ESCUDOESTUDIOSO = 50.0;
const float Estudioso::DANONOTAESTUDIOSO = 25.0 ;
const float Estudioso::VIDASEMESTREESTUDIOSO = 100.0;
// fim - static

// inicio - construtores
Estudioso::Estudioso( ): Aluno( ESTUDIOSOIDADE, ESTUDIOSONOME, DIANASCIMENTO, MESNASCIMENTO, ANONASCIMENTO, NOTAESTUDIOSO, MATRICULAESTUDIOSO ), Habilidades( ESCUDOESTUDIOSO, DANONOTAESTUDIOSO, VIDASEMESTREESTUDIOSO ) {
    numEstudiosos++;
 };
// implementar: se a nota for menor que 7, ele não é um aluno estudioso, ou esta com algum problema;

Estudioso::Estudioso( int idadeEstudioso, string nomeEstudioso, int diaNascimentoEstudioso, int mesNascimentoEstudios, int anoNascimentoEstudioso, double notaFinalEstudioso, int matriculaEstudioso ): Aluno( idadeEstudioso, nomeEstudioso, diaNascimentoEstudioso, mesNascimentoEstudios, anoNascimentoEstudioso, notaFinalEstudioso, matriculaEstudioso ), Habilidades( ESCUDOESTUDIOSO, DANONOTAESTUDIOSO, VIDASEMESTREESTUDIOSO ) {
    numEstudiosos++;
  
};
Estudioso::~Estudioso( ){ 
    for( auto i = 0; i < materiaisEstudioso.materiais.size( ); i++){
        materiaisEstudioso.materiais.pop_back();
        delete materiaisEstudioso.materiais[i];
    }
    numEstudiosos--;
};
Estudioso::Estudioso( const Estudioso& other ): Aluno( static_cast<Aluno> ( other )) , Habilidades (static_cast< Habilidades > ( other )) { 
    numEstudiosos++;
};
// fim - construtores

// inicio - exibir
void Estudioso::printCaracteristicaEstudioso( Estudioso nomeClass ) const {
    cout << "\n--------- CARAC. ESTUDIOSO ---------";
    cout << "\nNome Estudioso\t|\t" << nomeClass.getNomePessoa( ) << "\n";
    cout << "Tipo Estudioso\t|\t" << nomeClass.getTipoPessoa( )  << "\n";
    cout << "Numº Matricula\t|\t" << nomeClass.getMatriculaAluno( )  << "\n";
    cout << "Idade Estudioso\t|\t" << nomeClass.getIdadePessoa( ) << "\n";
    cout << "Data Nascimento\t|\t" << nomeClass.getDiaNascimento( ) << "/" << nomeClass.getMesNascimento( ) << "/" << nomeClass.getAnoNascimento( ) << "\n";
    cout << "Nota Final\t\t|\t" << nomeClass.getNotaFinalAluno( )  << "\n";
    cout << "Escudo Nota\t\t|\t" << nomeClass.getEscudoNota( )  << "\n";
    cout << "Dano Nota\t\t|\t" << nomeClass.getDanoNota( )  << "\n";
    cout << "Vida Semestre\t|\t" << nomeClass.getVidaSemestre( ) << "\n";
    cout << "-----------------------------------\n";
};

void Estudioso::materialSemestreEstudioso( ) {
        materiaisEstudioso.numMateriais = NUMMAXMATERIAIS;
        string materiaisEscolares[] = {
            "garrafinha: Tupperware",
            "lancheira: CK PRESENTES",
            "sombrinha: XIAOMI",
            "caneta: Pilot Frixion Ball",
            "caderno: Tilibra Happy"
         };
         for (int i = 0; i < sizeof( materiaisEscolares ) / sizeof( string ); i++){
            materiaisEstudioso.cadastrarMateriais( materiaisEscolares[ i ]);
         }
         materiaisEstudioso.printListaMateriais( );
};

// reescrita da função
void Estudioso::printListaMateriais( ){
    materiaisEstudioso.Materiais::printListaMateriais( );
};
// inicio - exibir

// inicio - sobrecarga de operadores 
    // adiciona mais um material escolar 
Estudioso& Estudioso::operator=( const string novoMaterialEscolar ){
    if ( materiaisEstudioso.materiais.size( ) < NUMMAXMATERIAIS ){
        materiaisEstudioso.materiais.push_back( new string ( novoMaterialEscolar ));
        // incrementar o numero de materiais globais static ;
    } else {
        cout << "\nEstudioso: [ " << getNomePessoa( ) << "] já  possui os materiais escolares necessarios\n";
    }
    return *this;
};

    // Compara se o nome ou idade são iguais
bool Estudioso::operator==( Pessoa aluno ){
    bool caracteristicasComuns = Estudioso::getNomePessoa( ) == aluno.getNomePessoa( ) || Estudioso::getIdadePessoa( ) == aluno.getIdadePessoa( );
    if ( caracteristicasComuns ){
        cout << Estudioso::getNomePessoa( ) << " e " << aluno.getNomePessoa( ) << " POSSUEM: \n Nome ou Idade iguais.\n";
        cout << "";
        return true;
    }
    cout << Estudioso::getNomePessoa( ) << " e " << aluno.getNomePessoa( ) << " NÃO POSSUEM: \n Nome ou Idade iguais.\n";
    return false;
};
    // verifica se a idade é igual ao ano de nascimento 
bool Estudioso::operator!=( Pessoa estudioso ){
    int calculoIdade = materiaisEstudioso.calcularAnoAtual( estudioso.getAnoNascimento( ) );
    if ( calculoIdade == Estudioso::getIdadePessoa( ) ){
        cout << "A idade é igual ao ano de nascimento\n";
        return true;
    }else{
       cout << "A idade é diferente do ano de nascimento\n";
        return false;
    }
};

    // exclue todos os materiais do aluno :(
Estudioso& Estudioso::operator!( ){
    cout << "\nExcluindo todos os materiais do aluno..." << "\n";
    while ( materiaisEstudioso.materiais.begin( ) != materiaisEstudioso.materiais.end( ) ){
      materiaisEstudioso.materiais.pop_back( );   
    }
    return *this;
};

    // exibe todas as caracteristicas da "pessoa"
ostream &operator<<( ostream &COUT, const Estudioso &estudioso ){
    COUT << static_cast< Aluno >( estudioso );
    COUT << "Escudo estudidoso: "<< estudioso.ESCUDOESTUDIOSO << "\n";
    COUT << "Dano Estudioso: "<< estudioso.DANONOTAESTUDIOSO << "\n";
    COUT << "Vida Semestre: " << estudioso.VIDASEMESTREESTUDIOSO << "\n";
    return COUT; 
};
// fim - sobrecarga de operadores 
