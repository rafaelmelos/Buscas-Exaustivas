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
        ordenados <ação, sucessor>, em que cada ação é uma das ações validas
        no estado x e cada sucessor é um estado que pode ser alcançado a partir
        de x aplicando-se a ação.
        Atualmente esta função retorna apenas os estados sucessores, já que 
        abstração das ações tornou desnecessária a sua descrição.
        */
        virtual vector< Estado * > *getSucessores(Estado &) = 0;
        virtual bool testeObjetivo(Estado &) = 0;
        //virtual int custoDeCaminho(No &
        typedef Estado tipoDeEstado;
};

#endif
