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
        string presidente, governador, senador_1, senador_2, federal, distrital;
        
    public:
        Eleitor();
        ~Eleitor();
        string get_nome();
	    void set_nome(string nome); 
        string get_nascimento();
        void set_nascimento(string nascimento);
        long int get_titulo_eleitor();
        void set_titulo_eleitor(long int titulo_eleitor);
        
        string get_presidente();
	    void set_presidente(string presidente); 
        string get_governador();
	    void set_governador(string governador); 
        string get_senador_1();
	    void set_senador_1(string senador_1); 
        string get_senador_2();
	    void set_senador_2(string senador_2); 
        string get_federal();
	    void set_federal(string federal); 
        string get_distrital();
	    void set_distrital(string distrital); 
        

};

#endif