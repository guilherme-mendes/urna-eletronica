#include "eleitor.hpp"
#include <string>
#include <iostream>

using namespace std;

Eleitor::Eleitor() {   
    
    set_nome("");   
}

Eleitor::~Eleitor

string Eleitor::get_nome(){
    return nome;
}
void Eleitor::set_nome(string nome){
    this->nome = nome;
}