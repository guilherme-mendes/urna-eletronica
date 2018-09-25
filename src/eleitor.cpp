#include "../inc/eleitor.hpp"
#include <string>

using namespace std;

Eleitor::Eleitor() {
    nome = "VAZIO";
    cpf = "VAZIO";
    titulo_eleitor = 0;
    VotoDD = "BRANCO";
    VotoDF = "BRANCO";
    VotoGov = "BRANCO";
    VotoGovVice = "BRANCO";
    VotoSen = "BRANCO";
    VotoSup1 = "BRANCO";
    VotoSup2 = "BRANCO";
    VotoSen2 = "BRANCO";
    VotoSup3 = "BRANCO";
    VotoSup4 = "BRANCO";
    VotoPres = "BRANCO";
    VotoPresVice = "BRANCO";

}

Eleitor::~Eleitor() {}

string Eleitor::get_nome(){
    return nome;
}
void Eleitor::set_nome(string nome){
    this->nome = nome;
}
string Eleitor::get_cpf(){
    return cpf;
}
void Eleitor::set_cpf(string cpf){
    this->cpf = cpf;
}
long int Eleitor::get_titulo_eleitor(){
    return titulo_eleitor;
}
void Eleitor::set_titulo_eleitor(long int titulo_eleitor){
    this->titulo_eleitor = titulo_eleitor;
}

