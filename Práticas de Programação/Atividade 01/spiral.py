# Espiral

from turtle import *

PLANE_SIZE = 230
turtle = Turtle()

def main():
  draw_cartesian_plane()
  go_to_without_writing(100, 100)
  draw_spiral()

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

def draw_spiral():
  for radius in range(50):
    turtle.circle(radius, 50)

main()
