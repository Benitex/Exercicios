import pygame
import random
from cartesian_plane import CartesianPlane
from histogram import Histogram

pygame.init()
SCREEN = pygame.display.set_mode((400, 300))
FONT = pygame.font.Font("assets/circulating-font.ttf", 8)

histograms = [
  Histogram(
    elements = [random.randint(100, 200) for number in range(50)],
  ),
  Histogram(
    elements = [100, 120, 130, 120, 150, 100, 160, 200, 190, 110, 115, 125, 135, 170, 130],
    number_of_columns = 5,
  ),
  Histogram(
    elements = [int(input("Insira o próximo número:\n")) for number in range(10)],
    number_of_columns = 3
  ),
]
plane = CartesianPlane(histograms[0])

histogram_number = 0

def update(pressed_keys):
  global histogram_number
  histograms_length = len(histograms)

  if pressed_keys != None:
    if pressed_keys[pygame.K_RIGHT]:
      histogram_number += 1
      if histogram_number >= histograms_length:
        histogram_number -= histograms_length

    elif pressed_keys[pygame.K_LEFT]:
      histogram_number -= 1
      if histogram_number < 0:
        histogram_number = histograms_length - 1

def draw():
  SCREEN.fill(color = "white")

  plane.draw(SCREEN, FONT)
  histograms[histogram_number].draw(SCREEN)

  pygame.display.update()

while True:
  pressed_keys = None
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()
    elif event.type == pygame.KEYDOWN:
      pressed_keys = pygame.key.get_pressed()

  update(pressed_keys)
  draw()
