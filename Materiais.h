#pragma once
#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <ctime>
using std::ctime;

struct Materiais{
	vector < string * > materiais;
	int numMateriais = 0;
	
	// funcao para cadastrar um novo material
	void cadastrarMateriais( const string &novoMaterial ) {
		if  ( materiais.size( ) < numMateriais){
			materiais.push_back( new string( novoMaterial ) );        
			return;
		}else{
			cout << "Nao e possivel cadastrar " << novoMaterial << '.' << " numero maximo de materiais.\n";
		}
	};
	
	// funcao para exibir os materiais
	void printListaMateriais( ) const {
	cout << "\n-------------- MATERIAIS --------------\n";
		for( int i = 0; i < materiais.size( ); i++ ){
			cout << materiais[ i ] << " |\t" << *materiais[ i ] << "\n";
		}
		cout << "---------------------------------------\n";
	};

	//funcao para calcular o ano atual
	int calcularAnoAtual( int anoParaTeste ){
		time_t t = time( nullptr );
		tm* dataAtual = localtime( &t );
    	return ( dataAtual -> tm_year + 1900) - anoParaTeste;
	};
	
};
