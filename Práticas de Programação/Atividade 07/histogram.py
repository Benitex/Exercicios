import pygame

class Histogram:
  def __init__(self, elements: list[int], number_of_columns = 4) -> None:
    self.elements = elements
    self.number_of_columns = number_of_columns

  elements = []
  number_of_columns = 4

  def draw(self, screen: pygame.Surface, padding = 50, space_between_columns = 10, y_multiplier = 10):
    screen_width, screen_height = screen.get_size()
    column_width = (screen_width - 2*padding) // self.number_of_columns

    for (column_number, number_of_elements_in_column) in enumerate(self.separate_elements_in_columns()):
      column_height = number_of_elements_in_column * y_multiplier
      color = 10 + (column_number * 255//self.number_of_columns)

      pygame.draw.rect(
        surface = screen,
        color = (color, color, color),
        rect = (
          padding + column_number * column_width,
          screen_height - column_height - padding,
          column_width - space_between_columns,
          column_height,
        )
      )

  def separate_elements_in_columns(self) -> list[int]:
    columns = [0 for column in range(self.number_of_columns)]

    greatest_element = max(self.elements)
    smallest_element = min(self.elements)
    column_range = self.get_column_range()

    for element in self.elements:
      for maximum_element_in_range in range(smallest_element + column_range, greatest_element + 1, column_range):
        if element <= maximum_element_in_range:
          columns[((maximum_element_in_range - smallest_element) // column_range) - 1] += 1
          break

    return columns

  def get_column_number_from(self, maximum_element_in_column: int) -> int:
    return ((maximum_element_in_column - min(self.elements)) // self.get_column_range()) - 1

  # Retorna o valor que divide elementos em uma coluna
  # Por exemplo, retorna 25 em uma lista com elementos entre 0 e 100 e 4 colunas
  def get_column_range(self) -> int:
    return (max(self.elements) - min(self.elements)) // self.number_of_columns
