#ifndef ELEITOR_HPP
#define ELEITOR_HPP
#include <iostream>
#include <string>

using namespace std;

class Eleitor {
    private:
        
        
    public:
        Eleitor();
        ~Eleitor();

        string nome;
        string nascimento;
        long int titulo_eleitor;
        string VotoDF, VotoDD, VotoSen, VotoSup1, VotoSup2,VotoGov, VotoPres;
        int num_eleitores;
        int counter_eleitor;

        string get_nome();
	    void set_nome(string nome); 
        string get_nascimento();
        void set_nascimento(string nascimento);
        long int get_titulo_eleitor();
        void set_titulo_eleitor(long int titulo_eleitor);
    
};

#endif