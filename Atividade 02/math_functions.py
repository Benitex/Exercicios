import math
from neo_turtle import NeoTurtle

turtle = NeoTurtle()
QUADRANT_SIZE = 230

def erase_plane(turtle: NeoTurtle):
  turtle.color("black")
  for quadrant_number in range(1, 5):
    turtle.erase_quadrant(quadrant_number, QUADRANT_SIZE)

# y = √x
def square_root(turtle: NeoTurtle, graphic_amplifier = 1):
  turtle.color("red")
  turtle.go_to_without_writing(0, 0)

  for x in range(0, QUADRANT_SIZE//graphic_amplifier):
    turtle.goto(
      x * graphic_amplifier,
      math.sqrt(x) * graphic_amplifier
    )

# y = 1/x
def reverse(turtle: NeoTurtle, graphic_amplifier = 1):
  turtle.color("red")
  turtle.go_to_without_writing(-QUADRANT_SIZE, 0)

  for x in range(-QUADRANT_SIZE//graphic_amplifier, QUADRANT_SIZE//graphic_amplifier):
    if x == 0: continue

    turtle.goto(
      x * graphic_amplifier,
      (1/x) * graphic_amplifier
    )

# y = 2^x
def powers_of_two(turtle: NeoTurtle, graphic_amplifier = 1):
  turtle.color("red")
  turtle.go_to_without_writing(0, 0)

  for x in range(0, QUADRANT_SIZE):
    y = (2 ** x) * graphic_amplifier
    if y > QUADRANT_SIZE: return

    turtle.goto(x * graphic_amplifier, y)

# y = 5 - x^2
def square_function_1(turtle: NeoTurtle, graphic_amplifier = 1):
  turtle.color("red")
  turtle.go_to_without_writing(-QUADRANT_SIZE, -QUADRANT_SIZE)

  for x in range(-QUADRANT_SIZE, QUADRANT_SIZE):
    y = (5 - (x ** 2)) * graphic_amplifier
    if (y > 0 and y < QUADRANT_SIZE) or (y < 0 and y > -QUADRANT_SIZE):
      turtle.goto(x * graphic_amplifier, y)

# y = x^2 - 5x + 6
def square_function_2(turtle: NeoTurtle, graphic_amplifier = 1):
  turtle.color("red")
  turtle.go_to_without_writing(-QUADRANT_SIZE, QUADRANT_SIZE)

  for x in range(-QUADRANT_SIZE, QUADRANT_SIZE):
    y = ((x ** 2) - 5*x + 6) * graphic_amplifier
    if (y > 0 and y < QUADRANT_SIZE) or (y < 0 and y > -QUADRANT_SIZE):
      turtle.goto(x * graphic_amplifier, y)

# y = x^3 - x^2 - x + 1
def cubic_function(turtle: NeoTurtle, graphic_amplifier = 1):
  turtle.color("red")
  turtle.go_to_without_writing(-QUADRANT_SIZE, 0)

  for x in range(-QUADRANT_SIZE, QUADRANT_SIZE):
    y = (x**3 - x**2 - x + 1) * graphic_amplifier
    if (y > 0 and y < QUADRANT_SIZE) or (y < 0 and y > -QUADRANT_SIZE):
      turtle.goto(x * graphic_amplifier, y)

turtle.draw_cartesian_plane(QUADRANT_SIZE)

square_root(turtle, 10)
erase_plane(turtle)

reverse(turtle, 15)
erase_plane(turtle)

powers_of_two(turtle, 10)
erase_plane(turtle)

square_function_1(turtle, 20)
erase_plane(turtle)

square_function_2(turtle, 5)
erase_plane(turtle)

cubic_function(turtle, 5)
