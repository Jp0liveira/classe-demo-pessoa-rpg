#pragma once
// habilidades dos alunos :)

class Habilidades{
	public:
		
		Habilidades( ); 
		Habilidades( float, float, float = 100.0 ); 
		Habilidades( const Habilidades & ); 
		~Habilidades( ); 

		void setEscudoNota( float );
		void setDanoNota( float );
		void setVidaSemestre( float );

		void receberDanoNota( );
		void curarDanoNota( float = 10 );
		// void bonusNotaAluno( float );
		// void momentoRaiva( );

		float getEscudoNota( ) { return escudoNota; }// problemas ao colocar o get assim ? 
		float getDanoNota( ) { return danoNota; }
		float getVidaSemestre( ) { return vidaSemestre; }

		

	private:
		float escudoNota, danoNota, vidaSemestre;
		bool fadiga = false;

		const int VIDASEMESTREMAXIMO;
		const int ESCUDONOTAMAXIMO;
		const int ESCUDONOTAMINIMO;

};