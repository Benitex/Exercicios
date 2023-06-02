import pygame
from game_objects.camera import Camera
from game_objects.player import Player
from game_objects.map import Map
from game_objects.tileset import Tileset

def update():
  clock.tick(60)
  dt = clock.get_time()

  keys_pressed = pygame.key.get_pressed()
  player.update(dt, keys_pressed, village_map.colliders, camera)

def draw():
  village_map.draw(screen, camera)
  player.draw(screen)

  pygame.display.update()

def convert_CSV_to_map_layer(csv_file_path: str) -> list[int]:
  layer = []

  file = open(csv_file_path)
  for line in file.readlines():
    for tile in line.split(","):
      layer.append(int(tile))

  return layer

pygame.init()

screen = pygame.display.set_mode((400, 300))
clock = pygame.time.Clock()
camera = Camera(104, 86)

player = Player(270, 200)
village_map = Map(
  width = 50,
  tileset = Tileset(
    image_name = "Bushido Outdoor Tileset",
    tiles_in_a_row = 8,
    tile_size = 32,
    non_collisionable_tiles = [
      -1, 0, 3,
      944, 960, 977,
      1000, 1001, 1002, 1003, 1004, 1005, 1006,
      1014, 1022, 1030, 1038, 1046,
      2584, 2585, 2588, 2589, 2597, 2605, 2613, 2621, 2592, 2600, 2608, 2617, 2620,
    ],
  ),
  map_layers = [
    convert_CSV_to_map_layer("maps/oriental village/oriental village - layer 1.csv"),
    convert_CSV_to_map_layer("maps/oriental village/oriental village - layer 2.csv"),
    convert_CSV_to_map_layer("maps/oriental village/oriental village - layer 3.csv"),
  ]
)

while True:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()

  update()
  draw()
