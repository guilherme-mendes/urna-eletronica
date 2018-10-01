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
        long int cpf;
        long int titulo_eleitor;
        int num_eleitores = 0;
        int contador = 0; // CONTADOR DE ELEITORES

        string DepFed, DepDis, Senad, Senad2; 
        string Suple1, Suple2, Suple3, Suple4; // SUPLENTES DOS SENADORES 
        string Govern, GovernVice, Presid, PresidVice;
        
        string get_nome();
	    void set_nome(string nome); 
        long int get_cpf();
        void set_cpf(long int cpf);
        long int get_titulo_eleitor();
        void set_titulo_eleitor(long int titulo_eleitor);
        
};

#endif