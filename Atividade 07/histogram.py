import pygame

class Histogram:
  def __init__(self, elements: list[int], number_of_columns = 4) -> None:
    self.__elements = elements
    self.__number_of_columns = number_of_columns

  __elements = []
  __number_of_columns = 4

  def draw(self, screen: pygame.Surface, padding = 50, space_between_columns = 10, y_multiplier = 10):
    screen_width, screen_height = screen.get_size()
    column_width = screen_width // self.__number_of_columns

    for (column_number, number_of_elements_in_column) in enumerate(self.separate_elements_in_columns()):
      column_height = number_of_elements_in_column * y_multiplier
      color = 10 + (column_number * 255//self.__number_of_columns)

      pygame.draw.rect(
        surface = screen,
        color = (color, color, color),
        rect = (
          column_number * column_width,
          screen_height - column_height - padding,
          column_width - space_between_columns,
          column_height,
        )
      )

  def separate_elements_in_columns(self) -> list[int]:
    columns = [0 for column in range(self.__number_of_columns)]

    greatest_element = max(self.__elements)
    smallest_element = min(self.__elements)
    elements_per_range = (greatest_element - smallest_element) // self.__number_of_columns

    for element in self.__elements:
      for maximum_element_in_range in range(smallest_element + elements_per_range, greatest_element + 1, elements_per_range):
        if element <= maximum_element_in_range:
          columns[((maximum_element_in_range - smallest_element) // elements_per_range) - 1] += 1
          break

    return columns
