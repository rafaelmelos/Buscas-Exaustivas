#include <fstream>
using std::ofstream;
using std:: ostream;

#ifndef DAMAS_H
#define DAMAS_H

#include "tabuleiro.h"
#include "problema.h"
#include "celula.h"

class Damas : public Problema< Tabuleiro >{
	public:
        Damas();
        virtual vector< Tabuleiro * > *getSucessores(Tabuleiro &);
        virtual bool testeObjetivo(Tabuleiro &);
        void imprimirTabuleiro(Tabuleiro *tabu, ostream &);
		void atualizarTabuleiro(Tabuleiro *);
		void setEstadoInicial();
		ofstream arquivo;
    private:
		Celula tabuleiro[8][8];
		void setArquivo();
};

#endif
