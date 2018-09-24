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

    cout << "DIGITE SEU NOME COMPLETO: " << endl;
    cin.ignore();
    getline(cin, eleitor[eleitor[0].counter_eleitor].nome);
    
    cout << "DIGITE SEU TITULO DE ELEITOR: " << endl;
    cin >> eleitor[eleitor[0].counter_eleitor].titulo_eleitor;
    
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
        }

            else if(opcao == '2'){
                cout << "PASSO CANCELADO !" << endl;
                    
                    if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO FEDERAL" ){
                        VotoDeputadoFederal();
                    }
                    
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "DEPUTADO FEDERAL" ){
                        VotoDeputadoDistrital();							
                    }
        
                    else if(cand_DF[cand_DF[0].cand_analise].DS_CARGO == "SENADOR" || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "1º SUPLENTE"  || cand_DF[cand_DF[0].cand_analise].DS_CARGO == "2º SUPLENTE" ){
                        VotoSenador();
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
        cout << "DIGITE O Nº DO SEU SENADOR: " << endl;
        
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
            
            if(cand_DF[i].NR_CANDIDATO == num_senador && cand_DF[i].DS_CARGO == "1º SUPLENTE"){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl;
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
            
            if(cand_DF[i].NR_CANDIDATO == num_senador && cand_DF[i].DS_CARGO == "2º SUPLENTE"){
                aux = 1;

			cout << "--------------INFORMAÇÕES DO CANDIDATO--------------" << endl;
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

void Urna::relatorio(){
    for(int i = 0; i < eleitor[0].num_eleitores; i++){
        cout << endl;
        cout << "-----------------RELATÓRIO DE VOTOS-----------------" << endl << endl;
        cout << "NOME: " << eleitor[i].nome << endl;
		cout << "TÍTULO DE ELEITOR: " << eleitor[i].titulo_eleitor << endl;
        cout << "DATA DE NASCIMENTO: " << eleitor[i].nascimento << endl << endl;

		cout << "DEPUTADO FEDERAL: " << eleitor[i].VotoDF << endl;
		cout << "DEPUTADO DISTRITAL: " << eleitor[i].VotoDD << endl;
		cout << "SENADOR: " << eleitor[i].VotoSen << "   PRIMEIRO SUPLENTE: " << eleitor[i].VotoSup1 << " SEGUNDO SUPLENTE: " << eleitor[i].VotoSup2 << endl << endl;

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

cout << "---------------CANDIDATOS VENCEDORES---------------" << endl;
cout << "DEPUTADO FEDERAL: " << GanhadorDF << endl;


}

