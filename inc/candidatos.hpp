#ifndef CANDIDATOS_HPP
#define CANDIDATOS_HPP
#include <string>
#define MAX 1365


using namespace std;

class Candidatos {
    private:
        
    public:
        Candidatos();
        ~Candidatos();

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
        void relatorio2();
        
        void GanhadorDepFederal();
        void GanhadorDepDistrital();
        void GanhadorSenador1();
        void GanhadorSenador2();
        void GanhadorGovernador();
        void GanhadorPresidente();
        
};

#endif