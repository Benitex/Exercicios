import pygame.draw

class Cloud:
  def __init__(self, screen, x: int, y: int):
    self.__screen = screen
    self.x = x
    self.initial_x = x
    self.y = y

  x = 0
  y = 0
  initial_x = 0
  __screen = None

  __CIRCLE_RADIUS = 20
  __CIRCLE_AMOUNT = 4

  def draw(self):
    for circle_number in range(1, self.__CIRCLE_AMOUNT + 1):
      pygame.draw.circle(
        surface = self.__screen,
        color = (255, 255, 255),
        center = (
          self.x + self.__CIRCLE_RADIUS * circle_number,
          self.y
        ),
        radius = self.__CIRCLE_RADIUS
      )

  def move(self):
    if self.x - self.__CIRCLE_RADIUS <= self.__screen.get_width():
      self.x += 1
    else:
      self.x = self.initial_x
    pygame.time.wait(100)
