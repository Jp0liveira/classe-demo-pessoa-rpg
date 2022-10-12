#include <iostream>
#include "Aluno.h"
#include <cmath>

//static
int Aluno::totalGeralAlunos = 0;
const string Aluno::TIPOS[ NUMTIPOSCADASTRADOS ] = {"bagunceiro, estudioso, timido, sociavel, distante, agressivo, lider"};

// inicio - construtores
Aluno::Aluno( ):IDADEALUNOMAXIMO( 120 ), ESCUDONOTAMAXIMO( 10 ), VIDAALUNOSEMESTREMAXIMO( 100 ), NOTAFINALMAXIMO( 10.0 ){//default
		//alocacao
		qtdHistoricoAlunosIdade = 0;
		tamAlocadoHistoricoAlunosIdade = 0;
	
    nomeAluno = "default";
    tipoAluno = "Estudioso";
    idadeAluno = 18;
    notaFinalAluno = 10.0;
		
		//vidaAlunoSemestre = 100;
    //escudo nota atual;
    //vida aluno semestre;
		totalGeralAlunos++;
		
};


Aluno::Aluno( string AnomeAluno, string AtipoAluno, int AidadeAluno, float AnotaFinalAluno ):IDADEALUNOMAXIMO( 120 ), ESCUDONOTAMAXIMO( 10 ), VIDAALUNOSEMESTREMAXIMO( 100 ), NOTAFINALMAXIMO( 10.0 ){//argumentos
		//alocacao
		qtdHistoricoAlunosIdade = 0;
		tamAlocadoHistoricoAlunosIdade = 0;
	
    setNomeAluno( AnomeAluno );
    setTipoAluno( AtipoAluno );
    setIdadeAluno( AidadeAluno );
		setNotaFinalAluno( AnotaFinalAluno );
		
	
		totalGeralAlunos++;
};

Aluno::Aluno( const Aluno& other ):IDADEALUNOMAXIMO( other.IDADEALUNOMAXIMO ), ESCUDONOTAMAXIMO( other.ESCUDONOTAMAXIMO ), VIDAALUNOSEMESTREMAXIMO( other.VIDAALUNOSEMESTREMAXIMO ), NOTAFINALMAXIMO( other.NOTAFINALMAXIMO ){//copia
    this -> nomeAluno = other.nomeAluno;
    this -> tipoAluno = other.tipoAluno;
    setIdadeAluno(other.idadeAluno);
		setNotaFinalAluno(other.notaFinalAluno);
	
		totalGeralAlunos++;
};

Aluno::~Aluno( ){//destrutor
	totalGeralAlunos--;
	delete [] histAlunosIdadePtr;
};

// fim - construtores

//  inicio - sets
    // inicio - sets (verificar)
void Aluno::setNomeAluno( string AnomeAluno ){
    nomeAluno = AnomeAluno;
    //buscar algumas condicoes while
};

void Aluno::setTipoAluno( string AtipoAluno ){
		tipoAluno = AtipoAluno;
    //falta fazer (for)
    // if (setIdadeAluno(idadeAluno)){
    // }
};

void Aluno::setIdadeAluno( int AidadeAluno ){
     if ( AidadeAluno >= 0 && AidadeAluno <= 120 ){
			 idadeAluno = AidadeAluno;
			 cadastrarHistALunosIdade( idadeAluno );
			 return;
     }
     idadeAluno = 18;
};

bool Aluno::setEscudoNotaAtual( int novoEscudoNotaAtual ){
    if ( novoEscudoNotaAtual >= 0  && novoEscudoNotaAtual < ESCUDONOTAMAXIMO ){
        return false;
    }
    escudoNotaAtual = novoEscudoNotaAtual;
    return true;
};

// if (notaVidaAluno > 0 && notaVidaAluno <= notaVidaAlunoMaximo){
//     notaVidaAluno = notaVidaAlunoMaximo;
//     return;
// }

void Aluno::setVidaAlunoSemestre( float AvidaAlunoSemestre ){
    if ( AvidaAlunoSemestre >= 0 && AvidaAlunoSemestre <= VIDAALUNOSEMESTREMAXIMO ){
        vidaAlunoSemestre = AvidaAlunoSemestre;
        return;
    }
    vidaAlunoSemestre = 5;
};

void Aluno::setNotaFinalAluno( float AnotaFinalAluno ){
    if ( AnotaFinalAluno >= 0 && AnotaFinalAluno <= NOTAFINALMAXIMO ){
        notaFinalAluno = AnotaFinalAluno;
			if ( notaFinalAluno <= 5.0){
				fadigaAlunoNota = true;
			}else{
				fadigaAlunoNota = false;
			}
      return;
    }
    notaFinalAluno = 0.0;
};
    // fim - sets (verificar)

    // inicio - sets (funcoes:()
