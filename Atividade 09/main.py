import pygame
from game_objects.player import Player

pygame.init()

screen = pygame.display.set_mode((400, 300))
clock = pygame.time.Clock()

player = Player(168, 118)

def update():
  clock.tick(60)
  dt = clock.get_time()

  keys_pressed = pygame.key.get_pressed()
  player.update(dt, keys_pressed)

def draw():
  screen.fill("black") # TODO remover isso quando adicionar o mapa

  player.draw(screen)

  pygame.display.update()

while True:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()

  update()
  draw()
