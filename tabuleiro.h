#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro{
	public:
		int localizacao[8];//onde as rainhas estão no tabuleiro
		vector< Tabuleiro * > sucessores;
};

#endif
