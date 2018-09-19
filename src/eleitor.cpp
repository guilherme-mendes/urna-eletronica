#include "eleitor.hpp"
#include <string>
#include <iostream>

using namespace std;

Eleitor::Eleitor() {   
    
    set_nome("");  
    set_nascimento("00/00/0000");
    set_titulo_eleitor("0000 0000 0000");
}

Eleitor::~Eleitor

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
