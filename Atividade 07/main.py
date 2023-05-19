import pygame
import random
from cartesian_plane import CartesianPlane
from histogram import Histogram

pygame.init()
SCREEN = pygame.display.set_mode((400, 300))
FONT = pygame.font.Font("assets/circulating-font.ttf", 8)

histogram_1 = Histogram(
  elements = [random.randint(100, 200) for number in range(50)],
)
histogram_2 = Histogram(
  elements = [100, 120, 130, 120, 150, 100, 160, 200, 190, 110, 115, 125, 135, 170, 130],
  number_of_columns = 5,
)
histogram_3 = Histogram(
  elements = [int(input("Insira o próximo número")) for number in range(5)],
  number_of_columns = 3
)
plane = CartesianPlane(histogram_1)

def draw():
  SCREEN.fill(color = "white")

  plane.draw(SCREEN, FONT)
  histogram_1.draw(SCREEN)

  pygame.display.update()

def quit():
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()

while True:
  quit()
  draw()
