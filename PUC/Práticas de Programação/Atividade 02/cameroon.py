from turtle import *
from neo_turtle import NeoTurtle

def draw_cameroon_flag():
  turtle = NeoTurtle()

  def draw_star(turtle: Turtle):
    x = turtle.xcor()
    y = turtle.ycor()

    turtle.penup()
    turtle.goto(x, y + 95)
    turtle.pendown()

    turtle.goto(x + 25, y + 25)
    turtle.goto(x + 95, y + 25)
    turtle.goto(x + 42, y - 17)
    turtle.goto(x + 42, y - 17)
    turtle.goto(x + 95, y - 95)
    turtle.goto(x, y - 45)

    turtle.goto(x - 95, y - 95)
    turtle.goto(x - 42, y - 17)
    turtle.goto(x - 42, y - 17)
    turtle.goto(x - 95, y + 25)
    turtle.goto(x - 25, y + 25)
    turtle.goto(x, y + 95)

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
    x = -134,
    y = 280,
    width = 266,
    height = 560,
    color = "red"
  )
  turtle.draw_rectangle(
    x = 132,
    y = 280,
    width = 268,
    height = 560,
    color = "yellow"
  )
  turtle.go_to_without_writing(0, 0)
  turtle.fillcolor("yellow")
  turtle.begin_fill()
  draw_star(turtle)
  turtle.end_fill()

draw_cameroon_flag()
