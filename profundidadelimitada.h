#include <stack>
using std::stack;

#ifndef PROFUNDIDADELIMITADA_H
#define PROFUNDIDADELIMITADA_H

template< typename DefiProb >
class ProfundidadeLimitada : public Profundidade< DefiProb >{
    protected:
        int limite;
        virtual bool expandidirEstado(){
            return (*(Busca< DefiProb >::node)).profundidade < limite;
        }
    public:
        virtual void tipodaBusca(){
            cout << "Busca em Profundidade Limitada.\n";
        }
        ProfundidadeLimitada(DefiProb *prob = 0){
			Busca< DefiProb >::problema = prob;
			limite = 0;
		}
		virtual void requisito(){
            cout << "Digite o limite da busca: ";
            cin >> limite;
        }
};

#endif
