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
    color1, color2 = None, None
    multiplier = None
    time = self.__sun.time

    if time <= 12:
      color1 = self.__AFTERNOON_COLOR
      color2 = self.__DAY_COLOR
      multiplier = time / 12
    elif time <= 18:
      color1 = self.__NIGHT_COLOR
      color2 = self.__AFTERNOON_COLOR
      multiplier = (time - 12) / 6
    else:
      color1 = self.__AFTERNOON_COLOR
      color2 = self.__NIGHT_COLOR
      multiplier = (time - 18) / 24

    self.__screen.fill(
      self.__get_mixed_color(
        color1 = color1,
        color2 = color2,
        multiplier = multiplier
      )
    )

  def __get_mixed_color(self, color1: tuple, color2: tuple, multiplier: int):
    color = []
    reversed_multiplier = 1 - multiplier

    # É calculado o RGB da cor final a partir da porcentagem até o horário definido
    for i in range(3):
      color.append(int(
        color1[i] * multiplier + color2[i] * reversed_multiplier
      ))

    return color
