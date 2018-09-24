#ifndef URNA_HPP
#define URNA_HPP
#include <string>
#include <iostream>


using namespace std;

class Urna {
    private:
        
    public:
        Urna();
        ~Urna();

        void VotoDeputadoFederal();
        void VotoDeputadoDistrital();
        void VotoSenador();
        void VotoGovernador();
        void VotoPresidente();
       
        void lerArquivo();
        int ReturnEleitores();
        void mesario();
        void cadastroEleitor();
        void confirmarVoto();
        void relatorio();
        void clearBuff();
        void Ganhador();
        

};

#endif