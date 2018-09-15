#ifndef CANDIDATOS_HPP
#define CANDIDATOS_HPP
#include <string>

using namespace std; 

class Candidatos {

	private:
		string NM_UE;
		string DS_CARGO;
		string NR_CANDIDATO;
        string NM_URNA_CANDIDATO;
        string NM_PARTIDO;
        string NR_CPF_CANDIDATO;
        string NM_EMAIL;
	public:
		Candidatos();
		~Candidatos();
		string get_NM_UE();
		void set_NM_UE(string NM_UE);
        string get_DS_CARGO();
		void set_DS_CARGO(string DS_CARGO);
        string get_NR_CANDIDATO();
		void set_NR_CANDIDATO(string NR_CANDIDATO);
        string get_NM_URNA_CANDIDATO();
		void set_NM_URNA_CANDIDATO(string NM_URNA_CANDIDATO);
        string get_NM_PARTIDO();
		void set_NM_PARTIDO(string NM_PARTIDO);
        string get_NR_CPF_CANDIDATO();
		void set_NR_CPF_CANDIDATO(string NR_CPF_CANDIDATO); 
        string get_NM_EMAIL();
		void set_NM_EMAIL(string NM_EMAIL);
		
};

#endif