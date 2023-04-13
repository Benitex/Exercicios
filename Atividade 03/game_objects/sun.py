import pygame.draw

class Sun:
  def __init__(self, screen, x: int, y: int):
    self.x = x
    self.y = y
    self.__screen = screen

  x = 0
  y = 0
  __screen = None
  __RADIUS = 20

  def draw(self):
    pygame.draw.circle(
      surface = self.__screen,
      color = (254, 249, 0),
      center = (self.x, self.y),
      radius = self.__RADIUS
    )

    LINE_SIZE = 10
    self.__draw_sun_line(((self.x, self.y + self.__RADIUS), (self.x, self.y + self.__RADIUS + LINE_SIZE)))
    self.__draw_sun_line(((self.x, self.y - self.__RADIUS), (self.x, self.y - self.__RADIUS - LINE_SIZE)))
    self.__draw_sun_line(((self.x + self.__RADIUS, self.y), (self.x + self.__RADIUS + LINE_SIZE, self.y)))
    self.__draw_sun_line(((self.x - self.__RADIUS, self.y), (self.x - self.__RADIUS - LINE_SIZE, self.y)))
    self.__draw_sun_line(((self.x + self.__RADIUS/2, self.y + self.__RADIUS/2), (self.x + self.__RADIUS/2 + LINE_SIZE, self.y + self.__RADIUS/2 + LINE_SIZE)))
    self.__draw_sun_line(((self.x - self.__RADIUS/2, self.y - self.__RADIUS/2), (self.x - self.__RADIUS/2 - LINE_SIZE, self.y - self.__RADIUS/2 - LINE_SIZE)))
    self.__draw_sun_line(((self.x - self.__RADIUS/2, self.y + self.__RADIUS/2), (self.x - self.__RADIUS/2 - LINE_SIZE, self.y + self.__RADIUS/2 + LINE_SIZE)))
    self.__draw_sun_line(((self.x + self.__RADIUS/2, self.y - self.__RADIUS/2), (self.x + self.__RADIUS/2 + LINE_SIZE, self.y - self.__RADIUS/2 - LINE_SIZE)))

  def __draw_sun_line(self, points):
    pygame.draw.line(
      surface = self.__screen,
      color = (254, 249, 0),
      start_pos = points[0],
      end_pos = points[1]
    )
