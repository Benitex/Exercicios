from turtle import *
from neo_turtle import NeoTurtle

def draw_belgium_flag():
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
    color = "black"
  )
  turtle.draw_rectangle(
    x = -134,
    y = 280,
    width = 266,
    height = 560,
    color = "yellow"
  )
  turtle.draw_rectangle(
    x = 132,
    y = 280,
    width = 268,
    height = 560,
    color = "red"
  )

draw_belgium_flag()
