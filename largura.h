#include <queue>
using std::queue;

#ifndef LARGURA_H
#define LARGURA_H

template< typename DefiProb >
class Largura : public Busca< DefiProb >{
    private:
        queue< typename Busca< DefiProb >::TipoDeNode * > borda;
    protected:
        virtual void inserirNaBorda(typename Busca< DefiProb >::TipoDeNode *nod){
            borda.push(nod);
            Busca< DefiProb >::nos.push_back(nod);
        }
        virtual void removerDaBorda(){
            Busca< DefiProb >::node = borda.front();
            //Retirar o Nó da borda
			borda.pop();
        }
        virtual bool bordaVazia(){return borda.empty();}
    public:
        virtual void tipodaBusca(){
            cout << "Busca em Largura.\n";
        }
        Largura(DefiProb *prob){
			Busca< DefiProb >::problema = prob;
		}
};

#endif
