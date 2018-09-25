#include "../inc/urna.hpp"
#include "../inc/candidatos.hpp"
#include "../inc/eleitor.hpp"
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

Urna::Urna() {}
Urna::~Urna() {}

Eleitor eleitor[1238];
Candidatos cand_DF[1265];

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
    
    cout << "DIGITE SEU CPF: " << endl;
    cin.ignore();
    getline(cin, eleitor[eleitor[0].counter_eleitor].cpf);

    eleitor[0].counter_eleitor++;
    cout << endl;
    system("clear");
}

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
	
	for (i=1238; i<= 1265; i++){
		
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

void Urna::clearBuff(){

    fflush(stdin);
    fflush(stdin);
    fflush(stdin);
    fflush(stdin);
    cin.clear();
    setbuf(stdin, NULL);

}

int Urna::ReturnEleitores(){
    return eleitor[0].num_eleitores;
}

void Urna::confirmarVoto(){
    char opcao;

        cout << "[1] - CONFIRMAR" << endl;
        cout << "[2] - CANCELAR PASSO" << endl;
        cout << "[ENTER] - BRANCO" << endl;
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
            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR" && cand_DF[3].cand_analise == 1){
                eleitor[eleitor[0].counter_eleitor-1].VotoSen = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup1 = cand_DF[cand_DF[1].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup2 = cand_DF[cand_DF[2].cand_analise].NM_CANDIDATO;
            }
            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR" && cand_DF[3].cand_analise == 2){
                eleitor[eleitor[0].counter_eleitor-1].VotoSen2 = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup3 = cand_DF[cand_DF[1].cand_analise].NM_CANDIDATO;
                eleitor[eleitor[0].counter_eleitor-1].VotoSup4 = cand_DF[cand_DF[2].cand_analise].NM_CANDIDATO;
            }
            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "GOVERNADOR"){
				eleitor[eleitor[0].counter_eleitor-1].VotoGov = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;
				eleitor[eleitor[0].counter_eleitor-1].VotoGovVice = cand_DF[cand_DF[1].cand_analise].NM_CANDIDATO;				
            }
            else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "PRESIDENTE"){
				eleitor[eleitor[0].counter_eleitor-1].VotoPres = cand_DF[cand_DF[0].cand_analise].NM_CANDIDATO;
				eleitor[eleitor[0].counter_eleitor-1].VotoPresVice = cand_DF[cand_DF[1].cand_analise].NM_CANDIDATO;
            }
        }

            else if(opcao == '2'){
                cout << "PASSO CANCELADO !" << endl;
                    
                    if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO FEDERAL" ){
                        VotoDeputadoFederal();
                    }
                    
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO FEDERAL" ){
                        VotoDeputadoDistrital();							
                    }
        
                    else if((cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "PRIMEIRO SUPLENTE"  || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SEGUNDO SUPLENTE" ) && cand_DF[3].cand_analise == 1){
                        VotoSenador();
                    }
                    else if((cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "PRIMEIRO SUPLENTE"  || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SEGUNDO SUPLENTE" ) && cand_DF[3].cand_analise == 2){
                        VotoSenador2();
                    }
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "GOVERNADOR" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "VICE-GOVERNADOR"){
                        VotoGovernador();
                    }
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "PRESIDENTE" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "VICE-PRESIDENTE"){
                        VotoPresidente();
                    }

            }
            
}      

