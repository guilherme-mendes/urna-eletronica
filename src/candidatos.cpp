#include "../inc/info_cand.hpp"
#include "../inc/candidatos.hpp"
#include "../inc/eleitor.hpp"
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

Candidatos::Candidatos(){}
Candidatos::~Candidatos(){}

Eleitor eleitor[1265];
Info_cand cand_BR[1265];

// FUNCIONALIDADES DA URNA ELETRONICA

void Candidatos::mesario(){ 

    cout << "DIGITE O Nº DE ELEITORES QUE VOTARÃO NESTA URNA: " << endl;
    cin >> eleitor[0].num_eleitores;
}

void Candidatos::cadastroEleitor(){

    system("clear");
    cout << "----------------CADASTRO DO ELEITOR-----------------" << endl << endl;

    cout << "DIGITE SEU NOME COMPLETO: " << endl;
    cin.ignore();
    getline(cin, eleitor[eleitor[0].contador].nome);
    cout << endl;

    cout << "DIGITE O Nº DO SEU TITULO DE ELEITOR: " << endl;
    cin >> eleitor[eleitor[0].contador].titulo_eleitor;
    cout << endl;
    
    cout << "DIGITE SEU CPF: " << endl;
    cin.ignore();
    cin >> eleitor[eleitor[0].contador].cpf;
    cout << endl;

    eleitor[0].contador++;
    cout << endl;
    system("clear");
}

void Candidatos::lerArquivo(){

    system("clear");
    
    int i;

    ifstream arquivo("./data/candidatos_DF.csv");
		
        if(!arquivo.is_open()){
		
            cout << "Não foi possível abrir o arquivo!" << endl;
		}
	
	for (i=0; i<= 1237; i++){
		
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

void Candidatos::lerArquivo2(){

    system("clear");
    
    int i;

    ifstream arquivo("./data/candidatos_BR.csv");
		
        if(!arquivo.is_open()){
		
            cout << "Não foi possível abrir o arquivo!" << endl;
		}
	
	for (i=1238; i<= 1265; i++){
		
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

void Candidatos::VotoDeputadoFederal(){
    
    int assist = 0;
    
    string num_federal;

    do{
        cout << "DIGITE O Nº DO SEU DEPUTADO FEDERAL: " << endl;

        do{
            fflush(stdin);
            cin.clear();
            setbuf(stdin, NULL);

            cin >> num_federal;
            system("clear");

            if(num_federal.size()!=4){
                cout << "INSIRA APENAS 4 DÍGITOS!" << endl;
            }
        }while(num_federal.size()!=4);
        
        for(int i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_federal){
                assist = 1;

                cand_BR[0].posicao = i;

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

            }
        }
        if(assist == 1){
            confirmarVoto();
        }

        else if(assist == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }
        while(assist == 0);
}

void Candidatos::VotoDeputadoDistrital(){
    int assist = 0;
    string num_distrital;

    do{
        cout << "DIGITE O Nº DO SEU DEPUTADO DISTRITAL: " << endl;
        
        do{
            fflush(stdin);
            cin.clear();
            setbuf(stdin, NULL);

            cin >> num_distrital;
            system("clear");

            if(num_distrital.size()!=5){
                cout << "INSIRA APENAS 5 DÍGITOS!" << endl;
            }
        }while(num_distrital.size()!=5);
        
        for(int i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_distrital){
                assist = 1;
                cand_BR[0].posicao = i;

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

            }
        }

        if(assist == 1){
            confirmarVoto();
        }

        else if(assist == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }    
        while(assist == 0);
}

void Candidatos::VotoSenador(){
    int assist = 0;
    string num_senador;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU SENADOR - 1ª VAGA: " << endl;
        
        do{
            fflush(stdin);
            cin.clear();
            setbuf(stdin, NULL);

            cin >> num_senador;
            
            if(num_senador.size()!=3){
                cout << "INSIRA APENAS 3 DÍGITOS!" << endl;
            }
        }while(num_senador.size()!=3);
        
        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_senador && cand_BR[i].DS_CARGO == "SENADOR"){
                assist = 1;
                
                cand_BR[0].posicao = i;
                cand_BR[3].posicao = 1;

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
                
            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_senador && cand_BR[i].DS_CARGO == "PRIMEIRO SUPLENTE"){
                assist = 1;
                cand_BR[1].posicao = i;

                cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
                cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
                cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
                cout << "Região: " << cand_BR[i].NM_UE << endl;
                cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
                cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
                cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
                cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
                cout << "----------------------------------------------------" << endl;

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_senador && cand_BR[i].DS_CARGO == "SEGUNDO SUPLENTE"){
                assist = 1;
                cand_BR[2].posicao = i;

                cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
                cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
                cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
                cout << "Região: " << cand_BR[i].NM_UE << endl;
                cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
                cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
                cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
                cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
                cout << "----------------------------------------------------" << endl;

            }
        }   

        if(assist == 1){
            confirmarVoto();
        }

        else if(assist == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }  
        while(assist == 0);
}

void Candidatos::VotoSenador2(){
    int assist = 0;
    string num_senador2;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU SENADOR - 2ª VAGA: " << endl;
        
        do{
            fflush(stdin);
            cin.clear();
            setbuf(stdin, NULL);

            cin >> num_senador2;
            
            if(num_senador2.size()!=3){
                cout << "INSIRA APENAS 3 DÍGITOS!" << endl;
            }
        }while(num_senador2.size()!=3);
        
        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_senador2 && cand_BR[i].DS_CARGO == "SENADOR"){
                assist = 1;

                cand_BR[0].posicao = i;
                cand_BR[3].posicao = 2;

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

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_senador2 && cand_BR[i].DS_CARGO == "PRIMEIRO SUPLENTE"){
                assist = 1;
                cand_BR[1].posicao = i;

                cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
                cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
                cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
                cout << "Região: " << cand_BR[i].NM_UE << endl;
                cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
                cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
                cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
                cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
                cout << "----------------------------------------------------" << endl;

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_senador2 && cand_BR[i].DS_CARGO == "SEGUNDO SUPLENTE"){
                assist = 1;
                cand_BR[2].posicao = i;

                cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
                cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
                cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
                cout << "Região: " << cand_BR[i].NM_UE << endl;
                cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
                cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
                cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
                cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
                cout << "----------------------------------------------------" << endl;

            }
        }   

        if(assist == 1){
            confirmarVoto();
        }

        else if(assist == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    } 
        while(assist == 0);
}