void Aluno::receberDanoNota( int danoNota ){
    if ( danoNota > escudoNotaAtual ){
      escudoNotaAtual = 0;
			return;
    }
		if (fadigaAlunoNota){
			escudoNotaAtual -= danoNota + 1;
			return;
		}
    escudoNotaAtual -= danoNota;
};

void Aluno::curarDanoNota( int curaAluno ){
    if ( curaAluno + escudoNotaAtual <= VIDAALUNOSEMESTREMAXIMO ){
        escudoNotaAtual = VIDAALUNOSEMESTREMAXIMO;
        return;
    }
    escudoNotaAtual += curaAluno;
};

void Aluno::bonusNotaAluno(float bonusNota){//setNotaFinalAluno (relacionado)
	int contador = 0;
	while(fadigaAlunoNota){
		notaFinalAluno += bonusNota;
		cout << "\nBonus aplicado: " << notaFinalAluno << "\n";
		contador++;
		if (contador == 1){
			return;
		}
	}
	cout << "\nO bonus não pode ser aplicado.\n";
};
    // fim - sets (funcoes)
// fim - sets

//inicio - get
string Aluno::getNomeAluno( ){
    return nomeAluno;
};

string Aluno::getTipoAluno( ){
    return tipoAluno;
};

int Aluno::getIdadeAluno( ){
    return idadeAluno;
};

int Aluno::getEscudoNotaAtual( ){
    return escudoNotaAtual;
};

float Aluno::getVidaAlunoSemestre( ){
    return vidaAlunoSemestre;
};

float Aluno::getNotaFinalAluno ( ){
    return notaFinalAluno;
};
//fim - get

//inicio - alocacao


 void Aluno::cadastrarHistALunosIdade( int AidadeAlunos ){
    if ( qtdHistoricoAlunosIdade < tamAlocadoHistoricoAlunosIdade )
    {
			histAlunosIdadePtr[qtdHistoricoAlunosIdade++ ] = AidadeAlunos;
			return;
    }

    if( tamAlocadoHistoricoAlunosIdade == 0 )
    {
			tamAlocadoHistoricoAlunosIdade = 1;
			histAlunosIdadePtr = new int[ tamAlocadoHistoricoAlunosIdade ];
			histAlunosIdadePtr[ qtdHistoricoAlunosIdade++ ] = AidadeAlunos;
			return;
    }       
    alocarHistALunosIdade( AidadeAlunos );    
};

/*
	int *histAlunosIdadePtr;
	int tamHistoricoAlunosIdade, qtdHistoricoAlunosIdade;
	void printHistAlunosIdade( ) const;
	void alocaHistAlunosIdade( int );	
*/
 void Aluno::alocarHistALunosIdade( int AidadeAlunos ) {    
    //cout << "Allocating...\n";
    int *histAlunosIdadeTemp = new int[ tamAlocadoHistoricoAlunosIdade ];
    for( int i = 0; i < qtdHistoricoAlunosIdade; i++ )
        histAlunosIdadeTemp[ i ] = histAlunosIdadePtr[ i ];

    delete [] histAlunosIdadePtr;
	 
    tamAlocadoHistoricoAlunosIdade += int( ceil( tamAlocadoHistoricoAlunosIdade * 0.5 ) );
    histAlunosIdadePtr = new int[ tamAlocadoHistoricoAlunosIdade ];
    for( int i = 0; i < qtdHistoricoAlunosIdade; i++ )
        histAlunosIdadePtr[ i ] = histAlunosIdadeTemp[ i ];
    histAlunosIdadePtr[ qtdHistoricoAlunosIdade++ ] = AidadeAlunos;
	 
    delete [] histAlunosIdadeTemp;     
};

void Aluno::printHistoricoIdadeAlunos( ) const{
	 for( int i = 0; i < qtdHistoricoAlunosIdade; i++ )
    cout << histAlunosIdadePtr[ i ] << '\n'; 
};
//fim - alocacao


	// inicio - normal
void Aluno::printCaracteristicasAluno( ) const{
    cout << "\n\tCaracterísticas do Aluno\n";
    cout << "Nome: " << nomeAluno;
    cout << "\nIdade: " << idadeAluno;
    cout << "\nTipo: " << tipoAluno;
		cout << "\nNota Final: " <<  notaFinalAluno << "\n"; 
		cout << "--------------------------------";
};
	// inicio - normal

	// inicio - static
void Aluno::printTiposCadastrados( ){
	for( int i = 0; i < NUMTIPOSCADASTRADOS; i++ )
		cout << "Tipo de Aluno: " << TIPOS[ i ] << " " << "\tLocal da memoria: " << &TIPOS[ i ] << "\n";
};
	// fim - static

// fim - exibir dados



