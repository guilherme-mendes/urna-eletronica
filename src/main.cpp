#include <iostream>
#include <string>
#include <fstream>
#include "../inc/candidatos.hpp"
#include "../inc/eleitor.hpp"
#include "../inc/urna.hpp"

using namespace std;

int main(){

	Urna urna;
	
	int i;
	
	urna.lerArquivo();
	urna.mesario();

	while(i < urna.ReturnEleitores()){
		
		urna.cadastroEleitor();
		urna.VotoDeputadoFederal();
		urna.VotoDeputadoDistrital();
		urna.VotoSenador();

		i++;
	}
		
	urna.relatorio();
	urna.Ganhador();

	return 0;
}

