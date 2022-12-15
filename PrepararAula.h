#pragma once
#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::vector;

struct PrepararAula{
    vector < string * > temasAula;
    vector < string * > materiaisApoio;
    int numMaximoTemas = 0;
    int numMaximoMateriais = 0;

    // funcao para cadastrar um novo tema
	void cadastrarTemasAula( const string &novoMaterial ) {
		if  ( temasAula.size( ) < numMaximoTemas ){
			temasAula.push_back( new string( novoMaterial ) );        
			return;
		}else{
			cout << "Nao e possivel cadastrar " << novoMaterial << '.' << " numero maximo de temasAula.\n";
		}
	};

    // funcao para exibir os temas
    void printTemasAula( ) const {
	cout << "\n-------------- TEMAS DE UM PROFESSOR --------------\n";
    for( int i = 0; i < temasAula.size( ); i++ ){
        cout << temasAula[ i ] << " |\t" << *temasAula[ i ] << "\n";
    }
    cout << "---------------------------------------\n";
	};

    // funcao para cadastrar os materiais de apoio
	void cadastrarMateriaisAula( const string &novoMaterial ) {
		if  ( materiaisApoio.size( ) < numMaximoMateriais ){
			materiaisApoio.push_back( new string( novoMaterial ) );        
			return;
		}else{
			cout << "Nao e possivel cadastrar " << novoMaterial << '.' << " numero maximo de temasAula.\n";
		}
	};

    // funcao para exibir os temas
    void printMateriaisAula( ) const {
	cout << "\n-------------- MATERIAIS DE APOIO --------------\n";
    for( int i = 0; i < materiaisApoio.size( ); i++ ){
        cout << materiaisApoio[ i ] << " |\t" << *materiaisApoio[ i ] << "\n";
    }
    cout << "---------------------------------------\n";
	};

};
