# Buscas_Exaustivas
Implementação dos algoritmos de busca exaustiva e aplicação no problema das 8 rainhas.

### Buscas exaustivas implementadas:

  - Busca em profundidade (recomendado);
  - Busca em largura;
  - Busca por profundidade limitada.
  - Busca em aprofundamento iterativo.

### O Problema das 8 Rainhas
Nesse jogo, é dado um tabuleiro quadrado de 8 por 8 (ou seja, 64 posições).
Para vencer o jogo, o jogador deve adicionar 8 rainhas ao tabuleiro de modo que nenhuma rainha
fique na região de ataque da outra. A região de ataque de uma rainha compreende todas as posições
do tabuleiro que estiverem na mesma linha, coluna ou diagonal da posição onde essa rainha estiver
posicionada.
Dessa forma, respeitando essas restrições, o desafiado vence o jogo quando o tabuleiro é
completamente preenchido.

Nesse cenário, dado um tabuleiro de 8 rainhas (que pode estar parcialmente preenchido pelo usuário),
o programa encontra uma solução válida possível (se ela existir no espaço de estados) usando
algum algoritmo de busca exaustiva citado a cima. As rainhas inseridas pelo usuário em algumas
posições do tabuleiro antes da execução da busca pela solução são mantidas. Portanto, por exemplo,
se o usuário inserir uma rainha na primeira posição da primeira linha, o programa deve encontrar
uma solução válida em que essa posição contenha uma rainha.o programa assume que o usuário insere
rainhas somente em posições válidas.
Após a execução da busca, o programa exibi uma mensagem informando qual foi o
resultado da busca. Se a solução for encontrada, ela é exibida. Portanto, nesse caso, o
tabuleiro é preenchido com essa solução. Caso contrário, se a busca não cair em ciclo
infinito, é mostrada uma mensagem informando que o objetivo não foi encontrado.
