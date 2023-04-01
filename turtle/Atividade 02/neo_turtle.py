from turtle import *

class NeoTurtle(Turtle):
  def go_to_without_writing(self, x: int, y: int):
    self.penup()
    self.goto(x, y)
    self.pendown()

  def draw_cartesian_plane(self, plane_size: int):
    # Eixo Y
    self.goto(0, plane_size)
    self.left(90)
    self.stamp()
    self.goto(0, -plane_size)
    self.goto(0, 0)

    # Eixo X
    self.goto(-plane_size, 0)
    self.goto(plane_size, 0)
    self.right(90)
    self.stamp()

  def erase_quadrant(self, quadrant_number: int, plane_size: int):
    x, y = 0, 0
  
    match quadrant_number:
      case 1:
        y = plane_size
      case 2:
        x = -plane_size
        y = plane_size
      case 3:
        x = -plane_size
      case 4:
        x = 0
      case _:
        raise "invalid quadrant number"

    self.draw_polygon(
      number_of_sides = 4,
      x = x, y = y,
      side_size = plane_size,
      color = "white"
    )

  def draw_polygon(self, number_of_sides: int, x: int, y: int, side_size = 60, color = "white"):
    self.go_to_without_writing(x, y)

    self.fillcolor(color)
    self.begin_fill()

    angle = 360//number_of_sides
    for line in range(number_of_sides):
      self.forward(side_size)
      self.right(angle)

    self.end_fill()

  def circle(self, radius: float, x: int, y: int, color = "white", extent: float | None = None, steps: int | None = None) -> None:
    self.fillcolor(color)
    self.begin_fill()

    # O valor do raio é diminuído de y para desenhar com a posição y como centro
    self.go_to_without_writing(x, y - radius) 
    super().circle(radius, extent, steps)

    self.end_fill()

  # Quanto menor a opening, maior a abertura
  def spiral(self, x: int, y: int, size = 50, opening = 50):
    self.go_to_without_writing(x, y)
    for radius in range(size):
      super().circle(radius, opening)