void Candidatos::VotoGovernador(){
    int assist = 0;
    string num_governador;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU GOVERNADOR: " << endl;
        
        do{
            fflush(stdin);
            cin.clear();
            setbuf(stdin, NULL);

            cin >> num_governador;
            
            if(num_governador.size()!=2){
                cout << "INSIRA APENAS 2 DÍGITOS!" << endl;
            }
        }while(num_governador.size()!=2);
        
        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_governador && cand_BR[i].DS_CARGO == "GOVERNADOR"){
                assist = 1;
                cand_BR[0].posicao = i;

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

            }

        }

        for(i = 0; i <= 1237; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_governador && cand_BR[i].DS_CARGO == "VICE-GOVERNADOR"){
                assist = 1;
                cand_BR[1].posicao = i;

                cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
                cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
                cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
                cout << "Região: " << cand_BR[i].NM_UE << endl;
                cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
                cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
                cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
                cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
                cout << "----------------------------------------------------" << endl;

            }
        }   

        if(assist == 1){
            confirmarVoto();
        }

        else if(assist == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    } 
        while(assist == 0);
}

void Candidatos::VotoPresidente(){
    int assist = 0;
    string num_presidente;
    int i;

    do{
        cout << "DIGITE O Nº DO SEU PRESIDENTE: " << endl;
        
        do{
            fflush(stdin);
            cin.clear();
            setbuf(stdin, NULL);

            cin >> num_presidente;
            
            if(num_presidente.size()!=2){
                cout << "INSIRA APENAS 2 DÍGITOS!" << endl;
            }
        }while(num_presidente.size()!=2);
        
        for(i=1238; i<= 1265; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_presidente && cand_BR[i].DS_CARGO == "PRESIDENTE"){
                assist = 1;
                cand_BR[0].posicao = i;

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

            }

        }

        for(i=1238; i<= 1265; i++){
            
            if(cand_BR[i].NR_CANDIDATO == num_presidente && cand_BR[i].DS_CARGO == "VICE-PRESIDENTE"){
                assist = 1;
                cand_BR[1].posicao = i;

                cout << "Nome Completo: " << cand_BR[i].NM_CANDIDATO << endl;
                cout << "Apelido: " << cand_BR[i].NM_URNA_CANDIDATO << endl;
                cout << "Cargo: " << cand_BR[i].DS_CARGO << endl;
                cout << "Região: " << cand_BR[i].NM_UE << endl;
                cout << "Nº do Candidato: " << cand_BR[i].NR_CANDIDATO << endl;
                cout << "Nº do Partido: " << cand_BR[i].NR_PARTIDO << endl;
                cout << "Sigla do Partido: " << cand_BR[i].NM_PARTIDO << endl;
                cout << "Nome do Partido: " << cand_BR[i].DS_PARTIDO << endl;
                cout << "----------------------------------------------------" << endl;

            }
        }   

        if(assist == 1){
            confirmarVoto();
        }

        else if(assist == 0){
            cout << "CANDIDATO INVÁLIDO. DIGITE NOVAMENTE! " << endl;
        }
    }    
        while(assist == 0);
}

