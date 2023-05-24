import pygame

class Fly:
  def __init__(self, x, y) -> None:
    self.__x = x
    self.__y = y

  __x, __y = 0, 0
  __is_moving = False
  __sprite_sheet = pygame.image.load("assets/fly.png")
  __animation_frame = 0
  __animation_time = 0

  def update(self, dt: int, mouse_buttons):
    if mouse_buttons != None and mouse_buttons[0]:
      self.__is_moving = not self.__is_moving

    if self.__is_moving:
      self.__animation_time += dt
      if self.__animation_time >= 10 * 60:
        self.__animation_time = 0
        self.__animation_frame += 1
        if self.__animation_frame > 1:
          self.__animation_frame = 0

  def draw(self, screen: pygame.Surface):
    screen.blit(
      source = self.__sprite_sheet,
      dest = (self.__x, self.__y),
      area = (16 * self.__animation_frame, 0, 16, 16)
    )
