#include "candidatos.hpp"

Candidatos::Candidatos(){
    
    votos = 0;
    NM_UE = "";
    DS_CARGO = "";
    NR_CANDIDATO = "00000";
    NM_URNA_CANDIDATO = "";
    NM_PARTIDO = "";
    NR_CPF_CANDIDATO = "00000000000";
    NM_EMAIL = "";

}
Candidatos::~Candidatos(){}

votos = 0;

string Candidatos::get_NM_UE(){
    return NM_UE;
}
void Candidatos::set_NM_UE(string NM_UE){
    this->NM_UE = NM_UE;
}
string Candidatos::get_DS_CARGO(){
    return NM_UE;
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
string Candidatos::get_NM_URNA_CANDIDATO(){
    return NM_URNA_CANDIDATO;
}
void Candidatos::set_NM_URNA_CANDIDATO(string NM_URNA_CANDIDATO){
    this->NM_URNA_CANDIDATO = NM_URNA_CANDIDATO;
}
string Candidatos::get_NM_PARTIDO(){
    return NM_PARTIDO;
}
void Candidatos::set_NM_PARTIDO(string NM_PARTIDO){
    this->NM_PARTIDO = NM_PARTIDO;
}
string Candidatos::get_NR_CPF_CANDIDATO(){
    return NR_CPF_CANDIDATO;
}
void Candidatos::set_NR_CPF_CANDIDATO(string NR_CPF_CANDIDATO){
    this->NR_CPF_CANDIDATO = NR_CPF_CANDIDATO;
}
string Candidatos::get_NM_EMAIL(){
    return NM_EMAIL;
}
void Candidatos::set_NM_EMAIL(string NM_EMAIL){
    this->NM_EMAIL = NM_EMAIL;
void Candidatos::adicionar_votos()
{
    votos++;    
}
int Candidatos::get_votos()
{
    return votos;    
}
