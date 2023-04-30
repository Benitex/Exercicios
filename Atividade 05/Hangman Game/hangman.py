import pygame
import random

class Hangman:
  __words_list = ['abacate', 'banana', 'caju', 'damasco', 'laranja', 'manga']
  __revealed_letters = []
  selected_word = ''

  def draw_revealed_letters(self, screen: pygame.Surface, font: pygame.font.Font):
    x_position = 40

    for letter in self.selected_word:
      if letter in self.__revealed_letters:
        screen.blit(
          source = font.render(letter, False, (0, 0, 0)),
          dest = (x_position, 200)
        )
      else:
        screen.blit(
          source = font.render('_', False, (0, 0, 0)),
          dest = (x_position, 200)
        )

      x_position += 20

  def ask_for_words(self):
    insert_new_word = (input("Você quer inserir uma palavra customizada?\n") == "sim")
    while insert_new_word:
      self.__words_list.append(input("Qual é a palavra?\n"))
      insert_new_word = (input("Você quer inserir outra palavra customizada?\n") == "sim")

  def select_word(self):
    self.selected_word = random.choice(self.__words_list)

  def reset_revealed_letters(self):
    self.__revealed_letters.clear()

  def reveal_letter(self, letter: str):
    if (letter in self.selected_word) and not (letter in self.__revealed_letters):
      self.__revealed_letters.append(letter)

  def are_all_letters_revealed(self) -> bool:
    for letter in self.selected_word:
      if not (letter in self.__revealed_letters):
        return False

    return True
  