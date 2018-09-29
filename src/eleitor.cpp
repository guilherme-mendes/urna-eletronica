#include "../inc/eleitor.hpp"
#include <string>

using namespace std;

Eleitor::Eleitor() {
    
    nome = "VAZIO";
    titulo_eleitor = 0;
    cpf = 0;
    DepDis = "BRANCO";
    DepFed = "BRANCO";
    Govern = "BRANCO";
    GovernVice = "BRANCO";
    Senad = "BRANCO";
    Senad2 = "BRANCO";
    Suple1 = "BRANCO";
    Suple2 = "BRANCO";
    Suple3 = "BRANCO";
    Suple4 = "BRANCO";
    Presid = "BRANCO";
    PresidVice = "BRANCO";

}

Eleitor::~Eleitor() {}

string Eleitor::get_nome(){
    return nome;
}
void Eleitor::set_nome(string nome){
    this->nome = nome;
}
long int Eleitor::get_cpf(){
    return cpf;
}
void Eleitor::set_cpf(long int cpf){
    this->cpf = cpf;
}
long int Eleitor::get_titulo_eleitor(){
    return titulo_eleitor;
}
void Eleitor::set_titulo_eleitor(long int titulo_eleitor){
    this->titulo_eleitor = titulo_eleitor;
}
