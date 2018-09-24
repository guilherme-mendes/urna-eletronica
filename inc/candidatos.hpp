#ifndef CANDIDATOS_HPP
#define CANDIDATOS_HPP
#include <string>

using namespace std; 

class Candidatos {
	private:	
		
		
	public:
		Candidatos();
		~Candidatos();
		
		string NM_UE;
		string DS_CARGO;
		string NR_CANDIDATO;
		string NM_CANDIDATO;
        string NM_URNA_CANDIDATO;
		string NR_PARTIDO;        
		string NM_PARTIDO;
        string DS_PARTIDO;

		int max_eleitores;
		int num_votos;
		int cand_analise;

		string get_NM_UE();
		void set_NM_UE(string NM_UE);
        string get_DS_CARGO();
		void set_DS_CARGO(string DS_CARGO);
        string get_NR_CANDIDATO();
		void set_NR_CANDIDATO(string NR_CANDIDATO);
		string get_NM_CANDIDATO();
		void set_NM_CANDIDATO(string NM_CANDIDATO);
        string get_NM_URNA_CANDIDATO();
		void set_NM_URNA_CANDIDATO(string NM_URNA_CANDIDATO);
		string get_NR_PARTIDO();
		void set_NR_PARTIDO(string NR_PARTIDO);
        string get_NM_PARTIDO();
		void set_NM_PARTIDO(string NM_PARTIDO);
        string get_DS_PARTIDO();
		void set_DS_PARTIDO(string DS_PARTIDO);
		void set_max_eleitores(int max_eleitores);
};

#endif
