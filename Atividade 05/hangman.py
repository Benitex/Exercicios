import random

lives = 6
words_list = ["bola", "casa", "careca", "pirata"]
selected_word = ''

word_try = ''

def load():
  global selected_word, lives

  insert_words()
  selected_word = random.choice(words_list)

  # Valores iniciais das letras reveladas
  revealed_letters = []
  for letter in range(len(selected_word)):
    revealed_letters.append("_")

  while lives > 0:
    word_try = input("Chute uma letra\n")

    # Chute de uma palavra
    if len(word_try) > 1:
      if word_try != selected_word:
        lives = 0
      break

    # Todas as letras foram reveladas
    if ("_" in revealed_letters) == False:
      break

    # Chute de uma letra
    else:
      if word_try in revealed_letters:
        print(f'A letra "{word_try}" já foi escolhida!')
        continue

      if word_try in selected_word: # tentativa correta
        letter_position = 0

        for letter in selected_word:
          if word_try == letter:
            revealed_letters[letter_position] = letter

          letter_position += 1

      else:
        lives -= 1

    print("As letras reveladas até agora são:", revealed_letters)

  if lives == 0:
    print("Você perdeu")
  else:
    print("Você ganhou")

def insert_words():
  insert_new_word = (input("Você quer inserir uma palavra customizada?\n") == "sim")
  while insert_new_word:
    words_list.append(input("Qual é a palavra?\n"))
    insert_new_word = (input("Você quer inserir uma palavra customizada?\n") == "sim")

load()
