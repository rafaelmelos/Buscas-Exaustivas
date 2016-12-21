#ifndef NODE_H
#define NODE_H

template< typename Estado >
class Node{
	public:
		Node(Estado &est, Node< Estado > * pai = 0, int cust = 0)
			: estado(est), noPai(pai), profundidade((pai == 0 ? 0 :(*pai).profundidade+1)), custoDoCaminho(cust){
		}
		Estado &estado;
		/*A referência pode ser declarada como: "No &noPai;", pois é implícito
        que noPai é uma referência para a classe gabarito No< Estado >, foi
        explicitado que se trata de uma referência para a classe gabarito
        No< Estado > para fins de documentação.*/
		Node< Estado > *noPai;
		//(Acao acao;) ou (string acao;)
        const int profundidade;
		const int custoDoCaminho;
};

#endif