void Urna::VotoDeputadoFederal(){
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
    }
        while(aux == 0);
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
            cand_DF[3].cand_analise = 1;

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

            cand_DF[0].cand_analise = i;
            cand_DF[3].cand_analise = 2;

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

            cand_DF[1].cand_analise = i;

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
        
        for(i=1238; i<= 1265; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_presidente && cand_DF[i].DS_CARGO == "PRESIDENTE"){
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

        for(i=1238; i<= 1265; i++){
            
            if(cand_DF[i].NR_CANDIDATO == num_presidente && cand_DF[i].DS_CARGO == "VICE-PRESIDENTE"){
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

void Urna::relatorio(){
    for(int i = 0; i < eleitor[0].num_eleitores; i++){
        cout << endl;
        cout << "-----------------RELATÓRIO DE VOTOS-----------------" << endl << endl;
        cout << "NOME: " << eleitor[i].nome << endl;
		cout << "TÍTULO DE ELEITOR: " << eleitor[i].titulo_eleitor << endl;
        cout << "CPF: " << eleitor[i].cpf << endl << endl;

		cout << "DEPUTADO FEDERAL: " << eleitor[i].VotoDF << endl << endl;
		cout << "DEPUTADO DISTRITAL: " << eleitor[i].VotoDD << endl << endl;

		cout << "SENADOR - 1ª VAGA: " << eleitor[i].VotoSen << endl;
        cout << "- 1º SUPLENTE: " << eleitor[i].VotoSup1 << endl;
        cout << "- 2º SUPLENTE: " << eleitor[i].VotoSup2 << endl << endl;

        cout << "SENADOR - 2ª VAGA: " << eleitor[i].VotoSen2 << endl;
        cout << "- 1º SUPLENTE: " << eleitor[i].VotoSup3 << endl;
        cout << "- 2º SUPLENTE: " << eleitor[i].VotoSup4 << endl << endl;

        cout << "GOVERNADOR: " << eleitor[i].VotoGov << endl;
        cout << "- VICE: " << eleitor[i].VotoGovVice << endl << endl;
        
        cout << "PRESIDENTE: " << eleitor[i].VotoPres << endl;
        cout << "- VICE: " << eleitor[i].VotoPresVice << endl << endl;
	}
}

void Urna::GanhadorDepFederal(){

int i;
int maior = 0;
string GanhadorDF = "BRANCO"; // Ganhador p/ Deputado Federal

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

void Urna::GanhadorDepDistrital(){

int i;
int maior = 0;
string GanhadorDD = "BRANCO";

	for(i=0;i<=1237;i++){

			if(cand_DF[i].DS_CARGO == "DEPUTADO DISTRITAL" ){

					if(cand_DF[i].num_votos > maior ){

						maior = cand_DF[i].num_votos;
						GanhadorDD = cand_DF[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "DEPUTADO DISTRITAL: " << GanhadorDD << endl;
}

void Urna::GanhadorSenador1(){

int i;
int maior = 0;
string GanhadorSen = "BRANCO"; 

	for(i=0;i<=1237;i++){

			if(cand_DF[i].DS_CARGO == "SENADOR" ){

					if(cand_DF[i].num_votos > maior ){

						maior = cand_DF[i].num_votos;
						GanhadorSen = cand_DF[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "SENADOR - 1ª VAGA: " << GanhadorSen << endl;

}

void Urna::GanhadorSenador2(){

int i;
int maior = 0;
string GanhadorSen2 = "BRANCO"; 
 
	for(i=0;i<=1237;i++){

			if(cand_DF[i].DS_CARGO == "SENADOR" ){

					if(cand_DF[i].num_votos > maior ){

						maior = cand_DF[i].num_votos;
						GanhadorSen2 = cand_DF[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "SENADOR - 2ª VAGA: " << GanhadorSen2 << endl;

}

void Urna::GanhadorGovernador(){

int i;
int maior = 0;
string GanhadorGov = "BRANCO"; 

	for(i=0;i<=1237;i++){

			if(cand_DF[i].DS_CARGO == "GOVERNADOR" ){

					if(cand_DF[i].num_votos > maior ){

						maior = cand_DF[i].num_votos;
						GanhadorGov = cand_DF[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "GOVERNADOR: " << GanhadorGov << endl;

}

void Urna::GanhadorPresidente(){

int i;
int maior = 0;
string GanhadorPres = "BRANCO";

	for(i=1238; i<= 1265; i++){

			if(cand_DF[i].DS_CARGO == "PRESIDENTE" ){

					if(cand_DF[i].num_votos > maior ){

						maior = cand_DF[i].num_votos;
						GanhadorPres = cand_DF[i].NM_CANDIDATO;
                        
					}
			}
    }        

cout << "PRESIDENTE: " << GanhadorPres << endl;
cout << "----------------------------------------------------" << endl;

}

