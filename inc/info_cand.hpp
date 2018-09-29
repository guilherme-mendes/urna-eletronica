#ifndef INFO_CAND_HPP
#define INFO_CAND_HPP
#include <string>

using namespace std; 

class Info_cand {
	private:	
		
	public:
		Info_cand();
		~Info_cand();
		
		string NM_UE;
		string DS_CARGO;
		string NR_CANDIDATO;
		string NM_CANDIDATO;
        string NM_URNA_CANDIDATO;
		string NR_PARTIDO;        
		string NM_PARTIDO;
        string DS_PARTIDO;
		int num_votos = 0;
		int posicao = 0;

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
		
};

#endif
