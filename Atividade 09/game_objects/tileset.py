import pygame

class Tileset:
  def __init__(self, image_name: str, tile_size: int, tiles_in_a_row: int, collisionable_tiles: list[int]) -> None:
    self.image = pygame.image.load("graphics/" + image_name + ".png")
    self.tile_size = tile_size
    self.tiles_in_a_row = tiles_in_a_row
    self.__collisionable_tiles = collisionable_tiles

  image = pygame.Surface((0, 0))
  tile_size = 0
  tiles_in_a_row = 0
  __collisionable_tiles = []

  def is_tile_collisionable(self, tile_number: int) -> bool:
    return tile_number in self.__collisionable_tiles
