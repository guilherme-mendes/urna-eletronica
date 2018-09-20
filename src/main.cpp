#include <iostream>
#include <string>
#include <fstream>
#include "../inc/candidatos.hpp"
#include "../inc/eleitor.hpp"

using namespace std;




Candidatos cand_DF[1238];
void federal(){
	cout << "Digite o nº do seu Deputado Federal: " << endl;
	string num_candidato;

do{
		cin >> num_candidato;
		if(num_candidato.size()!=4){
			cout << "Insira apenas 4 dígitos! " << endl;
		}
}
while(num_candidato.size()!=4);
	for(int i = 0; i <= 1237; i++){
		if(cand_DF[i].NR_CANDIDATO == num_candidato){
			
			cout << "-----------------------------------------------" << endl;
			cout << "Nome Completo: " << cand_DF[i].NM_CANDIDATO << endl;
			cout << "Apelido: " << cand_DF[i].NM_URNA_CANDIDATO << endl;
			cout << "Cargo: " << cand_DF[i].DS_CARGO << endl;
			cout << "Região: " << cand_DF[i].NM_UE << endl;
			cout << "Nº do Candidato: " << cand_DF[i].NR_CANDIDATO << endl;
			cout << "Nº do Partido: " << cand_DF[i].NR_PARTIDO << endl;
			cout << "Sigla do Partido: " << cand_DF[i].NM_PARTIDO << endl;
			cout << "Nome do Partido: " << cand_DF[i].DS_PARTIDO << endl;
			cout << "-----------------------------------------------" << endl;

		}
	}
}

int main() {

	int qtd_eleitores;
	int i;

	system("clear");
	
	cout << "Digite o nº de eleitores que votarão nesta urna: " << endl;
	cin >> qtd_eleitores;

	for(int n = 0; n < qtd_eleitores; n++){

		ifstream arquivo("./data/candidatos_DF.csv");
		if(!arquivo.is_open()){
		cout << "Não foi possível abrir o arquivo!" << endl;
		}
	
	for (i=0; i<= 1236; i++){
		
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

	federal();
	
	}

return 0;

}

