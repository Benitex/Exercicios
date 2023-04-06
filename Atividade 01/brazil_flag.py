# Bandeira média

from turtle import *

turtle = Turtle()
colormode(255)

def main():
  go_to_without_writing(-400, 280)
  draw_green_rectangle()
  go_to_without_writing(0, 216)
  draw_yellow_diamond()
  go_to_without_writing(0, -140)
  draw_blue_circle()

def go_to_without_writing(x: int, y: int):
  turtle.penup()
  turtle.goto(x, y)
  turtle.pendown()

def draw_green_rectangle():
  turtle.fillcolor(0, 156, 59)
  turtle.begin_fill()
  turtle.goto(400, 280)
  turtle.goto(400, -280)
  turtle.goto(-400, -280)
  turtle.goto(-400, 280)
  turtle.end_fill()

def draw_yellow_diamond():
  turtle.fillcolor(255, 223, 0)
  turtle.begin_fill()
  turtle.goto(332, 0)
  turtle.goto(0, -216)
  turtle.goto(-332, 0)
  turtle.goto(0, 216)
  turtle.end_fill()

def draw_blue_circle():
  turtle.fillcolor(0, 39, 118)
  turtle.begin_fill()
  turtle.circle(140)
  turtle.end_fill()

main()
