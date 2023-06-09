from neo_turtle import NeoTurtle

def draw_square_spiral(neo_turtle: NeoTurtle, line_size: int, number_of_lines: int):
  if number_of_lines == 0: return

  neo_turtle.forward(line_size)
  neo_turtle.left(90)

  draw_square_spiral(neo_turtle, line_size * 1.3, number_of_lines - 1)

def draw_funny_squares(neo_turtle: NeoTurtle, side_size: int, number_of_repetitions: int):
  if number_of_repetitions == 0: return

  for square in range(4):
    draw_square(neo_turtle, side_size)
    neo_turtle.forward(side_size)
    neo_turtle.right(90)

  draw_funny_squares(neo_turtle, side_size // 2, number_of_repetitions - 1)

def draw_square(neo_turtle: NeoTurtle, side_size: int):
  for side in range(4):
    neo_turtle.forward(side_size)
    neo_turtle.left(90)

def tree_fractal(neo_turtle: NeoTurtle, size: int, angle: int, level: int):
  if size < 40:
    return
  neo_turtle.pd()
  neo_turtle.fd(size)

  # right tree
  neo_turtle.rt(angle)
  neo_turtle.fd(size)
  tree_fractal(neo_turtle, size*0.8, angle, level-1)
  neo_turtle.back(size)

  # top tree
  neo_turtle.lt(angle)
  neo_turtle.fd(size)
  tree_fractal(neo_turtle, size*0.8, angle, level-1)
  neo_turtle.back(size)

  # left tree
  neo_turtle.lt(angle)
  neo_turtle.fd(size)
  tree_fractal(neo_turtle, size*0.8, angle, level-1)
  neo_turtle.back(size)

  neo_turtle.lt(-angle)
  neo_turtle.back(size)

neo_turtle = NeoTurtle()
neo_turtle.speed(8)

# Fácil
neo_turtle.go_to_without_writing(-200, 200)
draw_square_spiral(
  neo_turtle = neo_turtle,
  line_size = 10,
  number_of_lines = 10,
)

# Médio
neo_turtle.go_to_without_writing(200, 200)
draw_funny_squares(
  neo_turtle = neo_turtle,
  side_size = 100,
  number_of_repetitions = 4,
)

# Difícil
neo_turtle.right(90)
neo_turtle.go_to_without_writing(0, -200)
tree_fractal(neo_turtle, 60, 45, 20)
