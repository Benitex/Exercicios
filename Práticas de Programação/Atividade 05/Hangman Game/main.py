import pygame
from hanged_player import HangedPlayer
from hangman import Hangman

pygame.init()

SCREEN = pygame.display.set_mode((400, 300))
FONT = pygame.font.Font("assets/circulating-font.ttf", 12)

hanged_player = HangedPlayer()
hangman = Hangman()

def start():
  hangman.ask_for_words()
  hangman.select_word()
  hangman.reset_revealed_letters()
  hanged_player.lives = 6

def update():
  if hanged_player.lives > 0 and not hangman.are_all_letters_revealed():
    letter_try = hanged_player.try_a_letter()

    # Tentativa de palavra
    if len(letter_try) > 1:
      if letter_try == hangman.selected_word:
        for letter in hangman.selected_word:
          hangman.reveal_letter(letter)
      else:
        hanged_player.lives -= 1

    # Tentativa de letra
    elif len(letter_try) == 1:
      if letter_try in hangman.selected_word:
        hangman.reveal_letter(letter_try)
      else:
        hanged_player.lives -= 1

  else:
    # Reiniciar o jogo
    keys = pygame.key.get_pressed()
    if keys[pygame.K_SPACE]:
      start()

def draw():
  SCREEN.fill((255, 255, 255))

  hanged_player.draw(SCREEN)
  hangman.draw_revealed_letters(SCREEN, FONT)

  if hangman.are_all_letters_revealed() or hanged_player.lives == 0:
    if hangman.are_all_letters_revealed():
      SCREEN.blit(
        source = FONT.render("Você acertou!", False, (0, 0, 0)),
        dest = (30, 30)
      )
    else:
      SCREEN.blit(
        source = FONT.render(f"Você perdeu, a palavra era {hangman.selected_word}", False, (0, 0, 0)),
        dest = (30, 30)
      )

    SCREEN.blit(
      source = FONT.render("Aperte espaço para reiniciar.", False, (0, 0, 0)),
      dest = (30, 60)
    )

  pygame.display.update()

def quit():
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()

start()
while True:
  quit()
  draw()
  update()
