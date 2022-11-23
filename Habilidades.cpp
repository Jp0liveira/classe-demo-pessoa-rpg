#include <iostream>
#include "Habilidades.h"

// inicio - construtores
Habilidades::Habilidades( ): ESCUDONOTAMINIMO( 0.0 ), ESCUDONOTAMAXIMO( 100.0 ), VIDASEMESTREMAXIMO( 100.0 ){
	this -> escudoNota = ESCUDONOTAMINIMO;
	this -> danoNota = 0.0;
	this -> vidaSemestre = VIDASEMESTREMAXIMO;
};

Habilidades::Habilidades( float escudoNota, float danoNota, float vidaSemestre ): ESCUDONOTAMINIMO( 0.0 ), ESCUDONOTAMAXIMO( 100.0 ), VIDASEMESTREMAXIMO( 100.0 ){
	this -> setEscudoNota(  escudoNota );
	this -> setDanoNota( danoNota );
	this -> setVidaSemestre( vidaSemestre );
};

Habilidades::Habilidades( const Habilidades& other): ESCUDONOTAMINIMO( other.ESCUDONOTAMINIMO ), ESCUDONOTAMAXIMO( other.ESCUDONOTAMAXIMO ), VIDASEMESTREMAXIMO( other.VIDASEMESTREMAXIMO ){
	this -> escudoNota = other.escudoNota;
	this -> danoNota = other.danoNota;
	this -> vidaSemestre = other.vidaSemestre;
};

Habilidades::~Habilidades( ){ };
// fim - construtores

// inicio - set
void Habilidades::setEscudoNota( float escudoNota ){
	if ( escudoNota >= ESCUDONOTAMINIMO && escudoNota <= ESCUDONOTAMAXIMO ){
		this -> escudoNota = escudoNota;
		return;
	}
	this -> escudoNota = ESCUDONOTAMAXIMO;
	fadiga = false;
};

void Habilidades::setDanoNota( float danoNota ){
	if ( danoNota > VIDASEMESTREMAXIMO ){// aluno esgotado
		this -> danoNota = 0.0;
		this -> escudoNota = 0.0;
		this -> vidaSemestre = 0.0;
		return;
	}
	this -> danoNota = danoNota;
};

void Habilidades::setVidaSemestre( float vidaSemestre ){
	if ( vidaSemestre >= ESCUDONOTAMINIMO && vidaSemestre <= VIDASEMESTREMAXIMO ){
		this -> vidaSemestre = vidaSemestre;
		return;
	}
	this -> vidaSemestre = VIDASEMESTREMAXIMO;// meio que um bonus ao inverso
	fadiga = false;
};
// fim - set

// inicio - habilidades  
void Habilidades::receberDanoNota(  ){
	if ( danoNota >= escudoNota ){// escudo quebra 
		this -> escudoNota = ESCUDONOTAMINIMO;
		fadiga = true;
	}
	if ( fadiga ){
		this -> setVidaSemestre( vidaSemestre -= danoNota / 2 );
		return;
	}
	this -> escudoNota -= danoNota;
};

void Habilidades::curarDanoNota( float curarNota ){// 0 - 10 de cura ( > 10 cura o escudo )
	if ( curarNota < 0 ){
		curarNota *= -1;// bencao de Jp
	}
	if ( ( fadiga && ( curarNota <= ( VIDASEMESTREMAXIMO / 10 ) ) )){
		this -> setVidaSemestre( vidaSemestre += curarNota );
		return;
	}
	this -> setEscudoNota( escudoNota += curarNota ); 
};
// fim - habilidades

void Habilidades::printHabilidades( ) {
	cout << "\n------- CARAC. HABILIDADES --------\n";
	cout << "Vida semestre:\t|\t" << getVidaSemestre( )  << "\n";
	cout << "Escudo nota:\t|\t" << getEscudoNota( )  << "\n";
	cout << "Dano nota:\t\t|\t" << getDanoNota( )  << "\n";
	
	cout << "-----------------------------------\n";
};


//funções a parte, implementadas mais a frente

// void Habilidades::rendimentoAluno( ){// aluno cansado, rendimento não tão bom :(
// 	escudoNota *= 0.5;
// };

// void Habilidades::momentoRaiva( ){
// 	// (0) não liga -- (10) liga muito;
// 	danoNota -= 0.1;
// 	vidaSemestre += 0.1;
// };

// void Habilidades::bonusNotaAluno( float bonusNota ){//notaAlunoRelacionado
// 	int contador = 0;
// 	while( fadiga ){
// 		notaFinalAluno += bonusNota;
// 		cout << "\nBonus aplicado: " << notaFinalAluno << "\n";
// 		contador++;
// 		if ( contador == 1 ){// sim, eu fiz isso :)
// 			return;
// 		}
// 	}
// 	cout << "\nO bonus não pode ser aplicado.\n";
// };

// inicio - funcoes  
