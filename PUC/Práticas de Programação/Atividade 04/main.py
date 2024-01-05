import pygame
from game_objects.cloud import Cloud
from game_objects.house import House
from game_objects.tree import Tree
from game_objects.sun import Sun
from game_objects.sky import Sky

pygame.init()

screen = pygame.display.set_mode((400, 300))
clock = pygame.time.Clock()

cloud = Cloud(screen, x = 250, y = 50)
house = House(screen, x = 50, y = 250)
tree = Tree(screen, x = 230, y = 250)
sun = Sun(screen = screen, x = 50, y = 50)
sky = Sky(screen, sun)

font = pygame.font.Font("assets/circulating-font.ttf", 16)
image = pygame.image.load("assets/image.png")
music = pygame.mixer.music.load("assets/music/ai_piano_solo.mp3")

def update():
  clock.tick(60)
  dt = clock.get_time() * 0.1

  keys = pygame.key.get_pressed()
  mouse_x, mouse_y = pygame.mouse.get_pos()

  if pygame.mouse.get_pressed()[0]:
    load_music(sun.time)

  sun.move(keys, mouse_y, dt)
  sun.update_time()
  cloud.move(dt)

def draw():
  sky.draw()
  sun.draw()

  # Chão
  pygame.draw.rect(
    surface = screen,
    color = (0, 164, 0),
    rect = (0, 250, screen.get_width(), 50)
  )

  cloud.draw()
  house.draw()
  tree.draw()

  # Texto
  screen.blit(
    source = font.render("Peaceful scene", False, (0, 0, 0)),
    dest = (30, 30)
  )

  # Imagem
  screen.blit(
    source = pygame.transform.scale(image, (50, 50)),
    dest = (screen.get_width() - 100, screen.get_height() - 100)
  )

  pygame.display.update()

def load_music(time: int):
  global music
  if time <= 12:
    music = pygame.mixer.music.load("assets/music/ai_piano_solo.mp3")
  elif time <= 18:
    music = pygame.mixer.music.load("assets/music/ai_piano_jazz.mp3")
  else:
    music = pygame.mixer.music.load("assets/music/ai_jazz.mp3")
  pygame.mixer.music.play(loops = -1)

def quit():
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()

pygame.mixer.music.play(loops = -1)
while True:
  quit()
  update()
  draw()
