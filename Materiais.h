#pragma once
#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::vector;


struct Materiais{
	int numeroMateriais = 0;
	vector < string * > materiais;
	
	void cadastrarMateriais( const string &novoMaterial ) {
		if( materiais.size( ) < numeroMateriais ) {
			materiais.push_back( new string( novoMaterial ) );        
			return;
		}
		cout << "Nao eh possivel cadastrar " << novoMaterial << '.' << " numero maximo de materiais.\n";
	};
	
	void printListaMateriais( ) const {
	cout << "\n-------------- MATERIAIS --------------\n";
		for( int i = 0; i < materiais.size( ); i++ ){
			cout << materiais[ i ] << " |\t" << *materiais[ i ] << "\n";
		}
		cout << "---------------------------------------\n";
	};

};
