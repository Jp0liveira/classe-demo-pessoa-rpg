#include <iostream>
#include "Habilidades.h"

// inicio - construtores
Habilidades::Habilidades( ): ESCUDONOTAMINIMO( 0.0 ), ESCUDONOTAMAXIMO( 50.0 ), VIDASEMESTREMAXIMO( 100.0 ){
	escudoNota = ESCUDONOTAMINIMO;
	danoNota = 0.0;
	vidaSemestre = VIDASEMESTREMAXIMO;
};

Habilidades::Habilidades( float AescudoNota, float AdanoNota, float AvidaSemestre ): ESCUDONOTAMINIMO( 0.0 ), ESCUDONOTAMAXIMO( 50.0 ), VIDASEMESTREMAXIMO( 100.0 ){
	setEscudoNota(  AescudoNota );
	setDanoNota( AdanoNota );
	setVidaSemestre( AvidaSemestre );
};

Habilidades::Habilidades( const Habilidades& other): ESCUDONOTAMINIMO( other.ESCUDONOTAMINIMO ), ESCUDONOTAMAXIMO( other.ESCUDONOTAMAXIMO ), VIDASEMESTREMAXIMO( other.VIDASEMESTREMAXIMO ){
	this -> escudoNota = other.escudoNota;
	this -> danoNota = other.danoNota;
	this -> vidaSemestre = other.vidaSemestre;
};

Habilidades::~Habilidades( ){ };
// inicio - construtores

// inicio - verificar
void Habilidades::setEscudoNota( float AescudoNota ){
	if ( AescudoNota >= ESCUDONOTAMINIMO && AescudoNota <= ESCUDONOTAMAXIMO ){
		escudoNota = AescudoNota;
		return;
	}
	escudoNota = ESCUDONOTAMAXIMO;
	fadiga = false;
};

void Habilidades::setDanoNota( float AdanoNota ){
	if ( AdanoNota > VIDASEMESTREMAXIMO ){// aluno esgotado
		danoNota = 0.0;
		escudoNota = 0.0;
		vidaSemestre = 0.0;
		return;
	}
	danoNota = AdanoNota;
};

void Habilidades::setVidaSemestre( float AvidaSemestre ){
	if ( AvidaSemestre <= VIDASEMESTREMAXIMO ){
		vidaSemestre = AvidaSemestre;
		return;
	}
	vidaSemestre = VIDASEMESTREMAXIMO;// meio que um bonus ao inverso
	
};
// fim - verificar

// inicio - funcoes  
void Habilidades::receberDanoNota(  ){
	if ( danoNota > escudoNota ){// escudo quebra 
		escudoNota = ESCUDONOTAMINIMO;
		fadiga = true;
	}
	if ( fadiga ){
		vidaSemestre--;
		if ( vidaSemestre == 0.0 ){
			vidaSemestre = VIDASEMESTREMAXIMO;// aluno "morreu" e vida reiniciada
		}
		return;
	}
	escudoNota -= danoNota;
};

void Habilidades::curarDanoNota( float curarNota ){// 0 - 10 de cura
	if ( curarNota < 0 ){
			curarNota *= -1;// bencao de Jp
	}
	if ( ( fadiga && ( curarNota <= ( VIDASEMESTREMAXIMO / 10 ) ) )){
		setEscudoNota( escudoNota += curarNota ); 
		return;
	}
	setVidaSemestre( vidaSemestre += curarNota );
	
};
// fim - funcoes



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
