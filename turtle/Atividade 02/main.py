from turtle import *
import random
from neo_turtle import NeoTurtle

PLANE_SIZE = 230
turtle = NeoTurtle()
turtle.speed(8)

def draw_flag():
  flag = textinput(
    "Escolha uma bandeira",
    'Qual bandeira vai ser desenhada?\n(Opções: brazil, japan, cuba, belgium, cameroon, france, ireland, italy, nigeria, romenia)'
  )
  flag = flag.lower()

  exec(open(f"{flag}.py").read())

def draw_function(turtle: NeoTurtle):
  GRAPHIC_AMPLIFIER = 10

  turtle.go_to_without_writing(-PLANE_SIZE, 0)

  for x in range(-10, 10):
    turtle.goto(
      x // GRAPHIC_AMPLIFIER if x < 0 else x * GRAPHIC_AMPLIFIER,
      (2 ** x) * GRAPHIC_AMPLIFIER
    )

turtle.draw_cartesian_plane(PLANE_SIZE)

selected_color = textinput(
  "Escolha uma cor",
  "Insira uma cor em inglês para pintar as figuras geométricas."
)

# Triângulo
turtle.draw_polygon(
  number_of_sides = 3,
  side_size = 60,
  x = -random.randint(60, PLANE_SIZE),
  y = random.randint(60, PLANE_SIZE),
  color = selected_color
)
# Quadrado
turtle.draw_polygon(
  number_of_sides = 4,
  side_size = 60,
  x = random.randint(0, PLANE_SIZE - 60),
  y = random.randint(60, PLANE_SIZE),
  color = selected_color
)
# Hexágono
turtle.draw_polygon(
  number_of_sides = 6,
  side_size = 60,
  x = -random.randint(100, PLANE_SIZE - 60),
  y = -random.randint(0, PLANE_SIZE - 100),
  color = selected_color
)
# Octógono
turtle.draw_polygon(
  number_of_sides = 8,
  side_size = 60,
  x = random.randint(50, PLANE_SIZE - 150),
  y = -random.randint(0, PLANE_SIZE - 150),
  color = selected_color
)

for quadrant_number in range(1, 5):
  turtle.erase_quadrant(quadrant_number, PLANE_SIZE)

# Círculo
turtle.circle(
  radius = 30,
  x = -random.randint(60, PLANE_SIZE - 30),
  y = random.randint(60, PLANE_SIZE - 30),
  color = selected_color
)

turtle.spiral(x = 100, y = 100, opening = 25)

for quadrant_number in range(1, 5):
  turtle.erase_quadrant(quadrant_number, PLANE_SIZE)

draw_function(turtle)
draw_flag()
