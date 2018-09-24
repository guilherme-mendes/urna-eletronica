#include "../inc/urna.hpp"
#include "../inc/candidatos.hpp"
#include "../inc/eleitor.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;

Urna::Urna() {}
Urna::~Urna() {}

Eleitor eleitor[1238];
Candidatos cand_DF[1238];
Candidatos cand_BR[27];

void Urna::lerArquivo(){

    system("clear");
    
    int i;

    ifstream arquivo("./data/candidatos_DF.csv");
		
        if(!arquivo.is_open()){
		
            cout << "Não foi possível abrir o arquivo!" << endl;
		}
	
	for (i=0; i<= 1237; i++){
		
		getline(arquivo, cand_DF[i].NM_UE, ',');
		getline(arquivo, cand_DF[i].DS_CARGO, ',');
		getline(arquivo, cand_DF[i].NR_CANDIDATO, ',');
		getline(arquivo, cand_DF[i].NM_CANDIDATO, ',');
		getline(arquivo, cand_DF[i].NM_URNA_CANDIDATO, ',');
		getline(arquivo, cand_DF[i].NR_PARTIDO, ',');
		getline(arquivo, cand_DF[i].NM_PARTIDO, ',');
		getline(arquivo, cand_DF[i].DS_PARTIDO, '\n');

	}
 
	arquivo.close();

}

void Urna::lerArquivo2(){

    system("clear");
    
    int i;

    ifstream arquivo("./data/candidatos_BR.csv");
		
        if(!arquivo.is_open()){
		
            cout << "Não foi possível abrir o arquivo!" << endl;
		}
	
	for (i=0; i<= 26; i++){
		
		getline(arquivo, cand_BR[i].NM_UE, ',');
		getline(arquivo, cand_BR[i].DS_CARGO, ',');
		getline(arquivo, cand_BR[i].NR_CANDIDATO, ',');
		getline(arquivo, cand_BR[i].NM_CANDIDATO, ',');
		getline(arquivo, cand_BR[i].NM_URNA_CANDIDATO, ',');
		getline(arquivo, cand_BR[i].NR_PARTIDO, ',');
		getline(arquivo, cand_BR[i].NM_PARTIDO, ',');
		getline(arquivo, cand_BR[i].DS_PARTIDO, '\n');

	}
 
	arquivo.close();

}


void Urna::clearBuff(){

    fflush(stdin);
    fflush(stdin);
    fflush(stdin);
    fflush(stdin);
    cin.clear();
    setbuf(stdin, NULL);

}

void Urna::mesario(){

    cout << "DIGITE O Nº DE ELEITORES QUE VOTARÃO NESTA URNA: " << endl;
    cin >> eleitor[0].num_eleitores;

}

void Urna::cadastroEleitor(){

    system("clear");
    cout << "----------------CADASTRO DO ELEITOR-----------------" << endl << endl;

    cout << "DIGITE SEU NOME COMPLETO: " << endl;
    cin.ignore();
    getline(cin, eleitor[eleitor[0].counter_eleitor].nome);
    cout << endl;

    cout << "DIGITE O Nº DO SEU TITULO DE ELEITOR: " << endl;
    cin >> eleitor[eleitor[0].counter_eleitor].titulo_eleitor;
    cout << endl;
    
    cout << "DIGITE SUA DATA NASCIMENTO: [EX.: 26/06/1999]" << endl;
    cin.ignore();
    getline(cin, eleitor[eleitor[0].counter_eleitor].nascimento);

    eleitor[0].counter_eleitor++;
    cout << endl;
}

int Urna::ReturnEleitores(){
    return eleitor[0].num_eleitores;
}

