#ifndef URNA_HPP
#define URNA_HPP
#include <string>


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
        void clearBuff();
		int ReturnEleitores();
        void mesario();
        void cadastroEleitor();
        void confirmarVoto();
        void relatorio();
        void relatorio2();
        
        void GanhadorDepFederal();
        void GanhadorDepDistrital();
        void GanhadorSenador1();
        void GanhadorSenador2();
        void GanhadorGovernador();
        void GanhadorPresidente();
        
};

#endif