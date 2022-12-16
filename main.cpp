#include <iostream>
#include "AllClasses.h"


using std::cout;

int main( ) {
	Estudioso estudioso( 21, "Ferreira C. Oliveira", 28, 06, 2000, 9.5, 2021006895 );
	Bagunceiro bagunceiro( 15, "Thiago J. Pereira", 28, 06, 2008, 7.5, 2022007823 );
	
	// // materiais do semestre
	// bagunceiro.materialSemestreBagunceiro( );

	// // sobrecarga de operadores 
	// bagunceiro = "Mochila: nikeFashion";
	// bagunceiro == estudioso;
	// bagunceiro != bagunceiro;
	// cout << bagunceiro;

	// // caracteristicas do bagunceiro
	// bagunceiro.printListaMateriais( );
	// bagunceiro.printCaracteristicasBagunceiro( bagunceiro );
	// !bagunceiro;
	// bagunceiro.printListaMateriais( );
	
	// // habilidades
	// bagunceiro.printHabilidades( );
	// cout << "\n--------- SIST. BATALHA ---------"; // sim, poderia fazer um metodo pra isso.
	// cout << "\nEscudo: ";
	// while ( bagunceiro.getVidaSemestre( ) >= 50  ){
	// 	bagunceiro.receberDanoNota( );
	// 	// escudo recebe + 10 de dano
	// 	// vida recebe o danoNota / 2 == + 5 de dano;
	// 	cout << bagunceiro.getEscudoNota( ) << " ";
	// 	if ( bagunceiro.getEscudoNota( ) == 0 ){ // escudo quebra e começa a usar a vida
	// 		cout << "\nVida: " << bagunceiro.getVidaSemestre( ) << " Escudo: ";
	// 	}	
	// };
	// cout << "\n---------------------------------\n";
	// bagunceiro.printHabilidades( );
	
	// bagunceiro.curarDanoNota( 20 );// curando o escudo >= 10
	// bagunceiro.curarDanoNota( 5 );// curando a vida <= 10 

	// bagunceiro.printHabilidades( );

	// bagunceiro.printCaracteristicasBagunceiro( bagunceiro );

	ProfessorEnsinoSuperior professorSuperior( "Psicologia Social", "Mestrado em Psicologia", "Universidade Federal de Brasilia", 8000 );

	ProfessorEnsinoMedio professorMedio( 40, "Joao da Silva Pereira", 25, 03, 1990, 4500 );
	ProfessorFisica professordeFisica( 2, 3, 1, 4 );

	cout << "\nProfessor do ensino medio\n";

	professorMedio.prepararAula( );
	professorMedio.relatorioDesempenho( estudioso );
	cout<< "Bonificacao de 10%: "<< professorMedio.getBonificacao( );

	cout << "\nProfessor do ensino superior\n";
	
	// cadastrando o planejamento dos professsores...
	professorSuperior.planoDeAulas( "1° Apresentação da matéria e discussão dos objetivos do curso" );
	professorSuperior.planoDeAulas( "2° Discussão sobre as expectativas e objetivos da disciplina " );
	
	
	professorSuperior.curriculoProfessor( "1° Dados Pessoais" );
	professorSuperior.curriculoProfessor( "2° Formação Acadêmica" );

	professorSuperior.participacaoComites( "1° Professor de Matemática Aplicada na Universidade Federal de Santa Catarina (2015-atual)" );
	professorSuperior.participacaoComites( "2° Professor de Matemática Aplicada na Universidade do Estado de Santa Catarina (2008-2015)" );

	professorSuperior.printPlanejamento( );
	cout<< "Bonificacao de 20%: "<< professorSuperior.getBonificacao( );

	cout << "\nProfessor do ensino medio: professor de fisica\n";
	professordeFisica.metodoAvaliativo( );
	
	cout << professordeFisica.getTipoProfessor( );

	professordeFisica.prepararAula( );
	professordeFisica.metodoAvaliativo( );


	professordeFisica.relatorioDesempenho( estudioso );

	return 0;

};