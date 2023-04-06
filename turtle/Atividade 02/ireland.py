from turtle import *
from neo_turtle import NeoTurtle

def draw_ireland_flag():
  turtle = NeoTurtle()

  turtle.draw_rectangle(
    x = -400,
    y = 280,
    width = 800,
    height = 560
  )
  turtle.draw_rectangle(
    x = -400,
    y = 280,
    width = 266,
    height = 560,
    color = "green"
  )
  turtle.draw_rectangle(
    x = 134,
    y = 280,
    width = 266,
    height = 560,
    color = "orange"
  )

draw_ireland_flag()
