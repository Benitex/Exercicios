import pygame
from game_objects.sun import Sun

class Sky:
  def __init__(self, screen: pygame.Surface, sun: Sun):
    self.__screen = screen
    self.__sun = sun

  __screen = None
  __sun = None
  __DAY_COLOR = (137, 207, 240)
  __AFTERNOON_COLOR = (255, 172, 77)
  __NIGHT_COLOR = (11, 29, 58)

  def draw(self):
    if self.__sun.get_time() == "day":
      self.__screen.fill(self.__DAY_COLOR)
    elif self.__sun.get_time() == "afternoon":
      self.__screen.fill(self.__AFTERNOON_COLOR)
    elif self.__sun.get_time() == "night":
      self.__screen.fill(self.__NIGHT_COLOR)
