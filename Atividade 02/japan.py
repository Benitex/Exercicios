# Bandeira fácil

from turtle import *

def draw_japan_flag():
  turtle = Turtle()

  def go_to_without_writing(turtle: Turtle, x: int, y: int):
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()

  def draw_square(turtle: Turtle):
    turtle.goto(300, 200)
    turtle.goto(300, -200)
    turtle.goto(-300, -200)
    turtle.goto(-300, 200)

  def draw_circle(turtle: Turtle):
    turtle.fillcolor('red')
    turtle.begin_fill()
    turtle.circle(100)
    turtle.end_fill()

  go_to_without_writing(turtle, -300, 200)
  draw_square(turtle)
  go_to_without_writing(turtle, 0, -100)
  draw_circle(turtle)

draw_japan_flag()
