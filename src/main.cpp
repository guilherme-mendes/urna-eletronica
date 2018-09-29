#include <iostream>
#include "../inc/candidatos.hpp"
#include "../inc/eleitor.hpp"
#include "../inc/info_cand.hpp"

using namespace std;

int main(){

	Candidatos candidatos;
	
	candidatos.lerArquivo();
	candidatos.lerArquivo2();
	candidatos.mesario();
	
	int i;
	
	while(i < candidatos.ReturnEleitores()){
		
		candidatos.cadastroEleitor();
		candidatos.VotoDeputadoFederal();
		candidatos.VotoDeputadoDistrital();
		candidatos.VotoSenador();
		candidatos.VotoSenador2();
		candidatos.VotoGovernador();
		candidatos.VotoPresidente();

		i++;
	}
		
	candidatos.relatorio();
	candidatos.GanhadorPresidente();
	candidatos.GanhadorGovernador();
	candidatos.GanhadorSenador1();
	candidatos.GanhadorSenador2();
	candidatos.GanhadorDepFederal();
	candidatos.GanhadorDepDistrital();
	
	return 0;
}

