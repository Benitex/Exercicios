# Formas geométricas

from turtle import *

PLANE_SIZE = 230
turtle = Turtle()

def main():
  draw_cartesian_plane()
  ask_for_color()
  go_to_without_writing(-100, 100)
  draw_geometric_shape(60)
  go_to_without_writing(100, 100)
  draw_geometric_shape(90)
  go_to_without_writing(-100, -150)
  draw_geometric_shape(120)
  go_to_without_writing(100, -150)
  draw_geometric_shape(135)

def go_to_without_writing(x: int, y: int):
  turtle.penup()
  turtle.goto(x, y)
  turtle.pendown()

def draw_cartesian_plane():
  # Eixo Y
  turtle.goto(0, PLANE_SIZE)
  turtle.left(90)
  turtle.stamp()
  turtle.goto(0, -PLANE_SIZE)
  turtle.goto(0, 0)

  # Eixo X
  turtle.goto(-PLANE_SIZE, 0)
  turtle.goto(PLANE_SIZE, 0)
  turtle.right(90)
  turtle.stamp()

def ask_for_color():
  color = textinput("color", "Insira uma cor em inglês para pintar as figuras geométricas.")
  turtle.fillcolor(color)
  turtle.begin_fill()

# angle é um valor inteiro que representa o ângulo interno do polígono
def draw_geometric_shape(angle: int):
  turtle.begin_fill()

  external_angle = 180 - angle
  for line in range(360//external_angle):
    turtle.forward(60)
    turtle.left(external_angle)
    
  turtle.end_fill()

main()