void Candidatos::confirmarVoto(){
    char opcao;

        cout << "[1] - CONFIRMAR" << endl;
        cout << "[2] - CANCELAR PASSO" << endl;
        cout << "[3] - BRANCO" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "DIGITE A OPÇÃO DESEJADA: " << endl;

        fflush(stdin);
        cin.clear();
        setbuf(stdin, NULL);

        opcao = getchar();
        system("clear");

        if(opcao == '1'){
            cout << "----------------------------------------------------" << endl;
            cout << "VOTO COMPUTADO COM SUCESSO! " << endl;
            cout << "----------------------------------------------------" << endl;

            cand_BR[cand_BR[0].posicao].num_votos++;
        
            if(cand_BR[cand_BR[0].posicao].DS_CARGO == "DEPUTADO FEDERAL"){
                eleitor[eleitor[0].contador-1].DepFed = cand_BR[cand_BR[0].posicao].NM_CANDIDATO;   
            }

            else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "DEPUTADO DISTRITAL"){
                eleitor[eleitor[0].contador-1].DepDis = cand_BR[cand_BR[0].posicao].NM_CANDIDATO; 
            }
            else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "SENADOR" && cand_BR[3].posicao == 1){
                eleitor[eleitor[0].contador-1].Senad = cand_BR[cand_BR[0].posicao].NM_CANDIDATO;
                eleitor[eleitor[0].contador-1].Suple1 = cand_BR[cand_BR[1].posicao].NM_CANDIDATO;
                eleitor[eleitor[0].contador-1].Suple2 = cand_BR[cand_BR[2].posicao].NM_CANDIDATO;
            }
            else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "SENADOR" && cand_BR[3].posicao == 2){
                eleitor[eleitor[0].contador-1].Senad2 = cand_BR[cand_BR[0].posicao].NM_CANDIDATO;
                eleitor[eleitor[0].contador-1].Suple3 = cand_BR[cand_BR[1].posicao].NM_CANDIDATO;
                eleitor[eleitor[0].contador-1].Suple4 = cand_BR[cand_BR[2].posicao].NM_CANDIDATO;
            }
            else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "GOVERNADOR"){
				eleitor[eleitor[0].contador-1].Govern = cand_BR[cand_BR[0].posicao].NM_CANDIDATO;
				eleitor[eleitor[0].contador-1].GovernVice = cand_BR[cand_BR[1].posicao].NM_CANDIDATO;				
            }
            else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "PRESIDENTE"){
				eleitor[eleitor[0].contador-1].Presid = cand_BR[cand_BR[0].posicao].NM_CANDIDATO;
				eleitor[eleitor[0].contador-1].PresidVice = cand_BR[cand_BR[1].posicao].NM_CANDIDATO;
            }
        }

        else if(opcao == '2'){
            cout << "----------------------------------------------------" << endl;
            cout << "PASSO CANCELADO !" << endl;
            cout << "----------------------------------------------------" << endl;
                
                if(cand_BR[cand_BR[0].posicao].DS_CARGO == "DEPUTADO FEDERAL"){
                    VotoDeputadoFederal();
                }
                
                else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "DEPUTADO DISTRITAL"){
                    VotoDeputadoDistrital();							
                }
    
                else if((cand_BR[cand_BR[0].posicao].DS_CARGO == "SENADOR" || 
                cand_BR[cand_BR[0].posicao].DS_CARGO == "PRIMEIRO SUPLENTE" || 
                cand_BR[cand_BR[0].posicao].DS_CARGO == "SEGUNDO SUPLENTE") && 
                cand_BR[3].posicao == 1){

                    VotoSenador();
                }
                else if((cand_BR[cand_BR[0].posicao].DS_CARGO == "SENADOR" || 
                cand_BR[cand_BR[0].posicao].DS_CARGO == "PRIMEIRO SUPLENTE" || 
                cand_BR[cand_BR[0].posicao].DS_CARGO == "SEGUNDO SUPLENTE") && 
                cand_BR[3].posicao == 2){

                    VotoSenador2();
                }
                else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "GOVERNADOR" || 
                cand_BR[cand_BR[0].posicao].DS_CARGO == "VICE-GOVERNADOR"){

                    VotoGovernador();
                }
                else if(cand_BR[cand_BR[0].posicao].DS_CARGO == "PRESIDENTE" || 
                cand_BR[cand_BR[0].posicao].DS_CARGO == "VICE-PRESIDENTE"){

                    VotoPresidente();
                }

        }
        
} 

