#ifndef ELEITOR_HPP
#define ELEITOR_HPP
#include <iostream>
#include <string>

using namespace std;

class Eleitor {
    private:
        string nome;
    public:
        Eleitor();
        ~Eleitor();
        string get_nome();
	    void set_nome(string nome);     
};

#endif