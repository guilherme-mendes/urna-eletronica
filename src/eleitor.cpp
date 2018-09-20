#include "../inc/eleitor.hpp"
#include <string>
#include <iostream>

using namespace std;

Eleitor::Eleitor() {}

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

string Eleitor::get_presidente(){
    return presidente;
}
void Eleitor::set_presidente(string presidente){
    this->presidente = presidente;
}
string Eleitor::get_governador(){
    return governador;
}
void Eleitor::set_governador(string governador){
    this->governador = governador;
}
string Eleitor::get_senador_1(){
    return senador_1;
}
void Eleitor::set_senador_1(string senador_1){
    this->senador_1 = senador_1;
}
string Eleitor::get_senador_2(){
    return senador_2;
}
void Eleitor::set_senador_2(string senador_2){
    this->senador_2 = senador_2;
}
string Eleitor::get_federal(){
    return federal;
}
void Eleitor::set_federal(string federal){
    this->federal = federal;
}
string Eleitor::get_distrital(){
    return distrital;
}
void Eleitor::set_distrital(string distrital){
    this->distrital = distrital;
}
