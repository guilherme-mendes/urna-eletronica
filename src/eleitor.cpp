#include "../inc/eleitor.hpp"
#include <string>
#include <iostream>

using namespace std;

Eleitor::Eleitor() {
    nome = "VAZIO";
    nascimento = "";
    titulo_eleitor = 0;
    VotoDD = "NULL";
    VotoDF = "NULL";
    VotoGov = "NULL";
    VotoSen = "NULL";
    VotoSen2 = "NULL";
    VotoPres = "NULL";

}

Eleitor::~Eleitor() {}

string Eleitor::get_nome(){
    return nome;
}
void Eleitor::set_nome(string nome){
    this->nome = nome;
}
string Eleitor::get_nascimento(){
    return nascimento;
}
void Eleitor::set_nascimento(string nascimento){
    this->nascimento = nascimento;
}
long int Eleitor::get_titulo_eleitor(){
    return titulo_eleitor;
}
void Eleitor::set_titulo_eleitor(long int titulo_eleitor){
    this->titulo_eleitor = titulo_eleitor;
}

