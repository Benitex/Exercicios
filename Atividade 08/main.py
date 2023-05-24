import pygame
from game_objects.player import Player
from game_objects.enemy import Enemy
from game_objects.fly import Fly

pygame.init()

screen = pygame.display.set_mode((400, 300))
clock = pygame.time.Clock()

player = Player(x = 100, y = 230)
enemy = Enemy(x = 250, y = 230)
flies = [
  Fly(x = 100, y = 100),
  Fly(x = 150, y = 150)
]

def update(mouse_buttons):
  clock.tick(60)
  dt = clock.get_time()
  pressed_keys = pygame.key.get_pressed()

  player.update(dt, pressed_keys)
  enemy.update(dt)
  for fly in flies:
    fly.update(dt, mouse_buttons)

def draw():
  screen.fill("black")

  player.draw(screen)
  enemy.draw(screen)
  for fly in flies:
    fly.draw(screen)

  pygame.display.update()

while True:
  mouse_buttons = None
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()
    elif event.type == pygame.MOUSEBUTTONDOWN:
      mouse_buttons = pygame.mouse.get_pressed()

  update(mouse_buttons)
  draw()
