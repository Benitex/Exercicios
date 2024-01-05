import pygame.draw

class House:
  def __init__(self, screen, x: int, y: int):
    self.x = x
    self.y = y
    self.__screen = screen

  x = 0
  y = 0
  __screen = None
  __HOUSE_SIDE = 100

  def draw(self):
    self.__draw_base()
    self.__draw_window()
    self.__draw_door()
    self.__draw_roof()

  def __draw_base(self):
    pygame.draw.rect(
      surface = self.__screen,
      color = (100, 100, 100),
      rect = (self.x, self.y - self.__HOUSE_SIDE, self.__HOUSE_SIDE, self.__HOUSE_SIDE)
    )

  def __draw_roof(self):
    pygame.draw.polygon(
      surface = self.__screen,
      color = (255, 133, 0),
      points = (
        (self.x, self.y - self.__HOUSE_SIDE),
        (self.x + self.__HOUSE_SIDE/2, self.y - self.__HOUSE_SIDE - self.__HOUSE_SIDE/2),
        (self.x + self.__HOUSE_SIDE, self.y - self.__HOUSE_SIDE)
      )
    )

  def __draw_door(self):
    pygame.draw.rect(
      surface = self.__screen,
      color = (126, 76, 0),
      rect = (
        self.x + self.__HOUSE_SIDE - 60,
        self.y - self.__HOUSE_SIDE + 20,
        40,
        self.__HOUSE_SIDE - 20
      )
    )
    pygame.draw.circle(
      surface = self.__screen,
      color = (0, 0, 0),
      center = (
        self.x + self.__HOUSE_SIDE - 55,
        self.y - self.__HOUSE_SIDE/2
      ),
      radius = 5
    )

  def __draw_window(self):
    WINDOW_SIDE = 30
    pygame.draw.rect(
      surface = self.__screen,
      color = (21, 0, 104),
      rect = (
        self.x + 10,
        self.y - self.__HOUSE_SIDE/2 - WINDOW_SIDE/2,
        WINDOW_SIDE - 10,
        WINDOW_SIDE
      )
    )
