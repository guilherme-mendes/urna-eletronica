#include "../inc/candidatos.hpp"
#include "../inc/eleitor.hpp"
#include "../inc/urna.hpp"
#include <iostream>
#include <string>

Candidatos::Candidatos(){
    
    NM_UE = "";
    DS_CARGO = "VAZIO";
    NM_CANDIDATO = "";
    NR_CANDIDATO = "";
    NM_URNA_CANDIDATO = "";
    NR_PARTIDO = "";
    DS_PARTIDO = "";
    posicao = 0;
    num_votos = 0;
    
}

Candidatos::~Candidatos(){}

string Candidatos::get_NM_UE(){
    return NM_UE;
}
void Candidatos::set_NM_UE(string NM_UE){
    this->NM_UE = NM_UE;
}
string Candidatos::get_DS_CARGO(){
    return DS_CARGO;
}
void Candidatos::set_DS_CARGO(string DS_CARGO){
    this->DS_CARGO = DS_CARGO;
}
string Candidatos::get_NR_CANDIDATO(){
    return NR_CANDIDATO;
}
void Candidatos::set_NR_CANDIDATO(string NR_CANDIDATO){
    this->NR_CANDIDATO = NR_CANDIDATO;
}
string Candidatos::get_NM_CANDIDATO(){
    return NM_CANDIDATO;
}
void Candidatos::set_NM_CANDIDATO(string NM_CANDIDATO){
    this->NM_CANDIDATO = NM_CANDIDATO;
}
string Candidatos::get_NM_URNA_CANDIDATO(){
    return NM_URNA_CANDIDATO;
}
void Candidatos::set_NM_URNA_CANDIDATO(string NM_URNA_CANDIDATO){
    this->NM_URNA_CANDIDATO = NM_URNA_CANDIDATO;
}
string Candidatos::get_NR_PARTIDO(){
    return NR_PARTIDO;
}
void Candidatos::set_NR_PARTIDO(string NR_PARTIDO){
    this->NR_PARTIDO = NR_PARTIDO;
}
string Candidatos::get_NM_PARTIDO(){
    return NM_PARTIDO;
}
void Candidatos::set_NM_PARTIDO(string NM_PARTIDO){
    this->NM_PARTIDO = NM_PARTIDO;
}
string Candidatos::get_DS_PARTIDO(){
    return DS_PARTIDO;
}
void Candidatos::set_DS_PARTIDO(string DS_PARTIDO){
    this->DS_PARTIDO = DS_PARTIDO;
}


