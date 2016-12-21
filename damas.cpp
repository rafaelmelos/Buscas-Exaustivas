#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::ostream;
#include <string>
using std::string;
#include "damas.h"
#include "tabuleiro.h"
#include "problema.h"
#include "celula.h"

Damas::Damas(){
	int l,c;
	//Gerar tabuleiro
	int **prtCelula = new int*[2];
	prtCelula[0] = new int[15];//diagonais principais
	prtCelula[1] = new int[15];//diagonais segundarias
	int **prtCelula2 = new int*[2];
	prtCelula2[0] = new int[8];//linhas
	prtCelula2[1] = new int[8];//colunas
	for(l=0; l<8; l++){
		for(c=0; c<8; c++){
			(tabuleiro[l][c]).linha = prtCelula2[0]+l;
        	(tabuleiro[l][c]).coluna = prtCelula2[1]+c;
        	(tabuleiro[l][c]).diagonalPrincipal = prtCelula[0]+7-l+c;
        	(tabuleiro[l][c]).diagonalSecundaria = prtCelula[1]+l+c;
		}
	}
	//gerar estado inicial;
	Problema< Tabuleiro >::estadoInicial  = new Tabuleiro;
	setArquivo();
}
void Damas::setArquivo(){
    cout << "Digite o nome do arquivo para gravacao da seguencia\n"
         << "dos estados verificados (sem extensao). Caso o arquivo\n"
         << "nao exista sera criado um com este nome do mesmo diretorio\n"
         << "do projeto, se existir sera subistituido:\n";
    string nomeDoArquivo;
	cin >> nomeDoArquivo;
	nomeDoArquivo += ".txt";
	//abrir arquivo;
	arquivo.open(nomeDoArquivo.c_str(), ios::out);
	if (!arquivo){
		cerr << "Arquivo para gravacao do resultado nao pode ser aberto.\n";
		system("pause");
	}
}

void Damas::setEstadoInicial(){
    cout << "Montar estado inicial:\n";
    int i,l,c;
    for(i=0; i<8; i++){
		(Problema< Tabuleiro >::estadoInicial)->localizacao[i] = -1;
	}
    cout << "Digite o numero de damas iniciais: ";
	cin >> i;
	cout << "As linhas e colunas sao numeradas de 0 a 7.\n";
	while(i--){
		cout << "Linha da dama: ";
		cin >> l;
		cout << "Coluna da dama: ";
		cin >> c;
		(Problema< Tabuleiro >::estadoInicial)->localizacao[c] = l;
 	}
 	cout << "Estado inicial:\n";
 	atualizarTabuleiro(Problema< Tabuleiro >::estadoInicial);
    imprimirTabuleiro(Problema< Tabuleiro >::estadoInicial, cout);
}

vector< Tabuleiro * > *Damas::getSucessores(Tabuleiro &tabu){
	int a,b;
	Tabuleiro *novoTabu;
	//Coluna da vez
	for(a=0; a<8 && (-1 != tabu.localizacao[a]); a++){
	}
	if(a!=8){
        atualizarTabuleiro(&tabu);
		for(b=0;b<8;b++){
			if(!(tabuleiro[b][a]).emAtaque()){ //se nao estiver em ataque
				novoTabu = new Tabuleiro(tabu);
				novoTabu->localizacao[a] = b;
				novoTabu->sucessores.clear();
				tabu.sucessores.push_back(novoTabu);
			}
		}
	}
	return &(tabu.sucessores);
}

bool Damas::testeObjetivo(Tabuleiro &tabu){
	for(int a=0;a<8;a++){
        if(-1 == tabu.localizacao[a]){
            return false;
        }
    }
    return  true;
}

void Damas::imprimirTabuleiro(Tabuleiro *tabu, ostream &output){
	int b, a;
	output << "\n";
	for(a=0; a<8; a++){
		for(b=0; b<8; b++){
			if(tabu->localizacao[b] == a){
            	output << 2;
        	}else{
				output << (tabuleiro[a][b]).emAtaque();
			}
			output << " ";
		}
		output << "\n";
	}
	for(b=0; b<8; b++){
		output << "-";
	}
	output << "\n";
}

void Damas::atualizarTabuleiro(Tabuleiro *tabu){
    int a;
    //Zerar tabuleiro
    for(a=0; a<8; a++){
        *((tabuleiro[a][0]).linha) = 0;
        *((tabuleiro[0][a]).coluna) = 0;
        *((tabuleiro[a][0]).diagonalPrincipal) = 0;
        *((tabuleiro[a][7]).diagonalSecundaria) = 0;
    }
    for(a=1; a<8; a++){
        *((tabuleiro[0][a]).diagonalPrincipal) = 0;
        *((tabuleiro[0][a-1]).diagonalSecundaria) = 0;
    }
    //Colocar as rainhas do estado
    for(a=0; a<8; a++){
        if(-1 != (tabu->localizacao[a])){
            (tabuleiro[tabu->localizacao[a]][a]).colocarRainha();
        }
	}
}
