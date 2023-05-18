import pygame
import random
from cartesian_plane import CartesianPlane
from histogram import Histogram

pygame.init()
SCREEN = pygame.display.set_mode((400, 300))
Y_MULTIPLIER = 10

histogram_1 = Histogram(
  elements = [random.randint(100, 200) for number in range(50)],
)

def draw():
  SCREEN.fill(color = "white")

  histogram_1.draw(SCREEN, y_multiplier = Y_MULTIPLIER)

  pygame.display.update()

def quit():
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()

while True:
  quit()
  draw()
