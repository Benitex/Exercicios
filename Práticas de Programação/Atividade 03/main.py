import pygame
from game_objects.cloud import Cloud
from game_objects.house import House
from game_objects.tree import Tree
from game_objects.sun import Sun

pygame.init()

screen = pygame.display.set_mode((400, 300))
cloud = Cloud(screen, x = 250, y = 50)
house = House(screen, x = 50, y = 250)
tree = Tree(screen, x = 230, y = 250)
sun = Sun(screen, 50, 50)
font = pygame.font.Font("assets/circulating-font.ttf", 16)
image = pygame.image.load("assets/image.png")
music = pygame.mixer.music.load("assets/music.mp3")

def draw():
  screen.fill((137, 207, 240)) # fundo azul

  # Chão
  pygame.draw.rect(
    surface = screen,
    color = (0, 164, 0),
    rect = (0, 250, screen.get_width(), 50)
  )

  # Objetos
  sun.draw()
  cloud.draw()
  house.draw()
  tree.draw()

  # Texto
  screen.blit(
    source = font.render("Peaceful scene", False, (0, 0, 0)),
    dest = (30, 30)
  )

  # Imagem
  screen.blit(
    source = pygame.transform.scale(image, (50, 50)),
    dest = (screen.get_width() - 100, screen.get_height() - 100)
  )

  pygame.display.update()

pygame.mixer.music.play(loops = -1)
while True:
  cloud.move()
  draw()