void Urna::confirmarVoto(){
    char opcao;

        cout << "[1] - CONFIRMAR" << endl;
        cout << "[2] - CORRIGIR" << endl;
        cout << "[3] - BRANCO" << endl;
        cout << "[4] - CANCELAR" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "DIGITE A OPÇÃO DESEJADA: " << endl;

        clearBuff();    
        opcao = getchar();
        system("clear");

        if(opcao == '1'){
            cout << "----------------------------------------------------" << endl;
            cout << "VOTO COMPUTADO COM SUCESSO! " << endl;
            cout << "----------------------------------------------------" << endl;

            cand_DF[cand_DF[0].cand_analise].num_votos++;
        
            if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO FEDERAL"){
                eleitor[eleitor[0].counter_eleitor-1].VotoDF = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;   
            }

            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO DISTRITAL"){
                eleitor[eleitor[0].counter_eleitor-1].VotoDD = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO; 
            }
            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR"){
                eleitor[eleitor[0].counter_eleitor-1].VotoSen = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup1 = cand_DF[cand_DF[1].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup2 = cand_DF[cand_DF[2].cand_analise].NM_CANDIDATO;
            }
            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR"){
                eleitor[eleitor[0].counter_eleitor-1].VotoSen2 = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup3 = cand_DF[cand_DF[1].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup4 = cand_DF[cand_DF[2].cand_analise].NM_CANDIDATO;
            }
            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "GOVERNADOR"){
				eleitor[eleitor[0].counter_eleitor-1].VotoGov = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;
				eleitor[eleitor[0].counter_eleitor-1].VotoGovVice = cand_DF[cand_DF[1].cand_analise].NM_CANDIDATO;				
            }
            else if(cand_BR[cand_BR[0].cand_analise].DS_CARGO == "PRESIDENTE"){
				eleitor[eleitor[0].counter_eleitor-1].VotoPres = cand_BR[cand_BR[0].cand_analise].NM_CANDIDATO;
				eleitor[eleitor[0].counter_eleitor-1].VotoPresVice = cand_BR[cand_BR[1].cand_analise].NM_CANDIDATO;
            }
            else if(opcao == '2'){
                cout << "PASSO CANCELADO !" << endl;
                    
                    if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO FEDERAL" ){
                        VotoDeputadoFederal();
                    }
                    
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO FEDERAL" ){
                        VotoDeputadoDistrital();							
                    }
        
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "PRIMEIRO SUPLENTE"  || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SEGUNDO SUPLENTE" ){
                        VotoSenador();
                    }
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "PRIMEIRO SUPLENTE"  || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SEGUNDO SUPLENTE" ){
                        VotoSenador2();
                    }
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "GOVERNADOR" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "VICE-GOVERNADOR"){
                        VotoGovernador();
                    }
                    else if(cand_BR[cand_BR[0].cand_analise].DS_CARGO == "PRESIDENTE" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "VICE-PRESIDENTE"){
                        VotoPresidente();
                    }

                }
            }
}      

void Urna::VotoDeputadoFederal(){
    system("clear");
    int aux = 0;
    string num_federal;

    do{
        cout << "DIGITE O Nº DO SEU DEPUTADO FEDERAL: " << endl;

        do{
            clearBuff();
            cin >> num_federal;
            system("clear");

            if(num_federal.size()!=4){
                cout << "INSIRA APENAS 4 DÍGITOS!" << endl;
            }
        }while(num_federal.size()!=4);
        
        for(int i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_federal){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl << endl;
			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[0].cand_analise = i;

            }
        }
        if(aux == 1){
            confirmarVoto();
        }

        else if(aux == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }

    }while(aux == 0);

}

void Urna::VotoDeputadoDistrital(){
    int aux = 0;
    string num_distrital;

    do{
        cout << "DIGITE O Nº DO SEU DEPUTADO DISTRITAL: " << endl;
        
        do{
            clearBuff();
            cin >> num_distrital;
            system("clear");

            if(num_distrital.size()!=5){
                cout << "INSIRA APENAS 5 DÍGITOS!" << endl;
            }
        }while(num_distrital.size()!=5);
        
        for(int i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_distrital){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl << endl;
			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[0].cand_analise = i;

            }
        }

        if(aux == 1){
            confirmarVoto();
        }

        else if(aux == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }
    
        while(aux == 0);
}

void Urna::VotoSenador(){
    int aux = 0;
    string num_senador;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU SENADOR - 1ª VAGA: " << endl;
        
        do{
            clearBuff();
            cin >> num_senador;
            
            if(num_senador.size()!=3){
                cout << "INSIRA APENAS 3 DÍGITOS!" << endl;
            }
        }while(num_senador.size()!=3);
        
        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_senador && cand_DF[i].DS_CARGO == "SENADOR"){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl << endl;
			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[0].cand_analise = i;

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_senador && cand_DF[i].DS_CARGO == "PRIMEIRO SUPLENTE"){
                aux = 1;

			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[1].cand_analise = i;

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_senador && cand_DF[i].DS_CARGO == "SEGUNDO SUPLENTE"){
                aux = 1;

			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[2].cand_analise = i;

            }
        }   

        if(aux == 1){
            confirmarVoto();
        }

        else if(aux == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }
    
    while(aux == 0);
}

