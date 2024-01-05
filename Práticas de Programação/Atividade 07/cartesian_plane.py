import pygame
from histogram import Histogram

class CartesianPlane:
  def __init__(self, histogram: Histogram) -> None:
    self.histogram = histogram

  histogram = Histogram([])

  def draw(self, screen: pygame.Surface, font: pygame.font.Font):
    self.draw_x_vector(screen, font)
    self.draw_y_vector(screen, font)

  def draw_x_vector(self, screen: pygame.Surface, font: pygame.font.Font, padding = 50):
    screen_width, screen_height = screen.get_size()
    pygame.draw.line(
      surface = screen,
      color = "black",
      start_pos = (padding - 10, screen_height - padding),
      end_pos = (screen_width - padding, screen_height - padding),
    )

    column_range = self.histogram.get_column_range()
    for maximum_element_in_range in range(min(self.histogram.elements) + column_range, max(self.histogram.elements) + 1, column_range):
      column_width = (screen_width - 2*padding) // self.histogram.number_of_columns
      column_number = self.histogram.get_column_number_from(maximum_element_in_range)

      screen.blit(
        source = font.render(f"{maximum_element_in_range - column_range} - {maximum_element_in_range}", False, "black"),
        dest = (padding + column_width * column_number, screen_height - padding),
      )

  def draw_y_vector(self, screen: pygame.Surface, font: pygame.font.Font, y_multiplier = 20, padding = 40):
    screen_width, screen_height = screen.get_size()
    pygame.draw.line(
      surface = screen,
      color = "black",
      start_pos = (padding, padding),
      end_pos = (padding, screen_height - padding - 10),
    )

    for y_position in range(0, 11):
      screen.blit(
        source = font.render(str(y_position * 2), False, "black"),
        dest = (padding - 20, screen_height - padding - 20 - (y_position * y_multiplier)),
      )
