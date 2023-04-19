import pygame.draw

class Sun:
  def __init__(self, screen: pygame.Surface, x: int, y: int):
    self.__x = x
    self.__y = y
    self.__screen = screen

  __x = 0
  __y = 0
  __screen = None
  __RADIUS = 20
  __mouse_mode = False

  def move(self, keys: pygame.key.ScancodeWrapper, mouse_y: int, dt: int):
    # Trocar os controles
    if keys[pygame.K_1]:
      self.__mouse_mode = not self.__mouse_mode

    # Movimento pelo mouse
    if self.__mouse_mode:
      self.__y = mouse_y

    else: # Movimento por teclas
      if keys[pygame.K_w] or keys[pygame.K_UP]:
        self.__y -= 1 * dt
      elif keys[pygame.K_s] or keys[pygame.K_DOWN]:
        self.__y += 1 * dt

    # Controle para o sol não sair da tela
    if self.__y - self.__RADIUS <= 0:
      self.__y = 0 + self.__RADIUS
    if self.__y + self.__RADIUS >= self.__screen.get_height():
      self.__y = self.__screen.get_height() - self.__RADIUS

  def draw(self):
    pygame.draw.circle(
      surface = self.__screen,
      color = (254, 249, 0),
      center = (self.__x, self.__y),
      radius = self.__RADIUS
    )

    LINE_SIZE = 10
    self.__draw_sun_line(((self.__x, self.__y + self.__RADIUS), (self.__x, self.__y + self.__RADIUS + LINE_SIZE)))
    self.__draw_sun_line(((self.__x, self.__y - self.__RADIUS), (self.__x, self.__y - self.__RADIUS - LINE_SIZE)))
    self.__draw_sun_line(((self.__x + self.__RADIUS, self.__y), (self.__x + self.__RADIUS + LINE_SIZE, self.__y)))
    self.__draw_sun_line(((self.__x - self.__RADIUS, self.__y), (self.__x - self.__RADIUS - LINE_SIZE, self.__y)))
    self.__draw_sun_line(((self.__x + self.__RADIUS/2, self.__y + self.__RADIUS/2), (self.__x + self.__RADIUS/2 + LINE_SIZE, self.__y + self.__RADIUS/2 + LINE_SIZE)))
    self.__draw_sun_line(((self.__x - self.__RADIUS/2, self.__y - self.__RADIUS/2), (self.__x - self.__RADIUS/2 - LINE_SIZE, self.__y - self.__RADIUS/2 - LINE_SIZE)))
    self.__draw_sun_line(((self.__x - self.__RADIUS/2, self.__y + self.__RADIUS/2), (self.__x - self.__RADIUS/2 - LINE_SIZE, self.__y + self.__RADIUS/2 + LINE_SIZE)))
    self.__draw_sun_line(((self.__x + self.__RADIUS/2, self.__y - self.__RADIUS/2), (self.__x + self.__RADIUS/2 + LINE_SIZE, self.__y - self.__RADIUS/2 - LINE_SIZE)))

  def __draw_sun_line(self, points: list):
    pygame.draw.line(
      surface = self.__screen,
      color = (254, 249, 0),
      start_pos = points[0],
      end_pos = points[1]
    )

  def get_time(self):
    DAY_POSITION = 150
    AFTERNOON_POSITION = 250
    NIGHT_POSITION = 300

    if self.__y <= DAY_POSITION:
      return "day"
    elif self.__y <= AFTERNOON_POSITION:
      return "afternoon"
    elif self.__y <= NIGHT_POSITION:
      return "night"