void Urna::VotoSenador2(){
    int aux = 0;
    string num_senador2;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU SENADOR - 2ª VAGA: " << endl;
        
        do{
            clearBuff();
            cin >> num_senador2;
            
            if(num_senador2.size()!=3){
                cout << "INSIRA APENAS 3 DÍGITOS!" << endl;
            }
        }while(num_senador2.size()!=3);
        
        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_senador2 && cand_DF[i].DS_CARGO == "SENADOR"){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl << endl;
			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[i].cand_analise = i;

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_senador2 && cand_DF[i].DS_CARGO == "PRIMEIRO SUPLENTE"){
                aux = 1;

			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[i].cand_analise = i;

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_senador2 && cand_DF[i].DS_CARGO == "SEGUNDO SUPLENTE"){
                aux = 1;

			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[i].cand_analise = i;

            }
        }   

        if(aux == 1){
            confirmarVoto();
        }

        else if(aux == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }
    
    while(aux == 0);
}
void Urna::VotoGovernador(){
    int aux = 0;
    string num_governador;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU GOVERNADOR: " << endl;
        
        do{
            clearBuff();
            cin >> num_governador;
            
            if(num_governador.size()!=2){
                cout << "INSIRA APENAS 2 DÍGITOS!" << endl;
            }
        }while(num_governador.size()!=2);
        
        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_governador && cand_DF[i].DS_CARGO == "GOVERNADOR"){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl << endl;
			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[0].cand_analise = i;

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_governador && cand_DF[i].DS_CARGO == "VICE-GOVERNADOR"){
                aux = 1;

			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_DF[1].cand_analise = i;

            }
        }   

        if(aux == 1){
            confirmarVoto();
        }

        else if(aux == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }
    
    while(aux == 0);
}

void Urna::VotoPresidente(){
    int aux = 0;
    string num_presidente;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU PRESIDENTE: " << endl;
        
        do{
            clearBuff();
            cin >> num_presidente;
            
            if(num_presidente.size()!=2){
                cout << "INSIRA APENAS 2 DÍGITOS!" << endl;
            }
        }while(num_presidente.size()!=2);
        
        for(i = 0; i <= 26; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_presidente && cand_BR[i].DS_CARGO == "PRESIDENTE"){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl << endl;
			cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
			cout << "Região: " << cand_BR[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_BR[0].cand_analise = i;

            }

        }

        for(i = 0; i <= 26; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_presidente && cand_BR[i].DS_CARGO == "VICE-PRESIDENTE"){
                aux = 1;

			cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
			cout << "Região: " << cand_BR[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
			cout << "----------------------------------------------------" << endl;

            cand_BR[1].cand_analise = i;

            }
        }   

        if(aux == 1){
            confirmarVoto();
        }

        else if(aux == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }
    
    while(aux == 0);
}

void Urna::relatorio(){
    for(int i = 0; i < eleitor[0].num_eleitores; i++){
        cout << endl;
        cout << "-----------------RELATÓRIO DE VOTOS-----------------" << endl << endl;
        cout << "NOME: " << eleitor[i].nome << endl;
		cout << "TÍTULO DE ELEITOR: " << eleitor[i].titulo_eleitor << endl;
        cout << "DATA DE NASCIMENTO: " << eleitor[i].nascimento << endl << endl;

		cout << "DEPUTADO FEDERAL: " << eleitor[i].VotoDF << endl;
		cout << "DEPUTADO DISTRITAL: " << eleitor[i].VotoDD << endl << endl;

		cout << "SENADOR - 1ª VAGA: " << eleitor[i].VotoSen << endl;
        cout << "- 1º SUPLENTE: " << eleitor[i].VotoSup1 << endl;
        cout << "- 2º SUPLENTE: " << eleitor[i].VotoSup2 << endl << endl;

        cout << "SENADOR - 2ª VAGA: " << eleitor[3].VotoSen2 << endl;
        cout << "- 1º SUPLENTE: " << eleitor[i].VotoSup3 << endl;
        cout << "- 2º SUPLENTE: " << eleitor[i].VotoSup4 << endl << endl;

        cout << "GOVERNADOR: " << eleitor[i].VotoGov << endl;
        cout << "- VICE: " << eleitor[i].VotoGovVice << endl << endl;
        
        cout << "PRESIDENTE: " << eleitor[i].VotoPres << endl;
        cout << "- VICE: " << eleitor[i].VotoPresVice << endl << endl;
	}
}

void Urna::Ganhador(){

int i;

int maior = 0;
string GanhadorDF; // Ganhador p/ Deputado Federal

	for(i=0;i<=1237;i++){

			if(cand_DF[i].DS_CARGO == "DEPUTADO FEDERAL" ){

					if(cand_DF[i].num_votos > maior ){

						maior = cand_DF[i].num_votos;
						GanhadorDF = cand_DF[i].NM_CANDIDATO;
					}
			}
	}

cout << "---------------CANDIDATOS VENCEDORES---------------" << endl << endl;
cout << "DEPUTADO FEDERAL: " << GanhadorDF << endl;


}

