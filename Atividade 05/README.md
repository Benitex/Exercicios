# Atividade 05

Devem ser escolhidos no mínimo dois dos jogos abaixo para serem feitos essa semana.

Estes devem ser feitos inicialmente SOMENTE COM INPUT DO PYTHON. Por este motivo o extra inclui o PyGame. Além disso, USO DE FUNÇÕES É OBRIGATÓRIO PARA OS DOIS PROJETOS ESCOLHIDOS.

## JOGO DA FORCA

### PRINCIPAL

* Condição de vitória: Acertar a palavra toda
* Condição de derrota: Perder todos os membros/vidas (6 no total)
* Ao começar o jogo uma palavra aleatória deve ser gerada com base em uma LISTA DE PALAVRAS (todas dentro de um mesmo tema)
* A entrada do usuário deve ser validada, permitindo que ele digite SOMENTE LETRAS
* A única exceção é para o caso do jogador chutar uma palavra inteira
* O jogo deve poder ser reiniciado

### EXTRA

* Tudo da forca, porém feito no PyGame
* Deve ter interação com o teclado para entrada de dados

## PEDRA, PAPEL E TESOURA

### PRINCIPAL

* Condição de vitória e derrota: Pedra > Tesoura > Papel > Pedra
* O jogador decide se ele joga pedra, papel ou tesoura
* O computador gera um resultado aleatório
* O jogo deve poder ser reiniciado
* Deve haver uma pontuação para o jogador

### EXTRA

* Criar o jogo com uma interface gráfica no PyGame
* Usar imagens (de mãos ou dos itens)

## CALCULADORA

### PRINCIPAL

* Único que não é jogo, porém tem que funcionar como uma calculadora vagabunda
* Portanto, ela deve ter uma memória da ÚLTIMA OPERAÇÃO FEITA
* Exemplo: Se eu digito 5, depois X, depois 3, o resultado que aparece é 15
* Se eu quiser usar esse 15, eu consigo, é só eu digitar +, e depois 4, para obter 19
* Não opero com mais de dois operandos

### EXTRA

* Fazer a calculadora usando PyGame
* Interface parecida com aquelas calculadoras de celular, porém funcionando como na parte principal

## JOGO DE ADIVINHAÇÃO

### PRINCIPAL

* Implemente um jogo de adivinhação. O computador "escolhe" (gera aleatoriamente) um número entre 1 e 1023, e o usuário tenta adivinhar o número escolhido;
* Para cada tentativa do usuário, o programa deve exibir na tela:
* O número -1, se o número gerado for menor do que o número fornecido pelo usuário;
* O número 1, se o número gerado for maior do que o número fornecido pelo usuário;
* O número 0, se o número gerado for igual ao fornecido pelo usuário. Neste caso, o programa deve exibir o número de tentativas usadas pelo usuário para acertar a escolha do computador de finalizar a execução;

### EXTRA

* Implementar o jogo no PyGame, com botões no lugar das opções 0, 1 e -1, ou indicadores visuais;
* Implemente a variação do jogo na qual usuário e computador podem trocar de funções. O programa começa perguntando quem tentará adivinhar: o usuário ou o computador;
* Ou seja, usuário e computador podem trocar de funções.
