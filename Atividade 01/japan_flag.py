# Bandeira fácil

from turtle import *

turtle = Turtle()

def main():
  go_to_without_writing(-300, 200)
  draw_square()
  go_to_without_writing(0, -100)
  draw_circle()

def go_to_without_writing(x: int, y: int):
  turtle.penup()
  turtle.goto(x, y)
  turtle.pendown()

def draw_square():
  turtle.goto(300, 200)
  turtle.goto(300, -200)
  turtle.goto(-300, -200)
  turtle.goto(-300, 200)

def draw_circle():
  turtle.fillcolor('red')
  turtle.begin_fill()
  turtle.circle(100)
  turtle.end_fill()

main()
