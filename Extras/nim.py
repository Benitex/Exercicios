'''
Exercício da matéria Modelagem e Programação

O jogo NIM é composto por vários grupos de bastões. A quantidade de grupos e de bastões por grupo são valores
aleatórios. O vencedor do jogo é aquele que retirar o último bastão. Uma jogada consiste em remover uma
quantidade qualquer de um dos grupos (1 <= quantidade <= total de bastões do grupo).

1. Escreva uma função chamada exibeApresentacaoJogo que exiba as mensagens iniciais do jogo, conforme as
5 primeiras linhas do exemplo acima.

2. Escreva uma função chamada geraListaBastoes que retorna uma lista com N valores inteiros aleatórios no
intervalo [1, 7], representando a quantidade de bastões em cada um dos N grupos. N é um valor inteiro aleatório
no intervalo [3, 6].

3. Escreva uma função chamada exibeBastoes que receba a lista que contém a quantidade de bastões em cada
um dos grupos e exiba na tela os grupos conforme exemplo acima. Utilize o caractere '█' para representar cada
bastão (chr(9608)).

4. Escreva uma função chamada umaJogada que receba a lista que contém a quantidade de bastões em cada um
dos grupos e o número do jogador (1 ou 2) e leia o número do grupo do qual o jogador deseja remover bastões
e a quantidade de bastões a remover. A função deve remover os bastões do grupo escolhido e retornar True se
o jogador ganhou o jogo ou False, em caso contrário.

5. Utilizando as funções anteriores, escreva um programa que implemente o jogo NIM. Ao final, o programa deve
dar parabéns ao jogador que venceu o jogo.
'''

import random

def main():
  listaBastoes = geraListaBastoes()

  alguem_ganhou = False
  jogador = 1

  print("Faça sua jogada, jogador %d.\n" % jogador)
  while not alguem_ganhou:
    exibeBastoes(listaBastoes)
    if umaJogada(listaBastoes, jogador):
      print("Parabéns jogador %d, você ganhou!" % jogador)
      alguem_ganhou = True
    else:
      if jogador == 1:
        jogador = 2
      elif jogador == 2:
        jogador = 1

      print("Faça sua jogada, jogador %d.\n" % jogador)

def exibeApresentacaoJogo():
  print("***                                            ***")
  print("***                Jogo NIM                    ***")
  print("***     Vence quem retirar o último bastão     ***")
  print("***              Boa Sorte!!!                  ***")

def geraListaBastoes() -> list[int]:
  listaBastoes = []
  for i in range(random.randint(3, 7)):
    listaBastoes.append(random.randint(1, 6))

  return listaBastoes

def exibeBastoes(listaBastoes: list[int]):
  for numeroDoGrupo in range(len(listaBastoes)):
    print("Grupo %d:\t" % (numeroDoGrupo + 1), end = '')
    for numeroDoBastao in range(listaBastoes[numeroDoGrupo]):
      if numeroDoBastao == listaBastoes[numeroDoGrupo] - 1:
        print(chr(9608) + "\n")
      else:
        print(chr(9608), end = " ")

def umaJogada(listaBastoes: list[int], numeroJogador: int) -> bool:
  grupoSelecionado = -1
  quantidadeDeBastoes = -1

  while grupoSelecionado < 0 or grupoSelecionado >= len(listaBastoes):
    grupoSelecionado = int(input("De qual grupo você quer remover bastões?\n")) - 1

  while quantidadeDeBastoes <= 0 or quantidadeDeBastoes > listaBastoes[grupoSelecionado]:
    quantidadeDeBastoes = int(input("Quantos bastões você quer remover?\n"))

  listaBastoes[grupoSelecionado] -= quantidadeDeBastoes

  for elementos_no_grupo in listaBastoes:
    if elementos_no_grupo != 0:
      return False
  return True

main()
