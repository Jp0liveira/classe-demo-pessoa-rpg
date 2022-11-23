#pragma once
// habilidades dos alunos :)

class Habilidades{
	public:
		// construtores
		Habilidades( ); 
		Habilidades( float, float, float = 100.0 ); 
		Habilidades( const Habilidades & ); 
		~Habilidades( ); 

		// set & get
		void setEscudoNota( float );
		void setDanoNota( float );
		void setVidaSemestre( float );

		float getEscudoNota( ) { return escudoNota; }
		float getDanoNota( ) { return danoNota; }
		float getVidaSemestre( ) { return vidaSemestre; }
		
		// habilidades
		void receberDanoNota( );
		void curarDanoNota( float = 10 );
		
		// exibir 
		void printHabilidades( );

		// void bonusNotaAluno( float );
		// void momentoRaiva( );

	private:
		// atributos
		float escudoNota, danoNota, vidaSemestre;
		bool fadiga = false;
		
		// const
		const int VIDASEMESTREMAXIMO;
		const int ESCUDONOTAMAXIMO;
		const int ESCUDONOTAMINIMO;

};