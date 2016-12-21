#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;

#ifndef BUSCA_H
#define BUSCA_H

#include "node.h"

template< typename DefiProb >
class Busca{
	protected:
        typedef Node< typename DefiProb::tipoDeEstado >  TipoDeNode;
        TipoDeNode *node;
        virtual void inserirNaBorda(TipoDeNode *) = 0;
        virtual void removerDaBorda() = 0;
        virtual bool bordaVazia() = 0;
        virtual bool expandidirEstado(){return true;}
        DefiProb *problema;
        vector< typename DefiProb::tipoDeEstado * > *sucessores;
        vector< TipoDeNode * > nos;
        void limparMemoria(){
            //Deletar Nos que foram espandidos
			for(int i = 0; i < nos.size(); i++){
                node = nos[i];
                delete node;
            }
        }
    public:
        virtual void tipodaBusca() = 0;
        Busca(DefiProb *prob = 0): problema(prob){}
        ~Busca(){
            limparMemoria();
        }
        virtual TipoDeNode *buscar(){
            inserirNaBorda(new TipoDeNode(*(problema->getEstadoInicial())));
			
            while(!bordaVazia()){
				removerDaBorda();
				problema->atualizarTabuleiro(&(node->estado));
				problema->imprimirTabuleiro(&(node->estado), problema->arquivo);
				
				//Verifica o objetivo
				if(problema->testeObjetivo(node->estado)){
					//Retorna solução
					return node;
				}
				if(expandidirEstado()){
                    sucessores = problema->getSucessores(node->estado);
				    for(int i = 0; i != (*sucessores).size(); i++){
					   inserirNaBorda(new TipoDeNode(*((*sucessores)[i]), node));
				    }
                }
			}
			//Retorna Falha;
			return 0;
        }
        virtual void requisito(){}
};

#endif
