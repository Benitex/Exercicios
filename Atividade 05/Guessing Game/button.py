import pygame

class Button:
  def __init__(self, on_pressed: callable, x: int, y: int, width: int, height: int):
    self.__on_pressed = on_pressed
    self.__x = x
    self.__y = y
    self.__width = width
    self.__height = height

  __x, __y = 0, 0
  __width, __height = 0, 0
  __on_pressed = None

  def draw(self, screen: pygame.Surface):
    pygame.draw.rect(
      surface = screen,
      color = (0, 0, 0),
      rect = (self.__x, self.__y, self.__width, self.__height)
    )

  def is_mouse_inside(self, mouse_x: int, mouse_y: int) -> bool:
    x_collision = mouse_x >= self.__x and mouse_x <= self.__x + self.__width
    y_collision = mouse_y >= self.__y and mouse_y <= self.__y + self.__height
    return x_collision and y_collision

  def click(self): self.__on_pressed()
