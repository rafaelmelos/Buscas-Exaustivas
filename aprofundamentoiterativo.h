#include <stack>
using std::stack;

#ifndef APROFUNDAMENTOINTERATIVO_H
#define APROFUNDAMENTOINTERATIVO_H

template< typename DefiProb >
class AprofundamentoInterativo : public ProfundidadeLimitada< DefiProb >{
    public:
        virtual void tipodaBusca(){
            cout << "Busca em Aprofundamento Iterativo.\n";
        }
        AprofundamentoInterativo(DefiProb *prob): ProfundidadeLimitada< DefiProb >(prob){}
        virtual Node< typename DefiProb::tipoDeEstado > *buscar(){
            Node< typename DefiProb::tipoDeEstado > *caminho;
            do{
                cout << "Busca com limite: " << ProfundidadeLimitada< DefiProb >::limite << "\n";
                caminho = Busca< DefiProb >::buscar();
                if(caminho == 0){
                    //Busca< DefiProb >::limparMemoria();
                    ProfundidadeLimitada< DefiProb >::limite++;
                }
            }while(caminho == 0);
            
            return caminho;
        }
        virtual void requisito(){}
};

#endif
