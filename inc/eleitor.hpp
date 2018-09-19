#ifndef ELEITOR_HPP
#define ELEITOR_HPP
#include <iostream>
#include <string>

using namespace std;

class Eleitor {
    private:
        string nome;
        string nascimento;
        long int titulo_eleitor;
        
    public:
        Eleitor();
        ~Eleitor();
        string get_nome();
	    void set_nome(string nome); 
        string get_nascimento();
        void set_nascimento(string nascimento);
        long int get_titulo_eleitor();
        void set_titulo_eleitor(long int titulo_eleitor);
        
};

#endif