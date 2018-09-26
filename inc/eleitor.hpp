#ifndef ELEITOR_HPP
#define ELEITOR_HPP
#include <string>

using namespace std;

class Eleitor {
    private:     
        
    public:
        Eleitor();
        ~Eleitor();

        string nome;
        string cpf;
        long int titulo_eleitor;
        string VotoDF, VotoDD, VotoSen, VotoSen2; 
        string VotoSup1, VotoSup2, VotoSup3, VotoSup4; // Suplentes dos Senadores 
        string VotoGov, VotoGovVice, VotoPres, VotoPresVice;
        int num_eleitores = 0;
        int contador = 0; //  Contador de eleitores 

        string get_nome();
	    void set_nome(string nome); 
        string get_cpf();
        void set_cpf(string cpf);
        long int get_titulo_eleitor();
        void set_titulo_eleitor(long int titulo_eleitor);
        
};

#endif