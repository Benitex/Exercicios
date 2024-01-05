import pygame.draw

class Cloud:
  def __init__(self, screen: pygame.Surface, x: int, y: int):
    self.__screen = screen
    self.__x = x
    self.__y = y

  __x = 0
  __y = 0
  __direction = 1 # 1 para direita, -1 para esquerda
  __screen = None

  __CIRCLE_RADIUS = 20
  __CIRCLE_AMOUNT = 4

  def draw(self):
    for circle_number in range(1, self.__CIRCLE_AMOUNT + 1):
      pygame.draw.circle(
        surface = self.__screen,
        color = (255, 255, 255),
        center = (
          self.__x + self.__CIRCLE_RADIUS * circle_number,
          self.__y
        ),
        radius = self.__CIRCLE_RADIUS
      )

  def move(self, dt: int):
    if self.__x + self.__CIRCLE_RADIUS + (self.__CIRCLE_AMOUNT * self.__CIRCLE_RADIUS) >= self.__screen.get_width():
      self.__direction = -1
    elif self.__x <= 0:
      self.__direction = 1
    self.__x += self.__direction * dt
