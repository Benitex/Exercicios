import pygame

class HangedPlayer:
  lives = 6

  # Sprites
  GALLOW = pygame.image.load("assets/sprites/gallow.png")
  LEFT_LEG = pygame.image.load("assets/sprites/left_leg.png")
  RIGHT_LEG = pygame.image.load("assets/sprites/right_leg.png")
  LEFT_ARM = pygame.image.load("assets/sprites/left_arm.png")
  RIGHT_ARM = pygame.image.load("assets/sprites/right_arm.png")
  BODY = pygame.image.load("assets/sprites/body.png")
  HEAD = pygame.image.load("assets/sprites/head.png")

  def try_a_letter(self) -> str:
    word = input("Chute uma letra\n")
    while self.__validate_word(word) == False:
      word = input("Chute uma letra válida\n")

    return word

  def __validate_word(self, word: str):
    for letter in word:
      if letter < 'a' or letter > 'z':
        return False

    return True

  def draw(self, screen: pygame.Surface):
    if self.lives >= 4:
      screen.blit(
        source = pygame.transform.scale(self.LEFT_ARM, (64, 64)),
        dest = (318, 84)
      )

    if self.lives >= 3:
      screen.blit(
        source = pygame.transform.scale(self.RIGHT_ARM, (64, 64)),
        dest = (263, 86)
      )

    if self.lives >= 2:
      screen.blit(
        source = pygame.transform.scale(self.BODY, (64, 64)),
        dest = (274, 96)
      )

    if self.lives >= 6:
      screen.blit(
        source = pygame.transform.scale(self.LEFT_LEG, (64, 64)),
        dest = (312, 154)
      )

    if self.lives >= 5:
      screen.blit(
        source = pygame.transform.scale(self.RIGHT_LEG, (64, 64)),
        dest = (294, 154)
      )

    if self.lives >= 1:
      screen.blit(
        source = pygame.transform.scale(self.HEAD, (64, 64)),
        dest = (274, 32)
      )

    screen.blit(
      source = pygame.transform.scale(self.GALLOW, (96, 160)),
      dest = (300, 32)
    )
