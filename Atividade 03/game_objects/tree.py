import pygame.draw

class Tree:
  def __init__(self, screen, x: int, y: int):
    self.x = x
    self.y = y
    self.__screen = screen

  x = 0
  y = 0
  __screen = None

  def draw(self):
    TRUNK_HEIGHT = 80
    pygame.draw.rect(
      surface = self.__screen,
      color = (126, 76, 0),
      rect = (self.x - 10, self.y - TRUNK_HEIGHT, 20, TRUNK_HEIGHT)
    )

    RADIUS = 30
    pygame.draw.circle(
      surface = self.__screen,
      color = (0, 164, 0),
      center = (self.x, self.y - TRUNK_HEIGHT + RADIUS/2),
      radius = RADIUS
    )
