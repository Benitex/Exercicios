import pygame

class Enemy:
  def __init__(self, x: int, y: int) -> None:
    self.__x = x
    self.__y = y

  __x, __y = 0, 0
  __sprite_sheet = pygame.image.load("assets/enemy.png")
  __animation_frame = 0
  __animation_time = 0

  def update(self, dt: int):
    self.__animation_time += dt
    if self.__animation_time >= 5 * 60:
      self.__animation_time = 0
      self.__animation_frame += 1
      if self.__animation_frame > 2:
        self.__animation_frame = 1

  def draw(self, screen: pygame.Surface):
    screen.blit(
      source = self.__sprite_sheet,
      dest = (self.__x, self.__y),
      area = (16 * self.__animation_frame, 0, 16, 16)
    )
