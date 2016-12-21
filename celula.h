#ifndef CELULA_H
#define CELULA_H

class Celula{
    public:
        int *diagonalPrincipal;
        int *diagonalSecundaria;
        int *linha;
        int *coluna;
        bool emAtaque(){
            return (*diagonalPrincipal) || (*diagonalSecundaria) || (*linha) || (*coluna);
        }
        void colocarRainha(){
            (*diagonalPrincipal) = (*diagonalSecundaria) = (*linha) = (*coluna) = 1;
        }
};

#endif
