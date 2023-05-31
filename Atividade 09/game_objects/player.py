import pygame

class Player:
  def __init__(self, x: int, y: int) -> None:
    self.x = x
    self.y = y

  x, y = 0, 0
  __speed = 7
  __direction = 0   # 1: baixo, 2: esquerda, 3: direita, 4: cima

  __sprite_sheet = pygame.image.load("graphics/Player Tileset.png")
  __FRAME_SIZE = 64
  __animation_frame = 0
  __animation_time = 0

  def update(self, dt: int, keys_pressed):
    self.__collider = pygame.Rect(
      self.x,
      self.y,
      self.__FRAME_SIZE,
      self.__FRAME_SIZE,
    )
    self.move(dt, keys_pressed)

  def move(self, dt: int, keys_pressed):
    if keys_pressed[pygame.K_s] or keys_pressed[pygame.K_DOWN]:
      self.y += self.__speed * dt/60
      self.__direction = 0
      self.__walking_animation(dt)

    elif keys_pressed[pygame.K_a] or keys_pressed[pygame.K_LEFT]:
      self.x -= self.__speed * dt/60
      self.__direction = 1
      self.__walking_animation(dt)

    elif keys_pressed[pygame.K_d] or keys_pressed[pygame.K_RIGHT]:
      self.x += self.__speed * dt/60
      self.__direction = 2
      self.__walking_animation(dt)

    elif keys_pressed[pygame.K_w] or keys_pressed[pygame.K_UP]:
      self.y -= self.__speed * dt/60
      self.__direction = 3
      self.__walking_animation(dt)

    else:
      self.__animation_time = 0
      self.__animation_frame = 0

  def __walking_animation(self, dt: int):
    self.__animation_time += dt
    if self.__animation_time > 2 * 60:
      self.__animation_time = 0
      self.__animation_frame += 1
      if self.__animation_frame > 3:
        self.__animation_frame = 0

  def draw(self, screen: pygame.Surface):
    screen.blit(
      source = self.__sprite_sheet,
      dest = (self.x, self.y),
      area = (
        self.__animation_frame * self.__FRAME_SIZE,
        self.__direction * self.__FRAME_SIZE,
        self.__FRAME_SIZE,
        self.__FRAME_SIZE,
      )
    )
