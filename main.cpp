#include <iostream>
using std::cout;

#include "node.h"
#include "busca.h"
#include "largura.h"
#include "profundidade.h"
#include "profundidadelimitada.h"
#include "aprofundamentoiterativo.h"
#include "damas.h"

int main(){
    cout << "Trabalho de inteligencia artificial I - 8 Rainhas\n"
         << "Aluno: Rafael Melo\n"
         << "Ra: 142155\n"
         << "Data: 14/03/2013\n\n";
	
	Damas damas;
	Busca< Damas > *busca[4] = { new Profundidade< Damas >(&damas),
                                 new Largura< Damas >(&damas),
	                             new ProfundidadeLimitada< Damas >(&damas),
                                 new AprofundamentoInterativo< Damas >(&damas)};
	char resp;
	int indice;
    damas.setEstadoInicial();
	cout << "Legenda do tabuleiro:\n"
         << "0-Casa livre de ataques de rainhas;\n"
         << "1-casa sobre ataque de pelo menos uma rainha;\n"
         << "2-casa contem rainha;\n\n";
	
    cout << "Tipos de buscas:\n"
         << "0-Busca em profundidade (recomendado)\n"
         << "1-Busca em largura\n"
         << "2-Busca por profundidade limitada\n"
         << "3-Busca em aprofundamento iterativo\n"
         << "Escolha um tipo de busca: ";
    cin >> indice;
    (busca[indice])->tipodaBusca();
    (busca[indice])->requisito();
	Node < Damas::tipoDeEstado > *solucao = (busca[indice])->buscar();
	if( 0 != solucao ){
        cout << "Solucao:\n";
        cout << "Rainha  Coluna   Linha\n";
        for(int a=0;a<8;a++){
            cout << "   "<< a+1
                 << "       " <<a
                 << "       " << solucao->estado.localizacao[a] << "\n";
        }
    }else{
        cout << "Nao encontrou solucao.\n";
    }
    cout << "\n";
    cout << "Precione enter para concluir a gravacao do arquivo. ";
    getchar();
    getchar();
    return 0;
}
