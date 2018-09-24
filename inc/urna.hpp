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
        void VotoSenador2();
        void VotoGovernador();
        void VotoPresidente();
       
        void lerArquivo();
        void lerArquivo2();
        int ReturnEleitores();
        void mesario();
        void cadastroEleitor();
        void confirmarVoto();
        void relatorio();
        void clearBuff();
        void Ganhador();
        

};

#endif