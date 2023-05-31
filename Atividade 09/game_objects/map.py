import pygame
from game_objects.tileset import Tileset

class Map:
  def __init__(self, map_layers: list, width: int, tileset: Tileset) -> None:
    self.__map_layers = map_layers
    self.__width = width
    self.__tileset = tileset

  __map_layers = []
  __tileset = Tileset
  __width = 0

  def draw(self, screen: pygame.Surface):
    for layer in self.__map_layers:
      for tile_number, tile in enumerate(layer):
        if tile == -1: continue

        screen.blit(
          source = self.__tileset.image,
          dest = (
            (tile_number % self.__width) * self.__tileset.tile_size,
            (tile_number // self.__width) * self.__tileset.tile_size,
          ),
          area = (
            (tile % self.__tileset.tiles_in_a_row) * self.__tileset.tile_size,
            (tile // self.__tileset.tiles_in_a_row) * self.__tileset.tile_size,
            self.__tileset.tile_size,
            self.__tileset.tile_size,
          ),
        )

