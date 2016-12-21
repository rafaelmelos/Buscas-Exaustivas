#include <vector>
using std::vector;

#ifndef PROBLEMA_H
#define PROBLEMA_H

class No;

template< typename Estado >
class Problema{
    public:
		Estado *estadoInicial;
        Estado *getEstadoInicial() {return estadoInicial;}
		/*Dado um estado particular x, sucessor() retorna um conjunto de pares
        ordenados <a��o, sucessor>, em que cada a��o � uma das a��es validas
        no estado x e cada sucessor � um estado que pode ser alcan�ado a partir
        de x aplicando-se a a��o.
        Atualmente esta fun��o retorna apenas os estados sucessores, j� que 
        abstra��o das a��es tornou desnecess�ria a sua descri��o.
        */
        virtual vector< Estado * > *getSucessores(Estado &) = 0;
        virtual bool testeObjetivo(Estado &) = 0;
        //virtual int custoDeCaminho(No &
        typedef Estado tipoDeEstado;
};

#endif
