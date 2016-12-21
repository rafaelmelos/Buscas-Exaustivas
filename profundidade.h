#include <stack>
using std::stack;

#ifndef PROFUNDIDADE_H
#define PROFUNDIDADE_H

template< typename DefiProb >
class Profundidade : public Busca< DefiProb >{
    private:
        stack< typename Busca< DefiProb >::TipoDeNode * > borda;
    protected:
        virtual void inserirNaBorda(typename Busca< DefiProb >::TipoDeNode *nod){
            borda.push(nod);
            Busca< DefiProb >::nos.push_back(nod);
        }
        virtual void removerDaBorda(){
            Busca< DefiProb >::node = borda.top();
            //Retirar o Nó da borda
			borda.pop();
        }
        virtual bool bordaVazia(){return borda.empty();}
    public:
        virtual void tipodaBusca(){
            cout << "Busca em Profundidade.\n";
        }
        Profundidade(DefiProb *prob = 0){
			Busca< DefiProb >::problema = prob;
		}
};

#endif