void Candidatos::relatorio(){
    for(int i = 0; i < eleitor[0].num_eleitores; i++){
        cout << endl;
        cout << "-----------------RELATÓRIO DE VOTOS-----------------" << endl << endl;
        cout << "NOME: " << eleitor[i].nome << endl;
		cout << "TÍTULO DE ELEITOR: " << eleitor[i].titulo_eleitor << endl;
        cout << "CPF: " << eleitor[i].cpf << endl << endl;

		cout << "PRESIDENTE: " << eleitor[i].Presid << endl;
        cout << "- VICE: " << eleitor[i].PresidVice << endl << endl;
        
        cout << "GOVERNADOR: " << eleitor[i].Govern << endl;
        cout << "- VICE: " << eleitor[i].GovernVice << endl << endl;

        cout << "SENADOR - 1ª VAGA: " << eleitor[i].Senad << endl;
        cout << "- 1º SUPLENTE: " << eleitor[i].Suple1 << endl;
        cout << "- 2º SUPLENTE: " << eleitor[i].Suple2 << endl << endl;

        cout << "SENADOR - 2ª VAGA: " << eleitor[i].Senad2 << endl;
        cout << "- 1º SUPLENTE: " << eleitor[i].Suple3 << endl;
        cout << "- 2º SUPLENTE: " << eleitor[i].Suple4 << endl << endl;

        cout << "DEPUTADO FEDERAL: " << eleitor[i].DepFed << endl << endl;

        cout << "DEPUTADO DISTRITAL: " << eleitor[i].DepDis << endl << endl;

	}
}

void Candidatos::GanhadorPresidente(){

int i;
int vencedor = 0;
string GanhadorPres = "BRANCO";

	for(i=1238; i<= 1265; i++){

			if(cand_BR[i].DS_CARGO == "PRESIDENTE"){

					if(cand_BR[i].num_votos > vencedor ){

						vencedor = cand_BR[i].num_votos;
						GanhadorPres = cand_BR[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "---------------RESULTADO DAS ELEIÇÕES---------------" << endl << endl;
cout << "PRESIDENTE: " << GanhadorPres << endl;
}

void Candidatos::GanhadorGovernador(){

int i;
int vencedor = 0;
string GanhadorGov = "BRANCO"; 

	for(i=0;i<=1237;i++){

			if(cand_BR[i].DS_CARGO == "GOVERNADOR"){

					if(cand_BR[i].num_votos > vencedor ){

						vencedor = cand_BR[i].num_votos;
						GanhadorGov = cand_BR[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "GOVERNADOR: " << GanhadorGov << endl;
}

void Candidatos::GanhadorSenador1(){

int i;
int vencedor = 0;
string GanhadorSen = "BRANCO"; 

	for(i=0;i<=1237;i++){

			if(cand_BR[i].DS_CARGO == "SENADOR"){

					if(cand_BR[i].num_votos > vencedor ){

						vencedor = cand_BR[i].num_votos;
						GanhadorSen = cand_BR[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "SENADOR - 1ª VAGA: " << GanhadorSen << endl;
}

void Candidatos::GanhadorSenador2(){

int i;
int vencedor = 0;
string GanhadorSen2 = "BRANCO"; 
 
	for(i=0;i<=1237;i++){

			if(cand_BR[i].DS_CARGO == "SENADOR"){

					if(cand_BR[i].num_votos > vencedor ){
                        
						vencedor = cand_BR[i].num_votos;
						GanhadorSen2 = cand_BR[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "SENADOR - 2ª VAGA: " << GanhadorSen2 << endl;
}

void Candidatos::GanhadorDepFederal(){

int i;
int vencedor = 0;
string GanhadorDF = "BRANCO";

	for(i=0;i<=1237;i++){

			if(cand_BR[i].DS_CARGO == "DEPUTADO FEDERAL"){

					if(cand_BR[i].num_votos > vencedor ){

						vencedor = cand_BR[i].num_votos;
						GanhadorDF = cand_BR[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "DEPUTADO FEDERAL: " << GanhadorDF << endl;
}

void Candidatos::GanhadorDepDistrital(){

int i;
int vencedor = 0;
string GanhadorDD = "BRANCO";

	for(i=0;i<=1237;i++){

			if(cand_BR[i].DS_CARGO == "DEPUTADO DISTRITAL"){

					if(cand_BR[i].num_votos > vencedor ){

						vencedor = cand_BR[i].num_votos;
						GanhadorDD = cand_BR[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "DEPUTADO DISTRITAL: " << GanhadorDD << endl << endl;
cout << "----------------------------------------------------" << endl;
}

int Candidatos::ReturnEleitores(){

    return eleitor[0].num_eleitores;
}



